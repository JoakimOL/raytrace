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
    printf("usage: ./ray-tracer <input-file>\n");
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
    sphere* spheres = NULL;
    ray* rays       = NULL;
    read_scene(argv[1], spheres, rays);

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
