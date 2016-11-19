#ifndef SKILL_H
#define SKILL_H

#include "boolean.h"
#include "bintree.h"
#include "listrek.h"
#include "loadFile.h"


// ========== SELEKTOR ===========
hero h;
currhero ch;
monster m;
statHero sh;
statMonster sm;

// ========== OPERATOR TAMBAHAN ==
// mengecek apakah monster adalah boss
boolean isBoss(monster m);
void printSkill(currhero ch);

// ========== METHOD UTAMA =======
// skill ningkatin attack
// autoberserk - HP tinggal 5%, double attack
// -- ACQUIRED AT HERO LEVEL 5 (Skill Tree Level 3 (tinggi ke-2))
void autoberserk(currhero ch);

// frenzy - ningkatin defense, strength, ningkatin HP, nambahin EXP
// -- ACQUIRED AT HERO LEVEL 3 (Skill Tree Level 3 (tinggi ke-2))
int frenzyIncreaseDef(currhero ch);
int frenzyIncreaseStr(currhero ch);
int frenzyIncreaseHP(currhero ch);
int frenzyIncreaseExp(currhero ch);

// drop of youth - nambahin darah 5%
// ide sementara nambahinnnya tiap round
// -- ACQUIRED AT HERO LEVEL 5 (Skill Tree Level 3 (tinggi ke-2))
int dropOfYouth(currhero ch);

// reflect shield - kalau kita kena damage, musuh tersebut kena damage 5%
// -- ACQUIRED AT HERO LEVEL 2 (Skill Tree Level 2 (tinggi ke-1))
int reflectShieldPlayer(currhero ch);
int reflectShieldEnemy(currhero ch);

// counter - ketika musuh nyerang dan kita block, block kita nullify attack musuh tersebut, terus musuh darahnya kurang dikit 5%
// -- ACQUIRED AT HERO LEVEL 1 (Skill Tree Level 1 (tinggi ke-0))
void counter(currhero ch);

/* ACTIVE SKILLS */
// TP - pindah ke map berikutnya secara random
// -- ACQUIRED AT HERO LEVEL 4 (Skill Tree Level 3 (tinggi ke-2))
void teleport(currhero ch);

// ACQUIRED AT HERO LEVEL 2
// add SP costs HP - Skill Tree level 2 (tinggi ke-1)
int bloodRitual(currhero ch);

#endif