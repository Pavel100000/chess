#ifndef BITBOARDS_HEADER
#define BITBOARDS_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char figures[16] = {'O', 'R', 'N', 'B', 'Q', 'I', 'K', 'P', 'X', 'p', 'k', 'i', 'q', 'b', 'n', 'r'};

typedef struct {
  unsigned int fig;
  int column;
  int line;
} PosFigure;

static int RookM[8]    = {1, 0, -1, 0, 0, 1, 0, -1};
static int BishopM[8]  = {1, 1, -1, -1, 1, -1, -1, 1};
static int QueenM[16]  = {1, 0, -1, 0, 0, 1, 0, -1, 1, 1, -1, -1, 1, -1, -1, 1};
static int KnightM[16] = {2, 1, 2, -1, 1, 2, 1, -2, -1, 2, -1, -2, -2, 1, -2, -1};

static unsigned int ZeroMassive[8] = {0, 0, 0, 0, 0, 0, 0, 0};

#define isColumn(a) ( ((a >= 97) && (a <= 104) ? 1 : 0)

#define SetBit(A, k)     ( A[(k)/32] |= (1 << (31 - (k)%32)) )
#define ClearBit(A, k)   ( A[(k)/32] &= ~(1 << (31 - (k)%32)) )
#define SetBitChar(A, k)     ( A |= (1 << (7 - (k)%8)) )
#define ClearBitChar(A, k)   ( A &= ~(1 << (7 - (k)%8)) )

unsigned int TestBit(unsigned int A[],  int k);
/*get k bit from desk*/
unsigned char TestBitChar(unsigned char A,  int k );
/*get k bit from unsigned char*/
unsigned int findPos(char arr[], int len, char seek);
/* find pos char element in char massive arr[] */
void BitPrintDesk(unsigned int desk[8]);
/* print desk bits */
unsigned int GetKletka(unsigned int desk[8], unsigned int column, unsigned int line);
/* get value kletki (column, line): 0-15 */
void SetKletka(unsigned int desk[8], unsigned int column, unsigned int line, unsigned int figure);
/* Set kletka (column, line) on desk at value figure (0-15) */
void SimpleDecodNot(char Not[3], PosFigure* PosFig);
/* simple decodind notation (only 3 symbols: "Nf8", "pb3"...) */
void SetFigures(char Nots[], int len, unsigned int desk[8]);
/* set figures on desk ("Kf4rg1Na3") len = 3 (count of figures)*/
void StartPosition(unsigned int desk[8]);
/* set start position on desk */
void PrintDesk(unsigned int desk[8]);
/* print desk */


#endif // !BITBOARDS_HEADER
