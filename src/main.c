#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "sphere.h"
#include "utils.h"
#include "raytrace.h"
#include "args.h"

void preview_render(unsigned char img[3*WIDTH*HEIGHT]){
    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    for (int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){

            unsigned char r = *img++;
            unsigned char g = *img++;
            unsigned char b = *img++;
            /* img[(x + y * WIDTH) * 3 + 0] = (unsigned char)color.x; */
            /* img[(x + y * WIDTH) * 3 + 1] = (unsigned char)color.y; */
            /* img[(x + y * WIDTH) * 3 + 2] = (unsigned char)color.z; */

            SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }
    SDL_RenderPresent(renderer);
    while (1) {
        if (SDL_PollEvent(&event) && (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE))
            break;
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char *argv[]){
    parse_args(argc,argv);
    size_t numspheres;
    vector3f eye = (vector3f){0.0f,0.0f,0.0f};
    sphere* spheres = NULL;

    read_scene(filename, &numspheres, &spheres, &eye);
    puts("finished loading scene");

    unsigned char img[3*WIDTH*HEIGHT];

    render(&eye, &spheres, img, numspheres);

    free(spheres);

    if(preview)
        preview_render(img);
    else
        saveppm("output.ppm", img, WIDTH, HEIGHT);

    return OK;
}
