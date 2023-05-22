#include "EventHandler.hpp"

#include "Header.hpp"

#include "Event.hpp"
#include "Application.hpp"
#include "Debug.hpp"

namespace Tolik
{
void EventHandler::Init(Application *application, Debug *debug)
{
  m_application = application;
  m_debug = debug;
}

void EventHandler::Update()
{
  GetSDLEvents();
  Dispatch();
}
void EventHandler::Dispatch()
{
  while(!m_queue.empty())
  {
    Event* event = m_queue.front();
    m_application->OnEvent(event);
    m_queue.pop();
  }
}
void EventHandler::GetSDLEvents()
{
  SDL_Event event;
  while(SDL_PollEvent(&event))
  {
    switch(event.type)
    {
    case SDL_QUIT:
      m_queue.push(reinterpret_cast<Event*>(new QuitEvent()));
      break;
    default:
      m_debug->Info("Undifined SDL event @0", event.type);
      break;
    }
  }
}
}