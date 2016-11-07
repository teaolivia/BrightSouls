/* File : queuelist.c */
/* Representasi queue dengan list berkait dengan first (HEAD) dan last (TAIL) */

#include <stdlib.h>
#include "queuelist.h"

/* Prototype manajemen memori */
void AlokasiQueue (addressQueue *P, infotypeQueue X)
/* I.S. Sembarang */
/* F.S. Alamat P dialokasi, jika berhasil maka Info(P)=X dan 
        Next(P)=Nil */
/*      P=Nil jika alokasi gagal */
{	/* ALGORITMA */
	*P = (addressQueue) malloc (sizeof(ElmtQueue));
	if (*P!=Nil)
	{	InfoQueue(*P)=X;
		NextQueue(*P)=Nil;
	}
}
void DealokasiQueue (addressQueue  P)
/* I.S. P adalah hasil alokasi, P != Nil */
/* F.S. Alamat P didealokasi, dikembalikan ke sistem */
{	/* ALGORITMA */
	free(P);
}
boolean IsEmptyQueue (Queue Q)
/* Mengirim true jika Q kosong: HEAD(Q)=Nil and TAIL(Q)=Nil */
{	/* ALGORITMA */
	return((Head(Q)==Nil) && (Tail(Q)==Nil));
}
int NbElmtQueue(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{	/* KAMUS */
	int count;
	addressQueue P;
	/* ALGORITMA */
	count=0;
	P=Head(Q);
	while (P!=Tail(Q))
	{	count++;
		P=NextQueue(P);
	}
	if (P!=Nil)
		count++;
	return(count);
}
/*** Kreator ***/
void CreateQueue(Queue * Q)
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk */
{	/* ALGORITMA */
	Head(*Q)=Nil;
	Tail(*Q)=Nil;
}
/*** Primitif Add/Delete ***/
void AddQueue (Queue * Q, infotypeQueue X)
/* Proses: Mengalokasi X dan menambahkan X pada bagian TAIL dari Q
   jika alokasi berhasil; jika alokasi gagal Q tetap */
/* Pada dasarnya adalah proses insert last */
/* I.S. Q mungkin kosong */
/* F.S. X menjadi TAIL, TAIL "maju" */
{	/* KAMUS */
	addressQueue P;
	/* ALGORITMA */
	AlokasiQueue(&P,X);
	if (P!=Nil);
	{	if (IsEmptyQueue(*Q))
			Head(*Q)=P;
		else
			NextQueue(Tail(*Q))=P;
		Tail(*Q)=P;
	}
}
void DelQueue(Queue * Q, infotypeQueue * X)
/* Proses: Menghapus X pada bagian HEAD dari Q dan mendealokasi
   elemen HEAD */
/* Pada dasarnya operasi delete first */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "mundur" */
{	/* KAMUS */
	addressQueue P;
	/* ALGORITMA */
	*X=InfoHead(*Q);
	P=Head(*Q);
	Head(*Q)=NextQueue(Head(*Q));
	if (Head(*Q)==Nil)
		Tail(*Q)=Nil;
	NextQueue(P)=Nil;
	DealokasiQueue(P);
	
}