#ifndef SPHERE_H_
#define SPHERE_H_

#include "vector.h"

typedef struct {
    vector3 pos;
    float radius;
    int material;
} sphere;

#endif
