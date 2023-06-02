#include "RenderLayer.hpp"

#include "Header.hpp"

#include "Layer.hpp"
#include "DependencyInterfaces.hpp"
#include "RenderAPIOpenGL.hpp"
#include "Event.hpp"
#include "Debug.hpp"

namespace Tolik
{
RenderLayer::RenderLayer(BaseDeps *newBaseDeps)
{
  m_baseDeps = newBaseDeps;
  m_api = new RenderAPIOpenGL(m_baseDeps->debug);

  SDL_CALL(m_baseDeps->debug, SDL_Init(SDL_INIT_EVERYTHING));
  SDL_CALL(m_baseDeps->debug, m_window = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 500, 500, m_api->GetSDLWindowFlags()));
  m_api->CreateContext(m_context, m_window);
  m_api->Load();
}

RenderLayer::~RenderLayer()
{
  m_api->DestroyContext(m_context);
  SDL_Quit();
}

void RenderLayer::Update()
{
  m_api->Clear();



  m_api->SwapBuffers(m_window);
}
void RenderLayer::OnEvent(Event *event)
{
  if(event->GetHandlet())
    return;

  if(Event::Any(event->GetType() & EventType::WindowResize))
  {
    WindowResizeEvent *windowResizeEvent = reinterpret_cast<WindowResizeEvent*>(event);
    m_api->Viewport(0, 0, windowResizeEvent->GetNewWindowSize().x, windowResizeEvent->GetNewWindowSize().y);
  }
}
}