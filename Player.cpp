#include "Player.h"
#include <iostream>
#include <fstream>
#include "console.h"
using namespace std;
using namespace JadedHoboConsole;






bool Player::Save(string FileName)
{

  cout<<fg_magenta;
  cout<<"NAME:      "<<fg_white<<Name<<fg_magenta<<endl;
  cout<<"GENDER:    "<<fg_white<<Gender<<fg_magenta<<endl;
  cout<<"LEVEL:     "<<fg_white<<level<<fg_magenta<<endl;
  cout<<"HP:        "<<fg_white<<HP<<"/"<<HPMax<<fg_magenta<<endl;
  cout<<"MP:        "<<fg_white<<MP<<"/"<<MPMax<<fg_magenta<<endl;
  cout<<"XP:        "<<fg_white<<XP<<"/"<<XPForNext<<fg_magenta<<endl;
  cout<<"DAMAGE:    "<<fg_white<<Damage<<fg_magenta<<endl;
  cout<<"GOLD:      "<<fg_white<<Gold<<fg_magenta<<endl;
  cout<<"ATTACK:    "<<fg_white<<MinAtt<<" - "<<MaxAtt<<fg_magenta<<endl;
  cout<<"POTIONS:   "<<fg_white<<Potions<<fg_magenta<<endl;
  cout<<"ETHERS:    "<<fg_white<<Ethers<<fg_magenta<<endl;
  cout<<"QUEST:     "<<fg_white<<Quest<<fg_cyan<<endl;




  FileName +=  ".sav";
  fstream sav(FileName.c_str(), ios::out | ios::binary);
  if(!sav){cout<<fg_red<<"ERROR OPENING "<<FileName<<"!!"<<endl;return false;}
  cout<<fg_magenta<<"Now Saving To "<<FileName<<"..."<<fg_white;
  sav.write((char*)this,sizeof(Player));
  cout<<"DONE!"<<fg_cyan<<"\n\n"<<FileName<<" Should be "<<sizeof(Player)<<"Bytes."<<endl;
  sav.close();
  return true;

}

bool Player::Load(string FileName)
{
  FileName +=  ".sav";
  fstream sav(FileName.c_str(), ios::in | ios::binary);
  if(!sav){cout<<fg_red<<"ERROR OPENING "<<FileName<<"!!"<<endl;return false;}
  cout<<fg_magenta<<"Now Loading From "<<FileName<<"..."<<fg_white;
  sav.read((char*)this,sizeof(Player));
  cout<<"DONE!"<<fg_cyan<<"\n\n"<<endl;
  sav.close();
  cout<<fg_magenta;
  cout<<"NAME:      "<<fg_white<<Name<<fg_magenta<<endl;
  cout<<"GENDER:    "<<fg_white<<Gender<<fg_magenta<<endl;
  cout<<"LEVEL:     "<<fg_white<<level<<fg_magenta<<endl;
  cout<<"HP:        "<<fg_white<<HP<<"/"<<HPMax<<fg_magenta<<endl;
  cout<<"MP:        "<<fg_white<<MP<<"/"<<MPMax<<fg_magenta<<endl;
  cout<<"XP:        "<<fg_white<<XP<<"/"<<XPForNext<<fg_magenta<<endl;
  cout<<"DAMAGE:    "<<fg_white<<Damage<<fg_magenta<<endl;
  cout<<"GOLD:      "<<fg_white<<Gold<<fg_magenta<<endl;
  cout<<"ATTACK:    "<<fg_white<<MinAtt<<" - "<<MaxAtt<<fg_magenta<<endl;
  cout<<"POTIONS:   "<<fg_white<<Potions<<fg_magenta<<endl;
  cout<<"ETHERS:    "<<fg_white<<Ethers<<fg_magenta<<endl;
  cout<<"QUEST:     "<<fg_white<<Quest<<fg_cyan<<endl;
  cout<<"\n\n"<<endl;
  return true;

}

void Player::Create()
{
  int i;
  string choice = "";
  cout<<fg_magenta;
  cout<<"Welcome New Adventurer. We will now begin the character creation process."<<endl;
  cout<<"Firstly, What is your name? (up to 12 characters)"<<fg_white;
  cin>>choice;
  choice[0] = toupper(choice[0]);
  for(i=0; i<((int)choice.length()); i++){this->Name[i] = choice[i];}
  if(i<12){  Name[i] = '\0';}
  cout<<fg_magenta;
  cout<<"\nOk "<<Name<<", what's your Gender? "<<fg_white;
  cin>>choice;
  choice[0] = toupper(choice[0]);
  if((choice[0] == 'F') || (choice[0] == 'G')||(choice[0] == 'S')){choice = "Female";}
  else{choice = "Male  ";}
  for(int i=0; i<7; i++){Gender[i] = choice[i];}




  cout<<fg_magenta;
  system("cls");
  cout<<"Ok, now you must chose your character class."<<endl;
  cout<<fg_magenta;
  //cout<<"Keep in mind that you must use ALL of your points and ONLY all of your points."<<endl;
  //system("pause");
  //system("cls");
  bool done = false;
  do{
  cout<<"You have two options:\n"<<endl;
  cout<<"(A). The Fighter is strong physically. He deals good damage and can take a good amount of punishment."<<endl;
  cout<<"\n\n(B). The Mage is not so strong physically, but commands devastating magic.\n"<<endl;
  cout<<"Please choose one. (A, B): "<<fg_white;
  cin>>choice;
  cout<<fg_magenta;
  choice[0] = toupper(choice[0]);
  switch(choice[0])
  {
         case 'A':
              {
                  system("cls");


                  MaxAtt = 60;
                  MinAtt = (MaxAtt/4);
                  HPMax = 100;
                  HP = HPMax;
                  MPMax = 30;
                  MP = MPMax;
                  level = 1;
                  Potions = 10;
                  Ethers = 0;
                  Quest = 0;
                  XP = 0;
                  XPForNext = level * 107;
                  Damage = 0;
                  Gold = 200;
                  Magic = 0;
                  Magic.cure = 2;

                  done = true;
                  break;
              }
         case 'B':
              {
                  system("cls");



                  MaxAtt = 10;
                  MinAtt = (MaxAtt/4);
                  HPMax = 45;
                  HP = HPMax;
                  MPMax = 65;
                  MP = MPMax;
                  level = 1;
                  Potions = 5;
                  Ethers = 5;
                  Quest = 0;
                  XP = 0;
                  XPForNext = level * 115;
                  Damage = 0;
                  Gold = 100;
                  Magic = 3;
                  Magic.windslash = 1;

                  done = true;
                  break;
              }
         /*
         case 'C':
               {
                  system("cls");
                  cout<<"\nYou have chosen to creat a character from scratch. Typically for people who are\nfarmiliar with the system."<<endl;
                  done = true;
                  break;
               }
         */
         default: system("cls");
                  cout<<"\nYou must choose A or B only."<<endl;
                  system("pause");
                  system("cls");
                  done = false;
  }
  }while(!done);
}

