#ifndef GAME_LOOP_LAYER_HPP
#define GAME_LOOP_LAYER_HPP

#include "Header.hpp"

#include "Layer.hpp"

namespace Tolik
{
class GameLoopLayer : Layer
{
public:
  GameLoopLayer(std::queue<Event*> *eventQueue, Debug *debug);

  virtual void Update() override {}
};
}

#endif