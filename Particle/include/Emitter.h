#ifndef EMITTER_H_
#define EMITTER_H_
#include "Vec3.h"
#include "Particle.h"
#include <vector>
class Emitter
{
  public :
    Emitter(Vec3 _pos, size_t _numPart);
    void update();
    void draw() const;
    void saveFrame(size_t _frameNo) const;
  private :
    void resetParticle(Particle &io_p);
    std::vector<Particle> m_particles;
    Vec3 m_pos;

};

#endif