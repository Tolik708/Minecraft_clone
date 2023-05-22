#include "DependencyContainer.hpp"

#include "Header.hpp"

#include "Debug.hpp"

namespace Tolik
{
void DepContainer::TryLogError(const std::string &format, const char *typeName) const
{
  /* Almost allways Debug will be found. 
  Can't add own Debug to be sure that container is light weight to copy */
  MapType::const_iterator it = servicies.find(typeid(Debug));
  if(it != servicies.end())
    reinterpret_cast<Debug*>(it->second)->Error(format, typeName);
}
}