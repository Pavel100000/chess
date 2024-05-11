#include <SDL_main.h>
#include <SDL.h>
#include <SDL_ttf.h>

#include <stdio.h>
#include <stdbool.h>

#define WINDOW_WIDTH 900
#define WINDOW_HEIGHT 900
#define TILE_SIZE 100
#define BOARD_SIZE 8

void DrawChessboard(SDL_Renderer* renderer) {
    SDL_Rect rect;
    rect.w = TILE_SIZE;
    rect.h = TILE_SIZE;

    for (int row = 0; row < BOARD_SIZE + 1; row++) {
        for (int col = 0; col < BOARD_SIZE + 1; col++) {
            rect.x = col * TILE_SIZE;
            rect.y = row * TILE_SIZE;

            if ((row == 0 || col == 0) || ((row + col) % 2 == 0)) {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Белый цвет
            }
            else {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Черный цвет
            }

            SDL_RenderFillRect(renderer, &rect);

            if (row == 0 && col > 0) {
                char label = 'a' + col - 1;
                SDL_Color text_color = { 0, 0, 0, 255 };
                SDL_Surface* surface = TTF_RenderText_Solid(NULL, &label, text_color);
                SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
                SDL_Rect dstrect = { col * TILE_SIZE, 0, TILE_SIZE, TILE_SIZE };
                SDL_RenderCopy(renderer, texture, NULL, &dstrect);
                SDL_DestroyTexture(texture);
                SDL_FreeSurface(surface);
            }
            else if (col == 0 && row > 0) {
                char label[2] = { (char)(BOARD_SIZE - row + '0' + 1), '\0' };
                SDL_Color text_color = { 0, 0, 0, 255 };
                SDL_Surface* surface = TTF_RenderText_Solid(NULL, label, text_color);
                SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
                SDL_Rect dstrect = { 0, row * TILE_SIZE, TILE_SIZE, TILE_SIZE };
                SDL_RenderCopy(renderer, texture, NULL, &dstrect);
                SDL_DestroyTexture(texture);
                SDL_FreeSurface(surface);
            }
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
