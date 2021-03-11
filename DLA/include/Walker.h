#ifndef WALKER_H_
#define WALKER_H_
#include "Image.h"
#include <memory>
class Walker
{
  public :
    Walker(size_t _w, size_t _h);
    Walker(const Walker &)=delete;
  private :
    std::unique_ptr<Image> m_image;

};


#endif 