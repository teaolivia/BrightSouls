/* Nama/ NIM		:
 * Nama file		: 
 * Topik			: 
 * Tanggal			: 
 * Deskripsi		:
*/

#ifndef LISTREKURSIF_H
#define LISTREKURSIF_H
#include "boolean.h"

/* ListRek rekursif direpresentasi dengan pointer */
#define Nil NULL
typedef char infotypeListRek;
typedef struct tElmtListRekursif* address;
/* modul listrek untuk menyimpan skill dalam pohon */

typedef struct tElmtListRekursif {
	infotypeListRek 	info;
	address		next;
} ElmtListRek;

typedef address ListRek;


#define First(L) L
#define Info(P) (P)->info
#define Next(P) (P)->next 



/** Manajemen Memori **/
address Alokasi (infotypeListRek X);
/*	Mengirimkan address hasil alokasi sebuah elemen
	Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P,
	maka Info(P) = X, Next(P) = Nil
	Jika alokasi gagal, mengirimkan Nil
*/

void Dealokasi (address *P);
/* 	I.S. P terdefinisi
	F.S. P dikembalikan ke sistem
	Melakukan dealokasi/pengembalian address P
*/

/** Primitif-primitif yang harus direalisasikan **/
/** Selektor **/
infotypeListRek FirstElmt (ListRek L);
/*	Mengirimkan elemen pertama sebuah ListRek L yang tidak kosong */

ListRek Tail (ListRek L);
/* Mengirimkan ListRek L yang tidak kosong tanpa elemen pertamanya */

/** Konstruktor **/
ListRek Konso (infotypeListRek e, ListRek L);
/* 	Mengirimkan ListRek L dengan tambahan e sebagai elemen pertamanya
	e harus dialokasi terlebih dahulu
	Jika alokasi e gagal, mengirimkan L
*/
ListRek Konsdot (ListRek L, infotypeListRek e);
/* 	Mengirimkan ListRek L dengan tambahan e sebagai elemen terakhir
	e harus dialokasi terlebih dahulu
	Jika alokasi e gagal, mengirimkan L
*/

/** Predikat **/
boolean IsSkillListEmpty (ListRek L);
/* 	Mengirimkan true jika ListRek kosong, false jika tidak kosong
	Mungkin yang dikirimkan adalah sebuah ListRek kosong
*/

/** Operasi Lain **/
ListRek Copy (ListRek L);
/* 	Mengirimkan salinan ListRek L (menjadi ListRek baru)
	Jika ada alokasi gagal, mengirimkan L
*/

ListRek Concat (ListRek L1, ListRek L2);
/*	Mengirimkan salinan hasil konkatenasi ListRek L1 dan L2 (menjadi ListRek baru)
	Jika ada alokasi gagal, menghasilkan Nil
*/

void PrintSkillList (ListRek L);
/*	I.S. L terdefinisi. 
	F.S. Setiap elemen ListRek dicetak.
	Format mencetak: "el1, el2, el3" (no trailing space - ingat berikan newline pada akhir)
	Jika ListRek kosong, tidak perlu mencetak apapun
*/

int NBElmtSkillList (ListRek L);
/*	Mengirimkan banyaknya elemen ListRek L, Nol jika L kosong */

boolean Search (ListRek L, infotypeListRek X);
/*	Mengirim true jika X adalah anggota ListRek, false jika tidak 
	L boleh kosong
*/


#endif
