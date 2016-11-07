#ifndef __MAP_H__
#define __MAP_H__

#include <stdio.h>
#include "mesinkata.h"
#include "mesinkar.h"
#include "matriks.h"

typedef struct {
	MATRIKS TabMap[NMax]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
    int JumlahMap;
} AllMap;


/* *** Selektor *** */
#define JmlhMap(map) (map).JumlahMap

void BacaMap(AllMap *map, char text[100]);
/* Membaca file eksternal text dan memasukkannya ke dalam *map */

#endif
