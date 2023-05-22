#ifndef RENDER_LAYER_HPP
#define RENDER_LAYER_HPP

#include "Header.hpp"

#include "Layer.hpp"

namespace Tolik
{
class Event;
class IndexBuffer;

class RenderLayer : Layer
{
public:
  RenderLayer(std::queue<Event*> *eventQueue, Debug *debug);
  ~RenderLayer();

  virtual void Update() override;
};
}

#endif