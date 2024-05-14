#include <stdbool.h>
#include <SDL.h>
#include <SDL_image.h>

#include "rules.h"
#include "bitboards.h"
#include "chess.h"

typedef struct {
  int click;
  int x; int y;
  int x1; int y1;
  int x2; int y2;
  unsigned int fig;
  int selected_x;
  int selected_y;
} coordinates;

typedef struct {
  unsigned int desk[8];
  unsigned int vars[200][8];
  unsigned char castling; // (0 - dont moved, 1 - moved) 1 bit - w rook on a, 2 - w king, 3 - w rook on h, (4,5,6) - similary for b
  unsigned int castlevars[2][8];
  bool colour; // true - white; false - black
  int lenvars;
} gamevar;

int PrintVars(unsigned int vars[200][8], int len) {
  for (int i = 0; i < len; i++) {
    PrintDesk(vars[i]);
    printf("\n===========================================\n");
  }
  printf("\nlen: %d \n", len);
}

int GetLenVars(unsigned int vars[200][8]) {
  int i = 0;
  unsigned int t[8];
  CopyDesk(vars[0], t);
  while (i < 200 && !CmpDesks(vars[i], ZeroMassive) ) i++;
  for (int j = i + 1; j < 200; j++) {
    if (!CmpDesks(vars[j], ZeroMassive)) {
      CopyDesk(vars[j], vars[i]); CopyDesk(ZeroMassive, vars[j]);
      i++;
    }
  }
  return i;
}

void DecodSimplePawn(char* Not, unsigned int stdesk[8], unsigned int newdesk[8], bool colour, PosFigure* putfig, PosFigure* deletefig) {
  if (!colour) { Not[1] = (char)105 - Not[1]; Not[3] = (char)105 - Not[3]; }

  putfig->column = (unsigned int)(Not[2]) - 96;
  putfig->line = (unsigned int)(Not[3]) - 48;
  deletefig->column = (unsigned int)(Not[0]) - 96;
  deletefig->line = (unsigned int)(Not[1]) - 48;
  if (putfig->line == 4 && deletefig->line == 2) putfig->fig = (unsigned int)5;

  else if(putfig->column != deletefig->column && putfig->line == 6 && deletefig->line == 5 &&
    GetKletka(stdesk, putfig->column, 5) == 11) {
    SetKletka(newdesk, putfig->column, 5, 0);
    putfig->fig = (unsigned int)7;
  }
  else putfig->fig = (unsigned int)7;
}

void DecodPromotion(char* Not, unsigned int stdesk[8], unsigned int newdesk[8], bool colour, PosFigure* putfig, PosFigure* deletefig) {
  DecodSimplePawn(Not, stdesk, newdesk, colour, putfig, deletefig);
  putfig->fig = findPos(figures, 16, Not[4]);
}

void DecodFigNot(char* Not, unsigned int stdesk[8], unsigned int newdesk[8], bool colour, PosFigure* putfig, PosFigure* deletefig, unsigned char* castling) {
  if (!colour) { Not[2] = (char)105 - Not[2]; Not[4] = (char)105 - Not[4]; }
  putfig->fig = findPos(figures, 16, Not[0]);
  putfig->column = (unsigned int)(Not[3]) - 96;
  putfig->line = (unsigned int)(Not[4]) - 48;
  deletefig->column = (unsigned int)(Not[1]) - 96;
  deletefig->line = (unsigned int)(Not[2]) - 48;
}

void DecodNotation(char* Not, int lenNot, unsigned int stdesk[8], unsigned int newdesk[8], bool colour, unsigned char* castling, PosFigure* figure) {
  CopyDesk(stdesk, newdesk);
  bool flag = true;
  PosFigure* putfig = (PosFigure*)malloc(sizeof(PosFigure));
  PosFigure* deletefig = (PosFigure*)malloc(sizeof(PosFigure));
  deletefig->fig = (unsigned int)0;
  if (lenNot == 4) DecodSimplePawn(Not, stdesk, newdesk, colour, putfig, deletefig);
  else if (lenNot == 3) {SetFigures("Oe1Oh1Kg1Rf1", 4, newdesk); flag = false;}
  else if (Not[0] == '0') {SetFigures("Oe1Oa1Kc1Rd1", 4, newdesk); flag = false;}
  else if (Not[0] > (char)90) DecodPromotion(Not, stdesk, newdesk, colour, putfig, deletefig);
  else DecodFigNot(Not, stdesk, newdesk, colour, putfig, deletefig, castling);

  if (flag) {
    SetKletka(newdesk, putfig->column,    putfig->line,    putfig->fig);
    SetKletka(newdesk, deletefig->column, deletefig->line, deletefig->fig);
  }

  for (int i = 1; i < 9; i++) {
    if (GetKletka(newdesk, i, 5) == 11) SetKletka(newdesk, i, 5, 9);
  }
  figure->fig = putfig->fig; figure->column = deletefig->column; figure->line = deletefig->line;
  free(putfig); free(deletefig);
}

