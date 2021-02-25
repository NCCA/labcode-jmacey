# We will always try to use a version > 3.1 if avaliable
cmake_minimum_required(VERSION 3.2)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{CMAKE_TOOLCHAIN_FILE})
   set(CMAKE_TOOLCHAIN_FILE $ENV{CMAKE_TOOLCHAIN_FILE})
endif()

# name of the project It is best to use something different from the exe name
project(Image_build)
# Here we set the C++ standard to use
set(CMAKE_CXX_STANDARD 17)
# add include paths
include_directories(include)
# Now we add our target executable and the file it is built from.
add_executable(Image)
target_sources(Image PRIVATE src/main.cpp src/Image.cpp include/Image.h)

#################################################################################
# Testing code
#################################################################################

find_package(GTest CONFIG REQUIRED)
include(GoogleTest)
enable_testing()
add_executable(ImageTests)
target_sources(ImageTests PRIVATE tests/ImageTests.cpp src/Image.cpp include/Image.h)
target_link_libraries(ImageTests PRIVATE GTest::gtest GTest::gtest_main )
gtest_discover_tests(ImageTests)