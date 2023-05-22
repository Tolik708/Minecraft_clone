#include "Vec3.hpp"

namespace Tolik
{
vec3::vec3(float x, float y, float z)
{
  e[0] = x;
  e[1] = y;
  e[2] = z;
}
vec3::vec3(float xyz)
{
  e[0] = xyz;
  e[1] = xyz;
  e[2] = xyz;
}
vec3::vec3()
{
  e[0] = 0;
  e[1] = 0;
  e[2] = 0;
}

vec3 vec3::Normalized() const 
{
  float inverseMagnitude = 1 / Magnitude();
  return vec3(e[0] * inverseMagnitude, e[1] * inverseMagnitude, e[2] * inverseMagnitude);
}
void vec3::Normalize()
{
  float inverseMagnitude = 1 / Magnitude();
  e[0] *= inverseMagnitude;
  e[1] *= inverseMagnitude;
  e[2] *= inverseMagnitude;
}
void vec3::ClampMagnitude(float maxMagnitude, float minMagnitude)
{
  float sqrMagnitude = SqrMagnitude();
  if (sqrMagnitude > maxMagnitude * maxMagnitude)
  {
    Normalize();
    e[0] *= maxMagnitude;
    e[1] *= maxMagnitude;
    e[2] *= maxMagnitude;
  }
  else if (sqrMagnitude < minMagnitude * minMagnitude)
  {
    Normalize();
    e[0] *= minMagnitude;
    e[1] *= minMagnitude;
    e[2] *= minMagnitude;
  }
}

vec3 vec3::ClampMagnitude(const vec3 &vector, float maxMagnitude, float minMagnitude)
{
  float sqrMagnitude = vector.SqrMagnitude();
  if (sqrMagnitude > maxMagnitude * maxMagnitude)
    return vector.Normalized() * maxMagnitude;
  else if (sqrMagnitude < minMagnitude * minMagnitude)
    return vector.Normalized() * minMagnitude;
  return vector;
}

const vec3 vec3::right = vec3(1, 0, 0);
const vec3 vec3::left = vec3(-1, 0, 0);
const vec3 vec3::up = vec3(0, 1, 0);
const vec3 vec3::down = vec3(0, -1, 0);
const vec3 vec3::forward = vec3(0, 0, 1);
const vec3 vec3::backward = vec3(0, 0, -1);
const vec3 vec3::one = vec3(1, 1, 1);
const vec3 vec3::zero = vec3();
}