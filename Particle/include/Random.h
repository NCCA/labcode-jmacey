#ifndef RANDOM_H_
#define RANDOM_H_
#include "Vec3.h"
#include <random>

class Random
{
  public :
    static Vec3 randomVec3(float _mult=1.0f);
    static Vec3 randomPositiveVec3(float _mult=1.0f);
    
    static float randomFloat(float _mult=1.0f);
    static float randomPositiveFloat(float mult=1.0f);
    static Vec3 randomVectorOnSphere(float _radius=1.0f );

  private :
    static std::mt19937 m_generator;


};

#endif