#include "bitboards.h"
#include "rules.h"
#include <assert.h>

void ReverseColours(unsigned int desk[8]) {
  unsigned int t;
  for (int i = 1; i < 9; i++) {
    for (int j = 1; j < 9; j++) {
      t = GetKletka(desk, j, i);
      SetKletka(desk, j, i, (unsigned int)( (16 - t) % 16 ) );
    }
  }
  for (int i = 0; i < 4; i++) {
    t = desk[i]; desk[i] = desk[7 - i]; desk[7 - i] = t;
  }
}

PosFigure* NearFigure(unsigned int desk[8], int column, int line, int Ux, int Uy) {
  int Near = 1;
  unsigned int t;
  PosFigure* NearFig = (PosFigure*)malloc(sizeof(PosFigure));
  while ( (column + Ux*Near > 0) &&  (column + Ux*Near < 9) && (line + Uy*Near > 0) &&  (line + Uy*Near < 9) ) {
    t = GetKletka(desk, column + Ux*Near, line + Uy*Near);
    if (t == 0) {Near+=1;
    } else {NearFig->fig = t; NearFig->column = column + Ux*Near; NearFig->line = line + Uy*Near; return NearFig;}
  }
  NearFig->fig = 0; NearFig->column = 0; NearFig->line = 0; return NearFig;
}

int CheckKnight(unsigned int desk[8], int Kcolumn, int Kline) {
  if ( (Kline + 2 < 9) && (Kcolumn + 1 < 9) && GetKletka(desk, Kcolumn + 1, Kline + 2) == 14 ) return 1;
  if ( (Kline + 2 < 9) && (Kcolumn - 1 > 0) && GetKletka(desk, Kcolumn - 1, Kline + 2) == 14 ) return 1;
  if ( (Kline + 1 < 9) && (Kcolumn + 2 < 9) && GetKletka(desk, Kcolumn + 2, Kline + 1) == 14 ) return 1;
  if ( (Kline + 1 < 9) && (Kcolumn - 2 > 0) && GetKletka(desk, Kcolumn - 2, Kline + 1) == 14 ) return 1;
  if ( (Kline - 1 > 0) && (Kcolumn + 2 < 9) && GetKletka(desk, Kcolumn + 2, Kline - 1) == 14 ) return 1;
  if ( (Kline - 1 > 0) && (Kcolumn - 2 > 0) && GetKletka(desk, Kcolumn - 2, Kline - 1) == 14 ) return 1;
  if ( (Kline - 2 > 0) && (Kcolumn + 1 < 9) && GetKletka(desk, Kcolumn + 1, Kline - 2) == 14 ) return 1;
  if ( (Kline - 2 > 0) && (Kcolumn - 1 > 0) && GetKletka(desk, Kcolumn - 1, Kline - 2) == 14 ) return 1;
  return 0;
}

int CheckBtoWChecks(unsigned int desk[8]) {
  int Kcolumn, Kline;
  for (int i = 1; i < 9; i++) {
    for (int j = 1; j < 9; j++) {
      if (GetKletka(desk, j, i) == 6) {Kcolumn = j; Kline = i;}
    }
  }

  PosFigure* ColumnUp   = NearFigure(desk, Kcolumn, Kline, 0, 1);
  PosFigure* ColumnDown = NearFigure(desk, Kcolumn, Kline, 0, -1);
  PosFigure* LineRight  = NearFigure(desk, Kcolumn, Kline, 1, 0);
  PosFigure* LineLeft   = NearFigure(desk, Kcolumn, Kline, -1, 0);
  PosFigure* DiagRU     = NearFigure(desk, Kcolumn, Kline, 1, 1);
  PosFigure* DiagLD     = NearFigure(desk, Kcolumn, Kline, -1, -1);
  PosFigure* DiagLU     = NearFigure(desk, Kcolumn, Kline, -1, 1);
  PosFigure* DiagRD     = NearFigure(desk, Kcolumn, Kline, 1, -1);

  if ( (ColumnUp->fig == 12) || (ColumnUp->fig == 15) || (ColumnDown->fig == 12) || (ColumnDown->fig == 15) ) return 1;
  if ( (LineRight->fig == 12) || (LineRight->fig == 15) || (LineLeft->fig == 12) || (LineLeft->fig == 15) ) return 1;
  if ( (DiagRU->fig == 12) || (DiagRU->fig == 13) || (DiagLD->fig == 12) || (DiagLD->fig == 13) ) return 1;
  if ( (DiagLU->fig == 12) || (DiagLU->fig == 13) || (DiagRD->fig == 12) || (DiagRD->fig == 13) ) return 1;
  if ( (ColumnUp->line - Kline == 1) && (ColumnUp->fig == 10) ) return 1;
  if ( (ColumnDown->line - Kline == 1) && (ColumnDown->fig == 10) ) return 1;
  if ( (LineRight->line - Kline == 1) && (LineRight->fig == 10) ) return 1;
  if ( (LineLeft->line - Kline == 1) && (LineLeft->fig == 10) ) return 1;
  if ( (DiagLD->line - Kline == 1) && (DiagLD->fig == 10) ) return 1;
  if ( (DiagRD->line - Kline == 1) && (DiagRD->fig == 10) ) return 1;
  if ( (DiagRU->line - Kline == 1) && (DiagRU->fig == 10 || DiagRU->fig == 9 || DiagRU->fig == 11) ) return 1;
  if ( (DiagLU->line - Kline == 1) && (DiagLU->fig == 10 || DiagLU->fig == 9 || DiagLU->fig == 11) ) return 1;

  free(ColumnUp); free(ColumnDown); free(LineLeft); free(LineRight);
  free(DiagLD); free(DiagLU); free(DiagRD); free(DiagRU);

  return CheckKnight(desk, Kcolumn, Kline);
}

