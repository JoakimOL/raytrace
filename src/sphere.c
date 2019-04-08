#include "sphere.h"


bool intersect(const ray *ray, const sphere *sphere, float t0, float t1){
    vector3f l = (vector3f){
        sphere->pos.x - ray->origin.x,
        sphere->pos.y - ray->origin.y,
        sphere->pos.z - ray->origin.z
    };
    float tca = vector_dot(&l, &ray->dir);
    if (tca < 0) return false;
    float d2 = vector_dot(&l,&l) - tca * tca;
    if (d2 > (sphere->radius*sphere->radius)) return false;
    float thc = sqrtf(sphere->radius*sphere->radius - d2);
    t0 = tca - thc;
    t1 = tca + thc;
    
    return true;
}

