#include <stdio.h>
#include <string.h>

void PrintCredits();
/* Mencetak daftar nama pembuat game */
void PrintHeader();
/* Mencetak header game, berupa tulisan BRIGHTSOULS atau apapun yang akan muncul di layar permainan */
void PrintFooter();
/* Mencetak footer game, akan muncul di layar permainan */
void PrintMenu();
/* Mencetak daftar menu yang dapat dipilih oleh user */

int main()
{	char input[10];

	PrintHeader();
	PrintMenu();
	PrintFooter();
	printf("Input your command: ");
	scanf("%s",&input);
	
	while (strcmp(input,"Exit"))
	{

	}

	PrintCredits();


	return 0;
}

void PrintCredits()
{
	printf("\nBRIGHTSOULS\n");
	printf("K-01 / KELOMPOK 2\n");
	printf("TASYA		-	13515064\n");
	printf("SYLVIA JULIANA	-	13515070\n");
	printf("KEVIN ISWARA	-	13515085\n");
	printf("ADITYA PRATAMA	-	13515103\n");
	printf("THEA OLIVIA	-	13511001\n");
}

void PrintHeader()
{
	printf("Insert Header Here\n");
}

void PrintFooter()
{
	printf("Insert Footer Here\n\n");
}

void PrintMenu()
{
	printf("WELCOME TO BRIGHTSOULS!\n");
	printf("Please select:\n");
	printf("1. New Game\n");
	printf("2. Start Game\n");
}