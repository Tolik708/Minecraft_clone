#include "LayerStack.hpp"

#include "Header.hpp"

#include "Layer.hpp"
#include "GameLoopLayer.hpp"
#include "RenderLayer.hpp"

namespace Tolik
{
void LayerStack::Init(BaseDeps *baseDeps)
{
  layers.push_back(reinterpret_cast<Layer*>(new GameLoopLayer(baseDeps)));
  layers.push_back(reinterpret_cast<Layer*>(new RenderLayer(baseDeps)));
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