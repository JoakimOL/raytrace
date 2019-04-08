#include <stdio.h>
#include <stdbool.h>

#include "sphere.h"
#include "ray.h"
#include "utils.h"

#define WIDTH  800
#define HEIGHT 600

enum ERRORS{
    OK = 0,
    INVALID_INPUT,
};

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
    vector3 eye = (vector3){0.0f,0.0f,0.0f};
    sphere* spheres = NULL;

    read_scene(argv[1], &numspheres, &spheres, &eye);
    puts("finished loading scene");

    printf(
            "============\n"
            "= Eye:\n"
            "= x: %.2f\n"
            "= y: %.2f\n"
            "= z: %.2f\n"
            "============\n\n",
            eye.x,
            eye.y,
            eye.z
        );

    for(int i = 0; i < 3 ; i++){
        printf("==============\n"
               "= positions\n"
               "=-------------\n"
               "= x: %.2f\n"
               "= y: %.2f\n"
               "= z: %.2f\n"
               "=-------------\n"
               "= radius: %.2f\n"
               "= material: %d\n"
               "==============\n\n",
            spheres[i].pos.x,
            spheres[i].pos.y,
            spheres[i].pos.z,
            spheres[i].radius,
            spheres[i].material);
    }
    
	unsigned char img[3*WIDTH*HEIGHT];
    (void)img;

	for(int y=0;y<HEIGHT;y++){
		for(int x=0;x<WIDTH;x++){
            // TODO 1:
            // Add ray tracing
		}
	}

	/* saveppm("output.ppm", img, WIDTH, HEIGHT); */

	return OK;
}
