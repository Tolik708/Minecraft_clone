#ifndef LAYER_STACK_HPP
#define LAYER_STACK_HPP

#include "Header.hpp"

#include "Layer.hpp"

namespace Tolik
{
class BaseDeps;
class Event;

class LayerStack
{
public:
  void Init(BaseDeps *baseDeps);
  void Update();
  void Quit();
  void OnEvent(Event* event);

private:
  std::vector<Layer*> layers;
};
}

#endif