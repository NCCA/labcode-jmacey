#include "Vec3.h"

void Vec3::operator +=(const Vec3 &_r)
{
  m_x+=_r.m_x;
  m_y+=_r.m_y;
  m_z+=_r.m_z;
}