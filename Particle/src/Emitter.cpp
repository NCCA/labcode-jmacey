#include "Emitter.h"
#include <iostream>
#include "Random.h"
Emitter::Emitter(Vec3 _pos, size_t _numPart)
{
  m_pos=_pos;
  m_particles.resize(_numPart);
  for(auto &p : m_particles)
  {
    resetParticle(p);
  }
}

void Emitter::resetParticle(Particle &io_p)
{
  io_p.pos=m_pos;
  io_p.dir=Random::randomVectorOnSphere();
  io_p.dir.m_y=std::abs(io_p.dir.m_y);
  io_p.color = Random::randomPositiveVec3();
  io_p.life = 0;
  io_p.maxLife= static_cast<int>(Random::randomPositiveFloat(10));
}



void Emitter::update()
{
  std::cout<<"Update \n";
  for(auto &p : m_particles)
  {
    p.pos += p.dir;

    if(++p.life > p.maxLife)
    {
      std::cout<<"Reset\n";
      resetParticle(p);
    }
  }

}

void Emitter::draw() const
{
  std::cout<<"*********************************\n";
  for(auto p : m_particles)
  {
    std::cout<<p.pos.m_x<<' '<<p.pos.m_y<<' '<<p.pos.m_z<<'\n';
  }

}








