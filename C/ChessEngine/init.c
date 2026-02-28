#include "defs.h"

int Sq120ToSq64[BRD_SQ_NUM];
int Sq64ToSq120[64];

void InitSq120To64() {
    int file = FILE_A;
    int rank = RANK_1;

    //init 120squares to 65
    for (int i = 0; i < BRD_SQ_NUM; ++i){
        Sq120ToSq64[i] = 65;
    }

    int sq120 = 0;
    int sq64 = 0;

    for (rank = RANK_1; rank <= RANK_8; ++rank){
        for (file = FILE_A; file <= FILE_H; ++file){
            sq120 = FR2SQ(file, rank); //return the correct index for the 120 square board
            Sq120ToSq64[sq120] = sq64; //replace the board index with the 64 square index
            Sq64ToSq120[sq64] = sq120; //init the 64 square index with the correct 120 square index
            sq64++;
        }
    }
}

void AllInit() {
    InitSq120To64();
}