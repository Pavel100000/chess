#include <SDL_main.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include <stdio.h>
#include <stdbool.h>

#define WINDOW_WIDTH 450
#define WINDOW_HEIGHT 450
#define TILE_SIZE 50
#define BOARD_SIZE 8

// b square rgb(181,136,99)
// w square rgb(240,217,181)

void DrawChessboard(SDL_Renderer* renderer) {
    SDL_Rect rect;
    rect.w = TILE_SIZE;
    rect.h = TILE_SIZE;

    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            rect.x = col * TILE_SIZE;
            rect.y = row * TILE_SIZE;

            if ((row + col) % 2 == 0) {
                SDL_SetRenderDrawColor(renderer, 240, 217, 181, 255);  // Белый цвет
            }
            else {
                SDL_SetRenderDrawColor(renderer, 181, 136, 99, 255);  // Черный цвет
            }

            SDL_RenderFillRect(renderer, &rect);
        }
    }
}

int WinMain(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window* window = SDL_CreateWindow("Шахматная доска",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_SHOWN);

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    bool quit = false;
    SDL_Event event;

    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            if (event.button.button == SDL_BUTTON_LEFT) {
                int x = event.button.x;
                int y = event.button.y;
                printf("%d %d", x, y);
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        DrawChessboard(renderer);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
