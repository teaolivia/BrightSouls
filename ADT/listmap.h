#ifndef listmap_H
#define listmap_H

#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>
#include "map.h"
#include "allDataType.h"

/* Definisi list : */
/* ListMap kosong : FirstMap(L) = Nil */
/* Setiap elemen dengan addrMap P dapat diacu Info(P), RightMap(P) */
/* Elemen terakhir list : jika addressnya Last, maka RightMap(Last)=Nil */

boolean IsEmptyListMap (ListMap L);
/* Mengirim true jika list kosong */

void CreateEmptyListMap (ListMap *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

addrMap AlokasiMap (MATRIKS X, char namaMap, monster M);
/* Mengirimkan addrMap hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrMap tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, RightMap(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void DealokasiListMap (addrMap P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrMap P */

//addrMap SearchListMap (ListMap L, char nama_map);
/* Mencari apakah ada elemen list dengan NamaMap(P) = nama_map */
/* Jika ada, mengirimkan addrMap elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

void InsVLastListMap (ListMap *L, MATRIKS X, char namaMap, monster M);
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void InsertLastListMap (ListMap *L, addrMap P);
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

void InsertAfterListMap (ListMap *L, addrMap P, addrMap Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

//int NbElmtListMap (ListMap L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

addrMap SearchMap(char nama_map, ListMap L);

#endif
