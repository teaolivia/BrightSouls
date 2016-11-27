/* Nama/ NIM		: 
 * Nama file		: 
 * Topik			: 
 * Tanggal			: 
 * Deskripsi		: 
*/

#include "listrekursif.h"
#include "allDataType.h"
#include <stdio.h>
#include <stdlib.h>

/** Manajemen Memori **/
address Alokasi (infotypeListRek X) {
/*	Mengirimkan address hasil alokasi sebuah elemen
	Jika alokasi berhasil, maka address tidak Nil, dan misalnya menghasilkan P,
	maka Info(P) = X, Next(P) = Nil
	Jika alokasi gagal, mengirimkan Nil
*/
	//Kamus Lokal
	address	P;
	//Algoritma
	P = (address) malloc (sizeof(ElmtSkillList));
	if (P!=Nil) {
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}

void Dealokasi (address *P) {
/* 	I.S. P terdefinisi
	F.S. P dikembalikan ke sistem
	Melakukan dealokasi/pengembalian address P
*/
	free(*P);
}

/** Primitif-primitif yang harus direalisasikan **/
/** Selektor **/
infotypeListRek FirstElmt (ListRek L) {
/*	Mengirimkan elemen pertama sebuah ListRek L yang tidak kosong */
	return Info(L);
}

ListRek Tail (ListRek L) {
/* Mengirimkan ListRek L yang tidak kosong tanpa elemen pertamanya */
	return Next(L);
}

/** Konstruktor **/
ListRek Konso (infotypeListRek e, ListRek L) {
/* 	Mengirimkan ListRek L dengan tambahan e sebagai elemen pertamanya
	e harus dialokasi terlebih dahulu
	Jika alokasi e gagal, mengirimkan L
*/
	//Kamus Lokal
	address	P;
	//Algoritma
	P = Alokasi(e);
	if (P!=Nil) {
		Next(P) = L;
		L = P;
	}
	return L;
}

ListRek Konsdot (ListRek L, infotypeListRek e) {
/* 	Mengirimkan ListRek L dengan tambahan e sebagai elemen terakhir
	e harus dialokasi terlebih dahulu
	Jika alokasi e gagal, mengirimkan L
*/
	//Kamus Lokal
	address	P;
	//Algoritma
	if (IsSkillListEmpty(L)) {
		P = Alokasi(e);
		if (P!=Nil) {
			return P;
		}
		else return L;
	}
	else {
		Next(L) = Konsdot(Tail(L),e);
		return L;
	}
}

/** Predikat **/
boolean IsSkillListEmpty (ListRek L) {
/* 	Mengirimkan true jika ListRek kosong, false jika tidak kosong
	Mungkin yang dikirimkan adalah sebuah ListRek kosong
*/
	return (L == Nil);
}

/** Operasi Lain **/
ListRek Copy (ListRek L) {
/* 	Mengirimkan salinan ListRek L (menjadi ListRek baru)
	Jika ada alokasi gagal, mengirimkan L
*/
	//Kamus Lokal
	address	P;
	ListRek	L_cpy=Nil;
	//Algoritma
	if (IsSkillListEmpty(L)) {
		return L;
	}
	else {
		P = Alokasi (FirstElmt(L));
		if (P!=Nil) {
			L_cpy = P;
			Next(L_cpy) = Copy(Tail(L));
		}
		return L_cpy;
	}
}

ListRek Concat (ListRek L1, ListRek L2) {
/*	Mengirimkan salinan hasil konkatenasi ListRek L1 dan L2 (menjadi ListRek baru)
	Jika ada alokasi gagal, menghasilkan Nil
*/
	//Kamus Lokal
	ListRek	L_cpy=Nil;
	address	P;
	//Algoritma
	if (IsSkillListEmpty(L1)) {
		return Copy(L2);
	} 
	else {
		P = Alokasi (FirstElmt(L1));
		if (P!=Nil) {
			L_cpy = P;
			Next(L_cpy) = Concat(Tail(L1),L2);
		}
		return L_cpy;
	}
}

void PrintSkillList (ListRek L) {
/*	I.S. L terdefinisi. 
	F.S. Setiap elemen ListRek dicetak.
	Format mencetak: "el1, el2, el3" (no trailing space - ingat berikan newline pada akhir)
	Jika ListRek kosong, tidak perlu mencetak apapun
*/
	//Algoritma
	if (!IsSkillListEmpty(L)) {
		printf("%d",FirstElmt(L));
		if (Tail(L)!=Nil) printf(", ");
		fflush(stdout);
		PrintSkillList(Tail(L));
	}	
	else printf("\n");
}

int NBElmtSkillList (ListRek L) {
/*	Mengirimkan banyaknya elemen ListRek L, Nol jika L kosong */
	//Algoritma
	if (IsSkillListEmpty(L)) {
		return 0;
	}
	else {
		return 1 + NBElmtSkillList(Tail(L));
	}
}

boolean Search (ListRek L, infotypeListRek X) {
/*	Mengirim true jika X adalah anggota ListRek, false jika tidak */
	//Algoritma
	if (IsSkillListEmpty(L)) {
		return false;
	}
	else {
		if (FirstElmt(L)==X) {
			return true;
		}
		else return Search(Tail(L),X);
	}
}

