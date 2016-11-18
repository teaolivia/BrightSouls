#include "battle.h"
#include <string.h>

Stack RandomBattle (char nama[10], movement M)
{	/* KAMUS */
	Stack S;
	int i, j, k;
	/* ALGORITMA */
	CreateEmptyStack(&S);
	i = 0;
	while (strcmp(M.mov[i].name,nama)!=0)
		i++;
	/* M.mov[i].name == nama */
	for(j=1;j<=NeffArray(M.mov[i].TabMove);j++)
	{	k = (rand() % NeffArray(M.mov[i].TabMove));
		Push(&S,ElmtArray((M.mov[i].TabMove),k));
	}
	return(S);
}