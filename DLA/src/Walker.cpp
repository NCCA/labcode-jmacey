#include "Walker.h"
#include <iostream>

#include <random>

std::random_device g_rd;
std::seed_seq g_seed{g_rd(), g_rd(), g_rd(), g_rd(), g_rd(), g_rd(), g_rd(), g_rd()};
std::mt19937 g_rng(g_seed);
std::uniform_int_distribution<>g_walkDir(-1,1);


Walker::Walker(size_t _w, size_t _h)
{
  m_image = std::make_unique<Image>(_w,_h,255,255,255,0);
  initRNG();
  resetStart();

}


void Walker::initRNG()
{
  // we will select a point inside the image so we don't check edges
  // this is a bit of an optimisation 
  m_xRand=std::uniform_int_distribution<>(1,m_image->width()-1);
  m_yRand=std::uniform_int_distribution<>(1,m_image->height()-1);
}

void Walker::randomImageSeed()
{
  m_image->setPixel(m_xRand(g_rng), m_yRand(g_rng),255,255,255,255);
}

void Walker::setImageSeed(size_t _x, size_t _y)
{
  m_image->setPixel(_x,_y,255,255,255,255);
}


void Walker::saveImage(const std::string &_fname)
{
  m_image->save(_fname);
}

void Walker::setColour(const RGBA &_c)
{
  m_colour=_c;
}

bool Walker::walk()
{
  bool walking=true;
  bool found=true;

  while(walking)
  {
    // move the walker
    m_xpos += g_walkDir(g_rng);
    m_ypos += g_walkDir(g_rng);
    if(m_xpos ==0 || m_xpos >= m_image->width()-1 ||
       m_ypos ==0 || m_ypos >= m_image->height()-1 )
    {
      walking = false;
      found =false;
      break;
    } // end valid image bounds check
    RGBA p;
    // see if we have a hit
    for(int y=-1; y<=1; ++y)
    {
      for(int x=-1; x<=1; ++x)
      {
        p=m_image->getPixel(m_xpos+x,m_ypos+y);
        if(p.a == 255)
        {
          //std::cout<<"found seed "<<m_xpos<<' '<<m_ypos<<'\n';
          m_image->setPixel(m_xpos,m_ypos,m_colour);
          walking =false;
          found =true;
          break;
        }
      }
    }
  } // end while walking



  return found;
}

void Walker::resetStart()
{
  m_xpos=m_xRand(g_rng);
  m_ypos=m_yRand(g_rng);
 // std::cout<<"New Start "<<m_xpos<<' '<<m_ypos<<'\n';
}