int FindColisns(unsigned int desk[8], unsigned int vars[200][8], unsigned int castlevars[2][8]) {
  for (int i = 0; i < 200; i++) {
    if (CmpDesks(desk, vars[i])) return 1;
  }
  if (CmpDesks(desk, castlevars[0]) || CmpDesks(desk, castlevars[0])) return 1;
  return 0;
}

void InitGame(gamevar* game) {
  StartPosition(game->desk);
  GenAllMoves(game->desk, game->vars);
  game->castling = (unsigned int)0;
  game->colour = true;
  game->lenvars = 20;
}

int GetAttacks(unsigned int desk[8], int column, int line) { // return 1 if attack else 0
  PosFigure* NearFig = NearFigure(desk, column, line, 0, 1);
  if ( NearFig->fig == 12 || NearFig->fig == 16 ) return 1;
  NearFig = NearFigure(desk, column, line, 1, 1);
  if ( NearFig->fig == 12 || NearFig->fig == 14 ) return 1;
  if ( NearFig->fig == 9 && NearFig->line == 2 && NearFig->column == (column + 1) ) return 1;
  NearFig = NearFigure(desk, column, line, -1, 1);
  if ( NearFig->fig == 12 || NearFig->fig == 14 ) return 1;
  if ( NearFig->fig == 9 && NearFig->line == 2 && NearFig->column == (column - 1) ) return 1;
  if ( GetKletka(desk, column + 1, 3) == (unsigned int)(15) ) return 1;
  if ( GetKletka(desk, column - 1, 3) == (unsigned int)(15) ) return 1;
  free(NearFig);
  return 0;
}

int GenCastleVars(unsigned int stdesk[8], unsigned char possib, unsigned int castlevars[2][8], bool boolcolour) {
  int shortc = 1; int longc = 1; int colour = 3;
  if (boolcolour) colour = 0;

  if (CheckBtoWChecks(stdesk)) return 0;
  if (TestBitChar(possib, 2 + colour)) return 0;
  if (TestBitChar(possib, 1 + colour)) longc  = 0;
  if (TestBitChar(possib, 3 + colour)) shortc = 0;

  if (GetAttacks(stdesk, 6, 1)) shortc = 0;
  if (GetAttacks(stdesk, 4, 1)) longc  = 0;

  if (NearFigure(stdesk, 6, 1,  1, 0)->fig != 1 || GetKletka(stdesk, 6, 1) != 0) shortc = 0;
  if (NearFigure(stdesk, 4, 1, -1, 0)->fig != 1 || GetKletka(stdesk, 4, 1) != 0) longc  = 0;

  if (shortc == 1) {
    CopyDesk(stdesk, castlevars[0]);
    SetFigures("Oe1Oh1Kg1Rf1", 4, castlevars[0]);
    if ( CheckBtoWChecks(castlevars[0]) ) {CopyDesk(ZeroMassive, castlevars[0]); shortc = 0;}
  }
  if (longc  == 1) {
    CopyDesk(stdesk, castlevars[1]);
    SetFigures("Oe1Oa1Kc1Rd1", 4, castlevars[1]);
    if ( CheckBtoWChecks(castlevars[1]) ) {CopyDesk(ZeroMassive, castlevars[1]); longc  = 0;}
  }
  return shortc + longc;
}

