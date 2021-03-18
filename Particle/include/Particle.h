#ifndef PARTICLE_H_
#define PARTICLE_H_
#include "Vec3.h"
struct Particle
{
  Vec3 pos;
  Vec3 dir;
  Vec3 colour;
  int life=100;
  float size=1.0f;
};

#endif