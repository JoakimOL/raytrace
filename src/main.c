#include <stdio.h>
#include <stdbool.h>

#include "sphere.h"
#include "utils.h"
#include "raytrace.h"
#include "args.h"



int main(int argc, char *argv[]){
    parse_args(argc,argv);

    if(verbose){
        printf("preview: %d\n",preview);
        printf("filename: %s\n",filename);
    }
    size_t numspheres;
    vector3f eye = (vector3f){0.0f,0.0f,0.0f};
    sphere* spheres = NULL;

    read_scene(filename, &numspheres, &spheres, &eye);
    puts("finished loading scene");

    unsigned char img[3*WIDTH*HEIGHT];

    render(&eye, &spheres, img, numspheres);

    free(spheres);

    saveppm("output.ppm", img, WIDTH, HEIGHT);

    return OK;
}
