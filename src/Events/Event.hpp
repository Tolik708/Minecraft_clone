#ifndef EVENT_HPP
#define EVENT_HPP

#include "Header.hpp"

#include "Defines.hpp"
#include "Vec2.hpp"

namespace Tolik
{
enum class EventType : uint16_t
{
  None,
  Quit,
  WindowResize,
  MouseMove, MouseLeft, MouseMiddle, MouseRigth, MouseScroll,
  KeyDown, KeyUp
};
enum class EventGroup : uint16_t
{
  None,
  Window = BIT(0),
  Input = BIT(1) | BIT(2),
  MouseInput = BIT(1),
  KeyInput = BIT(2),
};

inline EventType operator&(EventType a, EventType b) { return static_cast<EventType>(static_cast<uint16_t>(a) & static_cast<uint16_t>(b)); }
inline EventType operator|(EventType a, EventType b) { return static_cast<EventType>(static_cast<uint16_t>(a) | static_cast<uint16_t>(b)); }
inline EventType operator^(EventType a, EventType b) { return static_cast<EventType>(static_cast<uint16_t>(a) ^ static_cast<uint16_t>(b)); }
inline EventType operator&(EventType a, EventGroup b) { return static_cast<EventType>(static_cast<uint16_t>(a) & static_cast<uint16_t>(b)); }
inline EventType operator|(EventType a, EventGroup b) { return static_cast<EventType>(static_cast<uint16_t>(a) | static_cast<uint16_t>(b)); }
inline EventType operator^(EventType a, EventGroup b) { return static_cast<EventType>(static_cast<uint16_t>(a) ^ static_cast<uint16_t>(b)); }
inline EventGroup operator&(EventGroup a, EventType b) { return static_cast<EventGroup>(static_cast<uint16_t>(a) & static_cast<uint16_t>(b)); }
inline EventGroup operator|(EventGroup a, EventType b) { return static_cast<EventGroup>(static_cast<uint16_t>(a) | static_cast<uint16_t>(b)); }
inline EventGroup operator^(EventGroup a, EventType b) { return static_cast<EventGroup>(static_cast<uint16_t>(a) ^ static_cast<uint16_t>(b)); }
inline EventGroup operator&(EventGroup a, EventGroup b) { return static_cast<EventGroup>(static_cast<uint16_t>(a) & static_cast<uint16_t>(b)); }
inline EventGroup operator|(EventGroup a, EventGroup b) { return static_cast<EventGroup>(static_cast<uint16_t>(a) | static_cast<uint16_t>(b)); }
inline EventGroup operator^(EventGroup a, EventGroup b) { return static_cast<EventGroup>(static_cast<uint16_t>(a) ^ static_cast<uint16_t>(b)); }

class Event
{
public:
  template<typename T> static bool Any(T event) { return static_cast<uint16_t>(event) != 0; }

  inline EventType GetType() { return type; }
  inline EventGroup GetGroup() { return group; }
  inline bool GetHandlet() { return handlet; }
  inline void SetAsHandlet() { handlet = true; }

  virtual std::string GetName() { return "None"; }
protected:
  Event(EventType newType, EventGroup newGroup) : type(newType), group(newGroup) {}

private:
  const EventType type;
  const EventGroup group;
  bool handlet;
};


class WindowResizeEvent : public Event
{
public:
  WindowResizeEvent(vec2 newWindowSize) : Event(EventType::WindowResize, EventGroup::Window) { m_newWindowSize = newWindowSize; }

  inline vec2 GetNewWindowSize() { return m_newWindowSize; }

  virtual std::string GetName() override { return "Window Resize"; }
private:
  vec2 m_newWindowSize;
};


class QuitEvent : public Event 
{
public:
  QuitEvent() : Event(EventType::Quit, EventGroup::Window) {}

  virtual std::string GetName() override { return "Quit Event"; }
};
}

#endif