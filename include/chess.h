#ifndef CHESS_HEADER
#define CHESS_HEADER

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

#include <stdio.h>
#include <stdbool.h>

#define WINDOW_WIDTH  500
#define WINDOW_HEIGHT 500
#define TILE_SIZE     50
#define BOARD_SIZE    10

void StartGrafikGame(SDL_Renderer *renderer, SDL_Texture *images[16], SDL_Texture* images_ascii[256]);
void InitImages(SDL_Texture* images[16], SDL_Renderer* renderer);
void InitASCII(SDL_Texture* images_ascii[256], SDL_Renderer* renderer);
void DrawChessboard(SDL_Renderer* renderer, unsigned int desk[8], SDL_Texture* images[16], SDL_Texture* images_ascii[256], int x, int y);

#endif
