#include <iostream>
#include <cstdlib>
#include "Walker.h"
#include <fmt/format.h>
int main()
{
  std::cout<<"DLA simulation starting\n";
  Walker w(400,400);
  w.setColour({0,0,0,255});  
  for(int i=0; i<20; i++)
    w.randomImageSeed();
  int imageIndex=0;
  for(int i=0; i<10000; i++)
  {
    if(w.walk() == true)
    {
      w.saveImage(fmt::format("sim{:04d}.tif",imageIndex++));
    }
    w.resetStart();
  }

  return EXIT_SUCCESS;
}