#ifndef IMAGE_H_
#define IMAGE_H_
#include "rgba.h"
#include <memory>
class Image
{
  public :
    Image()=default;
    Image(size_t _w, size_t _h);
    Image(size_t _w, size_t _h,unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a);
    
    size_t width() const;
    size_t height() const;
    RGBA getPixel(size_t _x, size_t _y) const ;
    void setPixel(size_t _x, size_t _y, unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a);
    void setPixel(size_t _x, size_t _y, RGBA _p);

  void clear(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a);

  private :
    size_t m_width=0;
    size_t m_height=0;
    std::unique_ptr<RGBA []> m_pixels;
};


#endif