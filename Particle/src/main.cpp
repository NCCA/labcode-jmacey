#include <iostream>
#include <chrono>
#include "Emitter.h"

int main()
{
  std::cout<<"Particle System\n";
  Emitter e(Vec3(0,0,0),2);
  for(int i=0; i<10; ++i)
  {
    e.update();
    e.draw();
  }
  return EXIT_SUCCESS;
}