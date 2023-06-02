#ifndef RENDER_LAYER_HPP
#define RENDER_LAYER_HPP

#include "Header.hpp"

#include "Layer.hpp"
#include "RenderAPI.hpp"

namespace Tolik
{
class BaseDeps;

class RenderLayer : Layer
{
public:
  RenderLayer(BaseDeps *newBaseDeps);
  virtual ~RenderLayer();

  virtual void Update() override;
  virtual void OnEvent(Event* event) override;

private:
  BaseDeps *m_baseDeps;
  RenderAPI *m_api;
  SDL_Window *m_window;
  void *m_context;
};
}

#endif