void CopyDesk(unsigned int startdesk[8], unsigned int copydesk[8]) {for (int i = 0; i < 8; i++) copydesk[i] = startdesk[i];}
int CmpDesks(unsigned int a[8], unsigned int b[8]) {
  int f = 1;
  for (int i = 0; i < 8; i++) f = f && (a[i] == b[i]);
  return f;
}

int isBlack(unsigned int fig) { if (fig > 8 && fig < 16) {return 1;} return 0; }

int CreaeteDesks(unsigned int desk[8], unsigned int var[200][8], int start, int x, int y, int x1, int y1, int Ux, int Uy, unsigned int fig) {
  //assert (y1 > 0);
  //assert (y1 < 9);
  unsigned int cpydesk[8];
  int count = 0;
  CopyDesk(desk, cpydesk);
  SetKletka(cpydesk, x, y, 0);
  x += Ux; y += Uy;
  while ( (x != x1 || y != y1) && x < 9 && x > 0 && y > 0 && y < 9) {
    SetKletka(cpydesk, x, y, fig);
    CopyDesk(cpydesk, var[start + count]);
    SetKletka(cpydesk, x, y, 0);
    count += 1; x += Ux; y += Uy;
  }
  if ( (x1 != 0) && (y1 != 0) && isBlack(GetKletka(desk, x1, y1))) {
    SetKletka(cpydesk, x1, y1, fig);
    CopyDesk(cpydesk, var[start + count]);
    count += 1;
  }
  return count;
}

int GenLongRangeFigMov(unsigned int desk[8], unsigned int var[200][8], int start, int count_var, int column, int line, unsigned int fig, int moves[], int len_moves) {
  int cur_var = 0;
  for (int i = 0; i < len_moves; i += 2) {
    PosFigure* ColumnUp = NearFigure(desk, column, line, moves[i], moves[i + 1]);
    cur_var += CreaeteDesks(desk, var, start + count_var + cur_var, column, line, ColumnUp->column, ColumnUp->line, moves[i], moves[i + 1], fig);
  }
  return cur_var;
}

int PawnCutDown(unsigned int desk[8], unsigned int cpydesk[8], unsigned int var[200][8], int start, int count_var, int column, int line, int u) {
  if (column + u > 8 || column + u < 1) return 0;
  unsigned int t = GetKletka(desk, column + u, line + 1);
  if (isBlack(t)) {
    SetKletka(cpydesk, column + u, line + 1, 7); CopyDesk(cpydesk, var[start + count_var]); SetKletka(cpydesk, column + u, line + 1, t);
    return 1;
  }
  return 0;
}

int GenStandartPawnMov(unsigned int desk[8], unsigned int cpydesk[8], unsigned int var[200][8], int start, int count_var, int column, int line) {
  unsigned int t = GetKletka(desk, column, line + 1);
  int cur_var = 0;
  if (t == 0) {
    SetKletka(cpydesk, column, line + 1, 7); CopyDesk(cpydesk, var[start + count_var]); SetKletka(cpydesk, column, line + 1, 0);
    cur_var += 1;
  }
  cur_var += PawnCutDown(desk, cpydesk, var, start, count_var + cur_var, column, line, 1);
  cur_var += PawnCutDown(desk, cpydesk, var, start, count_var + cur_var, column, line, -1);
  return cur_var;
}

int GenPassant(unsigned int desk[8], unsigned int cpydesk[8], unsigned int var[200][8], int start, int count_var, int column, int line, int u) {
  if (column + u > 8 || column + u < 1) return 0;
  unsigned int t = GetKletka(desk, column + u, line);
  if (t == 11) {
    SetKletka(cpydesk, column + u, line + 1, 7);
    SetKletka(cpydesk, column + u, line, 0);
    CopyDesk(cpydesk, var[start + count_var]);
    SetKletka(cpydesk, column + u, line + 1, 0);
    SetKletka(cpydesk, column + u, line, 11);
    return 1;
  }
  return 0;
}

