#include "GameLoopLayer.hpp"

#include "Header.hpp"

#include "Layer.hpp"
#include "DependencyInterfaces.hpp"

namespace Tolik
{
GameLoopLayer::GameLoopLayer(BaseDeps *newBaseDeps)
{
  m_baseDeps = newBaseDeps;
}
GameLoopLayer::~GameLoopLayer()
{
  
}
}