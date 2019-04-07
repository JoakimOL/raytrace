#ifndef VECTOR_H_
#define VECTOR_H_

#include <stddef.h>

typedef struct{
    float x;
    float y;
    float z;
} vector3;

vector3 vector_sub(const vector3 *v1, const vector3 *v2);

vector3 vector_add(const vector3 *v1, const vector3 *v2);

float vector_dot(const vector3 *v1, const vector3 *v2);

vector3 vector_scale(float c, vector3 *v);

#endif
