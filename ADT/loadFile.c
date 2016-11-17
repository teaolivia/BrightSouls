#include "loadfile.h"

void loadEnemy(monster *M, int *jum,char text[100]) {
	STARTKATA(text);
	
	int i = 1;
	int j, k;
	int temp;
	boolean pemindah = true;
	k = 0;
	(*jum) = 0;
	while (!EndKata) {	
		if (pemindah) {		
			for (k = 0; k < CKata.Length; k++) {
				(*M).Mon[i].name[k] = CKata.TabKata[k];
			}
			 (*M).Mon[i].name[k] = '\0';
			(*jum) = (*jum) + 1;	
			ADVKATA(text);
			pemindah = false;
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
			pemindah = true;
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

void loadBattle(movement *M, char text[100])
{	/* KAMUS */
	int i, j, k;
	/* ALGORITMA */
	i=0;
	STARTKATA(text);
	while(!EndKata)
	{	if (CKata.TabKata[0]=='*')
		{	ADVKATA(text);
			CreateEmptyArray(&((*M).mov[i].TabMove));
			for (k = 0; k < CKata.Length; k++) {
				(*M).mov[i].name[k] = CKata.TabKata[k];
			}
			 (*M).mov[i].name[k] = '\0';
			 ADVKATA(text);
			 j=0;
			 CreateQueue(&(ElmtArray(((*M).mov[i].TabMove),j)));
			 while ((CKata.TabKata[0]!='/') && (!EndKata))
			{	if (CKata.TabKata[0]!='-')
					AddQueue(&(ElmtArray(((*M).mov[i].TabMove),j)),CKata.TabKata[0]);
				else
				{	j++;
					CreateQueue(&(ElmtArray(((*M).mov[i].TabMove),j)));
				}
				ADVKATA(text);
			}
			NeffArray((*M).mov[i].TabMove)=j;
			i++;
		}
		ADVKATA(text);
	}
}