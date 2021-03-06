#include "sphere.h"


bool intersect(const ray *ray, const sphere *sphere, float* t0, float* t1){
    vector3f l = (vector3f){
        sphere->pos.x - ray->origin.x,
        sphere->pos.y - ray->origin.y,
        sphere->pos.z - ray->origin.z
    };
    //  signed distance between ray origin and a center point of sphere perpendicular to the ray distance
    float tca = vector_dot(&l, &ray->dir);
    if (tca < 0) return false; // This is behind us, so no need to render.
    float d2 = vector_dot(&l,&l) - tca * tca; // pythagoras
    if (d2 > (sphere->radius*sphere->radius)) return false;
    float thc = sqrtf(sphere->radius*sphere->radius - d2);
    *t0 = tca - thc;
    *t1 = tca + thc;

    return true;
}


vector3f normal_of_point(const sphere* sphere, const vector3f *point){
    vector3f v = (vector3f){
                point->x - sphere->pos.x,
                point->y - sphere->pos.y,
                point->z - sphere->pos.z,
    };
    return normalize(&v);
}
