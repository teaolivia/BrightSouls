/* NIM/Nama		:  13511001/Thea Olivia*/
/* Nama file	:  pohon.h*/
/* Topik		:  ADT Pohon*/
/* Tanggal		:  Selasa, 24 November 2012*/
/* Deskripsi	:  implementasi ADT Pohon */


/* ADT Pohon Biner */

#include <stdio.h>
#include <stdlib.h>

/* Modul lain yang digunakan */
#include "/ADT/header/listrekursif.h"
#include "/ADT/header/mesinkar.h"

#define Nil NULL
#define boolean unsigned char
#define true 1
#define false 0
#define MARK '.'

/* State Mesin */
char CC;
boolean EOP;

//typedef char Infotype
typedef char Infotype;
typedef struct tElmtList *Address;
typedef struct tElmtList {
	Infotype 	info;
	Address		next;
} ElmtList;

typedef Address List;

/*** Definisi Type Pohon Biner ***/
typedef struct tNode *AddressTree;
typedef struct tNode {
	Infotype Info;
	AddressTree Left;
	AddressTree Right;
} Node;
typedef AddressTree BinTree;

/*** Definisi Type List of Node ***/
typedef List ListOfNode;

/*
	BEBERAPA CATATAN
	1. Pohon merupakan pohon biner dengan representasi karakter
	2. pita karakter merupakan stdin (di-supply dari stdin)
*/

void START() {
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca. 
   Karakter pertama yang ada pada pita posisinya adalah pada jendela.
   I.S. : sembarang
   F.S. : CC adalah karakter pertama pada pita. Jika CC != MARK maka 
		  EOP akan padam (false). Jika CC = MARK maka EOP akan menyala (true) */
	ADV();
}

void ADV() {
/* Pita dimajukan satu karakter. 
   I.S. : Karakter pada jendela = CC, CC != MARK
   F.S. : CC adalah karakter berikutnya dari CC yang lama, CC mungkin = MARK
		  Jika  CC = MARK maka EOP akan menyala (true) */
	retval = scanf("%c",&CC);
	EOP = (CC == MARK);
}

/** Manajemen Memori **/
Address Alokasi (Infotype X) {
/*	Mengirimkan Address hasil alokasi sebuah elemen
	Jika alokasi berhasil, maka Address tidak Nil, dan misalnya menghasilkan P,
	maka Info(P) = X, Next(P) = Nil
	Jika alokasi gagal, mengirimkan Nil
*/
	//Kamus Lokal
	Address	P;
	//Algoritma
	P = (Address) malloc (sizeof(ElmtList));
	if (P!=Nil) {
		Info(P) = X;
		Next(P) = Nil;
	}
	return P;
}

void Dealokasi (Address *P) {
/* 	I.S. P terdefinisi
	F.S. P dikembalikan ke sistem
	Melakukan dealokasi/pengembalian Address P
*/
	free(*P);
}

/** Primitif-primitif yang harus direalisasikan **/
/** Selektor **/
Infotype FirstElmt (List L) {
/*	Mengirimkan elemen pertama sebuah list L yang tidak kosong */
	return Info(L);
}

List Tail (List L) {
/* Mengirimkan list L yang tidak kosong tanpa elemen pertamanya */
	return Next(L);
}

/** Konstruktor **/
List Konso (Infotype e, List L) {
/* 	Mengirimkan list L dengan tambahan e sebagai elemen pertamanya
	e harus dialokasi terlebih dahulu
	Jika alokasi e gagal, mengirimkan L
*/
	//Kamus Lokal
	Address	P;
	//Algoritma
	P = Alokasi(e);
	if (P!=Nil) {
		Next(P) = L;
		L = P;
	}
	return L;
}

