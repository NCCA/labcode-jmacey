#ifndef VEC3_H_
#define VEC3_H_

class Vec3
{
  public :
    Vec3()=default;
    Vec3(float _x, float _y, float _z) : 
    m_x{_x},m_y{_y},m_z{_z}{}
    void operator +=(const Vec3 &_r); 


    float m_x=0.0f;
    float m_y=0.0f;
    float m_z=0.0f;
};

#endif