#ifndef VEC2
#define VEC2

#include "Header.hpp"

namespace Tolik
{
struct vec2
{
  vec2(float x, float y);
  vec2(float xy);
  vec2();

  float e[2];
  inline float x() const { return e[0]; }
  inline float y() const { return e[1]; }
  inline float& x() { return e[0]; }
  inline float& y() { return e[1]; }

  inline float SqrMagnitude() const { return (e[0] * e[0]) + (e[1] * e[1]); }
  inline float Magnitude() const { return sqrt(SqrMagnitude()); }
  void ClampMagnitude(float minMagnitude, float maxMagnitude);
  inline void Round() { e[0] = round(e[0]); e[1] = round(e[1]); }
  vec2 Normalized() const;
  void Normalize();

  inline float& operator[](int i) { return e[i]; }
  inline float operator[](int i) const { return e[i]; }
  inline vec2 operator+(const vec2 &vector) const { return vec2(e[0] + vector[0], e[1] + vector[1]); }
  inline vec2 operator-(const vec2 &vector) const { return vec2(e[0] - vector[0], e[1] - vector[1]); }
  inline vec2 operator*(const vec2 &vector) const { return vec2(e[0] * vector[0], e[1] * vector[1]); }
  inline vec2 operator/(const vec2 &vector) const { return vec2(e[0] / vector[0], e[1] / vector[1]); }
  inline vec2 operator+(float num) const { return vec2(e[0] + num, e[1] + num); }
  inline vec2 operator-(float num) const { return vec2(e[0] - num, e[1] - num); }
  inline vec2 operator*(float num) const { return vec2(e[0] * num, e[1] * num); }
  inline vec2 operator/(float num) const { return vec2(e[0] / num, e[1] / num); }
  inline vec2 operator-() const { return vec2(-e[0], -e[1]); }
  inline friend std::ostream& operator<<(std::ostream& os, vec2 const& self) { return os << "vec3 " << self[0] << ' ' << self[1]; }
  
  inline static vec2 Lerp(const vec2 &a, const vec2 &b, float t) { return a * (1 - t) + (b * t); }
  inline static float Dot(const vec2 &a, const vec2 &b) { return a[0] * b[0] + a[1] * b[1]; }
  inline static vec2 Min(const vec2 &a, const vec2 &b) { return vec2(std::min(a[0], b[0]), std::min(a[1], b[1])); } //smallest from 2 vectors
  inline static vec2 Max(const vec2 &a, const vec2 &b) { return vec2(std::max(a[0], b[0]), std::max(a[1], b[1])); } //biggest from 2 vectors
  inline static vec2 Round(const vec2 &vector) { return vec2(round(vector[0]), round(vector[1])); }
  static vec2 ClampMagnitude(const vec2 &vector, float maxMagnitude, float minMagnitude);

  static const vec2 right;
  static const vec2 up;
  static const vec2 left;
  static const vec2 down;
  static const vec2 one;
  static const vec2 zero;
  static const vec2 min;
  static const vec2 max;
};

inline vec2 operator+(float num, const vec2 &vector) { return vector + num; }
inline vec2 operator-(float num, const vec2 &vector) { return vector - num; }
inline vec2 operator*(float num, const vec2 &vector) { return vector * num; }
inline vec2 operator/(float num, const vec2 &vector) { return vector / num; }
}

#endif