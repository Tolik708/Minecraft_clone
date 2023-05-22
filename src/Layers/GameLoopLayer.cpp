#include "GameLoopLayer.hpp"

#include "Header.hpp"

#include "Layer.hpp"

namespace Tolik
{
GameLoopLayer::GameLoopLayer(std::queue<Event*> *eventQueue, Debug *debug)
  : Layer(eventQueue, debug)
{}
}