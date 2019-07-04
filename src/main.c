#include <stdio.h>
#include <stdbool.h>

#include "sphere.h"
#include "utils.h"
#include "raytrace.h"
#include "args.h"
#include "preview.h"

int main(int argc, char *argv[]){
    parse_args(argc,argv);
    size_t numspheres;
    size_t numlights;
    vector3f eye = (vector3f){0.0f,0.0f,0.0f};
    sphere* spheres = NULL;
    light* lights = NULL;

    read_scene(filename,
            &numspheres,
            &numlights,
            &spheres,
            &lights,
            &eye);

    printf("%f\n",lights[0].intensity);
    printf("%f\n",lights[0].color.x);
    printf("%f\n",lights[0].color.y);
    printf("%f\n",lights[0].color.z);

    if(verbose)
        puts("finished loading scene");

    unsigned char img[3*WIDTH*HEIGHT];

    render(&eye, &spheres, &lights, img, numspheres, numlights);

    if(preview) {
        struct SDL_bundle sdl;
        if(!initialize_preview(&sdl)){
            preview_render(&sdl, img);
        }
        destroy_SDL(&sdl);
    }
    else
        saveppm("output.ppm", img, WIDTH, HEIGHT);

    free(spheres);

    return OK;
}
