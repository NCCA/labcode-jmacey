#ifndef EMITTER_H_
#define EMITTER_H_
#include "Vec3.h"
#include "Particle.h"
#include <vector>
class Emitter
{
  public :
    Emitter(Vec3 _pos, size_t _numPart, float _spread, Vec3 _emitDir);
    void update(float _dt);
    void draw() const;
    void saveFrame(size_t _frameNo) const;
  private :
    void resetParticle(Particle &io_p);
    std::vector<Particle> m_particles;
    Vec3 m_pos;
    Vec3 m_emitDir = Vec3(0.0f,10.0f, 0.0f);
    float m_spread  = 1.5f;

};

#endif