#ifndef DEPENDENCY_INTERFACES_HPP
#define DEPENDENCY_INTERFACES_HPP

#include "Header.hpp"

namespace Tolik
{
class Debug;
class Event;

struct BaseDeps
{
  Debug *debug;
  std::queue<Event*> *events;
};
}

#endif