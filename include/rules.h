#ifndef RULES_HEADER
#define RULES_HEADER

#include "bitboards.h"

void ReverseColours(unsigned int desk[8]);
/* reverse colours and lines on desk */
PosFigure* NearFigure(unsigned int desk[8], int column, int line, int Ux, int Uy);
/* searches for the nearest figure from the kletka (column, line) in the direction of (Uy, Ux) */
int CheckKnight(unsigned int desk[8], int Kcolumn, int Kline);
/* checks if the black knight can check on kletka (Kcolumn, Kline) */
int CheckBtoWChecks(unsigned int desk[8]);
/* checks if there is a check on the white king */
void CopyDesk(unsigned int startdesk[8], unsigned int copydesk[8]);
/* copied desk from start desk to copydesk, startdesk is inv */
int CmpDesks(unsigned int a[8], unsigned int b[8]);
/* return 1 if == */
int isBlack(unsigned int fig);
/* used only fig if black -> return 1 else 0 */
int CreaeteDesks(unsigned int desk[8], unsigned int var[200][8], int start, int x, int y, int x1, int y1, int Ux, int Uy, unsigned int fig);
/* create desks where figure = fig on kletka (y + n*Uy); (x + n*Ux), while kletka != x1; y1 or kletka outside desk */
int GenLongRangeFigMov(unsigned int desk[8], unsigned int var[200][8], int start, int count_var, int column, int line, unsigned int fig, int moves[], int len_moves);
/* generate all desks used fig (work only for long ranged fig) and its moves[] from column;line */
int PawnCutDown(unsigned int desk[8], unsigned int cpydesk[8], unsigned int var[200][8], int start, int count_var, int column, int line, int u);
/* gen variants where pawn cut down fig */
int GenStandartPawnMov(unsigned int desk[8], unsigned int cpydesk[8], unsigned int var[200][8], int start, int count_var, int column, int line);
/* gen standart pawn moves (not passant and promotion) */
int GenPassant(unsigned int desk[8], unsigned int cpydesk[8], unsigned int var[200][8], int start, int count_var, int column, int line, int u);
/* gen passant */
int GenPromotion(unsigned int desk[8], unsigned int cpydesk[8], unsigned int var[200][8], int start, int count_var, int column, int line, int u);
/* gen promotion */
int GenMovesFig(unsigned int desk[8], unsigned int var[200][8], int start, unsigned int fig, int column, int line);
/* gen all moves figure on (column;line) */
void GenAllMoves(unsigned int desk[8], unsigned int variants[200][8]);
/* gen all moves (not castling) at desk */


#endif
