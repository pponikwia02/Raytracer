cmake_minimum_required(VERSION 3.10)


project(Raytracer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include_directories(${CMAKE_SOURCE_DIR}/src)

#
set(SOURCES
    src/main.cpp
    src/camera.cpp
)


add_executable(${PROJECT_NAME} ${SOURCES})

if (WIN32)

elseif(UNIX)

endif()
