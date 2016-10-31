#ifndef SKILL_H
#define SKILL_H

#include "boolean.h"
#include "pohon.h"

// skill ningkatin attack
// autoberserk - HP tinggal 5%, double attack
void autoberserk();
// frenzy - ningkatin defense, strength, ningkatin HP, nambahin EXP
int frenzyIncreaseDef();
int frenzyIncreaseStr();
int frenzyIncreaseHP();
int frenzyIncreaseExp();
// drop of youth - nambahin darah 5%
// ide sementara nambahinnnya tiap round
int dropOfYouth();
// reflect shield - kalau kita kena damage, musuh tersebut kena damage 5%
int reflectShieldPlayer();
int reflectShieldEnemy();
// counter - ketika musuh nyerang dan kita block, block kita nullify attack musuh tersebut, terus musuh darahnya kurang dikit 5%
void counter();
#endif