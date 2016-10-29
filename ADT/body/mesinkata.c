/* File: mesinkata.c */
/* Implementasi Mesin Kata */

#include <stdio.h>
#include "boolean.h"
#include "mesinkata.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank(){
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ≠ BLANK atau CC = MARK */
   while ((CC != MARK) && (CC == BLANK)){
   		ADV();
   }
}

void STARTKATA(char text[100]){
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
	START(text);
	IgnoreBlank();
	if (CC != MARK){
		EndKata = false;
		SalinKata();
	}
	else EndKata = true;
}

void ADVKATA(){
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi 
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi, 
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.		  
   Proses : Akuisisi kata menggunakan procedure SalinKata */
	IgnoreBlank();
	if (CC == MARK){
		EndKata = true;
	}
	else{
		SalinKata();
		EndKata = false;	
	}
	IgnoreBlank();
}

void SalinKata(){
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi; 
          CC = BLANK atau CC = MARK; 
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
    int i;
    i = 0;
    do{
		CKata.TabKata[i] = CC;
		//printf("%c",CC);
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
