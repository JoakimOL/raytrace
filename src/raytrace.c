#include "raytrace.h"

vector3f trace(
        ray* ray,
        sphere** spheres,
        light** lights,
        int recursiondepth,
        size_t numspheres,
        size_t numlights)
{
    float tnear = INFINITY;
    float albedo = 0.18f;
    (void)albedo;
    (void)numlights; // Only supports one light so far
    /* (void)lights; */
    const sphere* sphere = NULL;
    for(size_t i = 0; i < numspheres; i++){
        float t0 = INFINITY;
        float t1 = INFINITY;
        if(intersect(ray, (*spheres + i),&t0,&t1)){

            if(t0 < t1) t0 = t1;
            if(t0 < tnear) {
                tnear = t0;
                sphere = (*spheres + i);
            }
            vector3f hitPoint = {
                sphere->pos.x + ray->dir.x,
                sphere->pos.y + ray->dir.y,
                sphere->pos.z + ray->dir.z,
            };
            hitPoint = vector_scale(t0,&hitPoint);
        }
    }

    if(sphere == NULL) return (vector3f){0,60,128};

    vector3f hit = (vector3f){
        (ray->origin.x + ray->dir.x) * tnear,
        (ray->origin.y + ray->dir.y) * tnear,
        (ray->origin.z + ray->dir.z) * tnear,
    };

    vector3f hit_normal = normal_of_point(sphere, &hit);

    vector3f backwards_light = lights[0]->dir;

    backwards_light.x *= -1;
    backwards_light.y *= -1;
    backwards_light.z *= -1;

    vector3f hitColor = {
        albedo / (float)M_PI *
             lights[0]->intensity *
             lights[0]->color.x *
             max(0.f, vector_dot(&hit_normal,&backwards_light)),
        albedo / (float)M_PI *
             lights[0]->intensity *
             lights[0]->color.y *
             max(0.f, vector_dot(&hit_normal,&backwards_light)),
        albedo / (float)M_PI *
             lights[0]->intensity *
             lights[0]->color.z *
             max(0.f, vector_dot(&hit_normal,&backwards_light)),
    };

    /* printf("r: %f, g: %f, b: %f\n",hitColor.x, hitColor.y, hitColor.z); */

    return color_expand_vec3f(&hitColor);
}

void render(
        vector3f* eye,
        sphere** spheres,
        light** lights,
        unsigned char img[WIDTH*HEIGHT*3],
        size_t numspheres,
        size_t numlights)
{
    const float fov          = 90;
    const float aspect_ratio = WIDTH / HEIGHT;
    const float angle        = tanf((float)M_PI * 0.5f * fov / 180.0f);

    for (size_t y = 0; y < HEIGHT; y++) {
        for (size_t x = 0; x < WIDTH; x++) {
            // Transform to screen space
            // see
            // https://www.scratchapixel.com/lessons/3d-basic-rendering/ray-tracing-generating-camera-rays/generating-camera-rays
            //
            float xx = (2 * (((float)x + 0.5f) / WIDTH) - 1) * angle * aspect_ratio;
            float yy = (1 - 2 * (((float)y + 0.5f) / HEIGHT)) * angle;

            ray r;
            r.origin.x = eye->x;
            r.origin.y = eye->y;
            r.origin.z = eye->z;

            r.dir.x = xx;
            r.dir.y = yy;
            r.dir.z = -1;
            normalize_inplace(&r.dir);

            vector3f color = trace(&r, spheres, lights, 0, numspheres, numlights);
            img[(x + y * WIDTH) * 3 + 0] = (unsigned char)color.x;
            img[(x + y * WIDTH) * 3 + 1] = (unsigned char)color.y;
            img[(x + y * WIDTH) * 3 + 2] = (unsigned char)color.z;
        }
    }

}

