#ifndef EVENT_HPP
#define EVENT_HPP

#include "Header.hpp"

#include "Defines.hpp"
#include "Vec2.hpp"

namespace Tolik
{
//max ammount of types is 65535 because we can use only first 16 bits
enum class EventType : uint32_t
{
  None,
  Quit,
  WindowResize,
  MouseMove, MouseLeft, MouseMiddle, MouseRigth, MouseScroll,
  KeyDown, KeyUp
};
//max ammount of groups is 16. They start at 17-th bit
enum class EventGroup : uint32_t
{
  Window = BIT(16),
  Input = BIT(17) | BIT(18),
  MouseInput = BIT(17),
  KeyInput = BIT(18),
};

class Event
{
public:
  virtual uint32_t GetType() = 0;
  inline bool GetHandlet() { return handlet; }
  inline void SetAsHandlet() { handlet = true; }

  virtual std::string GetName() { return "None"; }
private:
  bool handlet;
};


class WindowResizeEvent : public Event
{
public:
  WindowResizeEvent(vec2 newWindowSize) { m_newWindowSize = newWindowSize; }

  virtual uint32_t GetType() override { return static_cast<uint32_t>(EventGroup::Window) | static_cast<uint32_t>(EventType::WindowResize); }
  inline vec2 GetNewWindowSize() { return m_newWindowSize; }
  inline void SetNewWindowSize(vec2 newWindowSize) { m_newWindowSize = newWindowSize; }

  virtual std::string GetName() override { return "Window Resize"; }
private:
  vec2 m_newWindowSize;
};


class QuitEvent : public Event 
{
  virtual uint32_t GetType() override { return static_cast<uint32_t>(EventType::Quit); }
  virtual std::string GetName() override { return "Quit Event"; }
};
}

#endif