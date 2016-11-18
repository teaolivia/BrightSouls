/* File : stacklist.c */

#include <stdlib.h>
#include "stacklist.h"

/* Prototype manajemen memori */
void AlokasiStack (addressStack *P, infotypeStack X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{	/* ALGORITMA */
	*P = (addressStack) malloc (sizeof(ElmtStack));
	if (*P!=Nil)
	{	InfoStack(*P)=X;
		NextStack(*P)=Nil;
	}
}
void DealokasiStack (addressStack P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{	/* ALGORITMA */
	free(P);
}

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean IsEmptyStack (Stack S)
/* Mengirim true jika Stack kosong: TOP(S) = Nil */
{	/* ALGORITMA */
	return(Top(S)==Nil);
}
void CreateEmptyStack (Stack * S)
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack S yang kosong */
{	/* ALGORITMA */
	Top(*S)=Nil;
}
void Push (Stack * S, infotypeStack X)
/* Menambahkan X sebagai elemen Stack S */
/* I.S. S mungkin kosong, X terdefinisi */
/* F.S. X menjadi TOP yang baru jika alokasi X berhasil, */
/*      jika tidak, S tetap */
/* Pada dasarnya adalah operasi Insert First pada list linier */
{	/* KAMUS */
	addressStack P;
	/* ALGORITMA */
	AlokasiStack(&P,X);
	if (P!=Nil);
	{	NextStack(P)=Top(*S);
		Top(*S)=P;
	}
}
void Pop (Stack * S, infotypeStack * X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, */
/*      elemen TOP yang lama didealokasi */
/* Pada dasarnya adalah operasi Delete First pada list linier */
{	/* KAMUS */
	addressStack P;
	/* ALGORITMA */
	*X=InfoTop(*S);
	P=Top(*S);
	Top(*S)=NextStack(Top(*S));
	NextStack(P)=Nil;
	DealokasiStack(P);
	
}