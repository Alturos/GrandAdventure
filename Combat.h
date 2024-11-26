//Combat Engine.h
//Preprocessor
#ifndef Combat_H_INCLUDED
#define Combat_H_INCLUDED
#include <stdlib.h>
#include <time.h>
#include "Player.h"


class Combat
{


  void MonsterTurn(Monster &mstr);
  void PlayerTurn(Player &pc);
  void LevelUp(Player &pc);
  bool Defended;
  bool CanFlee;
  bool Fled;
  
 public:


  bool Start(Player &PC, Monster &mstr, bool escape);
  
  void Randomize()
  {
	 time_t t;
	 srand((unsigned) time(&t));
  } 
  int Randoms(int limit)
  {
	 return rand()%limit;
  }
 
};



//------------------------------------

#endif

