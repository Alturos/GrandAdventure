//preprocesser

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using std::string;

struct Spells
{
  int fire;
  int ice;
  int bolt;
  int cure;
  int drain;
  int rasp;
  int quake;
  int windslash;
  Spells operator=(int _x)
  {
      fire = _x;
      ice = _x;
      bolt = _x;
      cure = _x;
      drain = _x;
      rasp = _x;
      quake = _x;
      windslash = _x;
	  return *this;
  }


};

class Player
{
public:
   char Name[12];
   char Gender[7];
   int level;
   bool Alive;

   int HP;
   int HPMax;

   int MP;
   int MPMax;

   int MinAtt;
   int MaxAtt;
   int Damage;

   int Gold;

   int XP;
   int XPForNext;

   int Potions;
   int Ethers;

   Spells Magic;

   int Quest;
   bool Beaten;

   int Map;
   int Location;

   Player()
   {

   }
   bool Save(string Filename);     //Save game to a .sav file
   bool Load(string Filename);     //Load a game from a .sav file
   void Create();


};

class Monster
{
 public:
 char Name[12];         //Monsters Name
 bool IsMage;           //Can the monster cast any spells
 int Level;             //Monsters Level

 int HP;                // Current HP
 int HPMax;             // Maximum Hit Points
 int HPMod;             // HP Per Level

 int MP;                // Current MP
 int MPMax;             // Maximum Mana Points
 int MPMod;             // MP Per Level

 float BAtt;              //Base Attak per level
 int MinAtt;	        //Lowest attack possible(before Modifier)
 int MaxAtt;            //Highest attack possible(before Modifier)
 int AttMod;            //Any Modifiers to damage total
 int ToHit;             //Chance of 100 to hit target

 int Damage;            //Damage delivered on the monsters turn
 int MPDamage;          //MP Drain caused by Rasp

 int Gold;              //Gold monster is carrying
 int GPMod;             //Amount of Gold the monster drops per level.

 int Potions;           //Number of Potions the monster carries, Will drop any unused
 int Ethers;            //Same as potions but for Ethers, as a rule only Mage types should carry Ethers

 int XPMod;             //The experience per level the monster is worth.
 int XP;                //XP monster is worth

 void LvlChg(int Lvl);    //Overloaded Function; Initializes an already made monster to the level number entered
 void Init(string name, bool magic, int HD, int MD, int Lvl, int GP, int Pot, int Eth, int xp, float attack, int attackmod, int hit);
                        //^^^^ Function to initialize a new monster, THis should primarily be used with a monster editor sub program
 bool Save(string Filename); //Save structure to a .mon file
 bool Load(string FileName); //Load structure from a .mon file



};

#endif
