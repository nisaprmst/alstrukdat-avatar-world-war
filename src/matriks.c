/* 
Nama	: Annisa Ayu Pramesti
NIM 	: 13518085
Tanggal	: 19 September 2019
Topik	: Matriks
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "matriks.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
{
    NBrsEff(*M) = NB;
    NKolEff(*M) = NK;
}

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */
{
    return ((i >= BrsMin && i <= BrsMax) && (j >= KolMin && j <= KolMax));
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terkecil M */ 
{
    return BrsMin;
}
indeks GetFirstIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terkecil M */
{
    return KolMin;
}
indeks GetLastIdxBrs (MATRIKS M)
/* Mengirimkan indeks baris terbesar M */
{
    return BrsMin + NBrsEff(M) - 1;
}
indeks GetLastIdxKol (MATRIKS M)
/* Mengirimkan indeks kolom terbesar M */
{
    return KolMin + NKolEff(M) - 1;
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
{
    return ((i >= GetFirstIdxBrs(M) && i <= GetLastIdxBrs(M)) && (j >= GetFirstIdxKol(M) && j <= GetLastIdxKol(M)));
}
ElType GetElmtDiagonal (MATRIKS M, indeks i)
/* Mengirimkan elemen M(i,i) */
{
    return Elmt(M, i, i);
}

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
/* Melakukan assignment MHsl  MIn */
{
    indeks i, j;
    NBrsEff(*MHsl) = NBrsEff(MIn);
    NKolEff(*MHsl) = NKolEff(MIn);
    for (i = GetFirstIdxBrs(MIn); i <= GetLastIdxBrs(MIn); i++) {
        for (j = GetFirstIdxKol(MIn); j <= GetLastIdxKol(MIn); j++) {
            Elmt(*MHsl, i, j) = Elmt(MIn, i, j);
        }
    }
}

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
{
    indeks i, j;
    MakeMATRIKS(NB, NK, M);
    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
        for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
            scanf("%d", &Elmt(*M, i, j));
        }
    }
}
void TulisMATRIKS (MATRIKS M)
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/
{
    indeks i, j;
    for (i = GetFirstIdxBrs(M); i < GetLastIdxBrs(M); i++) {
        for (j = GetFirstIdxKol(M); j < GetLastIdxKol(M); j++) {
            printf("%d ", Elmt(M, i, j));
        }
        printf("%d\n", Elmt(M, i, GetLastIdxKol(M)));
    }
    for (j = GetFirstIdxKol(M); j < GetLastIdxKol(M); j++) {
        printf("%d ", Elmt(M, GetLastIdxBrs(M), j));
    }
    printf("%d", Elmt(M, GetLastIdxBrs(M), GetLastIdxKol(M)));
}

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
{
    MATRIKS M;
    indeks i, j;
    for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
        for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) {
            Elmt(M, i, j) = Elmt(M1, i, j) + Elmt(M2, i, j);
        }
    }
    NBrsEff(M) = NBrsEff(M1);
    NKolEff(M) = NKolEff(M1);
    return M;
}
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
{
    MATRIKS M;
    indeks i, j;
    for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
        for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) {
            Elmt(M, i, j) = Elmt(M1, i, j) - Elmt(M2, i, j);
        }
    }
    NBrsEff(M) = NBrsEff(M1);
    NKolEff(M) = NKolEff(M1);
    return M;
}
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
{
    indeks i, j, k, l;
    ElType sum;
    MATRIKS M;
    for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
        for (j = GetFirstIdxKol(M2); j <= GetLastIdxKol(M2); j++) {
            sum = 0;
            for (k = GetFirstIdxKol(M1); k <= GetLastIdxKol(M1); k++) {
                for (l = GetFirstIdxBrs(M2); l <= GetLastIdxBrs(M2); l++) {
                    if (k = l) sum += Elmt(M1, i, k) * Elmt(M2, l, j);
                }
            }
            Elmt(M, i, j) =  sum;
        }
    }
    NBrsEff(M) = NBrsEff(M1);
    NKolEff(M) = NKolEff(M2);
    return M;
}
MATRIKS KaliKons (MATRIKS M, ElType X)
/* Mengirim hasil perkalian setiap elemen M dengan X */
{
    MATRIKS res;
    indeks i, j;
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            Elmt(res, i, j) = Elmt(M, i, j) * X;
        }
    }
    NBrsEff(res) = NBrsEff(M);
    NKolEff(res) = NKolEff(M);
    return res;
}
void PKaliKons (MATRIKS * M, ElType K)
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */
{
    indeks i, j;
    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
        for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
            Elmt(*M, i, j) = Elmt(*M, i, j) * K;
        }
    }
}

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */

