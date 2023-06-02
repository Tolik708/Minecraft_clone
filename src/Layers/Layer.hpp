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
  virtual ~Layer() {}

  virtual void Update() {}
  virtual void OnEvent(Event *event) {}
};
}

#endif