#include "skill.h"
#include "bintree.h"
#include "listrek.h"
#include "loadFile.h"
#include "allDataType.h"
#include "boolean.h"
#include <stdlib.h>
#include <time.h>


// mengecek apakah monster adalah boss
boolean isBoss(monster m) {
	if (m.boss)
		return true;
}

boolean isBeingAttacked(currHero ch, monster m, movement movv) {
	// if being attacked.
	for (int i=0; i<10; i++) {
		return (movv.mov[i].name[i] == attack);
	}
}

/* ============================================================== */
// skill ningkatin attack
// autoberserk - HP tinggal 5%, double attack
void autoberserk (currHero ch){
	int current;
	monster m;

	for (int i=0; i<10; i++) {
		if (ch.status.level == 5) {
			if (current == ch.status.hp * 0.05) {
				m.Mon[i].hp--;
			}
	}
}
// frenzy - ningkatin defense, strength, ningkatin HP, nambahin EXP
int frenzy(currHero ch){
	int current;

	for (int i=0; i<10; i++) {
		if (ch.status.level == 3) {
			ch.status.hp++;
			ch.status.str++;
			ch.status.def++;
			ch.status.exp++;
		}
	}
}

// drop of youth - nambahin darah 5%
// ide sementara nambahinnnya tiap round
int dropOfYouth(currHero ch, movement movv) {

	for (int i=0; i<10; i++) {
	if (ch.status[i].level == 5) {
			movv.mov[i]++;
			ch.status.hp++;
	}
}

// reflect shield - kalau kita kena damage, musuh tersebut kena damage 5%
int reflectShield(currHero ch, monster m) {
	for (int i=0; i<10; i++) {
		if (isBeingAttacked(ch,m)) {
			return m.Mon[i].hp = (ch.status[i+1].hp - ch.status[i].hp) * 0.05;
		}		
	}
}

// counter - ketika musuh nyerang dan kita block, block kita nullify attack musuh tersebut
void counter(currHero ch, monster m) {
	if (isBeingAttacked(ch,m)) {
		damage = nil;
	}
}


/* ACTIVE SKILLS */
// TP - pindah ke map berikutnya secara random
// -- ACQUIRED AT HERO LEVEL 4 (Skill Tree Level 3 (tinggi ke-2))
void teleport(currHero ch, AllMap *map) {
	for (int i=0; i<10; i++) {
	if (ch.status.level == 4) {
		rand(NomorMap(*map));
	}
}

// ACQUIRED AT HERO LEVEL 2
// add SP decrease enemy HP - Skill Tree level 2 (tinggi ke-1)
int bloodRitual(currHero ch) {
	for (int i=0; i<10; i++) {
	if (ch.status.level == 2) {
		ch.status.hp--;
		// blah blah blah
	}
}