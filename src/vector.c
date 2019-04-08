#include "vector.h"

vector3f vector_sub(const vector3f *v1, const vector3f *v2){
    vector3f res = {
        v1->x - v2->x,
        v1->y - v2->y,
        v1->z - v2->z,
    };
    return res;
}

vector3f vector_add(const vector3f *v1, const vector3f *v2){
    vector3f res = {
        v1->x + v2->x,
        v1->y + v2->y,
        v1->z + v2->z,
    };
    return res;
}

float vector_dot(const vector3f *v1, const vector3f *v2){
    return 
        v1->x * v2->x +
        v1->y * v2->y +
        v1->z * v2->z;
}

vector3f vector_scale(const float c, const vector3f *v){
    vector3f res = {
        v->x * c,
        v->y * c,
        v->z * c,
    };
    return res;
}

void normalize_inplace(vector3f *v){
    const float normalization = sqrtf(v->x*v->x + v->y*v->y + v->z*v->z);
    v->x /= normalization;
    v->y /= normalization;
    v->z /= normalization;
}


vector3f normalize(vector3f *v){
    const float normalization = sqrtf(v->x*v->x + v->y*v->y + v->z*v->z);
    vector3f ret = {v->x, v->y, v->z};
    ret.x /= normalization;
    ret.y /= normalization;
    ret.z /= normalization;
    return ret;
}

