#ifndef EVENT_HANDLER_HPP
#define EVENT_HANDLER_HPP

#include "Header.hpp"

namespace Tolik
{
class Event;
class Application;
class Debug;

class EventHandler
{
public:
  void Init(Application *application, Debug *debug);
  void Update();

  inline std::queue<Event*> *GetQueue() { return &m_queue; }

private:
  void Dispatch();
  void GetSDLEvents();

  std::queue<Event*> m_queue;
  Application *m_application;
  Debug *m_debug;
};
}

#endif