#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "LayerStack.hpp"
#include "EventHandler.hpp"
#include "Debug.hpp"

namespace Tolik
{
class Event;

class Application
{
  friend class EventHandler;
public:
  Application() { Init(); }
  void Init();
  void Run();
  void Quit();

private:
  void OnEvent(Event* event);

  bool m_running = false;
  LayerStack m_layerStack;
  EventHandler m_eventHandler;
  Debug m_debug;
  
};
}

#endif