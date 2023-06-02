#include "Application.hpp"

#include "EventHandler.hpp"
#include "Event.hpp"
#include "DependencyInterfaces.hpp"

namespace Tolik
{
void Application::Init()
{
  SDL_Init(SDL_INIT_EVERYTHING);

  BaseDeps baseDeps;
  baseDeps.debug = &m_debug;

  m_eventHandler.Init([this](Event* event) -> void { OnEvent(event); }, &m_debug);
  baseDeps.events = m_eventHandler.GetQueue();
  
  m_layerStack.Init(&baseDeps);
  m_eventHandler.Update();
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
    m_running = false;
}
}
