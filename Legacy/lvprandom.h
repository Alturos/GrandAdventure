/*	Lawrenceville Press Random Library                         */
/*	Semptember 1998                                            */
/*	The following code works correctly under CodeWarrior 3.3   */

#ifndef RANDOM_I
#define RANDOM_I

#include <stdlib.h>
#include <time.h>
void randomize()
{
	 time_t t;
	 srand((unsigned) time(&t));
}
//------------------------------------
int lvprandom(int limit)
{
	 return rand()%limit;
}
#endif
//------------------------------------
//----END OF RANDOM LIBRARY-----------

