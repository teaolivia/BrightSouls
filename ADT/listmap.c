#include "listmap.h"

/* PROTOTYPE */
/****************** TEST ListMap KOSONG ******************/
boolean IsEmptyListMap (ListMap L){
/* Mengirim true jika ListMap kosong */
	return (FirstMap(L) == Nil);
}

/****************** PEMBUATAN ListMap KOSONG ******************/
void CreateEmptyListMap (ListMap *L){
/* I.S. sembarang             */
/* F.S. Terbentuk ListMap kosong */
	FirstMap(*L) = Nil;
}

/****************** Manajemen Memori ******************/
addrMap AlokasiMap (MATRIKS X, char namaMap, monster M){
/* Mengirimkan addrMap hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrMap tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, RightMap(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
	addrMap P = (addrMap) malloc (sizeof(ElmtListMap));
	if (P != NULL){
		InfoMap(P) = X;
		InfoNamaMap(P) = namaMap;
		InfoMonsterMap(P) = M;
		NextMap(P) = Nil;
		return P;
	}
	else return Nil;
}

void DealokasiListMap (addrMap P){
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrMap P */
	free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN ListMap ******************/
/*addrMap SearchListMapMap (ListMapMap L, char nama_map){
	addrMap p;
	p = FirstMap(L);
	while ((p != Nil) && (NamaMap(p) != nama_map)) {
		p = RightMap(p);
	}
	return p;
}*/

void InsVLastListMap (ListMap *L, MATRIKS X, char namaMap, monster M){
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen ListMap di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
	addrMap p;
	p = AlokasiMap(X, namaMap, M);
	if (p!=Nil){
		InsertLastListMap(L,p);
	}
}

void InsertLastListMap (ListMap *L, addrMap P){
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
	addrMap point;
	if (IsEmptyListMap(*L)){
		FirstMap(*L) = P;
		NextMap(P) = Nil;
	}
	else {
		point = FirstMap (*L);
		while (NextMap(point) != Nil){
			point = NextMap(point);
		}
		InsertAfterListMap(L,P,point);
	}
}

void InsertAfterListMap (ListMap *L, addrMap P, addrMap Prec){
/* I.S. Prec pastilah elemen ListMap dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
	NextMap(P) = NextMap(Prec);
	NextMap(Prec) = P;
}

addrMap SearchMap(char nama_map, ListMap L) {
	boolean found = false;
	addrMap P;
	P = FirstMap(L);
	if (InfoNamaMap(P) == nama_map) {
		found = true;
	}
	P = NextMap(P);
	while ((P != FirstMap(L)) && !found) {
		if (InfoNamaMap(P) == nama_map) {
			found = true;
		} else {
			P = NextMap(P);
		}
	}
	
	if (found == false) {
		return Nil;
	}
	
}

/*int NbElmtListMapMap (ListMapMap L){
/* Mengirimkan banyaknya elemen ListMap; mengirimkan 0 jika ListMap kosong */
/*	int i;
	if(IsEmptyListMapMap(L)){
		i = 0;
	}
	else{
		addrMap o = FirstMap(L);
		i = 0;
		while (o!=Nil){
			i++;
			o = RightMap(o);
		}
	}
	return i;
}*/