List Konsdot (List L, Infotype e) {
/* 	Mengirimkan list L dengan tambahan e sebagai elemen terakhir
	e harus dialokasi terlebih dahulu
	Jika alokasi e gagal, mengirimkan L
*/
	//Kamus Lokal
	Address	P;
	//Algoritma
	if (IsListEmpty(L)) {
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
boolean IsListEmpty (List L) {
/* 	Mengirimkan true jika list kosong, false jika tidak kosong
	Mungkin yang dikirimkan adalah sebuah list kosong
*/
	return (L == Nil);
}

/** Operasi Lain **/
List Copy (List L) {
/* 	Mengirimkan salinan list L (menjadi list baru)
	Jika ada alokasi gagal, mengirimkan L
*/
	//Kamus Lokal
	Address	P;
	List	L_cpy=Nil;
	//Algoritma
	if (IsListEmpty(L)) {
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

List Concat (List L1, List L2) {
/*	Mengirimkan salinan hasil konkatenasi list L1 dan L2 (menjadi list baru)
	Jika ada alokasi gagal, menghasilkan Nil
*/
	//Kamus Lokal
	List	L_cpy=Nil;
	Address	P;
	//Algoritma
	if (IsListEmpty(L1)) {
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

void Printlist (List L) {
/*	I.S. L terdefinisi. 
	F.S. Setiap elemen list dicetak.
	Format mencetak: "el1, el2, el3" (no trailing space - ingat berikan newline pada akhir)
	Jika list kosong, tidak perlu mencetak apapun
*/
	//Algoritma
	if (!IsListEmpty(L)) {
		printf("%d",FirstElmt(L));
		if (Tail(L)!=Nil) printf(", ");
		fflush(stdout);
		Printlist(Tail(L));
	}	
	else printf("\n");
}

int NBElmtList (List L) {
/*	Mengirimkan banyaknya elemen list L, Nol jika L kosong */
	//Algoritma
	if (IsListEmpty(L)) {
		return 0;
	}
	else {
		return 1 + NBElmtList(Tail(L));
	}
}

boolean Search (List L, Infotype X) {
/*	Mengirim true jika X adalah anggota list, false jika tidak */
	//Algoritma
	if (IsListEmpty(L)) {
		return false;
	}
	else {
		if (FirstElmt(L)==X) {
			return true;
		}
		else return Search(Tail(L),X);
	}
}

BinTree Tree (Infotype Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
	// kamus lokal
	BinTree P;
	// algoritma
	Alokasi(P);
	if (P != Nil) {
		Akar(P) = Akar;
		Left(P) = L;
		Right(P) = R;
	} else {
		P = Nil;
	}
	return P;
}

void MakeTree (Infotype Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Sembarang */
/* F.S. Menghasilkan sebuah pohon P */
/* Menghasilkan sebuah pohon biner P dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal */
{
	Alokasi(*P);
	if (*P!=Nil)
	{
		Akar(*P) = Akar;
		Left(*P) = L;
		Right(*P) = R;
	}
	else 
	{
		(*P) = Nil;
	}
}

void BuildTree (BinTree *P)
/* Membentuk sebuah pohon biner P dari pita karakter yang dibaca */
/* I.S. Pita berisi "konstanta" pohon dalam bentuk prefix.
Memori pasti cukup, alokasi pasti berhasil. */
/* F.S. P dibentuk dari ekspresi dalam pita */
{
	//Kamus Lokal
	char Num[256];
	int i;
	//Algoritma
	ADV();
	if(CC==')')
		(*P) = Nil;
	else {
		Alokasi(P);
		for(i=0; i<256; i++)
			Num[i] = 0;
		i = 0;
		while((CC != '(') && (CC != ')')){
			Num[i] = CC;
			ADV();
			i++;
		}
		Akar(*P) = atoi(Num);
		BuildTree(&Left(*P));
		BuildTree(&Right(*P));
	}
	ADV();
}


/*** Predikat-Predikat Penting ***/
boolean IsTreeEmpty (BinTree P)
/* Mengirimkan true jika P adalah pohon biner kosong */
{
	return P==Nil;
}

boolean IsOneElmt (BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1
elemen */
{
	return ((!IsTreeEmpty(P))&&(IsTreeEmpty(Left(P)))&&(IsTreeEmpty(Right(P))));
}

boolean IsUnerLeft (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya
mempunyai subpohon kiri */
{
	return ((Right(P) == Nil) && (Left(P) != Nil));
}

boolean IsUnerRight (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya
mempunyai subpohon kanan */
{
	return ((Right(P) != Nil) && (Left(P) == Nil));
}

boolean IsBiner (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai
subpohon kiri dan subpohon kanan */
{
	return ((Right(P) != Nil) && (Left(P) != Nil));
}


/*** Traversal ***/
void PrintPreorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon
kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). */
/* Contoh: (a (b (d () ()) ()) (c () ())) */
{
	if (P!=Nil){
		printf("%d\n", Akar(P));
		PrintPreorder(Left(P));
		PrintPreorder(Right(P));
	}
}

void PrintInorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder:pohon kiri, akar, dan pohon
kanan. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). */
/* Contoh: (((() d ()) b ()) a (() c ())) */
{
	if (P!=Nil){
		PrintInorder(Left(P));
		printf("%d\n", Akar(P));
		PrintInorder(Right(P));
	}
}

void PrintPostorder (BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan
akar. Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). */
/* Contoh: (((() () d) () b) (() () c) a) */
{
	if (P!=Nil){
		PrintPostorder(Left(P));
		PrintInorder(Right(P));
		printf("%d\n", Akar(P));
	}
}

void PrintTree (BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi */
/* F.S. Semua simpul P sudah ditulis dengan indentasi, Nil diganti dengan '.' */
/* Contoh: h=2
a
  b
    d
        .
        .
    .
  c
    .
    .
*/
{
	if(!IsTreeEmpty(P)){
		printf("%d", Akar(P));
		if(!IsTreeEmpty(Left(P))){
			PrintTree(Left(P), h);
		}
		if(!IsTreeEmpty(Right(P))){
			PrintTree(Right(P),h);
		}
	}
}


/*** Searching ***/
boolean SearchTree (BinTree P, Infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
	if (IsTreeEmpty(P)){
		return false;
	} if (X==Akar(P)){
		return true;
	} else {
		return (SearchTree(Left(P),X) || SearchTree(Right(P),X));
	}
}


/*** Fungsi-Fungsi Lain ***/
int NbElmt (BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
	if (IsTreeEmpty(P)){
		return 0;
	} else {
		return 1+NbElmt(Left(P))+NbElmt(Right(P));
	}
}

int NbDaun (BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
{
	if ((Left(P) == Nil)&&(Right(P)==Nil)){
		return 1;
	}
	else {
		if ((Left(P)!=Nil)&&(Right(P)==Nil)){
			return NbDaun(Left(P));
		}
		else if ((Left(P)==Nil)&&(Right(P)!=Nil)){
			return NbDaun(Right(P));
		}
		else if  ((Left(P)!=Nil)&&(Right(P)!=Nil)){
			return NbDaun(Left(P))+NbDaun(Right(P));
		}
	}
}

boolean IsSkewLeft (BinTree P)
/* Mengirimkan true jika P adalah pohon condong kiri */
{
	if (IsTreeEmpty(P))
		return false;
	else {
		if (IsOneElmt(P)){
			return true;
		}
		else {
			if (IsUnerLeft(P)){
				return IsSkewLeft(Left(P));
			} else {
				return false;
			}
		}
	}
}

boolean IsSkewRight (BinTree P)
/* Mengirimkan true jika P adalah pohon condong kanan */
{
	if (IsTreeEmpty(P))
		return false;
	else {
		if (IsOneElmt(P)){
			return true;
		}
		else {
			if (IsUnerRight(P)){
				return IsSkewRight(Right(P));
			} else {
				return false;
			}
		}
	}

}

int Level (BinTree P, Infotype X)
/* Mengirimkan level dari node X yang merupakan salah satu simpul dari pohon biner
P. Akar(P) level-nya adalah 1. Pohon P tidak kosong. */
{
	if (X==Akar(P)) 
		return 1;
	else {
		if(SearchTree(Left(P),X)){
			return 1+Level(Left(P), X);
		}
		else {
			return 1+Level(Right(P), X);
		}
	}
}

/*** Operasi lain ***/
void AddDaunTerkiri (BinTree *P, Infotype X)
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
{
	BinTree Pk;

	if (IsTreeEmpty(*P)) {
		printf("kosong\n");
		Alokasi(*P);
		if(P == Nil) printf("kosong\n");
		Akar (*P) = X;
	}
	else {
		if (IsTreeEmpty(Left(*P))) {
			Alokasi(&Pk);
			Left(*P) = Pk;
			Akar (Pk) = X;
		}
		else {
			AddDaunTerkiri(&Left(*P), X);
		}
	}
}

void AddDaun (BinTree *P, Infotype X, Infotype Y, boolean Kiri)
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
sebagai anak k@anan X (jika Kiri = false) */
{
	BinTree Pk;
	
	if (X==Akar(*P)) {
		Alokasi(Pk);
		Akar(Pk) = Y;
		if (Kiri) {
			Left(*P) = Pk;
		}
		else {
			Right(*P) = Pk;
		}
	}
	else {
		if (SearchTree(Left(*P), X)) {
			AddDaun(&Left(*P), X, Y, Kiri);
		}
		else {
			AddDaun(&Right(*P),X,Y,Kiri);
		}
	}
}

void DelDaunTerkiri (BinTree *P, Infotype *X)
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
disimpan pada daun terkiri yang dihapus */
{
	if (Left(*P)==Nil) {
		if (Right(*P)==Nil) {
			(*X) = Akar(*P);
			(*P) = Nil;
			free(*P);
		}
		else {
			DelDaunTerkiri(&Right(*P), X);
		}
	}
	else {
		DelDaunTerkiri(&Left(*P), X);
	}
}

void DelDaun (BinTree *P, Infotype X)
/* I.S. P tidak kosong, X adalah salah satu daun */
/* F.S. Semua daun bernilai X dihapus dari P */
{
	if ((X==Akar(*P))&&(IsOneElmt(*P))) {
		free(*P);
	}
	else {
		if (SearchTree(Left(*P), X)) {
			DelDaun(&Left(*P), X);
		}
		if (SearchTree(Right(*P), X)) {
			DelDaun(&Right(*P), X);
		}
	}
}

ListOfNode MakeListDaun (BinTree P)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong : menghasilkan list yang elemennya adalah semua daun
pohon P, jika semua alokasi list berhasil. Menghasilkan list kosong jika ada
alokasi yang gagal. */
{
	ListOfNode L, L1;

	L = Nil; L1= Nil;
	if (IsTreeEmpty(P)) {
		return L;
	}
	else {
		if (IsOneElmt(P)) {
			L = Konso(Akar(P), L1);
			return L;
		}
		else {
			L1 = Concat(MakeListDaun(Left(P)), MakeListDaun(Right(P)));
			return L1;
		}
	}
}

ListOfNode MakeListPreorder (BinTree P)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen
pohon P dengan urutan Preorder, jika semua alokasi berhasil. Menghasilkan list
kosong jika ada alokasi yang gagal. */
{
	ListOfNode L, L1;
	
	L = Nil; L1=Nil;
	if (IsTreeEmpty(P)) {
		return L;
	}
	else {
		L1 = Concat(MakeListPreorder(Left(P)), MakeListPreorder(Right(P)));
		L = Konso (Akar(P), L1);
		return L;
	}
}

ListOfNode MakeListLevel (BinTree P, int N)
/* Jika P adalah pohon kosong, maka menghasilkan list kosong. */
/* Jika P bukan pohon kosong: menghasilkan list yang elemennya adalah semua elemen
pohon P yang levelnya=N, jika semua alokasi berhasil. Menghasilkan list kosong jika
ada alokasi yang gagal. */
{
	List L, L1;
	
	L = Nil;
	if (IsTreeEmpty(P)) {
		return L;
	}
	else {
		if (N==1) {
			L = Konso (Akar(P), L);
			return L;
		}
		else {
			L1 = Concat(MakeListLevel(Left(P), N-1), MakeListLevel(Right(P), N-1));
			return L1;
		}
	}
}


/*** Balanced tree ***/
BinTree BuildBalanceTree (int n)
/* Menghasilkan sebuah balanced tree dengan n node, nilai setiap node dibaca dari input */
/* Contoh (Preorder): (1 (2 (3 () ()) ()) (4 (5 () ()) ())) */
{
	BinTree P;
	int nL, nR;
	Infotype X;
	BinTree R, L;

	if (n==0){
		return Nil;
	}
	else {
		scanf("%s", &X);
		Alokasi(P);
		if (P!=Nil) {
			Akar(P) = X;
			nL = n/2;
			nR = n-nL-1;
			L = BuildBalanceTree(nL);
			R = BuildBalanceTree(nR);
			Left(P) = L;
			Right(P) = R; 
		}
		return P;
	}
}


/*** Binary Search Tree ***/
boolean BSearch (BinTree P, Infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
	if (IsTreeEmpty(P)){
		return false;
	}
	else if (X==Akar(P)){
		return true;
	} else {
		return (BSearch(Left(P),X) || BSearch(Right(P),X));
	}
}

BinTree InsSearch (BinTree P, Infotype X)
/* Menghasilkan sebuah pohon Binary Search Tree P dengan tambahan simpul X. Belum
ada simpul P yang bernilai X. */
{
	BinTree Pout;

	if (IsTreeEmpty(P)){
		MakeTree(X,Nil,Nil,&Pout);
	} else {
		if (X>Akar(P)){
			Pout = InsSearch(Right(P),X);
		}
		else if (X<Akar(P)){
			Pout = InsSearch(Left(P),X);
		}
	}
	return Pout;
}

void DelBtree (BinTree *P, Infotype X)
/* I.S. Pohon P tidak kosong */
/* F.S. Nilai X yang dihapus pasti ada */
/* Sebuah node dengan nilai X dihapus, node di bawahnya menjadi node yang dihapus,
gunakan node yang kiri jika kedua node di bawahnya terdefinisi */
{
	BinTree a;

	if(X<Akar(*P)){
		DelBtree(&Left(*P),X);
	}
	else if (X>Akar(*P)){
		DelBtree(&Right(*P),X);
	}
	else if (X==Akar(*P)){
		a = Tree(Akar(*P), Left(*P), Right(*P));
		if (Right(a) == Nil) {
			(*P) = Left(a);
		}
		else if (Left(a)==Nil){
			(*P) = Right(a);
		}
		else {
			//DelDaun(&Left(a));
			free(&a);
		}
	}
}