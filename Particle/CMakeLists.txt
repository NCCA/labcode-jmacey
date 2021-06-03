# We will always try to use a version > 3.1 if avaliable
cmake_minimum_required(VERSION 3.2)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{CMAKE_TOOLCHAIN_FILE})
   set(CMAKE_TOOLCHAIN_FILE $ENV{CMAKE_TOOLCHAIN_FILE})
endif()
# name of the project It is best to use something different from the exe name
project(Particle_build)
find_package(fmt CONFIG REQUIRED)

# Here we set the C++ standard to use
set(CMAKE_CXX_STANDARD 17)
# add include paths
include_directories(include)
# Now we add our target executable and the file it is built from.
add_executable(Particle)
add_compile_definitions(_USE_MATH_DEFINES)

target_sources(Particle PRIVATE src/main.cpp src/Emitter.cpp src/Vec3.cpp src/Random.cpp 
include/Particle.h include/Emitter.h  )
target_link_libraries(Particle PRIVATE  fmt::fmt-header-only)

#################################################################################
# Testing code
#################################################################################

find_package(GTest CONFIG REQUIRED)
include(GoogleTest)
enable_testing()
add_executable(ParticleTests)
add_compile_definitions(_USE_MATH_DEFINES)

target_sources(ParticleTests PRIVATE tests/ParticleTests.cpp  src/Emitter.cpp src/Vec3.cpp src/Random.cpp  include/Emitter.h include/Particle.h include/Vec3.h)
target_link_libraries(ParticleTests PRIVATE GTest::gtest GTest::gtest_main fmt::fmt-header-only )
gtest_discover_tests(ParticleTests)
