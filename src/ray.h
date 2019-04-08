#ifndef RAY_H_
#define RAY_H_

#include <stdio.h>
#include "vector.h"

typedef struct{
    vector3f origin;
    vector3f dir;
} ray;

#endif
