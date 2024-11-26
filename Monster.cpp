//Monster.cpp

#include "Player.h"
#include <iostream>
#include <fstream>
#include "Globals.h"
//#include "console.h"
using namespace std;
//using namespace JadedHoboConsole;
using namespace Globals;

bool Monster::Save(string FileName)
{

  FileName +=  ".mon";
  fstream sav(FileName.c_str(), ios::out | ios::binary);
  if(!sav){cout<<fg_red<<"ERROR OPENING "<<FileName<<"!!"<<endl;return false;}
  cout<<fg_magenta<<"Now Saving To "<<FileName<<"..."<<fg_white;
  sav.write((char*)this,sizeof(Monster));
  cout<<"DONE!"<<fg_cyan<<"\n\n"<<FileName<<" Should be "<<sizeof(Monster)<<"Bytes."<<endl;
  sav.close();
  return true;
}


bool Monster::Load(string FileName)
{
  FileName +=  ".mon";
  fstream sav(FileName.c_str(), ios::in | ios::binary);
  if(!sav){cout<<fg_red<<"ERROR OPENING "<<FileName<<"!!"<<endl;return false;}
  //cout<<fg_magenta<<"Now Loading From "<<FileName<<"..."<<fg_white;
  sav.read((char*)this,sizeof(Monster));
  //cout<<"DONE!"<<fg_cyan<<"\n\n"<<endl;
  sav.close();
  return true;
}

void Monster::Init(string name, bool magic, int HD, int MD, int Lvl, int GP, int Pot, int Eth, int xp, float attack, int attackmod, int hit)
{


 for(int i=0; i<12; i++){Name[i] = name[i];}
 cout<<fg_magenta;


 IsMage = magic;

 Level = Lvl;
 GPMod = GP;
 Gold = (GPMod*Level);

 Potions = Pot;
 Ethers = Eth;

 XPMod = xp;
 XP = (XPMod*Level);

 HPMod = HD;
 HPMax = (HPMod*Level);
 HP = HPMax;

 MPMod = MD;
 MPMax = (MPMod*Level);
 MP = MPMax;

 BAtt = attack;

 float test = 0;
 test = BAtt + (BAtt*((float)Level/3));

 MaxAtt = (int)test;
 MinAtt = (MaxAtt/4);
 AttMod = attackmod;

 ToHit = hit;
 Damage = 0;
 MPDamage = 0;

}

void Monster::LvlChg(int Lvl)
{

   Level = Lvl;

   Gold = (GPMod*(Level/2));

   float test = 0;
   test = BAtt + (BAtt*((float)Level/3));

   MaxAtt = (int)test;
   test = (float)MaxAtt / 4;

   MinAtt = (int)test;


   Damage = 0;
   MPDamage = 0;

   HPMax = (HPMod*Level);
   HP = HPMax;

   MPMax = (MPMod*Level);
   MP = MPMax;

   XP = (XPMod*Level);
}
