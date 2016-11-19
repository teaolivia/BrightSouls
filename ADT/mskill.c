// UNIT TESTER FOR SKILL

#include "skill.h"
#include "bintree.h"
#include "listrek.h"
#include "loadFile.h"
#include "boolean.h"
#include <stdlib.h>

int main() {
	char code;
	hero h;
	currhero ch;
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
	 *		 /	   \			 /	   \
	 * 		/		\			/		\
	 *	Drops of	tele- 	Frenzy(3)		Auto-Berserk(5)
	 *	Youth(5)	port(4)
	 * 
	 *
	 * Number inside the parentheses are level hero needs to be acquired
	 * 
	 */


	 /* 
	  * ========= CODE FOR ACTIVE SKILLS ================
	  * tp - teleport
	  * br - blood ritual
	  */
	  switch (code) {
	  	case 'tp':
	  		teleport(ch);
	  		break;
	  	case 'br':
	  		bloodRitual(ch);
	  		break;
	  }
	return 0;
}