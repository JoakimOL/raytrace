cmake_minimum_required(VERSION 3.9.2)
project(raytracer)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

IF( EXISTS "${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json" )
  EXECUTE_PROCESS( COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_CURRENT_BINARY_DIR}/compile_commands.json
    ${CMAKE_CURRENT_SOURCE_DIR}/compile_commands.json
  )
ENDIF()


set(RAY_TRACER_SOURCES
  src/main.c
  src/preview.c
  src/preview.h
  src/ray.h
  src/utils.c
  src/utils.h
  src/sphere.c
  src/sphere.h
  src/vector.c
  src/vector.h
  src/raytrace.c
  src/raytrace.h
  src/args.c
  src/args.h
  )

add_executable(raytracer ${RAY_TRACER_SOURCES})

set_target_properties(raytracer PROPERTIES
  CXX_STANDARD 11)

target_compile_options(raytracer PRIVATE
  -Wall
  -Werror
  -Wconversion
  -Wunused-variable
  -pedantic
  )

INCLUDE(FindPkgConfig)
PKG_SEARCH_MODULE(SDL2 REQUIRED sdl2)

# find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

TARGET_LINK_LIBRARIES(raytracer ${SDL2_LIBRARIES})

IF(UNIX)
    TARGET_LINK_LIBRARIES(raytracer m)
ENDIF()

