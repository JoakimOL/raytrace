#ifndef MATERIAL_H_
#define MATERIAL_H_ 

#include "color.h"

typedef struct {
    color diffuse;
    float reflection;
} material;

#endif
