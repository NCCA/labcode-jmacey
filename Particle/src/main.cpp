#include <iostream>
#include <chrono>
#include "Emitter.h"

int main()
{
  std::cout<<"Particle System\n";
  Emitter e(Vec3(0,0,0),200,4.5f,{0.0f,12.0f,0.0f});
  for(int i=0; i<500; ++i)
  {
    e.update(0.001f);
    //e.draw();
    e.saveFrame(i);
  }
  return EXIT_SUCCESS;
}