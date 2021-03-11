# We will always try to use a version > 3.1 if avaliable
cmake_minimum_required(VERSION 3.2)

if(NOT DEFINED CMAKE_TOOLCHAIN_FILE AND DEFINED ENV{CMAKE_TOOLCHAIN_FILE})
   set(CMAKE_TOOLCHAIN_FILE $ENV{CMAKE_TOOLCHAIN_FILE})
endif()
# name of the project It is best to use something different from the exe name
project(DLA_build)
find_package(OpenImageIO CONFIG REQUIRED)
find_package(IlmBase CONFIG REQUIRED)
find_package(OpenEXR CONFIG REQUIRED)
find_package(fmt CONFIG REQUIRED)


# Here we set the C++ standard to use
set(CMAKE_CXX_STANDARD 17)
# add include paths
include_directories(include)
# Now we add our target executable and the file it is built from.
add_executable(DLA)
target_sources(DLA PRIVATE src/main.cpp 
                           src/Image.cpp 
                           src/Walker.cpp
                           include/Image.h 
                           include/Walker.h
                           )
target_link_libraries(DLA PRIVATE OpenImageIO::OpenImageIO OpenImageIO::OpenImageIO_Util)
target_link_libraries(DLA PRIVATE  IlmBase::Iex IlmBase::Half IlmBase::Imath IlmBase::IexMath)
target_link_libraries(DLA PRIVATE OpenEXR::IlmImf OpenEXR::IlmImfUtil OpenEXR::IlmImfConfig)
target_link_libraries(DLA PRIVATE  fmt::fmt-header-only)