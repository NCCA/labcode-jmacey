#include <gtest/gtest.h>
#include "Image.h"
TEST(IMAGE,ctor)
{
  Image img;
  ASSERT_TRUE(img.width() == 0);
  ASSERT_TRUE(img.height() == 0);
}

TEST(IMAGE,userctor)
{
  Image img(640,480);
  EXPECT_EQ(img.width(),640);
  EXPECT_EQ(img.height(),480);
}

TEST(IMAGE,getPixelDefault)
{
  Image img(640,480);
  RGBA p;
  for(size_t h=0; h<img.height(); ++h)
  {
    for(size_t w=0; w<img.width(); ++w)
    {
      p=img.getPixel(w,h);
      ASSERT_EQ(p.r,0);
      ASSERT_EQ(p.g,0);
      ASSERT_EQ(p.b,0);
      ASSERT_EQ(p.a,0);
      ASSERT_EQ(p.pixels,0);
    }
  }
}

TEST(IMAGE,getPixelDefaultColour)
{
  Image img(640,480,255,0,128,200);
  RGBA p;
  for(size_t h=0; h<img.height(); ++h)
  {
    for(size_t w=0; w<img.width(); ++w)
    {
      p=img.getPixel(w,h);
      ASSERT_EQ(p.r,255);
      ASSERT_EQ(p.g,0);
      ASSERT_EQ(p.b,128);
      ASSERT_EQ(p.a,200);
    }
  }
}



TEST(IMAGE,clear)
{
  Image img(640,480,255,0,128,200);
  RGBA p;
  for(size_t h=0; h<img.height(); ++h)
  {
    for(size_t w=0; w<img.width(); ++w)
    {
      p=img.getPixel(w,h);
      ASSERT_EQ(p.r,255);
      ASSERT_EQ(p.g,0);
      ASSERT_EQ(p.b,128);
      ASSERT_EQ(p.a,200);
    }
  }

  img.clear(255,0,0,255);
  for(size_t h=0; h<img.height(); ++h)
  {
    for(size_t w=0; w<img.width(); ++w)
    {
      p=img.getPixel(w,h);
      ASSERT_EQ(p.r,255);
      ASSERT_EQ(p.g,0);
      ASSERT_EQ(p.b,0);
      ASSERT_EQ(p.a,255);
    }
  }




}










