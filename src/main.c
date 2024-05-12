#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <stdio.h>
#include <stdbool.h>

#include "mydef.h"
#include "chess.h"

int WinMain() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0){PRINT_ERROR("Ошибка инициализации SDL: %s\n", SDL_GetError());}
    if (IMG_Init(IMG_INIT_PNG) == 0) {PRINT_ERROR("Ошибка инициализации IMG: %s\n", SDL_GetError());}
    if (TTF_Init() == -1)            {PRINT_ERROR("Ошибка инициализации TTF: %s\n", SDL_GetError());}

    SDL_Window *window = SDL_CreateWindow(
        "Шахматная доска",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN
    );

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Texture* images[16];
    SDL_Texture* images_ascii[256];
    InitImages(images, renderer);
    InitASCII(images_ascii, renderer);

    StartGrafikGame(renderer, images, images_ascii);

    SDL_RenderClear(renderer);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    return 0;
}
