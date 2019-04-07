#ifndef LIGHT_H_
#define LIGHT_H_
#include "vector.h"
#include "color.h"

typedef struct {
    vector3 pos;
    color intensity;
} light;
#endif
