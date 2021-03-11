#include <iostream>
#include <cstdlib>
#include "Walker.h"
int main()
{
  std::cout<<"DLA simulation starting\n";
  Walker w(400,400);
  for(int i=0; i<100; i++)
    w.randomImageSeed();
  w.saveImage("test.tif");
  return EXIT_SUCCESS;
}