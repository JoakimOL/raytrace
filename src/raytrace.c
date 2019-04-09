#include "raytrace.h"

vector3f trace(
        ray* ray,
        sphere** spheres,
        int recursiondepth,
        size_t numspheres)
{
    float tnear = INFINITY;
    (void)tnear;
    const sphere* sphere = NULL;
    (void)sphere;
    for(size_t i = 0; i < numspheres; i++){
        float t0 = INFINITY;
        float t1 = INFINITY;
        if(intersect(ray, (*spheres + i),t0,t1)){
            return color_expand_vec3f(&(*spheres + i)->color_surface);
            /* return (vector3u){255,0,0}; */
        }
    }
    return (vector3f){0,0,0};
}

void render(vector3f* eye, sphere** spheres, unsigned char img[WIDTH*HEIGHT*3], size_t numspheres){

    const float fov            = 90;
    const float aspect_ratio   = WIDTH / HEIGHT;
    const float angle = tanf((float)M_PI * 0.5f * fov / 180.0f);

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

            vector3f color = trace(&r, spheres, 0, numspheres);
            img[(x + y * WIDTH) * 3 + 0] = (unsigned char)color.x;
            img[(x + y * WIDTH) * 3 + 1] = (unsigned char)color.y;
            img[(x + y * WIDTH) * 3 + 2] = (unsigned char)color.z;
        }
    }

}

