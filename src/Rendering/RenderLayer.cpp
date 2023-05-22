#include "RenderLayer.hpp"

#include "Header.hpp"

#include "Layer.hpp"
#include "Debug.hpp"

namespace Tolik
{
RenderLayer::RenderLayer(std::queue<Event*> *eventQueue, Debug *debug)
  : Layer(eventQueue, debug)
{
  
}

RenderLayer::~RenderLayer()
{
  
}

void RenderLayer::Update()
{
  
}
}