void EnterMove(gamevar* game, unsigned int newdesk[8], PosFigure* movingfig) {
  char* move = (char*)calloc(sizeof(char), 6);
  printf("Enter move: ");
  scanf("%s", move);
  DecodNotation(move, strlen(move), game->desk, newdesk, game->colour, &game->castling, movingfig);

  while (!FindColisns(newdesk, game->vars, game->castlevars)) {
    printf("Incorrect move, try again: ");
    scanf("%s", move);
    DecodNotation(move, strlen(move), game->desk, newdesk, game->colour, &game->castling, movingfig);
  }

  int cof;
  if (game->colour) cof = 0;
  else cof = 1;

  if (movingfig->fig == 6) SetBitChar(game->castling, 2 + cof*3);
  else if (movingfig->fig == 1 && movingfig->column == 1)  SetBitChar(game->castling, 1 + cof*3);
  else if (movingfig->fig == 1 && movingfig->column == 1)  SetBitChar(game->castling, 3 + cof*3);

  free(move);
}

void StartGame(SDL_Renderer* renderer, SDL_Texture* images[16], SDL_Texture* images_ascii[256]) {
  gamevar* game = (gamevar*)calloc(sizeof(gamevar), 1);

  InitGame(game);

  unsigned int newdesk[8] = {0};
  PosFigure* movingfig = (PosFigure*)malloc(sizeof(PosFigure));

  while ( !CmpDesks(ZeroMassive, game->vars[0]) ) {
    if (game->colour) PrintDesk(game->desk);
    else { ReverseColours(game->desk); PrintDesk(game->desk); ReverseColours(game->desk); }

    EnterMove(game, newdesk, movingfig);

    game->colour = !(game->colour);
    ReverseColours(newdesk);
    CopyDesk(newdesk, game->desk);
    memset(game->vars, 0, sizeof(unsigned int)*200*8);
    GenAllMoves(game->desk, game->vars);
    GenCastleVars(game->desk, game->castling, game->castlevars, game->colour);
    game->lenvars = GetLenVars(game->vars);
  }

  free(game);
}

