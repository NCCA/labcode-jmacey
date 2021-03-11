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
    void saveImage(const std::string &_fname);
  private :
    std::unique_ptr<Image> m_image;
    std::uniform_int_distribution<> m_xRand;
    std::uniform_int_distribution<> m_yRand;

};


#endif 