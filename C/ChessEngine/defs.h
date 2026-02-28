#ifndef DEFS_H
#define DEFS_H

#include <stdlib.h>

#define DEBUG

#ifndef DEBUG
#define ASSERT(n)
#else
#define ASSERT(N) if (!(N)) { \
    printf("%s - Failed", #N); \
    printf("On %s ", __DATE__); \
    printf("At %s ", __TIME__); \
    printf("In %s ", __FILE__); \
    printf("At Line %d\n", __LINE__); \
    exit(1);}
#endif

typedef unsigned long long U64;

#define NAME "VICE 1.0"
#define BRD_SQ_NUM 120
#define MAXGAMEMOVES 2048

//piece
enum {EMPTY, wP, wN, wB, wR, wQ, wK, bP, bN, bB, bR, bQ, bK};

//column
enum {FILE_A, FILE_B, FILE_C, FILE_D, FILE_E, FILE_F, FILE_G, FILE_H, FILE_NONE};

//row
enum {RANK_1, RANK_2, RANK_3, RANK_4, RANK_5, RANK_6, RANK_7, RANK_8, RANK_NONE};

//color
enum {WHITE, BLACK, BOTH};

//squares
enum {A1=21, B1, C1, D1, E1, F1, G1, H1,
      A2=31, B2, C2, D2, E2, F2, G2, H2,
      A3=41, B3, C3, D3, E3, F3, G3, H3,
      A4=51, B4, C4, D4, E4, F4, G4, H4,
      A5=61, B5, C5, D5, E5, F5, G5, H5,
      A6=71, B6, C6, D6, E6, F6, G6, H6,
      A7=81, B7, C7, D7, E7, F7, G7, H7,
      A8=91, B8, C8, D8, E8, F8, G8, H8, NO_SQ};

//bool
enum {FALSE, TRUE};

//castling permissions bitwise
enum {WKCA = 1, WQCA = 2, BKCA = 4, BQCA = 8};

//undo structure
typedef struct{
    int move; //move made
    int castlePerm; //castling permissions before the move
    int enPas; //en passant square before the move
    int fiftyMove; //fifty move counter before the move
    U64 posKey; //position key before the move
} S_UNDO;

//board structure
typedef struct{

    int pieces[BRD_SQ_NUM]; //board squares

    U64 pawns[3]; //pawns bitboard for white, black and both
    int kingSq[2]; //king square for white and black

    int side; //side to move
    int enPas; //en passant flag
    int fiftyMove; //fifty move rule counter

    int castlePerm; //castling permissions

    int ply;
    int hisPly;

    U64 posKey; //position key

    int pceNum[13]; //number of pieces of each type
    int bigPce[3]; //number of big pieces (non-pawns) for white, black and both
    int majPce[3]; //number of major pieces (rooks and queens) for white, black and both
    int minPce[3]; //number of minor pieces (bishops and knights) for white, black and both

    S_UNDO history[MAXGAMEMOVES]; //history of moves for undo functionality

    //piece list for each piece type
    int pList[13][10]; //maximum 10 pieces of each type on the board

} S_BOARD;

//macros
#define FR2SQ(f , r) ((21 + (f)) + ((r) * 10))

//global variables
extern int Sq120ToSq64[BRD_SQ_NUM];
extern int Sq64ToSq120[64];

//function
extern void AllInit();

#endif /* DEFS_H */