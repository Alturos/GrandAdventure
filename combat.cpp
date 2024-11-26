#include "Combat.h"
#include <iostream>
#include "Globals.h"
//#include "console.h"
//#include <conio.h>
//using namespace JadedHoboConsole;
using namespace Globals;
using std::cout;
using std::cin;
using std::endl;

#include <sstream>
#include <string>

template <typename T>
T fromString(const std::string& string)
{
   T temp;
   std::istringstream stream(string);
   stream>>temp;
   return temp;
}

int stoi(string& str)
{
    int num;
    num = fromString<int>(str);
    return num;
}


void Combat::MonsterTurn(Monster &mstr)
{                                //The Monster Turn Function
     int choice;
     int Damage = 0;
     int Attack = 0;
     choice = Randoms(99);
     mstr.Damage = 0;
     mstr.MPDamage = 0;

     //Non Magical Monster
     if(!mstr.IsMage)
     {                           //Monster is Not a Mage
     	if(choice<15)
	    {                        //Use a Potion?
	     if(mstr.HP<mstr.HPMax)
	     {                       //Heal With Potion
	      cout<<fg_red<<mstr.Name<<fg_cyan<<" consumes a potion."<<endl;
	      mstr.HP+=25;
	      mstr.Damage = 0;
	      if(mstr.HP>=mstr.HPMax){mstr.HP = mstr.HPMax;}
	     }                       //END Heal With Potion
	     else{choice = 70;}      //Don't Need one, Attack instead
        }                        //END Use a Potion
        if(choice>=15)
        {                        //Attack
          
          Damage = mstr.AttMod+(mstr.MinAtt+Randoms(mstr.MaxAtt));
	      Attack = Randoms(99);
	  	  if(mstr.ToHit>Attack)
	  	  {                      //Attack Hits
     		 cout<<fg_red<<mstr.Name<<fg_cyan<<" Hits you and does "<<fg_yellow<<Damage<<fg_cyan<<" Damage!"<<endl;
     		 mstr.Damage = Damage;
          }                      //END Attack Hits
		  else
		  {                      //Attack Misses
		   cout<<fg_red<<mstr.Name<<fg_cyan<<" Attacks, but misses you!"<<endl;
           mstr.Damage = 0;
          }                      //END Attack Mises
        }                        //END Attack      
     }                           //END Monster is Not a Mage
     //Mage Type Monster
     else
     {                           //Monster Is A Mage
         if(choice<5)
         {                       //Use A Potion
          if(mstr.HP<mstr.HPMax)
	      {                     //Heal With Potion
	       cout<<fg_red<<mstr.Name<<fg_cyan<<" consumes a potion."<<endl;
	       mstr.HP+=25;
 	       mstr.Damage = 0;
	       if(mstr.HP>=mstr.HPMax){mstr.HP = mstr.HPMax;}
          }                     //END Heal With Potion
          else{choice=10;}      //Don't Need one Use Ether Instead
         }                      //END Use a Potion
         if((choice>=5)&&(choice<15))
         {                      //Use An Ether
           cout<<fg_red<<mstr.Name<<fg_cyan<<" consumes an ether."<<endl;
	       mstr.MP+=25;
 	       mstr.Damage = 0;
	       if(mstr.MP>=mstr.MPMax){mstr.MP = mstr.MPMax;}
         }                      //END USe AN Ether
         if((choice>=15) && (choice<70))
         {                      //Attack
          
          Damage = mstr.AttMod+(mstr.MinAtt+Randoms(mstr.MaxAtt-mstr.MinAtt));
	      Attack = Randoms(99);
	  	  if(mstr.ToHit>Attack)
	  	  {                    //Hits
     		 cout<<fg_red<<mstr.Name<<fg_cyan<<" Hits you and does "<<fg_yellow<<Damage<<fg_cyan<<" Damage!"<<endl;
     		 mstr.Damage = Damage;
          }                    //END Hits
		  else
		  {                    //Misses
		   cout<<fg_red<<mstr.Name<<fg_cyan<<" Attacks, but misses you!"<<endl;
           mstr.Damage = 0;
          }                    //END Misses
         }                     //END ATTACK
         if(choice>=70)
         {                     //Cast A Spell
             int cast = 0;
             if(mstr.HP<=(mstr.HPMax*(80/100)))
             {                 //Low HP? Cast Heal!
              int heal = 15+(Randoms(mstr.HPMax*(10/100)));
              cout<<fg_red<<mstr.Name<<fg_cyan<<" Casts Cure and heals "<<fg_white<<heal<<fg_cyan<<" HitPoints"<<endl;
              mstr.HP += heal;
              if(mstr.HP>=mstr.HPMax){mstr.HP = mstr.HPMax;}
              mstr.Damage = 0;
             }                //END Low HP? Cast Heal!
             else
             {                //Cast Other Spells
               cast = 1 + Randoms(3);
               if((cast == 1) || (cast == 3))  //FIREBALL
               {
                  cast = mstr.Level*(Randoms(30));
                  cout<<fg_red<<mstr.Name<<fg_cyan<<" unleashes a Fireball and does "<<fg_yellow<<cast<<fg_cyan<<" damage!"<<endl;
                  mstr.Damage = cast;
               }              //END FIREBALL
               else if(cast == 2)  //RASP
               {
                 cast = mstr.Level*(Randoms(10));
                 cout<<fg_red<<mstr.Name<<fg_cyan<<" casts Rasp and drains "<<fg_blue<<cast<<fg_cyan<<" Magic Points from you!"<<endl;
                 mstr.Damage = 0;
                 mstr.MPDamage = cast;
               }                 //END RASP
               
             }             //END Cast Other Spells
         }                 //END Cast A Spell
         
         
              
         
               
         
     
     
     
     }         //END Monster Is A Mage   
     

}              //END Monster Turn Function

