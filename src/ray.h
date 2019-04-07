#ifndef RAY_H_
#define RAY_H_

#include <stdio.h>
#include "vector.h"

typedef struct{
    vector3 start;
    vector3 dir;
} ray;

#endif
