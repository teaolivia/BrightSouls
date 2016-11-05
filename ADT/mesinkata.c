#include <stdio.h>
#include "mesinkata.h"

/* State Mesin Kata */
boolean EndKata;
Kata CKata;

boolean IsAngka(char CC) {
	if (CC == '0') {
		return true;
	} else if (CC == '1') {
		return true;
	} else if (CC == '2') {
		return true;
	} else if (CC == '3') {
		return true;
	} else if (CC == '4') {
		return true;
	} else if (CC == '5') {
		return true;
	} else if (CC == '6') {
		return true;
	} else if (CC == '7') {
		return true;
	} else if (CC == '8') {
		return true;
	} else if (CC == '9') {
		return true;
	} else {
		return false;
	}      
}

/**********************
IgnoreBlank() nya ada gua ganti jadi ada skip enter, selama ini sih gua coba punya gua ama kevin ga ada masalah
kalo misalkan ada masalah jadi gabisa kabarin gua tar gua benerin

**********************/
void IgnoreBlank() {
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang 
   F.S. : CC ? BLANK atau CC = MARK */
	while (((CC == BLANK) && (CC != MARK)) || ((CC == 10) && (CC != MARK))) {
		ADV();
	}
}
void STARTKATA(char text[100]) {
/* I.S. : CC sembarang 
   F.S. : EndKata = true, dan CC = MARK; 
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */
	START(text);
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
	int i, temp;
	i = 0;
	CKata.Length = 0;
	IgnoreBlank();
	if (IsAngka(CC)) {
		CKata.angka = 0;
		while ((i <= NMax) && (CC != BLANK) && (CC != 10) && (CC != MARK)) {
				temp = CC - '0';
				CKata.angka = CKata.angka * 10 + temp;
				ADV();
				i++;	
			}
	} else {
		while ((i <= NMax) && (CC != BLANK) && (CC != 10) && (CC != MARK)) {	
				CKata.TabKata[i] = CC;
				CKata.Length++;
				ADV();
				i++;
		}
	}
}
