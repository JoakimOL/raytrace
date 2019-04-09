#include "utils.h"
#include "preview.h"

int initialize_preview(struct SDL_bundle *s){
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    if ( SDL_CreateWindowAndRenderer(
                WIDTH,
                HEIGHT,
                SDL_WINDOW_SHOWN | SDL_RENDERER_PRESENTVSYNC,
                &s->window,
                &s->renderer) != 0) {
        SDL_Log("Unable to create SDL window and renderer: %s", SDL_GetError());
        return SDL_ERROR;
    }

    return 0;
}

void destroy_SDL(struct SDL_bundle* bundle){
    SDL_DestroyRenderer(bundle->renderer);
    SDL_DestroyWindow(bundle->window);
    SDL_Quit();
    if(verbose)
        puts("destroyed SDL");
}

void preview_render(struct SDL_bundle *bundle, unsigned char img[3*WIDTH*HEIGHT]){
    SDL_Event event;

    SDL_SetRenderDrawColor(bundle->renderer, 0, 0, 0, 0);
    SDL_RenderClear(bundle->renderer);

    for (int y = 0; y < HEIGHT; y++){
        for (int x = 0; x < WIDTH; x++){
            unsigned char r = *img++;
            unsigned char g = *img++;
            unsigned char b = *img++;
            SDL_SetRenderDrawColor(bundle->renderer, r, g, b, SDL_ALPHA_OPAQUE);
            SDL_RenderDrawPoint(bundle->renderer, x, y);
        }
    }

    SDL_RenderPresent(bundle->renderer);

    unsigned int startTime    = 0;
    unsigned int endTime      = 0;
    unsigned int delta        = 0;
    unsigned int fps          = 60;
    unsigned int timePerFrame = 16; // ms

    while (1) { 
        if (!startTime) {
            startTime = SDL_GetTicks(); 
        } 
        else {
            delta = endTime - startTime;
        }

        if (delta < timePerFrame) {
            SDL_Delay(timePerFrame - delta);
        }

        if (delta > timePerFrame) {
            fps = 1000 / delta;
        }

        if(SDL_PollEvent(&event) 
                && event.type == SDL_KEYDOWN
                && event.key.keysym.sym == SDLK_ESCAPE)
            break;

        if(verbose)
            printf("\rFPS is: %i ", fps);

        startTime = endTime;
        endTime = SDL_GetTicks();
    }
    if(verbose)
        puts("\n");
}
