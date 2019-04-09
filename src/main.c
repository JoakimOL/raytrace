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
    vector3f eye = (vector3f){0.0f,0.0f,0.0f};
    sphere* spheres = NULL;

    read_scene(filename, &numspheres, &spheres, &eye);
    if(verbose)
        puts("finished loading scene");

    unsigned char img[3*WIDTH*HEIGHT];

    render(&eye, &spheres, img, numspheres);

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
