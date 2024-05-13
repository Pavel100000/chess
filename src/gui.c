#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "chess.h"
#include "bitboards.h"

void InitImages(SDL_Texture* images[16], SDL_Renderer* renderer) {
    images[1]  = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/wr.png"));
    images[2]  = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/wn.png"));
    images[3]  = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/wb.png"));
    images[4]  = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/wq.png"));
    images[5]  = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/wp.png"));
    images[6]  = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/wk.png"));
    images[7]  = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/wp.png"));
    images[8]  = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/wp.png"));
    images[9]  = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/bp.png"));
    images[10] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/bk.png"));
    images[11] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/bp.png"));
    images[12] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/bq.png"));
    images[13] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/bb.png"));
    images[14] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/bn.png"));
    images[15] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/br.png"));
}

void InitASCII(SDL_Texture* images_ascii[256], SDL_Renderer* renderer) {
    TTF_Font *font = TTF_OpenFont("../fonts/arial.ttf", 25);
    SDL_Color color = { 255, 255, 255, 255 };

    char label[2] = "a";
    for (int i = 0; i < 256; i++)
    {
        label[0] = i;
        images_ascii[i] = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Blended(font, label, color));
    }
    TTF_CloseFont(font);
}

void DrawChessboard(SDL_Renderer* renderer, unsigned int desk[8], SDL_Texture* images[16], SDL_Texture* images_ascii[256], int x, int y)
{
    SDL_Rect rect;
    rect.w = TILE_SIZE;
    rect.h = TILE_SIZE;

    unsigned int t;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            rect.x = j * TILE_SIZE;
            rect.y = (9 - i) * TILE_SIZE;
            if (i == 9 || i == 0 || j == 9 || j == 0) {
                rect.y = i * TILE_SIZE;
                rect.w = TILE_SIZE;
                rect.h = TILE_SIZE;

                SDL_SetRenderDrawColor(renderer, 25, 23, 20, 255);  // Белый цвет
                SDL_RenderFillRect(renderer, &rect);
                rect.w = TILE_SIZE/4;
                rect.h = TILE_SIZE/4;
                if (i == 9 & 0 < j && j < 9 )      SDL_RenderCopy(renderer, images_ascii['a' + j - 1], NULL, &rect);
                else if (j == 9 & 0 < i && i < 9 ) SDL_RenderCopy(renderer, images_ascii['8' - i + 1], NULL, &rect);
            }
            else {
              rect.w = TILE_SIZE;
              rect.h = TILE_SIZE;
                if ((i + j) % 2 == 1) SDL_SetRenderDrawColor(renderer, 240, 217, 181, 255);  // Белый цвет
                else                  SDL_SetRenderDrawColor(renderer, 181, 139, 99, 255);
                SDL_RenderFillRect(renderer, &rect);

                t = GetKletka(desk, j, i);
                if (t != 0) SDL_RenderCopy(renderer, images[t], NULL, &rect);
            }
        }
    }
    if (x != 0 && y != 0) {
    rect.x = x * TILE_SIZE; rect.y = (9 - y) * TILE_SIZE; rect.w = TILE_SIZE; rect.h = TILE_SIZE;
    t = GetKletka(desk, x, y);
      if ((x + y) % 2 == 0) SDL_SetRenderDrawColor(renderer, 100, 111, 64, 255);
      else SDL_SetRenderDrawColor(renderer, 130, 151, 105, 255);
      SDL_RenderFillRect(renderer, &rect);
      SDL_RenderCopy(renderer, images[t], NULL, &rect);
    }
}
