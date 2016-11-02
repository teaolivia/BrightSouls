#include "loadfile.h"

void loadEnemy(monster *M, int *jum,char text[100]) {
	STARTKATA(text);
	int i = 1;
	int j, k;
	int temp;
	k = 0;
	(*jum) = 0;
	while (!EndKata) {				
		if (CKata.tanda == BINTANG) {	
			for (k = 0; k < CKata.Length; k++) {
				(*M).Mon[i].name[k] = CKata.TabKata[k];
			}
			 (*M).Mon[i].name[k] = NULL;
			(*jum) = (*jum) + 1;	
			ADVKATA(text);
		} else {
			j = 1;
			while (j <= 5) {
				if (j == 1) {
					(*M).Mon[i].level = CKata.angka;
					j++;
				} else if (j == 2) {
					(*M).Mon[i].hp = CKata.angka;
					j++;					
				} else if (j == 3) {
					(*M).Mon[i].str = CKata.angka;
					j++;				
				} else if (j == 4) {
					(*M).Mon[i].def = CKata.angka;
					j++;					
				} else {
					(*M).Mon[i].exp = CKata.angka;
					j++;
					if (CKata.angka == 999) {
						(*M).boss = (*M).Mon[i];
					}
				}
				ADVKATA(text);
			}
			i++;
		}
	}
}

void loadStatHero(hero *H, int *jum,char text[100]) {
	STARTKATA(text);
	int i = 1;
	int j, k;
	k = 0;
	(*jum) = 0;
	while (!EndKata) {				
		j = 1;
		while (j <= 5) {
			if (j == 1) {
				(*H).status[i].level = CKata.angka;
				j++;
			} else if (j == 2) {
				(*H).status[i].hp = CKata.angka;
				j++;					
			} else if (j == 3) {
				(*H).status[i].str = CKata.angka;
				j++;				
			} else if (j == 4) {
				(*H).status[i].def = CKata.angka;
				j++;					
			} else {
				(*H).status[i].exp = CKata.angka;
				j++;
			}
			ADVKATA(text);
		}
		(*jum) = (*jum) + 1;
		i++;
	}
}

