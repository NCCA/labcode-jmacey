#include "Image.h"

Image::Image(size_t _w, size_t _h)
{
  m_width = _w;
  m_height = _h;
  m_pixels = std::make_unique<RGBA []>(m_width* m_height); 
}

Image::Image(size_t _w, size_t _h,unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a) : Image(_w, _h)
{
  RGBA p(_r,_g,_b,_a);
  for(size_t i=0; i<m_width*m_height; ++i)
  {
    m_pixels[i]=p;
  }
}    


size_t Image::width() const
{
  return m_width;
}

size_t Image::height() const
{
  return m_height;
}


  void Image::clear(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
  {
    RGBA p{_r,_g,_b,_a};
    for(size_t i=0; i<m_width*m_height; ++i)
    {
      m_pixels[i]=p;
    }
  }



RGBA Image::getPixel(size_t _x, size_t _y) const
{
  return m_pixels[_y*m_width+_x];
}


void Image::setPixel(size_t _x, size_t _y, unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a)
{
  RGBA p{_r,_g,_b,_a};
  m_pixels[_y*m_width+_x]=p;
}

void Image::setPixel(size_t _x, size_t _y, RGBA _p)
{
  m_pixels[_y*m_width+_x]=_p;
}


