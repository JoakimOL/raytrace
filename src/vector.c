#include "vector.h"

vector3 vector_sub(const vector3 *v1, const vector3 *v2){
    vector3 res = {
        v1->x - v2->x,
        v1->y - v2->y,
        v1->z - v2->z,
    };
    return res;
}

vector3 vector_add(const vector3 *v1, const vector3 *v2){
    vector3 res = {
        v1->x + v2->x,
        v1->y + v2->y,
        v1->z + v2->z,
    };
    return res;
}

float vector_dot( const vector3 *v1, const vector3 *v2){
    return 
        v1->x * v2->x +
        v1->y * v2->y +
        v1->z * v2->z;
}

vector3 vector_scale(float c, vector3 *v){
    vector3 res = {
        v->x * c,
        v->y * c,
        v->z * c,
    };
    return res;
}
