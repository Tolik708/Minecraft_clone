#ifndef VEC3
#define VEC3

#include "Header.hpp"

namespace Tolik
{
struct vec3
{
  float e[3];

  inline float& x() { return e[0]; }
  inline float& y() { return e[1]; }
  inline float& z() { return e[2]; }
  inline float x() const { return e[0]; }
  inline float y() const { return e[1]; }
  inline float z() const { return e[2]; }

  vec3(float x, float y, float z);
  vec3(float xyz);
  vec3();

  inline float SqrMagnitude() const { return (e[0] * e[0]) + (e[1] * e[1]) + (e[2] * e[2]); }
  inline float Magnitude() const { return sqrt(SqrMagnitude()); }
  inline void Round() { e[0] = round(e[0]); e[1] = round(e[1]); e[2] = round(e[2]); }
  void ClampMagnitude(float minMagnitude, float maxMagnitude);
  vec3 Normalized() const;
  void Normalize();

  inline float& operator[](int i) { return e[i]; }
  inline float operator[](int i) const { return e[i]; }
  inline vec3 operator+(const vec3 &vector) const { return vec3(e[0] + vector[0], e[1] + vector[1], e[2] + vector[2]); }
  inline vec3 operator-(const vec3 &vector) const { return vec3(e[0] - vector[0], e[1] - vector[1], e[2] - vector[2]); }
  inline vec3 operator*(const vec3 &vector) const { return vec3(e[0] * vector[0], e[1] * vector[1], e[2] * vector[2]); }
  inline vec3 operator/(const vec3 &vector) const { return vec3(e[0] / vector[0], e[1] / vector[1], e[2] / vector[2]); }
  inline vec3 operator+(float num) const { return vec3(e[0] + num, e[1] + num, e[2] + num); }
  inline vec3 operator-(float num) const { return vec3(e[0] - num, e[1] - num, e[2] - num); }
  inline vec3 operator*(float num) const { return vec3(e[0] * num, e[1] * num, e[2] * num); }
  inline vec3 operator/(float num) const { return vec3(e[0] / num, e[1] / num, e[2] / num); }
  inline vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); }
  inline friend std::ostream& operator<<(std::ostream& os, vec3 const& self) { return os << "vec3 " << self[0] << ' ' << self[1] << ' ' << self[2]; }
  
  inline static vec3 Lerp(const vec3 &a, const vec3 &b, float t) { return a * (1 - t) + (b * t); }
  inline static float Dot(const vec3 &a, const vec3 &b) { return a.x() * b.x() + a.y() * b.y() + a.z() * b.z(); }
  inline static vec3 Min(const vec3 &a, const vec3 &b) { return vec3(std::min(a[0], b[0]), std::min(a[1], b[1]), std::min(a[2], b[2])); } //smallest from 2 vectors
  inline static vec3 Max(const vec3 &a, const vec3 &b) { return vec3(std::max(a[0], b[0]), std::max(a[1], b[1]), std::max(a[2], b[2])); } //biggest from 2 vectors
  inline static vec3 Round(const vec3 &vector) { return vec3(round(vector[0]), round(vector[1]), round(vector[2])); }
  static vec3 ClampMagnitude(const vec3 &vector, float maxMagnitude, float minMagnitude);

  static const vec3 right;
  static const vec3 up;
  static const vec3 left;
  static const vec3 down;
  static const vec3 forward;
  static const vec3 backward;
  static const vec3 one;
  static const vec3 zero;
  static const vec3 min;
  static const vec3 max;
};

inline vec3 operator+(float num, const vec3 &vector) { return vector + num; }
inline vec3 operator-(float num, const vec3 &vector) { return vector - num; }
inline vec3 operator*(float num, const vec3 &vector) { return vector * num; }
inline vec3 operator/(float num, const vec3 &vector) { return vector / num; }
}

#endif