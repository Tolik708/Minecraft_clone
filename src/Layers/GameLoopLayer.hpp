#ifndef GAME_LOOP_LAYER_HPP
#define GAME_LOOP_LAYER_HPP

#include "Header.hpp"

#include "Layer.hpp"

namespace Tolik
{
class BaseDeps;

class GameLoopLayer : Layer
{
public:
  GameLoopLayer(BaseDeps *newBaseDeps);
  virtual ~GameLoopLayer();

  virtual void Update() override {}

private:
  BaseDeps *m_baseDeps;
};
}

#endif