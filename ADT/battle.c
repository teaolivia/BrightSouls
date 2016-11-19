#include "battle.h"
#include <string.h>
#include <time.h>

Stack RandomBattle (char nama[10], movement M)
{	/* KAMUS */
	Stack S;
	boolean check;
	int idx[20];
	int i, j, k;
	/* ALGORITMA */
	CreateEmptyStack(&S);
	i = 0;
	while (strcmp(M.mov[i].name,nama)!=0)
		i++;
	/* M.mov[i].name == nama */
	srand(time(NULL));
	for(j=1;j<=NeffArray(M.mov[i].TabMove);j++)
	{	k = (rand() % NeffArray(M.mov[i].TabMove)) + 1;
		check = false;
		while (!check)
		{	if (idx[k]==1)
				k = (rand() % NeffArray(M.mov[i].TabMove)) + 1;
			else
			{	Push(&S,ElmtArray((M.mov[i].TabMove),k));
				idx[k] = 1;
				check = true;
			}
		}
	}
	return(S);
}