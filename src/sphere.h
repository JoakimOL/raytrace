#ifndef SPHERE_H_
#define SPHERE_H_

#include <stdbool.h>
#include "vector.h"
#include "ray.h"

typedef struct {
    vector3f pos;
    vector3f color_surface;
    vector3f color_emit;
    float radius;
    float transparent;
    float reflection;
} sphere;

bool intersect(const ray *ray, const sphere *sphere, float *t0, float *t1);

vector3f normal_of_point(const sphere* sphere, const vector3f *point);

#endif
