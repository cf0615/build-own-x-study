#ifndef DEFS_H
#define DEFS_H

typedef unsigned long long U64;

#define NAME "VICE 1.0"
#define BRD_SQ_NUM 120

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

//board structure
typedef struct{

    int pieces[BRD_SQ_NUM]; //board squares

    U64 pawns[3]; //pawns bitboard for white, black and both
    int kingSq[2]; //king square for white and black

    int side; //side to move
    int enPas; //en passant flag
    int fiftyMove; //fifty move rule counter

    int ply;
    int hisPly;

    U64 posKey; //position key

    int pceNum[13]; //number of pieces of each type
    int bigPce[3]; //number of big pieces (non-pawns) for white, black and both
    int majPce[3]; //number of major pieces (rooks and queens) for white, black and both
    int minPce[3]; //number of minor pieces (bishops and knights) for white, black and both

} S_BOARD;

#endif /* DEFS_H */