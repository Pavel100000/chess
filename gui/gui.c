#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

// Размеры доски и клеток
#define BOARD_WIDTH  720
#define BOARD_HEIGHT 720
#define CELL_SIZE    80

// Функция для отрисовки доски
void drawBoard(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Установка цвета белого
    SDL_Rect rect;
    rect.w = CELL_SIZE;
    rect.h = CELL_SIZE;

    // Рисуем клетки
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            rect.x = col * CELL_SIZE;
            rect.y = row * CELL_SIZE;

            // Чередуем цвета клеток
            if (row == 8 || col == 8) {
                SDL_SetRenderDrawColor(renderer, 255, 206, 158, 255); // Светло-коричневая клетка
            }
            else if ((row + col) % 2 == 0) {
                SDL_SetRenderDrawColor(renderer, 255, 206, 158, 255); // Светло-коричневая клетка
            } else {
                SDL_SetRenderDrawColor(renderer, 209, 139, 71, 255); // Темно-коричневая клетка
            }
            SDL_RenderFillRect(renderer, &rect);
        }
    }

    // Рисуем буквы и цифры по краям доски
    SDL_Color textColor = {0, 0, 0, 255}; // Черный цвет текста
    TTF_Font* font = TTF_OpenFont("../gui/arial.ttf", 24); // Загрузка шрифта
    if (font == NULL) {
        printf("Ошибка загрузки шрифта: %s\n", TTF_GetError());
        return;
    }

    for (int i = 0; i < 8; i++) {
        char letter = 'a' + i;

        // Рисуем буквы по нижней границе доски
        SDL_Surface* surface = TTF_RenderText_Solid(font, &letter, textColor);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect letterRect = {i * CELL_SIZE, 8 * CELL_SIZE, surface->w, surface->h};
        SDL_RenderCopy(renderer, texture, NULL, &letterRect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }

    // Рисуем цифры по правой границе доски
    for (int i = 0; i < 8; i++) {
        char digit = '8' - i;

        // Рисуем буквы по нижней границе доски
        SDL_Surface* surface = TTF_RenderText_Solid(font, &digit, textColor);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect letterRect = {8 * CELL_SIZE, i * CELL_SIZE, surface->w, surface->h};
        SDL_RenderCopy(renderer, texture, NULL, &letterRect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
    }
    TTF_CloseFont(font);
}

// Функция для отрисовки фигур
void drawPieces(SDL_Renderer* renderer) {
    // Английские буквы для обозначения фигур
    char pieces[8] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
    for (int i = 0; i < 8; ++i) {
        SDL_Color textColor = {0, 0, 0, 255}; // Черный цвет текста
        TTF_Font* font = TTF_OpenFont("../gui/arial.ttf", 48); // Загрузка шрифта
        if (font == NULL) {
            printf("Ошибка загрузки шрифта: %s\n", TTF_GetError());
            return;
        }

        char piece = pieces[i];
        SDL_Surface* surface = TTF_RenderText_Solid(font, &piece, textColor);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect pieceRect = {i * CELL_SIZE, 0, surface->w, surface->h};
        SDL_RenderCopy(renderer, texture, NULL, &pieceRect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);
        TTF_CloseFont(font);
    }
}

int main(int argc, char* argv[]) {
    SDL_Window   *window   = NULL;
    SDL_Renderer *renderer = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
        return 1;
    }

    // Инициализация SDL_ttf
    if (TTF_Init() < 0) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        return 1;
    }
    
    window = SDL_CreateWindow("Chess Board", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, BOARD_WIDTH, BOARD_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    // Отрисовка доски
    drawBoard(renderer);

    // Отрисовка фигур
    drawPieces(renderer);

    SDL_RenderPresent(renderer);

    SDL_Delay(5000); // Подождать 3 секунды перед закрытием окна

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    TTF_Quit();

    return 0;
}
