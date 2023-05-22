#include "LayerStack.hpp"

#include "Header.hpp"

#include "Layer.hpp"
#include "GameLoopLayer.hpp"
#include "RenderLayer.hpp"

namespace Tolik
{
void LayerStack::Init(Debug *debug, std::queue<Event*> *eventQueue)
{
  layers.push_back(reinterpret_cast<Layer*>(new GameLoopLayer(eventQueue, debug)));
  layers.push_back(reinterpret_cast<Layer*>(new RenderLayer(eventQueue, debug)));
}

void LayerStack::Update()
{
  for (std::vector<Layer*>::iterator it = layers.begin(); it != layers.end(); it++)
    (*it)->Update();
}

void LayerStack::Quit()
{
  for (std::vector<Layer*>::iterator it = layers.begin(); it != layers.end(); it++)
    delete *it;
}

void LayerStack::OnEvent(Event *event)
{
  for (std::vector<Layer*>::iterator it = layers.begin(); it != layers.end(); it++)
    (*it)->OnEvent(event);
}
}