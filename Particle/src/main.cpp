#include <iostream>
#include <chrono>
#include "Emitter.h"

int main()
{
  std::cout<<"Particle System\n";
  Emitter e(Vec3(0,0,0),100);
  while(true)
  {
    e.update();
    e.draw();
  }
  return EXIT_SUCCESS;
}