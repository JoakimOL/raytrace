#include <stdio.h>
#include <stdbool.h>

#include "sphere.h"
#include "utils.h"
#include "raytrace.h"


void print_usage(){
    // TODO 2
    // add parameters to help text
    puts("usage: ./ray-tracer <input-file>\n");
}

int main(int argc, char *argv[]){
    // TODO 3
    // add parameters to program
    printf("%d\n",argc);
    printf("%s\n",argv[0]);
    if(argc != 2){
        print_usage();
        return INVALID_INPUT;
    }

    size_t numspheres;
    vector3f eye = (vector3f){0.0f,0.0f,0.0f};
    sphere* spheres = NULL;

    read_scene(argv[1], &numspheres, &spheres, &eye);
    puts("finished loading scene");

    unsigned char img[3*WIDTH*HEIGHT];

    /* To ray trace */
    render(&eye, &spheres, img, numspheres);

    free(spheres);

    saveppm("output.ppm", img, WIDTH, HEIGHT);

    return OK;
}