{
    indeks i = GetFirstIdxBrs(M1);
    indeks j = GetFirstIdxKol(M1);
    if (NBElmt(M1) != NBElmt(M2)) {
        return false;
    } else if (GetFirstIdxBrs(M1) != GetFirstIdxBrs(M2)) {
        return false;
    } else {
        for (i = GetFirstIdxBrs(M1); i <= GetLastIdxBrs(M1); i++) {
            for (j = GetFirstIdxKol(M1); j <= GetLastIdxKol(M1); j++) {
                if (Elmt(M1, i, j) != Elmt(M2, i, j)) {
                    return false;
                }
            }
        }
        return true;
    }
}
boolean NEQ (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika M1 tidak sama dengan M2 */
{
    return !(EQ(M1, M2));
}
boolean EQSize (MATRIKS M1, MATRIKS M2)
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */
{
    return (NBrsEff(M1) == NBrsEff(M2) && NKolEff(M1) == NKolEff(M2));
}

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
/* Mengirimkan banyaknya elemen M */
{
    return (NBrsEff(M) * NKolEff(M));
}

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
{
    return (NBrsEff(M) == NKolEff(M));
}
boolean IsSimetri (MATRIKS M)
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
{
    indeks i, j;
    if (!IsBujurSangkar(M)) {
        return false;
    } else {
        for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
            for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
                if (Elmt(M, i, j) != Elmt(M, j, i)) {
                    return false;
                }
            }
        }
        return true;
    }
}
boolean IsSatuan (MATRIKS M)
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
{
    indeks i, j;
    if (!IsBujurSangkar(M)) {
        return false;
    } else {
        for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
            for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
                if (i == j && Elmt(M, i, j) != 1) {
                    return false;
                }
                else if (i != j && Elmt(M, i, j) != 0) {
                    return false;
                }
                
            }
        }
        return true;
    }
}
boolean IsSparse (MATRIKS M)
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
{
    indeks i, j;
    double count = 0.0;
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            if (Elmt(M, i, j) == 0) count = count + 1.0;
        }
    }
    return (count/NBElmt(M) > 95.0/100);
}
MATRIKS Inverse1 (MATRIKS M)
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
{
    indeks i, j;
    MATRIKS inv;
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
            Elmt(inv, i, j) = Elmt(M, i, j) * (-1);
        }
    }
    NBrsEff(inv) = NBrsEff(M);
    NKolEff(inv) = NKolEff(M);
    return inv;
}
float Determinan (MATRIKS M)
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */ 
{
    float det;
    MATRIKS minor;
    int p;
    indeks i, j, k, idx_kol;
    ElType a11, a12, a21, a22;
    indeks n = NBrsEff(M);
    if (n == 1) { // matriks 1x1
        return Elmt(M, GetFirstIdxBrs(M), GetFirstIdxKol(M));
    } else if (n == 2) { // matriks 2x2
        a11 = Elmt(M, GetFirstIdxBrs(M), GetFirstIdxKol(M));
        a12 = Elmt(M, GetFirstIdxBrs(M), GetLastIdxKol(M));
        a21 = Elmt(M, GetLastIdxBrs(M), GetFirstIdxKol(M));
        a22 = Elmt(M, GetLastIdxBrs(M), GetLastIdxKol(M));
        det=(a11 * a22 - a12 * a21);
        return det;
    } else { // rekursif
        det = 0;
        for (i = GetFirstIdxKol(M); i <= GetLastIdxKol(M); i++) {
            // nyari matriks minornya dulu :"
            for (j = GetFirstIdxBrs(M)+1; j <= GetLastIdxBrs(M); j++) {
                idx_kol = GetFirstIdxBrs(M);
                for (k = GetFirstIdxKol(M); k <= GetLastIdxKol(M); k++) {
                    if (k != i) {
                        Elmt(minor, j-1, idx_kol) = Elmt(M, j, k);
                        idx_kol++;
                    }
                }
            }
            if (GetFirstIdxKol(M)%2 == 0) p = 1; // buat nentuin tanda
            else p = -1;
            NBrsEff(minor) = NBrsEff(M) - 1;
            NKolEff(minor) = NKolEff(M) - 1;
            det += pow((-1.0), i) * p * Elmt(M, GetFirstIdxBrs(M), i) * Determinan(minor);
        }
    }
    return det;
}
void PInverse1 (MATRIKS * M)
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
{
    indeks i, j;
    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxKol(*M); i++) {
        for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
            Elmt(*M, i, j) = Elmt(*M, i, j) * (-1);
        }
    }
}
void Transpose (MATRIKS * M)
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */
{
    indeks i, j;
    MATRIKS temp;
    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
        for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
            Elmt(temp, i, j) = Elmt(*M, j, i);
        }
    }
    for (i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++) {
        for (j = GetFirstIdxKol(*M); j <= GetLastIdxKol(*M); j++) {
            Elmt(*M, i, j) = Elmt(temp, i, j);
        }
    }
}

