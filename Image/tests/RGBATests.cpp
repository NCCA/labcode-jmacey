#include <gtest/gtest.h>
#include "rgba.h"


TEST(RGBA,construct)
{
  RGBA a;
  ASSERT_TRUE(a.r ==0);
  ASSERT_TRUE(a.g ==0);
  ASSERT_TRUE(a.b ==0);
  ASSERT_TRUE(a.a ==0);
}

TEST(RGBA,fromValues)
{
  RGBA red(255,0,0,255);
  ASSERT_TRUE(red.r ==255);
  ASSERT_TRUE(red.g ==0);
  ASSERT_TRUE(red.b ==0);
  ASSERT_TRUE(red.a ==255);

}

TEST(RGBA,set)
{
  RGBA c;
  c.set(0,255,128,99);
  ASSERT_TRUE(c.r ==0);
  ASSERT_TRUE(c.g ==255);
  ASSERT_TRUE(c.b ==128);
  ASSERT_TRUE(c.a ==99);

}




