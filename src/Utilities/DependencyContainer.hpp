#ifndef DEPENDENCY_CONTAINER_HPP
#define DEPENDENCY_CONTAINER_HPP

#include "Header.hpp"
#include "Debug.hpp"

namespace Tolik
{
class DepContainer
{
  using MapType = std::unordered_map<std::type_index, void*>;
public:
  //Get object (not check)
  template<typename T> inline T *Get() const;
  //Use to check if object exists
  template<typename T> inline bool Exsist() const;
  //Add existing object
  template<typename T> inline void Push(T *newService);
  //Create new object from parametrs
  template<typename T, typename... Args> inline void Emplace(Args&&... args);
  
private:
  //take const char* insted of type_info beacause it usually lighter
  void TryLogError(const std::string &format, const char *typeName) const;

  MapType servicies;
};


template <typename T> inline T *DepContainer::Get() const
{
  MapType::const_iterator it = servicies.find(typeid(T));
  if(it != servicies.end())
    return reinterpret_cast<T*>(it->second);
  
  // expected that most of the times service will be found. 
  TryLogError(std::string("Service @0 not found"), typeid(T).name());
  return nullptr;
}

template <typename T> inline bool DepContainer::Exsist() const
{
  return servicies.count(typeid(T));
}

template <typename T>
void inline DepContainer::Push(T *newService)
{
  servicies[typeid(T)] = newService;
}

template <typename T, typename... Args> inline void DepContainer::Emplace(Args&&... args)
{
  servicies[typeid(T)] = new T(std::move(args)...);
}
}

#endif