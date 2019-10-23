
// BODY ADT BUILDING

#include "boolean.h"
#include "../include/building.h"

/* ********* Prototype ********* */
boolean IsOwned (BUILDING B)
/* Mengembalikan true jika B dimiliki oleh suatu pemain */
{   //Kamus lokal
    //Algoritma
    return (Owner(B) != 0);
}

boolean IsTroopFull (BUILDING B)
/* Mengembalikan true jika jumlah pasukan sudah sama dengan M */
{   //Kamus lokal
    //Algoritma
    return (Troop(B)==M(B));
}

/* *** Konstruktor *** */
void InitGame (BUILDING * B, int X, char K)
/* I. S. BUILDING B sembarang */
/* F. S. BUILDING B terdefinisi dengan Owner X dan jenis K seperti level 1 */
{   //Kamus lokal
    //Algoritma
    Owner(*B) = X;
    Troop(*B) = U(*B);
    Level(*B) = 1;
    if (Kind(*B) == 'C'){
        A(*B) = 10;
        M(*B) = 40;
        P(*B) = false;
        U(*B) = 40;
    } 
    else if (Kind(*B) == 'T'){
        A(*B) = 5;
        M(*B) = 20;
        P(*B) = true;
        U(*B) = 30;
    } 
    else if (Kind(*B) == 'F'){
        A(*B) = 10;
        M(*B) = 20;
        P(*B) = false;
        U(*B) = 80;
    } 
    else if (Kind(*B) == 'V'){
        A(*B) = 5;
        M(*B) = 20;
        P(*B) = false;
        U(*B) = 20;
    } 
}

/* *** Fungsi Lain *** */
void InitTurn (BUILDING * B)
/* I. S. BUILDING B terdefinisi */
/* F. S. BUILDING B akan bertambah pasukannya sebanyak A pada awal giliran */
/* Penambahan tidak dilakukan jika pasukan sudah lebih dari atau sama dengan M */
/* Penambahan disesuaikan dengan jenis BUILDING */
{   //Kamus lokal
    int M;
    //Algoritma
    M = M(*B);
    if ((Kind(*B)=='C') && (Troop(*B)<M)){
        if (Level(*B)==1){
            Troop(*B) += 10;
        }
        else if (Level(*B)==2){
            Troop(*B) += 15;
        }
        else if (Level(*B)==3){
            Troop(*B) += 20;
        }
        else if (Level(*B)==4){
            Troop(*B) += 25;
        }
    }
    else if ((Kind(*B)=='T') && (Troop(*B)<M)){
        if (Level(*B)==1){
            Troop(*B) += 5;
        }
        else if (Level(*B)==2){
            Troop(*B) += 10;
        }
        else if (Level(*B)==3){
            Troop(*B) += 20;
        }
        else if (Level(*B)==4){
            Troop(*B) += 30;
        }
    }
    else if ((Kind(*B)=='F') && (Troop(*B)<M)){
        if (Level(*B)==1){
            Troop(*B) += 10;
        }
        else if (Level(*B)==2){
            Troop(*B) += 20;
        }
        else if (Level(*B)==3){
            Troop(*B) += 30;
        }
        else if (Level(*B)==4){
            Troop(*B) += 40;
        }
    }
    else if ((Kind(*B)=='V') && (Troop(*B)<M)){
        if (Level(*B)==1){
            Troop(*B) += 5;
        }
        else if (Level(*B)==2){
            Troop(*B) += 10;
        }
        else if (Level(*B)==3){
            Troop(*B) += 15;
        }
        else if (Level(*B)==4){
            Troop(*B) += 20;
        }
    }
}

void LevelUp (BUILDING * B)
/* I. S. BUILDING B terdefinisi dan tidak level 4 */
/* F. S. BUILDING B levelnya naik */
/* Deskripsi level (sesui jenis building) ada di spek tubes */
/* untuk naik level harus ada minimal pasukan sebanyak M/2 untuk dikurangi sebagai ganti naik level */
{   //Kamus lokal
    int M;
    //Algoritma
    M = M(*B);
    if (Troop(*B)>=M/2){
        if (Kind(*B)=='C'){
            if (Level(*B)==1){
                A(*B) = 15;
                M(*B) = 60;
                P(*B) = false;
                Level(*B)++;
                Troop(*B) -= M/2;
            }
            else if (Level(*B)==2){
                A(*B) = 20;
                M(*B) = 80;
                P(*B) = false;
                Level(*B)++;
                Troop(*B) -= M/2;
            }
            else if (Level(*B)==3){
                A(*B) = 25;
                M(*B) = 100;
                P(*B) = false;
                Level(*B)++; 
                Troop(*B) -= M/2;
            }
        }
        else if (Kind(*B)=='T'){
            if (Level(*B)==1){
                A(*B) = 10;
                M(*B) = 30;
                P(*B) = true;
                Level(*B)++;
                Troop(*B) -= M/2;
            }
            else if (Level(*B)==2){
                A(*B) = 20;
                M(*B) = 40;
                P(*B) = true;
                Level(*B)++;
                Troop(*B) -= M/2; 
            }
            else if (Level(*B)==3){
                A(*B) = 30;
                M(*B) = 50;
                P(*B) = true;
                Level(*B)++; 
                Troop(*B) -= M/2; 
            }
        }
        else if (Kind(*B)=='F'){
            if (Level(*B)==1){
                A(*B) = 20;
                M(*B) = 40;
                P(*B) = false;
                Level(*B)++; 
                Troop(*B) -= M/2;
            }
            else if (Level(*B)==2){
                A(*B) = 30;
                M(*B) = 60;
                P(*B) = true;
                Level(*B)++;
                Troop(*B) -= M/2;
            }
            else if (Level(*B)==3){
                A(*B) = 40;
                M(*B) = 80;
                P(*B) = true;
                Level(*B)++; 
                Troop(*B) -= M/2;
            }
        }
        else if (Kind(*B)=='V'){
            if (Level(*B)==1){
                A(*B) = 10;
                M(*B) = 30;
                P(*B) = false;
                Level(*B)++; 
                Troop(*B) -= M/2;
            }
            else if (Level(*B)==2){
                A(*B) = 15;
                M(*B) = 40;
                P(*B) = false;
                Level(*B)++; 
                Troop(*B) -= M/2;
            }
            else if (Level(*B)==3){
                A(*B) = 20;
                M(*B) = 50;
                P(*B) = false;
                Level(*B)++; 
                Troop(*B) -= M/2; 
            }
        }
    }
}