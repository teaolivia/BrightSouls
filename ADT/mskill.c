// UNIT TESTER FOR SKILL

#include "skill.h"
#include "bintree.h"
#include "listrekursif.h"
#include "loadFile.h"
#include "allDataType.h"
#include "boolean.h"
#include <stdlib.h>

int main() {
	char code;
	hero h;
	currHero ch;
	monster m;
	statHero sh;
	statMonster sm;

	/* =============== TEST SKENARIO =================== 
	 * 
	 * Skill should be gained each level with this order:
	 *
	 * 					counter(1)
	 *					/	\
	 *				   /	 \
	 *				  /		  \
	 *				 /		   \
	 *				/	  		\
	 *		Blood Ritual(2) 	Reflect Shield(2)
	 *		 /	   				 /	   \
	 * 		/					/		\
	 *	Drops of		 	Frenzy(3)		Auto-Berserk(5)
	 *	Youth(5)	
	 * 
	 *
	 * Number inside the parentheses are level hero needs to be acquired
	 * 
	 */


	 /* 
	  * ========= CODE FOR ACTIVE SKILLS ================
	  * tp - teleport
	  * br - blood ritual
	  *
	  */

 	scanf("%s",&code);
 	while (strcmp(&code,"br"))
	{
		bloodRitual(ch);
	}

	return 0;
}