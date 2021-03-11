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
  bool found=false;

  return found;
}

void Walker::resetStart()
{
  m_xpos=m_xRand(g_rng);
  m_ypos=m_xRand(g_rng);
  std::cout<<"New Start "<<m_xpos<<' '<<m_ypos<<'\n';
}