#ifndef SKILL_H
#define SKILL_H

#include "boolean.h"
#include "allDataType.h"
#include "listrek.h"
#include "bintree.h"
#include "map.h"
#include "battle.h"
#include "loadFile.h"


// ===================== SELEKTOR ===============================
hero h;
currHero ch;
monster m;
statHero sh;
statMonster sm;
BinTree P;
movement mov;
AllMap *map;

/* PRIMITIF ADT BINARY SEARCH TREE YANG DIPAKAI 
addrNode AlokNode (infotype X);
void DealokNode (addrNode P);
void MakeTree (BinTree P);
int NbElmt (BinTree P); // NbElmt = 7
int NbDaun (BinTree P); // NbDaun = 6
int Level (BinTree P, infotype X);
int Tinggi (BinTree P);
void AddSkill (BinTree *P, infotype X, infotype Y, boolean Kiri);
boolean SearchTree (BinTree P, infotype X);
void printSkill(currHero ch, BinTree P); 
*/

// ========== OPERATOR TAMBAHAN =================================
boolean isBoss(monster m);
boolean isBeingAttacked(currHero ch, monster m, movement movv);

// ========== METHOD UTAMA =======
// skill ningkatin attack
// autoberserk - HP tinggal 5%, double attack
// -- ACQUIRED AT HERO LEVEL 5 (Skill Tree Level 3 (tinggi ke-2))
void autoberserk(currHero ch);

// frenzy - ningkatin defense, strength, ningkatin HP, nambahin EXP
// -- ACQUIRED AT HERO LEVEL 3 (Skill Tree Level 3 (tinggi ke-2))
int frenzy(currHero ch);

// drop of youth - nambahin darah 5%
// ide sementara nambahinnnya tiap round
// -- ACQUIRED AT HERO LEVEL 5 (Skill Tree Level 3 (tinggi ke-2))
int dropOfYouth(currHero ch, movement movv);

// reflect shield - kalau kita kena damage, musuh tersebut kena damage 5%
// -- ACQUIRED AT HERO LEVEL 2 (Skill Tree Level 2 (tinggi ke-1))
int reflectShield(currHero ch, monster m);

// counter - ketika musuh nyerang dan kita block, block kita nullify attack musuh tersebut, terus musuh darahnya kurang dikit 5%
// -- ACQUIRED AT HERO LEVEL 1 (Skill Tree Level 1 (tinggi ke-0))
void counter(currHero ch, monster m);

/* ACTIVE SKILLS */
// TP - pindah ke map berikutnya secara random
// -- ACQUIRED AT HERO LEVEL 4 (Skill Tree Level 3 (tinggi ke-2))
void teleport(currHero ch, AllMap *map);

// ACQUIRED AT HERO LEVEL 2
// *masih bingung sih mending apa ya* pokoknya costs HP - Skill Tree level 2 (tinggi ke-1)
int bloodRitual(currHero ch);

#endif