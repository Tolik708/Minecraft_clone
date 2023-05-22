#ifndef LAYER_HPP
#define LAYER_HPP

#include "Header.hpp"

namespace Tolik
{
class Event;
class Debug;

class Layer
{
public:
  Layer(std::queue<Event*> *eventQueue, Debug *debug) { m_eventQueue = eventQueue; m_debug = debug; }
  virtual ~Layer() {}

  virtual void Update() {}
  virtual void OnEvent(Event *event) {}

protected:
  std::queue<Event*> *m_eventQueue;
  Debug *m_debug;
};
}

#endif