/* Operasi berbasis baris dan per kolom */

float RataBrs (MATRIKS M, indeks i)
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
{
    indeks j;
    float sum = 0;
    for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
        sum += Elmt(M, i, j);
    }
    return (sum/NKolEff(M));
}

float RataKol (MATRIKS M, indeks j)
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
{
    indeks i;
    float sum = 0;
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        sum += Elmt(M, i, j);
    }
    return (sum/NBrsEff(M));
}

void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
{
    indeks j;
    ElType mx = Elmt(M, i, GetFirstIdxKol(M));
    ElType mn = Elmt(M, i, GetFirstIdxKol(M));

    for (j = GetFirstIdxKol(M) + 1; j <= GetLastIdxKol(M); j++) {
        if (Elmt(M, i, j) > mx) {
            mx = Elmt(M, i, j);
        } 
        if (Elmt(M, i ,j) < mn) {
            mn = Elmt(M, i, j);
        }
    }
    *max = mx;
    *min = mn;

}
void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
{
    indeks i;
    ElType mx = Elmt(M, GetFirstIdxBrs(M), j);
    ElType mn = Elmt(M, GetFirstIdxBrs(M), j);
    for (i = GetFirstIdxBrs(M) + 1; i <= GetLastIdxBrs(M); i++) {
        if (Elmt(M, i, j) > mx) {
            mx = Elmt(M, i, j);
        } 
        if (Elmt(M, i ,j) < mn) {
            mn = Elmt(M, i, j);
        }
    }
    *max = mx;
    *min = mn;
}

int CountXBrs (MATRIKS M, indeks i, ElType X)
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
{
    indeks j;
    int count = 0;
    for (j = GetFirstIdxKol(M); j <= GetLastIdxKol(M); j++) {
        if (Elmt(M, i, j) == X) count++;
    }
    return count;
}

int CountXKol (MATRIKS M, indeks j, ElType X)
/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */
{
    indeks i;
    int count = 0;
    for (i = GetFirstIdxBrs(M); i <= GetLastIdxBrs(M); i++) {
        if (Elmt(M, i, j) == X) count++;
    }
    return count;
}
