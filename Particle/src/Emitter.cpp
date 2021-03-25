#include "Emitter.h"
#include <iostream>
#include "Random.h"
#include <fstream>
#include <fmt/format.h>
#include <sstream>

Emitter::Emitter(Vec3 _pos, size_t _numPart,float _spread, Vec3 _emitDir)
{
  m_pos=_pos;
  m_spread=_spread;
  m_emitDir=_emitDir;
  m_particles.resize(_numPart);
  for(auto &p : m_particles)
  {
    resetParticle(p);
  }
}

void Emitter::resetParticle(Particle &io_p)
{
  if(Random::randomPositiveFloat(500) > 450)
  {
    io_p.pos=m_pos;
    io_p.dir=m_emitDir * Random::randomPositiveFloat() + Random::randomVectorOnSphere() * m_spread;
    io_p.dir.m_y=std::abs(io_p.dir.m_y);
    io_p.colour = Random::randomPositiveVec3();
    io_p.life = 0;
    io_p.maxLife= static_cast<int>(Random::randomPositiveFloat(1000)+50);
    io_p.size = 0.01f;
  }

  else
  {
    io_p.pos=m_pos;
    io_p.dir=Vec3(0,0,0);
    io_p.colour = Vec3(0,0,0);
    io_p.life = 0;
    io_p.maxLife= static_cast<int>(Random::randomPositiveFloat(100)+50);
    io_p.size = 0.01f;
  }

}

void Emitter::update(float _dt)
{
  const Vec3 gravity(0.0f,-9.81f,0.0f);
 // std::cout<<"Update \n";
  for(auto &p : m_particles)
  {
    p.dir +=gravity * _dt * 0.5;
    p.pos +=p.dir * _dt;
    p.size += Random::randomPositiveFloat(0.05f);
    if(++p.life >= p.maxLife || p.pos.m_y<= 0.0f)
    {
    //  std::cout<<"Reset\n";
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



  void Emitter::saveFrame(size_t _frameNo) const
  {
    std::ofstream file;
    std::stringstream ss;
    std::cout<<"saving frame "<<_frameNo<<'\n';
    file.open(fmt::format("particle{:04d}.geo",static_cast<int>(_frameNo)));
    if(!file.is_open())
    {
      std::cerr<<"Trouble opening file \n";
      exit(EXIT_FAILURE);
    }

    ss<< "PGEOMETRY V5\n";
    ss<< "NPoints "<< m_particles.size() << " NPrims 1 \n";
    ss <<"NPointGroups 0 NPrimGroups 0 \n";
    ss <<"NPointAttrib 2 NVertexAttrib 0 NPrimAttrib 1 NAttrib 0\n";

    ss <<"PointAttrib \n";
    ss <<"Cd 3 float 1 1 1\n";
    ss <<"pscale 1 float 1 \n";
    for (auto p : m_particles)
    {
      ss<< p.pos.m_x<<' '<<p.pos.m_y<<' '<<p.pos.m_z<<" 1 ";
      ss<<'('<<p.colour.m_x<<' '<<p.colour.m_y<<' '<<p.colour.m_z<<' '<<p.size<<")\n";
    }

    ss<<"PrimitiveAttrib \n";
    ss<<"generator 1 index 1 pa \n";
    ss<<"Part "<<m_particles.size()<<' ';
    for(size_t i=0; i<m_particles.size(); ++i)
    {
      ss<<i<<' ';
    }
    ss<<"[0]\n";
    ss<<"beginExtra\n";
    ss<<"endExtra\n";
    file<<ss.rdbuf();
    file.close();
  }









