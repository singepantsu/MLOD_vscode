
#include <stdlib.h>
#include <stdio.h>

#include "02-convexe.h"

int main(void) {
	bool tabConvexe1[5] = { false,false,false,false,true };

	bool tabConvexe2[5] = { false,false,false,false,false };
	bool tabConvexe3[5] = { false,false,true,true,false };
	bool tabConvexe[5] = { true,true,false,false,true };
	bool tabNonConvexe[5] = { true,true,false,true,false };

	printf("tabConvexe1 %s\n",		  est_convexe(tabConvexe1,5)?"[OK]":"[ERROR]");
	printf("tabConvexe2 %s\n",		  est_convexe(tabConvexe2,5)?"[OK]":"[ERROR]");
	printf("tabConvexe3 %s\n",		  est_convexe(tabConvexe3,5)?"[OK]":"[ERROR]");
	printf("tabConvexe %s\n",		  est_convexe(tabConvexe,5)?"[OK]":"[ERROR]");

	printf("tabNonConvexe %s\n",	(!est_convexe(tabNonConvexe,5))?"[OK]":"[ERROR]");


	return 0;
}