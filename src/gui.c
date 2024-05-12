#define SDL_MAIN_HANDLED

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "chess.h"
#include "bitboards.h"

void DrawText(SDL_Renderer* renderer) {
  TTF_Font* Arial = TTF_OpenFont("./../gui/arial.ttf", TILE_SIZE);
  if (!Arial) printf("Error \n");
  // this is the color in rgb format,
// maxing out all would give you the color white,
// and it will be your text's color
  SDL_Color White = {255, 255, 255};

// as TTF_RenderText_Solid could only be used on
// SDL_Surface then you have to create the surface first
  SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Arial, "A", White);

// now you can convert it into a texture
  SDL_Texture* Message = SDL_CreateTextureFromSurface(renderer, surfaceMessage);

  SDL_Rect Message_rect; //create a rect
  Message_rect.x = 0;  //controls the rect's x coordinate
  Message_rect.y = 0; // controls the rect's y coordinte
  Message_rect.w = 100; // controls the width of the rect
  Message_rect.h = 100; // controls the height of the rect

// (0,0) is on the top left of the window/screen,
// think a rect as the text's box,
// that way it would be very simple to understand

// Now since it's a texture, you have to put RenderCopy
// in your game loop area, the area where the whole code executes

// you put the renderer's name first, the Message,
// the crop size (you can ignore this if you don't want
// to dabble with cropping), and the rect which is the size
// and coordinate of your texture
  SDL_RenderCopy(renderer, Message, NULL, &Message_rect);

// Don't forget to free your surface and texture
  SDL_FreeSurface(surfaceMessage);
  SDL_DestroyTexture(Message);
}

void DrawPressKletka(SDL_Renderer* renderer, int column, int line) {
  SDL_Rect rect = {(column - 1)*TILE_SIZE, (8 - line)*TILE_SIZE, TILE_SIZE, TILE_SIZE};
  if ((column + line) % 2 == 0) SDL_SetRenderDrawColor(renderer, 100, 111, 64, 255);
  else SDL_SetRenderDrawColor(renderer, 130, 151, 105, 255);
  SDL_RenderFillRect(renderer, &rect);
}

void InitImages(SDL_Texture* images[16], SDL_Renderer* renderer) {
    images[1] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/wr.png"));
    images[2] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/wn.png"));
    images[3] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/wb.png"));
    images[4] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/wq.png"));
    images[5] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/wp.png"));
    images[6] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/wk.png"));
    images[7] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/wp.png"));
    images[8] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/wp.png"));
    images[9] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/bp.png"));
    images[10] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/bk.png"));
    images[11] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/bp.png"));
    images[12] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/bq.png"));
    images[13] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/bb.png"));
    images[14] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/bn.png"));
    images[15] = SDL_CreateTextureFromSurface(renderer, IMG_Load("../images/br.png"));
    assert(images[1] != NULL);
    assert(images[5] != NULL);
    assert(images[7] != NULL);
    assert(images[13] != NULL);
}

void InitASCII(SDL_Texture* images_ascii[256], SDL_Renderer* renderer) {
    TTF_Font *font = TTF_OpenFont("../fonts/arial.ttf", 100);
    SDL_Color color = { 255, 255, 255, 255 };

    char label[2] = "a";
    for (int i = 0; i < 256; i++)
    {
        label[0] = i;
        images_ascii[i] = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Blended(font, label, color));
    }
    TTF_CloseFont(font);
}

void DrawChessboard(SDL_Renderer* renderer, unsigned int desk[8], SDL_Texture* images[16], SDL_Texture* images_ascii[256])
{
    SDL_Rect rect;
    rect.w = TILE_SIZE;
    rect.h = TILE_SIZE;
    
    unsigned int t;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            rect.x = j * TILE_SIZE;
            rect.y = (9 - i) * TILE_SIZE;
            if (i == 9 || i == 0 || j == 9 || j == 0)
            {
                rect.y = i * TILE_SIZE;

                SDL_SetRenderDrawColor(renderer, 255, 191, 131, 255);  // Белый цвет
                SDL_RenderFillRect(renderer, &rect);

                if (i == 9 & 0 < j && j < 9 )
                {
                    SDL_RenderCopy(renderer, images_ascii['a' + j - 1], NULL, &rect);
                }
                else if (j == 9 & 0 < i && i < 9 )
                {
                    SDL_RenderCopy(renderer, images_ascii['8' - i + 1], NULL, &rect);
                }
            }
            else
            {
                if ((i + j) % 2 == 1) SDL_SetRenderDrawColor(renderer, 255, 191, 131, 255);  // Белый цвет
                else                  SDL_SetRenderDrawColor(renderer, 106, 52, 2, 255);
                SDL_RenderFillRect(renderer, &rect);

                t = GetKletka(desk, j, i);
                if (t != 0) {
                    if ((i + j) % 2 == 0) SDL_RenderCopy(renderer, images[t], NULL, &rect);
                    else                  SDL_RenderCopy(renderer, images[t], NULL, &rect);
                }
            }
        }
    }
}

int Print(SDL_Renderer *renderer, SDL_Texture *images[16], SDL_Texture* images_ascii[256], unsigned int *desk)
{    
    // bool quit = false;
    // while (!quit)
    // {
    //     SDL_Event event;
    //     int x; int y;

    //     SDL_WaitEvent(&event);
    //     switch (event.type)
    //     {
    //         case SDL_QUIT:
    //             quit = true;
    //             break;

    //         case SDL_KEYDOWN:
    //             switch (event.key.keysym.sym)
    //             {
    //                 case SDLK_ESCAPE:
    //                     quit = true;
    //                     break;
                    
    //                 default:
    //                     break;
    //             }

    //         case SDL_MOUSEBUTTONDOWN:
    //             // обработка нажатия мыши
    //             SDL_GetMouseState(&x, &y);
    //             printf("Нажатие (%d; %d)\n", x, y);
    //             break;
            
    //         default:
    //             break;
    //     }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        DrawChessboard(renderer, desk, images, images_ascii);
        SDL_RenderPresent(renderer);
    // }

    return 0;
}
