/* NIM : 13515064 */
/* Nama : Tasya */
/* Tanggal : 5 September 2016 */
/* Topik Praktikum : Pra-Praktikum 03 */
/* Deskripsi : array.c */ 

/* MODUL TABEL INTEGER */
/* Berisi definisi dan semua primitif pemrosesan tabel integer */
/* Penempatan elemen selalu rapat kiri */
/* Versi I : dengan banyaknya elemen didefinisikan secara eksplisit, 
   memori tabel statik */

#include <stdio.h>
#include "array.h"
#include "boolean.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void CreateEmptyArray (Tab * T)
/* I.S. T sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{	NeffArray(*T) = 0;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtArray (Tab T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
{	return (NeffArray(T));
}

/* *** Daya tampung container *** */
int MaxNbElArray (Tab T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{	return (IdxMaxArray-IdxMinArray+1);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArray (Tab T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{ 	return (NeffArray(T) == 0);
}


/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */

IdxType SearchArray (Tab T, ElTypeArray X)
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Memakai skema search DENGAN boolean Found */
{	IdxType i;
	boolean found;
	i = IdxMinArray;
	found = false;
	if (IsEmptyArray(T)==false) {
		while ((found == false) && (i<=GetLastIdxArray(T))) {
			if (X == ElmtArray(T,i)) {
				found = true;
			}
			else {
				i = i+1;
			}
		}
		if (found) {
			return i;
		}
		else {
			return IdxUndef;
		}
	}
	else {
		return IdxUndef;
	}
}