void Combat::PlayerTurn(Player &pc)
{
     bool TurnOver = false;
     do{
     string opt;
     int Damage = 0;
     pc.Damage = 0;
     Defended = false;

     
     cout<<"("<<fg_white<<"F"<<fg_cyan<<")ight"<<endl; 
	 cout<<"("<<fg_white<<"R"<<fg_cyan<<")un"<<endl; 
	 cout<<"("<<fg_white<<"D"<<fg_cyan<<")efend"<<endl; 
	 cout<<"("<<fg_white<<"M"<<fg_cyan<<")agic"<<endl; 
	 cout<<"("<<fg_white<<"U"<<fg_cyan<<")se Item"<<endl;
	 cout<<fg_blue<<"What do you want to do? "<<fg_white;
     cin>>opt;
     cout<<"\n";
     cout<<fg_cyan;
     opt[0] = toupper(opt[0]);
     
     if(opt[0] == 'F')
     {
        int roll = Randoms(100);
        if(roll<=83)
        {
         Damage = pc.MinAtt+Randoms(pc.MaxAtt-pc.MinAtt); 
         pc.Damage = Damage;
         cout<<"Your attack deals "<<fg_yellow<<Damage<<fg_cyan<<" damage!"<<endl;
        }
        else
        {
          cout<<"Your attack misses the monster"<<endl;
          
        }
        TurnOver = true;
     }
     else if(opt[0] == 'R')
     {
       int flee = Randoms(100);
       
       if(flee>77 && CanFlee)
       {
         cout<<"You flee from the monster!"<<endl;
         _getch();
         system("clear");
         Fled = true;
         TurnOver = true;
       }
       else if(!CanFlee)
       {
         cout<<"Can't Escape!"<<endl;
         _getch();
         TurnOver = true;
       }
       else
       {     
         cout<<"You attempt to escape from the battle, but fail miserably"<<endl;
         TurnOver = true;
       }   
     }
     else if(opt[0] == 'D')
     {
      Damage = pc.MinAtt+Randoms(pc.MaxAtt-pc.MinAtt); 
      pc.Damage = Damage;
      cout<<"You take up a defensive stance and are able to resist "<<fg_yellow<<Damage<<fg_cyan<<" damage!"<<endl;
      Defended = true;
      TurnOver = true;
     }
     else if(opt[0] == 'U')
     {
        system("clear");
        cout<<"("<<fg_white<<"E"<<fg_cyan<<")ther    ("<<pc.Ethers<<")"<<endl; 
		cout<<"("<<fg_white<<"P"<<fg_cyan<<")otion   ("<<pc.Potions<<")"<<endl; 
	    cout<<"("<<fg_white<<"R"<<fg_cyan<<")eturn"<<endl;
        cout<<fg_blue<<"Which Item? "<<fg_white;
		cin>>opt;
        cout<<"\n";
		cout<<fg_cyan;
        opt[0] = toupper(opt[0]);
               if(opt[0] == 'E')
               {
                 if(pc.MP>=pc.MPMax)
                 {
                   cout<<"You don't need one."<<endl;
                   cout<<"Press A Key..."<<endl;
                   _getch();
                   system("clear");
                 }
                 else if(pc.Ethers<=0)
                 {
                   cout<<"You don't have any"<<endl;
                   cout<<"Press A Key..."<<endl;
                   _getch();
                   system("clear");
                 }
                 else
                 { 
                 cout<<"You use an Ether and recover "<<fg_blue<<"35 "<<fg_cyan<<"MP."<<endl;
                 pc.MP += 35;
                 if(pc.MP>=pc.MPMax){pc.MP=pc.MPMax;}
                 pc.Ethers -=1;
                 TurnOver = true;
                 }
               }
               else if(opt[0] == 'P')
               {
                 if(pc.HP>=pc.HPMax)
                 {
                   cout<<"You don't need one."<<endl;
                   cout<<"Press A Key..."<<endl;
                   _getch();
                   system("clear");
                 }
                 else if(pc.Potions<=0)
                 {
                   cout<<"You don't have any"<<endl;
                   cout<<"Press A Key..."<<endl;
                   _getch();
                   system("clear");
                 }
                 else
                 { 
                 cout<<"You use a Potion and recover "<<fg_red<<"50 "<<fg_cyan<<"HP."<<endl;
                 pc.HP += 50;
                 if(pc.HP>=pc.HPMax){pc.HP=pc.HPMax;}
                 pc.Potions -=1;
                 TurnOver = true;
                 }
               }
               else if(opt[0] == 'R')
               {
                 system("clear");
               }   
     }
     else if(opt[0] == 'M')
     {
         system("clear");
         cout<<"("<<fg_white<<"A"<<fg_cyan<<")   Quake     "<<pc.Magic.quake<<"/10   4MP"<<endl; 
		 cout<<"("<<fg_white<<"B"<<fg_cyan<<")   Fire      "<<pc.Magic.fire<<"/10   6MP"<<endl; 
		 cout<<"("<<fg_white<<"C"<<fg_cyan<<")   Bolt      "<<pc.Magic.bolt<<"/10   8MP"<<endl; 
		 cout<<"("<<fg_white<<"D"<<fg_cyan<<")   Ice       "<<pc.Magic.ice<<"/10   10MP"<<endl; 
		 cout<<"("<<fg_white<<"E"<<fg_cyan<<")   Cure      "<<pc.Magic.cure<<"/30   5MP"<<endl; 
		 cout<<"("<<fg_white<<"F"<<fg_cyan<<")   Drain     "<<pc.Magic.drain<<"/10  10MP"<<endl; 
		 cout<<"("<<fg_white<<"G"<<fg_cyan<<")   Rasp      "<<pc.Magic.rasp<<"/10   20MP"<<endl; 
		 cout<<"("<<fg_white<<"H"<<fg_cyan<<")   Windslash "<<pc.Magic.windslash<<"/15   15MP"<<endl; 
		 cout<<"("<<fg_white<<"R"<<fg_cyan<<")eturn"<<endl; 
		 cout<<fg_blue<<"What spell do you wish to cast? "<<fg_white;
         cin>>opt;
         cout<<"\n";
         opt[0] = toupper(opt[0]);
         cout<<fg_cyan; 
           if(opt[0] == 'A')
           {
              if(pc.Magic.quake)
              {
                if(pc.MP>=4)
                {
                   Damage = pc.Magic.quake * 10;
                   cout<<"You cast quake and do "<<fg_yellow<<Damage<<fg_cyan<<" damage."<<endl;        
                   pc.MP -= 4;
                   pc.Damage = Damage;
                   TurnOver = true;
                }
                else{cout<<"Not Enough MP!"<<pc.MP<<endl; _getch(); system("clear");}
              }
              else{cout<<"You Don't Have That Spell!"<<endl; _getch(); system("clear");}         
           }
           
           else if(opt[0] == 'B')
           {
              if(pc.Magic.fire)
              {
                if(pc.MP>=6)
                {
                   Damage =(pc.Magic.fire * 5)+Randoms(51);
                   cout<<"You cast Fire and do "<<fg_yellow<<Damage<<fg_cyan<<" damage."<<endl;        
                   pc.MP -= 6;
                   pc.Damage = Damage;
                   TurnOver = true;
                }
                else{cout<<"Not Enough MP!"<<endl; _getch(); system("clear");}
              }
              else{cout<<"You Don't Have That Spell!"<<endl; _getch(); system("clear");}         
           }
           
           else if(opt[0] == 'C')
           {
              if(pc.Magic.bolt)
              {
                if(pc.MP>=8)
                {
                   Damage =(pc.Magic.bolt * 5)+Randoms(61);
                   cout<<"You cast Bolt and do "<<fg_yellow<<Damage<<fg_cyan<<" damage."<<endl;        
                   pc.MP -= 8;
                   pc.Damage = Damage;
                   TurnOver = true;
                }
                else{cout<<"Not Enough MP!"<<endl; _getch(); system("clear");}
              }
              else{cout<<"You Don't Have That Spell!"<<endl; _getch(); system("clear");}         
           }
           
           else if(opt[0] == 'D')
           {
              if(pc.Magic.ice)
              {
                if(pc.MP>=10)
                {
                   Damage =(pc.Magic.ice * 5)+Randoms(71);
                   cout<<"You cast Ice and do "<<fg_yellow<<Damage<<fg_cyan<<" damage."<<endl;        
                   pc.MP -= 10;
                   pc.Damage = Damage;
                   TurnOver = true;
                }
                else{cout<<"Not Enough MP!"<<endl; _getch(); system("clear");}
              }
              else{cout<<"You Don't Have That Spell!"<<endl; _getch(); system("clear");}         
           }
           
           else if(opt[0] == 'E')
           {
              if(pc.Magic.cure)
              {
                if(pc.MP>=5)
                {
                   if(pc.HP<=pc.HPMax){
                   cout<<"You cast Cure and heal "<<fg_red<<(pc.Magic.cure * 20)<<fg_cyan<<" damage."<<endl;        
                   pc.MP -= 5;
                   pc.HP += (pc.Magic.cure * 25);
                   if(pc.HP>=pc.HPMax){pc.HP=pc.HPMax;}
                   pc.Damage = 0;
                   TurnOver = true;
                   }
                   else{cout<<"You're at full health already!"<<endl; _getch(); system("clear");}
                }
                else{cout<<"Not Enough MP!"<<endl; _getch(); system("clear");}
              }
              else{cout<<"You Don't Have That Spell!"<<endl; _getch(); system("clear");}         
           }
           
           else if(opt[0] == 'F')
           {
              if(pc.Magic.drain)
              {
                if(pc.MP>=10)
                {
                   Damage = 1+Randoms(pc.Magic.drain * 5);
                   cout<<"You cast Drain and siphon "<<fg_yellow<<Damage<<fg_cyan<<" HP to heal your wounds!"<<endl;
                   pc.MP -= 10;
                   pc.Damage = Damage;
                   pc.HP += Damage;
                   if(pc.HP>=pc.HPMax){pc.HP=pc.HPMax;}
                   TurnOver = true;
                }
                else{cout<<"Not Enough MP!"<<endl; _getch(); system("clear");}
              }
              else{cout<<"You Don't Have That Spell!"<<endl; _getch(); system("clear");}         
           }
           
           else if(opt[0] == 'G')
           {
              if(pc.Magic.rasp)
              {
                if(pc.MP>=5)
                {
                   Damage = 1+Randoms(pc.Magic.drain * 5);
                   cout<<"You cast Rasp and siphon "<<fg_yellow<<Damage<<fg_cyan<<" HP to replenish your Mana!"<<endl;
                   pc.MP -= 5;
                   pc.Damage = Damage;
                   pc.MP += Damage;
                   if(pc.MP>=pc.MPMax){pc.MP=pc.MPMax;}
                   TurnOver = true;
                }
                else{cout<<"Not Enough MP!"<<endl; _getch(); system("clear");}
              }
              else{cout<<"You Don't Have That Spell!"<<endl; _getch(); system("clear");}         
           }
           
           else if(opt[0] == 'H')
           {
              if(pc.Magic.windslash)
              {
                if(pc.MP>=15)
                {
                   Damage =(pc.Magic.windslash * 20)+Randoms(21);
                   cout<<"You cast WindSlash and do "<<fg_yellow<<Damage<<fg_cyan<<" damage."<<endl;        
                   pc.MP -= 15;
                   pc.Damage = Damage;
                   TurnOver = true;
                }
                else{cout<<"Not Enough MP!"<<endl; _getch(); system("clear");}
              }
              else{cout<<"You Don't Have That Spell!"<<endl; _getch(); system("clear");}         
           }
           else{system("clear");}
     }
     else
         {
          cout<<"You Can't Do That! Try Again."<<endl;
          cout<<"Press Any Key"<<endl;
          _getch();
          system("clear");

         } 
    }while(!TurnOver); 
}//END PLAYERS TURN

