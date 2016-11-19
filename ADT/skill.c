#include "skill.h"
#include "bintree.h"
#include "listrek.h"
#include "loadFile.h"
#include "boolean.h"
#include <stdlib.h>
#include <time.h>

// mengecek apakah monster adalah boss
boolean isBoss(monster m) {
	if (m.boss)
		return true;
}

void printSkill(currhero ch) {

}

// skill ningkatin attack
// autoberserk - HP tinggal 5%, double attack
void autoberserk (currhero ch){
	int current;
	monster m;

	for (int i=0; i<10; i++) {
		switch (ch.status[i].level) {
			case 0: break;
			case 1: 
				if (current == ch.status[i].hp * 0.05) {
					m.Mon[i].hp--;
				}
				break;
			case 2: break;
			case 3: break;
			case 4: break;
			case 5: break;
		}

	}
}
// frenzy - ningkatin defense, strength, ningkatin HP, nambahin EXP
int frenzyIncreaseDef(){

}

int frenzyIncreaseStr(){

}

int frenzyIncreaseHP() {

}

int frenzyIncreaseExp() {

}
// drop of youth - nambahin darah 5%
// ide sementara nambahinnnya tiap round
int dropOfYouth(currhero ch) {
	for (int i=0; i<10; i++) {
		switch (ch.status[i].level) {
			case 0: break;
			case 1: 
				if (current == ch.status[i].hp * 0.05) {
					m.Mon[i].hp--;
				}
				break;
			case 2: break;
			case 3: break;
			case 4: break;
			case 5: break;
		}

	}
}

// reflect shield - kalau kita kena damage, musuh tersebut kena damage 5%
int reflectShieldPlayer() {

}

int reflectShieldEnemy() {

}

// counter - ketika musuh nyerang dan kita block, block kita nullify attack musuh tersebut
void counter() {
	if (enemy) {
		damage = nil;
	}
}


/* ACTIVE SKILLS */
// TP - pindah ke map berikutnya secara random
// -- ACQUIRED AT HERO LEVEL 4 (Skill Tree Level 3 (tinggi ke-2))
void teleport(currhero ch) {
	
}

// ACQUIRED AT HERO LEVEL 2
// add SP costs HP - Skill Tree level 2 (tinggi ke-1)
int bloodRitual(currhero ch) {
	
}