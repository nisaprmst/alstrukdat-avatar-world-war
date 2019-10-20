/* ********** Definisi TYPE BUILDING ********** */

#ifndef BUILDING_H
#define BUILDING_H

#include "boolean.h"

/* Ukuran minimum dan maksimum baris dan kolom */
#define LvlMin 1
#define LvlMax 4
#define TroopsMax 1000000

typedef struct {
    char Kind; /* C untuk castle, T untuk Tower, F untuk Fort, V untuk Village */
    boolean Owner; /* 0 jika tidak dimiliki siapapun, 1 jika pemain 1, 2 jika pemain 2 */
    int Troop; /* banyaknya pasukan yang menempati bangunan, tidak lebih dari TroopsMax */
    int Level; /* menandakan level dari bangunan [1..4] */
    int A; /* penambahan pasukan pada awal giliran */
    int M; /* maksimal penambahan pasukan */
    boolean P; /* true jika bangunan memiliki pertahanan, false jika tidak */
    int U; /* jumlah pasukan awal yang harus dikalahkan untuk menjadikan bangunan ini milik pemain */
} BUILDING;

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */

/* *** Selektor *** */
#define Kind(B) (B).Kind
#define Owner(B) (B).Owner
#define Troop(B) (B).Troop
#define Level(B) (B).Level
#define A(B) (B).A
#define M(B) (B).M
#define P(B) (B).P
#define U(B) (B).U

/* ********* Prototype ********* */
boolean IsOwned (BUILDING B);
/* Mengembalikan true jika B dimiliki oleh suatu pemain */
boolean IsFull (BUILDING B); 
/* Mengembalikan true jika jumlah pasukan sudah sama dengan M */

/* *** Konstruktor *** */
void InitGame (BUILDING * B, int X, char K);
/* I. S. BUILDING B sembarang */
/* F. S. BUILDING B terdefinisi dengan Owner X dan jenis K seperti level 1 */

/* *** Fungsi Lain *** */
void InitTurn (BUILDING * B);
/* I. S. BUILDING B terdefinisi */
/* F. S. BUILDING B akan bertambah pasukannya sebanyak A pada awal giliran */
/* Penambahan tidak dilakukan jika pasukan sudah lebih dari atau sama dengan M */
/* Penambahan disesuaikan dengan jenis BUILDING */
void LevelUp (BUILDING * B);
/* I. S. BUILDING B terdefinisi */
/* F. S. BUILDING B levelnya naik */
/* Deskripsi level (sesui jenis building) ada di spek tubes */
/* untuk naik level harus ada minimal pasukan sebanyak M/2 untuk dikurangi sebagai ganti naik level */



#endif