void Combat::LevelUp(Player &pc)
{
    cout<<fg_yellow<<"You Have Gained a Level!"<<fg_cyan<<endl;
    _getch();
    system("clear");
    int points = 0;
    bool done = false;
    do
    {
        string opt;
        int choice;
        int HP, MP, AP;
        points = 50;
        choice = 0;
        HP = 0;
        MP = 0;
        AP = 0;
        cout<<"You may now add points to your HP, MP and Attack."<<endl;
        system("pause");
        cout<<"You currently have: "<<fg_white<<points<<fg_cyan<<" points"<<endl;
        cout<<"HP:   "<<fg_yellow<<pc.HPMax<<fg_cyan<<endl;
        cout<<"MP:   "<<fg_yellow<<pc.MPMax<<fg_cyan<<endl;
        cout<<"Att:  "<<fg_yellow<<pc.MaxAtt<<fg_cyan<<endl;
        cout<<fg_blue<<"How many points would you like to add to your HP?: "<<fg_white;
        cin>>opt;
        choice = stoi(opt);
        cout<<fg_cyan;
        system("clear");
        if(choice<=points){HP += choice; points -= choice;}
        //else if(){points = -1;}
        else{ points = -1;}
        if(points>0)
        {
         cout<<"You currently have: "<<fg_white<<points<<fg_cyan<<" points"<<endl;           
         cout<<"HP:   "<<fg_yellow<<pc.HPMax<<fg_white<<"      +        "<<HP<<fg_cyan<<endl;
         cout<<"MP:   "<<fg_yellow<<pc.MPMax<<fg_white<<"      +        "<<MP<<fg_cyan<<endl;
         cout<<"Att:  "<<fg_yellow<<pc.MaxAtt<<fg_white<<"      +        "<<AP<<fg_cyan<<endl;
         cout<<fg_blue<<"How many points would you like to add to your MP?: "<<fg_white;
         cin>>opt;
         choice = stoi(opt);
         cout<<fg_cyan;
         system("clear");
         if((int)choice<=points){MP += choice; points -= choice;}
         else{ points = -1;}
        }
        if(points>0)
        {
         cout<<"You currently have: "<<fg_white<<points<<fg_cyan<<" points"<<endl;
         cout<<"HP:   "<<fg_yellow<<pc.HPMax<<fg_white<<"      +        "<<HP<<fg_cyan<<endl;
         cout<<"MP:   "<<fg_yellow<<pc.MPMax<<fg_white<<"      +        "<<MP<<fg_cyan<<endl;
         cout<<"Att:  "<<fg_yellow<<pc.MaxAtt<<fg_white<<"      +        "<<AP<<fg_cyan<<endl;;
         cout<<fg_blue<<"How many points would you like to add to your Attack?: "<<fg_white;
         cin>>opt;
         choice = stoi(opt);
         cout<<fg_cyan;
         system("clear");
         if((int)choice<=points){AP += choice; points -= choice;}
        }
        if(!points)
        {
         cout<<"HP:   "<<fg_yellow<<pc.HPMax<<fg_white<<"      +        "<<HP<<fg_cyan<<endl;
         cout<<"MP:   "<<fg_yellow<<pc.MPMax<<fg_white<<"      +        "<<MP<<fg_cyan<<endl;
         cout<<"Att:  "<<fg_yellow<<pc.MaxAtt<<fg_white<<"      +        "<<AP<<fg_cyan<<endl;
         cout<<fg_blue<<"Are These Stats OK?"<<fg_white;
         cin>>opt;
         opt[0] = toupper(opt[0]);
         cout<<fg_cyan;
         if(opt[0] == 'Y')
         {
          pc.HPMax += HP;
          pc.HP = pc.HPMax;
          pc.MPMax += MP;
          pc.MP = pc.MPMax;
          pc.MaxAtt += AP;
          pc.MinAtt = (pc.MaxAtt*(60/100));
          pc.XPForNext = pc.level * 107;
          pc.level++;        
          done = true;
         }
          system("clear");
        }
        if(points){cout<<"You must use all points, and only all points. Please try again."<<endl;
        _getch();
        }
    }while(!done);
         
}

