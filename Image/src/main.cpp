#include <iostream>
#include <cstdlib>
#include "Image.h"
#include <random>

constexpr int c_width=1024;
constexpr int c_height=720;

int main()
{

  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution<unsigned short> cv(0,255);
  std::uniform_int_distribution<> width(0,c_width-1);
  std::uniform_int_distribution<> height(0,c_height-1);
  
  Image img(c_width,c_height,255,255,255,255);

  RGBA p{0,0,0,255};
  for(size_t i=0; i<100000; ++i)
  {
    img.setPixel(width(gen),height(gen),
    cv(gen),cv(gen),cv(gen),255
    );
  }
   img.save("randomDots.png");
/*  for(size_t i=0; i<c_width; ++i )
  {
    p.r=cv(gen);
    p.g=cv(gen);
    p.b=cv(gen);
    for(size_t y=(c_height/2)-5; y<(c_height/2)+5; ++y)
    {
      img.setPixel(i,y,p);
    }
  }
  img.save("random.png");
*/
  return EXIT_SUCCESS;
}