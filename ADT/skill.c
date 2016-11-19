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

boolean isBeingAttacked(currhero ch, monster m) {
	// blah blah
	return false;
}

/* ============================================================== */
// skill ningkatin attack
// autoberserk - HP tinggal 5%, double attack
void autoberserk (currhero ch){
	int current;
	monster m;

	for (int i=0; i<10; i++) {
		if (ch.status[i].level == 5) {
			if (current == ch.status[i].hp * 0.05) {
				m.Mon[i].hp--;
			}
	}
}
// frenzy - ningkatin defense, strength, ningkatin HP, nambahin EXP
int frenzy(currhero ch){
	int current;

	for (int i=0; i<10; i++) {
		if (ch.status[i].level == 3) {
			ch.status[i].hp++;
			ch.status[i].str++;
			ch.status[i].def++;
			ch.status[i].exp++;
		}
	}
}

// drop of youth - nambahin darah 5%
// ide sementara nambahinnnya tiap round
int dropOfYouth(currhero ch) {

	for (int i=0; i<10; i++) {
	if (ch.status[i].level == 5) {
		for (/* every movement made */) {
			ch.status[i].hp++;
	}
}

// reflect shield - kalau kita kena damage, musuh tersebut kena damage 5%
int reflectShield(currhero ch, monster m) {
	for (int i=0; i<10; i++) {
		if (isBeingAttacked(ch,m)) {
			return m.Mon[i].hp = (ch.status[i+1].hp - ch.status[i].hp) * 0.05;
		}		
	}
}

// counter - ketika musuh nyerang dan kita block, block kita nullify attack musuh tersebut
void counter(currhero ch, monster m) {
	if (isBeingAttacked(ch,m)) {
		damage = nil;
	}
}


/* ACTIVE SKILLS */
// TP - pindah ke map berikutnya secara random
// -- ACQUIRED AT HERO LEVEL 4 (Skill Tree Level 3 (tinggi ke-2))
void teleport(currhero ch, AllMap *map) {
	for (int i=0; i<10; i++) {
	if (ch.status[i].level == 4) {
		rand(NomorMap(*map));
	}
}

// ACQUIRED AT HERO LEVEL 2
// add SP costs HP - Skill Tree level 2 (tinggi ke-1)
int bloodRitual(currhero ch) {
	for (int i=0; i<10; i++) {
	if (ch.status[i].level == 2) {
		ch.status[i].hp--;
		// blah blah blah
	}
}