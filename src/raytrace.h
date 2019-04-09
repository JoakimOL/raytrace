#ifndef RAYTRACE_H_
#define RAYTRACE_H_

#include "ray.h"
#include "sphere.h"
#include "utils.h"
#include "args.h"

vector3f trace(
        ray* ray,
        sphere** spheres,
        int recursiondepth,
        size_t numspheres);

void render(vector3f* eye, sphere** spheres, unsigned char img[WIDTH*HEIGHT*3], size_t numspheres);
#endif
