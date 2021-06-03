#include <gtest/gtest.h>
#include "Particle.h"
#include "Emitter.h"
#include "Vec3.h"
TEST(Emitter,ctor)
{
  Emitter e(Vec3(2.0f,2.0f,2.0f),10,1.5,{0,10,0});
  
}



TEST(Particle,ctor)
{
  Particle p;
  EXPECT_FLOAT_EQ(p.pos.m_x,0.0f);
  EXPECT_FLOAT_EQ(p.pos.m_y,0.0f);
  EXPECT_FLOAT_EQ(p.pos.m_z,0.0f);
  EXPECT_FLOAT_EQ(p.dir.m_x,0.0f);
  EXPECT_FLOAT_EQ(p.dir.m_y,0.0f);
  EXPECT_FLOAT_EQ(p.dir.m_z,0.0f);
  EXPECT_FLOAT_EQ(p.colour.m_x,0.0f);
  EXPECT_FLOAT_EQ(p.colour.m_y,0.0f);
  EXPECT_FLOAT_EQ(p.colour.m_z,0.0f);
  EXPECT_EQ(p.life,100);
  EXPECT_FLOAT_EQ(p.size,1.0f);
}