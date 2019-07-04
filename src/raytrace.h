#ifndef RAYTRACE_H_
#define RAYTRACE_H_

#include "ray.h"
#include "sphere.h"
#include "utils.h"
#include "args.h"

vector3f trace(
        ray* ray,
        sphere** spheres,
        light** lights,
        int recursiondepth,
        size_t numspheres,
        size_t numlights);

void render(
        vector3f* eye,
        sphere** spheres,
        light** lights,
        unsigned char img[WIDTH*HEIGHT*3],
        size_t numspheres,
        size_t numlights);
#endif
