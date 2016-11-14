#include <stdio.h>
#include "map.h"

void BacaMap(AllMap *map, char text[100]){
	int i,j,jmlhmap;
	STARTKATA(text);
	
	jmlhmap = 0;
	if((CC != '.') && (CKata.TabKata[0] != '.')){
		jmlhmap++;
		while((CKata.TabKata[0]=='A') || (CKata.TabKata[0]=='B') || (CKata.TabKata[0]=='C') || (CKata.TabKata[0]=='D') || (CKata.TabKata[0]=='Z') || (CKata.TabKata[0]=='F') || (CKata.TabKata[0]=='G') || (CKata.TabKata[0]=='H')){
			NomorMap(*map)[jmlhmap] = CKata.TabKata[0];
			ADVKATA(text);
			i = 1;
			while((CC != '.') && (CKata.TabKata[0] != '/') && (CKata.TabKata[0] != '.')){
				j = 1;
				while((CC != '.') && (CKata.TabKata[0] != '-') && (CKata.TabKata[0] != '.') && (CKata.TabKata[0] != '/')){
					ElmtMat(((*map).TabMap[jmlhmap]),i,j) = CKata.TabKata[0];
					j++;
					ADVKATA(text);
				}
				if((CC != '.') && (CKata.TabKata[0] != '/') && (CKata.TabKata[0] != MARK)){
					ADVKATA(text);
					i++;
				}
				else if (CC == MARK){
					ElmtMat(((*map).TabMap[jmlhmap]),i,j) = CKata.TabKata[0];
				}
			}
			NBrsEff((*map).TabMap[jmlhmap]) = i;
			NKolEff((*map).TabMap[jmlhmap]) = j;
			if(CC!=MARK){
				ADVKATA(text);
				jmlhmap++;
			}
		}
	}
	JmlhMap(*map) = jmlhmap;
}
