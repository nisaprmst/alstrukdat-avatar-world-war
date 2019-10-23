#include "../include/state.h"
#include <stdio.h>
#include "boolean.h"

void PrintDaftarBangunan(PLAYER P){
/*  I. S.   P terdefinisi
    F. S.   Mencetak jenis, posisi, jumlah pasukan, dan level dari tiap bangunan yang dimiliki oleh P */

    // KAMUS LOKAL
    int i;

    // ALGORITMA
    printf("Daftar bangunan:\n");
    // jenis, lokasi, jumlah pasukan, level
    for (i = 1; i <= NbElmt(OwnBuilding(P)); i++) {
        printf("%d. ", i);
        if (Kind(Elmt(OwnBuilding(P), i)) == 'C') {
            printf("Castle ");
        } else if (Kind(Elmt(OwnBuilding(P), i)) == 'T') {
            printf("Tower ");
        } else if (Kind(Elmt(OwnBuilding(P), i)) == 'F') {
            printf("Fort ");
        } else if (Kind(Elmt(OwnBuilding(P), i)) == 'V') {
            printf("Village ");
        }

        // Print POINT (posisi dari bangunan belum ada point di building.h)

        printf("%d ", Troop(Elmt(OwnBuilding(P), i))); // Jumlah Pasukan
        print("lv. %d\n", Level(Elmt(OwnBuilding(P), i)));
    }
}

PLAYER CheckTurn(STATE S){
    /*  Mengembalikan PLAYER yang sedang menjalankan turn, yaitu apabila IsTurn = true */
    // KAMUS LOKAL
    PLAYER P;

    // ALGORITMA
    if (IsTurn(P1(S))) {
        P = P1(S);
    } else {
        P = P2(S);
    }

    return P;
}


void ATTACK(STATE *S){
/*  I. S.   S terdefinisi
    F. S.   PLAYER yang sedang melaksanakan turn melaksanakan ATTACK kepada suatu bangunan
            Jumlah pasukan di masing-masing bangunan yang bersangkutan berkurang
            Kepemilikian bangunan yang diserang mungkin berubah */


}
void LEVEL_UP(STATE *S){}
/*  I. S.   S terdefinisi
    F. S.   Apabila bangunan yang dipilih PLAYER yang sedang melaksanakan turn memiliki jumlah pasukan >= M/2,
            maka level bangunan akan bertambah 1 dan pasukan berkurang sejumlah M/2.
            Apabila bangunan tidak memiliki jumlah pasukan >= M/2, maka akan ditampilkan pesan dan I. S. = F. S. */
    //AKAMUS LOKAL
    PLAYER P;

    // ALGORITMA
    P = CheckTurn(*S);

    if (Troop(P) >= M(B)/2){
        Level(&B)++;
        M(&B) = M(&B) - M(&B)/2;
    } else{
        printf("Jumlah pasukan Castle kurang untuk level up");
    }
}
void MOVE(STATE *S){}
/*  I. S.   S terdefinisi
    F. S.   PLAYER yang menggunakan skill ini memindahkan sejumlah pasukan dari 1 bangunan ke bangunan yang lain
            yang terhubung */

void InstantUpgrade(STATE *S){
/*  I. S.   S terdefinisi
    F. S.   Seluruh bangunan PLAYER yang menggunakan skill ini, seluruh bangunannya akan bertambah 1 level */

    // KAMUS LOKAL
    PLAYER P;
    int i;

    // ALGORITMA
    P = CheckTurn(*S);
    for (i = 1; i <= NbElmt(OwnBuilding(P)); i++) {
        Level(Elmt(OwnBuilding(P), i))++;
    }
}


void Shield(STATE *S){
/*  I. S.   S terdefinisi
    F. S.   Seluruh bangunan PLAYER yang menggunakan skill ini, akan memiliki pertahanan selama 2 turn.
            Apabila digunakan 2 kali berturut-turut, durasi tidak akan bertambah namun akan menjadi nilai maksimum */
    // KAMUS LOKAL
    boolean IsShieldAvailable;
    PLAYER P;
    int countshield;

    // ALGORITMA
    countshield = 0;
    P = CheckTurn(*S);
    IsShieldAvailable = true;
    
    if (P == P2(*S)){;
        countshield++;
        if (countshield == 2){
            IsShieldAvailable = false;
        }
    } else{
        IsShieldAvailable = false;
    }
}
void ExtraTurn(STATE *S){}
/*  I. S.   S terdefinisi
    F. S.   Player yang menggunakan skill ini akan mendapatkan turn tambahan */

void AttackUp(STATE *S){}
/*  I. S.   S terdefinisi
    F. S.   Pada turn ini, bangunan PLAYER lawan yang memiliki pertahanan tidak akan mempengaruhi penyerangan */

void CriticalHit(STATE *S){}
/*  I. S.   S terdefinisi
    F. S.   Setelah skill diaktifkan, jumlah pasukan pada bangunan yang melakukan serangan tepat selanjutnya hanya berkurang
            setengah dari jumlah seharusnya */

void InstantReinforcement(STATE *S){}
/*  I. S.   S terdefinisi
    F. S.   Seluruh bangunan PLAYER yang memiliki skill ini akan mendapat tambahan 5 pasukan */

void Barrage(STATE *S){
/*  I. S.   S terdefinisi
    F. S.   Jumlah pasukan dari bangunan PLAYER lawan akan berkurang sejumlah 10 */

    // KAMUS LOKAL
    PLAYER P;

    // ALGORITMA
    P = CheckTurn(*S);
    
    if (P == P1(*S)){
        Troop(Elmt(OwnBuilding(P1) = Troop(Elmt(OwnBuilding(P1) - 10;
    } else{
        Troop(Elmt(OwnBuilding(P2) = Troop(Elmt(OwnBuilding(P2) - 10;
    }
}