unsigned int DrawPawnVariants(unsigned int column, unsigned int line, SDL_Renderer* renderer, SDL_Texture* images[16]) {
  SDL_Rect rect; rect.w = TILE_SIZE; rect.h = TILE_SIZE; rect.y = (9 - line) * TILE_SIZE;
  unsigned int x; unsigned int y; SDL_Event event;
  for (unsigned int i = 0; i < 4; i++) {
    rect.x = (column - 1 + i) * TILE_SIZE;
    SDL_SetRenderDrawColor(renderer, 130, 151, 105, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderCopy(renderer, images[i + 1], NULL, &rect);
    SDL_RenderPresent(renderer);
  }
  bool quit = false;
  while (!quit) {
    SDL_WaitEvent(&event);
    if (event.type == SDL_MOUSEBUTTONDOWN) {
      SDL_GetMouseState(&x, &y); x = x / TILE_SIZE; y = 9 - y / TILE_SIZE;
      if (0 < (x - column + 2) && (x - column + 2) < 5 && y == line) return (x - column) + 2;
    }
  }

}

int ConverToNot(char* Not, int x1, int y1, unsigned int fig, int x2, int y2, SDL_Renderer* renderer, SDL_Texture* images[16]) {
  if (fig == 5 || fig == 7 || fig == 9 || fig == 11) {
    Not[0] = (char)((int)'a' + x1 - 1);
    Not[1] = (char)((int)'1' + y1 - 1);
    Not[2] = (char)((int)'a' + x2 - 1);
    Not[3] = (char)((int)'1' + y2 - 1);
    if ((y2 == 8 && y1 == 7) || (y2 == 1 && y1 == 2)) {Not[4] = figures[DrawPawnVariants(x2, y2, renderer, images)]; return 5;}
    return 4;
  }
  else if ( (fig == 6 && x1 == 5 && y1 == 1 && x2 == 7 && y2 == 1) || (fig == 10 && x1 == 5 && y1 == 8 && x2 == 7 && y2 == 8) ) {
    Not[0] = '0'; Not[1] = '-'; Not[2] = '0'; return 3;
  }
  else if ( (fig == 6 && x1 == 5 && y1 == 1 && x2 == 3 && y2 == 1) || (fig == 10 && x1 == 5 && y1 == 8 && x2 == 3 && y2 == 8) ) {
    Not[0] = '0'; Not[1] = '-'; Not[2] = '0'; Not[3] = '-'; Not[4] = '0'; return 5;
  }
  else {
    if (isBlack(fig)) Not[0] = figures[16 - fig];
    else Not[0] = figures[fig];
    Not[1] = (char)((int)'a' + x1 - 1);
    Not[2] = (char)((int)'1' + y1 - 1);
    Not[3] = (char)((int)'a' + x2 - 1);
    Not[4] = (char)((int)'1' + y2 - 1);
    return 5;
  }
}

void GameMove(int x1, int y1, unsigned int fig, int x2, int y2, SDL_Renderer* renderer, gamevar* game,
  unsigned int newdesk[8], SDL_Texture* images[16], PosFigure* movingfig) {
  char* Not = (char*)calloc(sizeof(char), 6); Not[5] = '\0';
  int lenNot = ConverToNot(Not, x1, y1, fig, x2, y2, renderer, images); int cof = 0;
  printf("Notation: %s\n", Not);
  DecodNotation(Not, lenNot, game->desk, newdesk, game->colour, &game->castling, movingfig);

  if (FindColisns(newdesk, game->vars, game->castlevars)) {
    if (game->colour) cof = 0;
    else cof = 1;

    if (movingfig->fig == 6) SetBitChar(game->castling, 2 + cof*3);
    else if (movingfig->fig == 1 && movingfig->column == 1)  SetBitChar(game->castling, 1 + cof*3);
    else if (movingfig->fig == 1 && movingfig->column == 1)  SetBitChar(game->castling, 3 + cof*3);

    game->colour = !(game->colour);
    ReverseColours(newdesk);
    CopyDesk(newdesk, game->desk);
    memset(game->vars, 0, sizeof(unsigned int)*200*8);
    GenAllMoves(game->desk, game->vars);
    GenCastleVars(game->desk, game->castling, game->castlevars, game->colour);
    game->lenvars = GetLenVars(game->vars);
  }
  free(Not);
}

void ClickAccum(coordinates* game_c, gamevar* game) {
  game_c->selected_x = 0; game_c->selected_y = 0;
  if (game->colour) game_c->fig = GetKletka(game->desk, game_c->x, game_c->y);
  else {
    ReverseColours(game->desk);
    game_c->fig = GetKletka(game->desk, game_c->x, game_c->y);
    ReverseColours(game->desk);
  }
  if (game_c->fig != 0) {
    game_c->x1 = game_c->x; game_c->y1 = game_c->y; game_c->click++;
    game_c->selected_x = game_c->x; game_c->selected_y = game_c->y;
  }
}

void StartGrafikGame(SDL_Renderer* renderer, SDL_Texture* images[16], SDL_Texture* images_ascii[256]) {
  bool quit = false;
  coordinates game_c = {0, 0, 0, 0, 0, 0, 0};
  gamevar* game = (gamevar*)calloc(sizeof(gamevar), 1);

  InitGame(game);

  unsigned int newdesk[8] = {0};
  PosFigure* movingfig = (PosFigure*)malloc(sizeof(PosFigure));

  while (!quit && !CmpDesks(ZeroMassive, game->vars[0])) {
      SDL_Event event;

      SDL_WaitEvent(&event);
      switch (event.type) {
          case SDL_QUIT:
              quit = true;
              break;
          case SDL_MOUSEBUTTONDOWN:
               // обработка нажатия мыши
               SDL_GetMouseState(&game_c.x, &game_c.y);
               game_c.x = game_c.x / TILE_SIZE;
               game_c.y = 9 - game_c.y / TILE_SIZE;
               if (0 < game_c.x && game_c.x < 9 && 0 < game_c.y && game_c.y < 9) {
                 if (game_c.click == 0) ClickAccum(&game_c, game);
                 else {
                   game_c.x2 = game_c.x; game_c.y2 = game_c.y; game_c.click = 0;
                   GameMove(game_c.x1, game_c.y1, game_c.fig, game_c.x2, game_c.y2, renderer, game, newdesk, images, movingfig);
                   game_c.selected_x = 0; game_c.selected_y = 0;
                 }
              }
      }

      SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
      SDL_RenderClear(renderer);

      if (game->colour) DrawChessboard(renderer, game->desk, images, images_ascii, game_c.selected_x, game_c.selected_y);
      else {
        ReverseColours(game->desk);
        DrawChessboard(renderer, game->desk, images, images_ascii, game_c.selected_x, game_c.selected_y);
        ReverseColours(game->desk);}
      SDL_RenderPresent(renderer);
   }
}
