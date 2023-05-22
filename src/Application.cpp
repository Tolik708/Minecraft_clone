#include "Application.hpp"

#include "EventHandler.hpp"
#include "Event.hpp"

namespace Tolik
{
void Application::Init()
{
  SDL_Init(SDL_INIT_EVERYTHING);

  m_eventHandler.Init(this, &m_debug);
  m_layerStack.Init(&m_debug, m_eventHandler.GetQueue());
}

void Application::Run()
{
  m_running = true;
  while(m_running)
  {
    m_layerStack.Update();
    m_eventHandler.Update();
  }
  Quit();
}

void Application::Quit()
{
  m_layerStack.Quit();
}


void Application::OnEvent(Event *event)
{
  m_layerStack.OnEvent(event);
  if(!event->GetHandlet() && (event->GetType() & static_cast<uint32_t>(EventType::Quit)))
  {
    m_running = false;
  }
}
}
