#ifndef LAYER_STACK_HPP
#define LAYER_STACK_HPP

#include "Header.hpp"

#include "Layer.hpp"

namespace Tolik
{
class Debug;
class Event;

class LayerStack
{
public:
  void Init(Debug *debug, std::queue<Event*> *eventQueue);
  void Update();
  void Quit();
  void OnEvent(Event* event);

private:
  std::vector<Layer*> layers;
};
}

#endif