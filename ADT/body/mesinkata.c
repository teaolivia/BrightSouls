#include <stdio.h>
#include <string.h>
#include "mesinkata.h"

/* State Mesin Kata */
boolean kataPertama;
boolean EndKata;
Kata CKata;

void IgnoreBlank() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ? BLANK atau CC = MARK */
	while ((CC == BLANK) && (CC != MARK)) {
		ADV();
	}	
}

void STARTKATA(char text[100]) {
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
	START(text);
	kataPertama = true;
	IgnoreBlank();
	if (CC != MARK) {
		SalinKata(text);
		EndKata = false;
	} else {
		EndKata = true;
	}
}
void ADVKATA(char text[100]) {
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
	IgnoreBlank();
	if (CC != MARK) {
		SalinKata(text);
		EndKata = false;
	} else {
		EndKata = true;
	}
	IgnoreBlank();
}
void SalinKata(char text[100]) {
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
	if ((strcmp(text,"enemy.txt") == 0) ||(strcmp(text,"player.txt") == 0)) {
		int i;
		i = 0;
		int temp = 0;
		CKata.Length = 0;
		if (CC == STRIP) {
			CKata.tanda = CC;
			ADV();
			CKata.angka = 0;
			while ((i <= NMax) && (CC != STRIP) && (CC != BINTANG) && (CC != MARK)) {
				if (CC != 10) {
					temp = CC - '0';
					CKata.angka = CKata.angka * 10 + temp;
					ADV();
					i++;
				} else {
					ADV();
				}
				
			}
		} else if (CC == BINTANG) {
			CKata.tanda = CC;
			ADV();
			while ((i <= NMax) && (CC != STRIP) && (CC != BINTANG) && (CC != MARK)) {
				if (CC != 10) {
					CKata.TabKata[i] = CC;
					CKata.Length++;
					ADV();
					i++;
				} else {
					ADV();
				}
			}		
		}	
	} else {
		int i;
	    i = 0;
	    do{
			CKata.TabKata[i] = CC;
			ADV();
			if((CC != MARK) && (CC != BLANK)){
				i++;
			}
		} while ((CC != MARK) && (CC != BLANK));
		if (i<=NMax){
			CKata.Length = i+1;
		}
		else CKata.Length = NMax;
		
		CKata.TabKata[i+1] = NULL;
	}
	
}

