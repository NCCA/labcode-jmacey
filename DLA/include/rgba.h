#ifndef RGBA_H_
#define RGBA_H_
#include <cstdint>
//     8bit  8bits     8bits   8bits
// |  red  |  green  | blue  |  A  |

struct RGBA
{
  RGBA()=default;
  RGBA(unsigned char _r, unsigned char _g, unsigned char _b, unsigned char _a) 
  {
    r=_r;
    g=_g;
    b=_b;
    a=_a;
  }

  void set(unsigned char _r,unsigned char _g, unsigned char _b, unsigned char _a)
  {
    r=_r;
    g=_g;
    b=_b;
    a=_a;
  }

  union 
  {
    uint32_t pixels=0;
    struct
    {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
    };
  };
};

#endif