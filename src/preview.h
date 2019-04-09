#ifndef PREVIEW_H_
#define PREVIEW_H_

#include <SDL2/SDL.h>
#include "args.h"

struct SDL_bundle{
    SDL_Renderer *renderer;
    SDL_Window *window;
};

struct SDL_bundle initialize_preview();

void destroy_SDL(struct SDL_bundle* bundle);

void preview_render(struct SDL_bundle *bundle, unsigned char img[3*WIDTH*HEIGHT]);

#endif