int GenPromotion(unsigned int desk[8], unsigned int cpydesk[8], unsigned int var[200][8], int start, int count_var, int column, int line, int u) {
  if (column + u > 8 || column + u < 1) return 0;
  int cur_len = 0;
  if (u == 0) {
    if (GetKletka(desk, column, line + 1) != 0) return 0;
    for (int i = 1; i < 5; i++) {
      SetKletka(cpydesk, column, line + 1, i); CopyDesk(cpydesk, var[start + count_var + cur_len]);
      cur_len += 1;
    }
    SetKletka(cpydesk, column, line + 1, 0);
    return cur_len;
  }
  unsigned int t = GetKletka(desk, column + u, line + 1);
  if (isBlack(t)) {
    for (unsigned int i = 1; i < 5; i++) {
      SetKletka(cpydesk, column + u, line + 1, i); CopyDesk(cpydesk, var[start + count_var + cur_len]);
      cur_len += 1;
    }
    SetKletka(cpydesk, column + u, line + 1, t);
    return cur_len;
  }
  return 0;
}

int GenMovesFig(unsigned int desk[8], unsigned int var[200][8], int start, unsigned int fig, int column, int line) {
  assert (line > 0);
  assert (line < 9);
  int count_var = 0;
  unsigned int t = 0;
  unsigned int cpydesk[8]; CopyDesk(desk, cpydesk);
  switch(fig) {
    case 0: return 0;
    case 1: count_var += GenLongRangeFigMov(desk, var, start, count_var, column, line, (unsigned int)1, RookM, 8); break;
    case 2: //White Knight
      SetKletka(cpydesk, column, line, 0);
      for (int i = 0; i < 16; i += 2) {
        int x = column + KnightM[i]; int y = line + KnightM[i + 1];
        if ( (x < 9) && (x > 0) && (y < 9) && (y > 0) ) {
          t = GetKletka(desk, x, y);
          if (t == 0 || isBlack(t)) {
            SetKletka(cpydesk, x, y, 2);
            CopyDesk(cpydesk, var[start + count_var]);
            SetKletka(cpydesk, x, y, t);
            count_var += 1;
          }
        }
      }
      break;
    case 3: count_var += GenLongRangeFigMov(desk, var, start, count_var, column, line, (unsigned int)3, BishopM, 8); break;
    case 4: count_var += GenLongRangeFigMov(desk, var, start, count_var, column, line, (unsigned int)4, QueenM, 16); break;
    case 6: //White King
      SetKletka(cpydesk, column, line, 0);
      for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
          int x = column + i; int y = line + j;
          if ( (x < 9) && (x > 0) && (y < 9) && (y > 0) ) {
            t = GetKletka(desk, x, y);
            if (t == 0 || isBlack(t)) {
              SetKletka(cpydesk, x, y, 6); CopyDesk(cpydesk, var[start + count_var]); SetKletka(cpydesk, x, y, t);
              count_var += 1;
            }
          }
        }
      }
      break;
    case 7: //White Pawn not in line 4
      SetKletka(cpydesk, column, line, 0);
      if (line != 7) {
        count_var += GenStandartPawnMov(desk, cpydesk, var, start, count_var, column, line);
      }
      if (line == 2) {
        t = GetKletka(desk, column, line + 2); unsigned int t1 = GetKletka(desk, column, line + 1);
        if (t == 0 && t1 == 0) {
          SetKletka(cpydesk, column, line + 2, 5); CopyDesk(cpydesk, var[start + count_var]); SetKletka(cpydesk, column, line + 2, 0);
          count_var += 1;
        }
      }
      if (line == 5) {
        count_var += GenPassant(desk, cpydesk, var, start, count_var, column, line, 1);
        count_var += GenPassant(desk, cpydesk, var, start, count_var, column, line, -1);
      }
      if (line == 7) {
        count_var += GenPromotion(desk, cpydesk, var, start, count_var, column, line, 1);
        count_var += GenPromotion(desk, cpydesk, var, start, count_var, column, line, 0);
        count_var += GenPromotion(desk, cpydesk, var, start, count_var, column, line, -1);
      }
      break;
    case 5:
      SetKletka(cpydesk, column, line, 0);
      count_var += GenStandartPawnMov(desk, cpydesk, var, start, count_var, column, line);
      break;
  }
  return count_var;
}


void GenAllMoves(unsigned int desk[8], unsigned int variants[200][8]) {
  unsigned int t;
  int cur_len = 0;

  for (int i = 1; i < 9; i++) {
    for (int j = 1; j < 9; j++) {
      t = GetKletka(desk, j, i);
      cur_len += GenMovesFig(desk, variants, cur_len, t, j, i);
    }
  }
  for (int i = 0; i < cur_len; i++) {
    if (CheckBtoWChecks(variants[i])) {
      CopyDesk(ZeroMassive, variants[i]);
    }
    for (int j = 1; j < 9; j++) {
      if (GetKletka(variants[i], j, 5) == 11) SetKletka(variants[i], j, 5, 9);
    }
  }
}
