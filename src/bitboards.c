#include "bitboards.h"
#include <assert.h>

unsigned int TestBit(unsigned int A[],  int k ) { return ( (A[k/32] & (1 << (31 - k%32) )) != 0 );}

unsigned char TestBitChar(unsigned char A,  int k ) { return ( (A & (1 << (7 - k%8) )) != 0 );}

unsigned int findPos(char arr[], int len, char seek) {
    for (int i = 0; i < len; i++) {
      if (arr[i] == seek) return i;
    }
    return -1;
}

void BitPrintDesk(unsigned int desk[8]) {
  for (int i = 0; i < 256; i++) {
    printf("%d", TestBit(desk, i));
  }
  printf("\n");
}

unsigned int GetKletka(unsigned int desk[8], unsigned int column, unsigned int line) { // column, line = 1 - 8
  assert (line > 0);
  assert (line < 9);
  return (desk[line - 1] & (15 << (28 - (column - 1)*4 ))) >> (28 - (column - 1)*4);
}

void SetKletka(unsigned int desk[8], unsigned int column, unsigned int line, unsigned int figure) { // column, line = 1 - 8
  desk[line - 1] = ( ( ~(15 << (28 - (column - 1)*4)) ) & (desk[line - 1]) ) | (figure << (28 - (column - 1)*4) );
}

void SimpleDecodNot(char Not[3], PosFigure* PosFig) {
  PosFig->fig = findPos(figures, 16, Not[0]);
  PosFig->column = (unsigned int)(Not[1]) - 96;
  PosFig->line = (unsigned int)(Not[2]) - 48;
}

void SetFigures(char Nots[], int len, unsigned int desk[8]) {
  char Not[3];
  for (int i = 0; i < len*3; i+=3) {
    Not[0] = Nots[i]; Not[1] = Nots[i+1]; Not[2] = Nots[i+2];
    PosFigure* PosFig = (PosFigure*)malloc(sizeof(PosFigure));
    SimpleDecodNot(Not, PosFig);
    SetKletka(desk, PosFig->column, PosFig->line, PosFig->fig);
  }
}

void StartPosition(unsigned int desk[8]) {
  for (int i = 0; i < 8; i++) {
    char pf[3]; pf[0] = 'P'; pf[2] = '2'; pf[1] = 'a' + i;
    SetFigures(pf, 1, desk);
  }
  for (int i = 0; i < 8; i++) {
    char pf[3]; pf[0] = 'p'; pf[2] = '7'; pf[1] = 'a' + i;
    SetFigures(pf, 1, desk);
  }
  SetFigures("Ra1Rh1ra8rh8Nb1Ng1nb8ng8Bc1Bf1bc8bf8Qd1qd8Ke1ke8", 16, desk);
}

void PrintDesk(unsigned int desk[8]) {
  for (int i = 8; i > 0; i--) {
    for (int j = 1; j < 9; j++) {
      unsigned int t = GetKletka(desk, j, i);
      printf("|%c| ", figures[t]);
    }
    printf("\n");
  }
}
