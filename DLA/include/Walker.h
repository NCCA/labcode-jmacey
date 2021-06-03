#ifndef WALKER_H_
#define WALKER_H_
#include "Image.h"
#include <memory>
#include <random>
#include <string>
class Walker
{
  public :
    Walker(size_t _w, size_t _h);
    Walker(const Walker &)=delete;
    void initRNG();
    void randomImageSeed();
    void setImageSeed(size_t _x, size_t _y);
    void saveImage(const std::string &_fname);
    void setColour(const RGBA &_c);
    bool walk();
    void resetStart();
  private :
    std::unique_ptr<Image> m_image;
    std::uniform_int_distribution<> m_xRand;
    std::uniform_int_distribution<> m_yRand;
    RGBA m_colour;
    size_t m_xpos;
    size_t m_ypos;

};


#endif 