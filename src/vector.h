#ifndef VECTOR_H_
#define VECTOR_H_

#include <stddef.h>
#include <math.h>

typedef struct{
    unsigned x;
    unsigned y;
    unsigned z;
} vector3u;

typedef struct{
    float x;
    float y;
    float z;
} vector3f;

vector3f vector_sub(const vector3f *v1, const vector3f *v2);

vector3f vector_add(const vector3f *v1, const vector3f *v2);

float vector_dot(const vector3f *v1, const vector3f *v2);

vector3f vector_scale(const float c, const vector3f *v);

void normalize_inplace(vector3f *v);

vector3f normalize(vector3f *v);

#endif
