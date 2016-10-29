#include <stdio.h>
#include "map.h"

void BacaMap(AllMap *map, char text[100]){
	int i,j;
	STARTKATA(text);
	
	JmlhMap(*map) = 0;
	while(CC != '.'){
		JmlhMap(*map)++;
		i = 1;
		while((CC != '/') && (CC != '.')){
			j = 1;
			while((CC != '-') && (CC != '.') && (CC != '/')){
				Elmt(((*map).TabMap[JmlhMap(*map)]),i,j) = CKata.TabKata[0];
				j++;
				ADVKATA(text);
			}
			if((CC != '/') && (CC != MARK)){
				Elmt(((*map).TabMap[JmlhMap(*map)]),i,j) = CKata.TabKata[0];
				ADV();
				ADV();
				ADVKATA(text);
				i++;
			}
			else{
				Elmt(((*map).TabMap[JmlhMap(*map)]),i,j) = CKata.TabKata[0];
			}
		}
		ADV();
		ADV();
		ADVKATA(text);
		NBrsEff((*map).TabMap[JmlhMap(*map)]) = i;
		NKolEff((*map).TabMap[JmlhMap(*map)]) = j;
	}
}
int main(){
	AllMap map;
	char text[100] = "map.txt";
	BacaMap(&map,text);
	int i;
	int j,k;
	for (i=1;i<=JmlhMap(map);i++){
		for (j=1;j<=NBrsEff(map.TabMap[JmlhMap(map)]);j++){
			for (k=1;k<=NKolEff((map).TabMap[JmlhMap(map)]);k++){
				printf("%c ",Elmt((map.TabMap[JmlhMap(map)]),j,k));
			}
			printf("\n");
		}
		printf("map ke - %d",i);
	}
	return 0;
}
