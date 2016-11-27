#ifndef __ALLDATATYPE_H_
#define __ALLDATATYPE_H_

#include "listrekursif.h"

#define Nil NULL

#define BrsMin 1
#define BrsMax 100
#define KolMin 1
#define KolMax 100

#define IdxMaxArray 20
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMinArray 1
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/

typedef int indeks; /* indeks baris, kolom */
typedef char ElType; 
typedef int IdxTypeArray;  /* type indeks */
typedef char infotypeQueue;
typedef struct tElmtlistmap *addrMap;
typedef struct tElmtQueue * addressQueue;
typedef struct tElmtStack * addressStack;
typedef struct tNode *addrNode;

typedef struct { 
	ElType Mem[BrsMax][KolMax];
    int NBrsEff; /* banyaknya/ukuran baris yg terdefinisi */
	int NKolEff; /* banyaknya/ukuran kolom yg terdefinisi */
} MATRIKS;

typedef struct { 
	int X; /* absis   */
	int Y; /* ordinat */
} POINT;


/* Queue dengan representasi berkait dengan pointer */

typedef struct tElmtQueue { 
	infotypeQueue InfoQueue;
	addressQueue NextQueue; 
} ElmtQueue; 

/* Type queue dengan ciri HEAD dan TAIL : */
typedef struct { 
	addressQueue HEAD;  /* alamat penghapusan */
	addressQueue TAIL;  /* alamat penambahan */
} Queue;

typedef Queue ElTypeArray;   /* type elemen tabel */
typedef Queue infotypeStack;

/* Stack dengan representasi berkait dengan pointer */
typedef struct tElmtStack { 
	infotypeStack InfoStack;
	addressStack NextStack; 
} ElmtStack; 

/* Type stack dengan ciri TOP : */
typedef struct { 
	addressStack TOP;  /* alamat TOP: elemen puncak */
} Stack;

/* Definisi elemen dan koleksi objek */

typedef struct { 
	ElTypeArray TI[IdxMaxArray+1]; /* memori tempat penyimpan elemen (container) */
	int NeffArray; /* >=0, banyaknya elemen efektif */
} Tab;

/* *** Definisi Type Pohon Biner *** */
typedef struct tNode { 
	infotypeListRek info;
	addrNode left;
	addrNode right;
} Node;
/* type infotype sesuai pada modul listrek */

/* Definisi PohonBiner : */
/* Pohon Biner kosong : P = Nil */
typedef addrNode BinTree;



/* **************** DEFINISI VARIABEL BRIGHT SOULS ****************** */

typedef struct {
	addrMap FirstMap;
} ListMap;

typedef struct {
	int hp;
	int str;
	int def;
	int exp;
	int level;
	char name[10];
} statMonster;

typedef struct {
	statMonster Mon[10];
	statMonster boss;
} monster;

typedef struct {
	int hp;
	int str;
	int def;
	int exp;
	int level;
} statHero;

typedef struct {
	char name[20]; // ini tempat simpen nama hero yg kita input
	statHero status[10];
	boolean isiNama;
} hero;

typedef struct {
	char name[20];	
	char nama_map;
	float expPct;
	statHero status;
	POINT coor;
	MATRIKS map;
	addrMap pointTo;
	monster enemy;
} currHero;

typedef struct {
	char name[10];
	Tab TabMove;
} statMovement;

typedef struct {
	statMovement mov[10];
} movement;

typedef struct tElmtlistmap { 
	MATRIKS info;
	char nama_map;
	monster monsterCurrMap;
	addrMap right;
	addrMap left;
	addrMap up;
	addrMap down;
	addrMap next;
	addrMap prev;
} ElmtListMap;

#define FirstMap(L) ((L).FirstMap)
#define InfoMap(P) (P)->info
#define InfoNamaMap(P) (P)->nama_map
#define InfoMonsterMap(P) (P)->monsterCurrMap
#define RightMap(P) (P)->right
#define LeftMap(P) (P)->left
#define UpMap(P) (P)->up
#define DownMap(P) (P)->down
#define NextMap(P) (P)->next
#define PrevMap(P) (P)->prev

#define NeffArray(T)   (T).NeffArray
#define Tab(T)     (T).TI
#define ElmtArray(T,i) (T).TI[(i)]

#define Top(S) (S).TOP
#define InfoTop(S) (S).TOP->InfoStack
#define NextStack(P) (P)->NextStack
#define InfoStack(P) (P)->InfoStack

#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).HEAD->InfoQueue
#define InfoTail(Q) (Q).TAIL->InfoQueue
#define NextQueue(P) (P)->NextQueue
#define InfoQueue(P) (P)->InfoQueue

#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define ElmtMat(M,i,j) (M).Mem[(i)][(j)]

#define First(L) L
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Akar(P) (P)->info
#define Left(P) (P)->left
#define Right(P) (P)->right

#endif