bool Combat::Start(Player &PC, Monster &mstr, bool escape)
{
  cout<<fg_yellow<<"\n\n Get Ready For A Fight!"<<fg_cyan<<endl;     
  CanFlee = escape;
  Fled = false;
  Defended = false;
  bool done = false;
  do
  {   
      _getch();
      system("clear");
      cout<<"Name:    "<<fg_white<<PC.Name<<fg_cyan<<endl;
      cout<<"HP:      "<<fg_white<<PC.HP<<fg_cyan<<"/"<<PC.HPMax<<endl;
      cout<<"MP:      "<<fg_white<<PC.MP<<fg_cyan<<"/"<<PC.MPMax<<endl;
      cout<<"\n";
      cout<<"Monster: "<<fg_white<<mstr.Name<<fg_cyan<<endl;
      cout<<"\n\n";
      PlayerTurn(PC);
      cout<<"\n";
      if(Fled){done = true; break;}
      MonsterTurn(mstr);
      if(Defended){mstr.Damage -= PC.Damage; PC.Damage = 0;}
      if(mstr.Damage < 0){mstr.Damage = 0;}
      PC.HP -= mstr.Damage;
      PC.MP -= mstr.MPDamage;
      mstr.HP -= PC.Damage;
      if(PC.MP<0){PC.MP = 0;}
      if(PC.HP<0){PC.HP = 0;}
      
      if(PC.HP<=0){cout<<fg_red<<"\n\nYou Have Been Defeated!!"<<endl; PC.Alive = false; system("pause");cout<<fg_cyan<<endl;return(false);}//DEFEAT!
      if(mstr.HP<=0)              //VICTORY!
      {
        cout<<fg_magenta<<"\n\nYou Have Defeated "<<mstr.Name<<"!!\n"<<endl;
        cout<<"You Recieve: "<<fg_white<<mstr.XP<<" XP, "<<fg_red<<mstr.Potions<<fg_white<<" Potions, "<<fg_magenta<<mstr.Ethers<<fg_white<<" Ethers, and "<<fg_yellow<<mstr.Gold<<fg_white<<" Gold.\n\n";
        PC.Gold += mstr.Gold;
        PC.Potions += mstr.Potions;
        PC.Ethers += mstr.Ethers;
        PC.XP += mstr.XP;
        if(PC.XP >= PC.XPForNext){LevelUp(PC);}
        done = true;
        
      }
      
  }while(!done);
  return true;
}

