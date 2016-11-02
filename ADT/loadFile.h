#include <stdio.h>
#include <string.h>
#include "mesinkar.h"
#include "mesinkata.h"

#ifndef __LOADFILE_H_
#define __LOADFILE_H_

typedef struct {
	int hp;
	int str;
	int def;
	int exp;
	int level;
	char name[10];
} statMonster;

typedef struct {
	statMonster Mon[10];
	statMonster boss;
} monster;

typedef struct {
	int hp;
	int str;
	int def;
	int exp;
	int level;
} statHero;

typedef struct {
	char name[100];
	statHero status[10];
} hero, currhero;

//char text[100] = nama file txt yang bakal lu load
//int jum = jumlah monster / level hero yang ada
void loadEnemy(monster *M, int *jum,char text[100]);

void loadStatHero(hero *H, int *jum,char text[100]);



#endif
