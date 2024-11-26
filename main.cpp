#include <cstdlib>
#include <iostream>
#include <fmod.hpp>
#include <fmod_errors.h>
#include <fmod_common.h>
#include "Combat.h"
#include "Quests.h"
#include "Mastermind.hpp"
#include "Globals.h"
#include "Legacy/battle.h"
//#include "console.h"

//using namespace JadedHoboConsole;
using namespace std;
using namespace Globals;


FMOD_RESULT result;


FMOD::System *soundSystem = NULL;
FMOD::SoundGroup *musicGroup = 0;
FMOD::ChannelGroup *channelGroup = 0;
FMOD::Sound *Battle = 0, *Quest = 0, *Opening = 0, *KBattle = 0, *pop = 0;
FMOD::Channel *battleChannel = 0, *questChannel = 0, *openingChannel = 0, *kBattleChannel = 0, *popChannel=0;


bool Shop = false;

void StartGame(Player &PC);


//TODO: Finish Quest formatting in quest 8
//TODO: Rework Monster engine to actually have levels make sense (Increased difficulty, but sanely, on second playthroughs)
//TODO: Fix all spelling and grammar errors
//TODO: Do colouring in Quest 8
//TODO: Balance tweaks (some things are WAY to hard, others too easy)
//TODO: Apply learned C# OOP principles to make this code not stupid.
//TODO: Rework Mastermind
//TODO: Rework Combat UI, and UI in general and, indeed, the quest engine.
/*
    Most story posts should clear the screen, and redraw the UI (Need a DrawUI method)
    Quest should be a class with a list(std::vector?) of story steps (Also a class)
    Methods to return render a quest step under the UI (eg. Quest.RenderStep();)
    RenderStep would Render the Base UI and also handle rendering the base UI
    Shop could be refactored into this Quest object.
    PC should be saved at each quest step, and QuestStep status stored for easy pickup and go.
*/
//TODO: Create Hunting grounds as an option between quests to fight for money and levels.
//TODO: Create a Random Laberynth built of generated rooms.

int main(int argc, char *argv[])
{
     MFight();
     smallperson();
// if (FSOUND_GetVersion() < FMOD_VERSION)
//     {
//         cout<< "Error : You are using the wrong DLL version!  You should be using FMOD %.02f\n";
//         cout<< FMOD_VERSION;
//         exit(1);
//     }
// if (!FSOUND_Init(44100, 32, 0))
// 	{
// 		cout<<fg_red<<FSOUND_GetError();
// 		exit(1);
// 	}
     result = FMOD::System_Create(&soundSystem);      // Create the main system object.
     if (result != FMOD_OK)
     {
          printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
          exit(-1);
     }

     result = soundSystem->init(512, FMOD_INIT_NORMAL, 0);    // Initialize FMOD.
     if (result != FMOD_OK)
     {
          printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
          exit(-1);
     }

     soundSystem->createSound("music/battle.mid", FMOD_LOOP_NORMAL, 0, &Battle);
     soundSystem->createSound("music/quest.mid", FMOD_LOOP_NORMAL, 0, &Quest);
     soundSystem->createSound("music/opener.mid", FMOD_LOOP_NORMAL, 0, &Opening);
     soundSystem->createSound("music/kbattle.mid", FMOD_LOOP_NORMAL, 0, &KBattle);
     soundSystem->createSound("music/pop.mid", FMOD_LOOP_NORMAL, 0, &pop);
     soundSystem->createSoundGroup("Music", &musicGroup);
     soundSystem->createChannelGroup("MusicChannels", &channelGroup);

     Battle->setSoundGroup(musicGroup);
     Quest->setSoundGroup(musicGroup);
     Opening->setSoundGroup(musicGroup);
     KBattle->setSoundGroup(musicGroup);
     pop->setSoundGroup(musicGroup);


    string opt;
    Player *PC = new Player;
    bool Exit = false;
    soundSystem->playSound(Opening, channelGroup, false, &openingChannel);
 do{
    cout<<fg_cyan<<"Welcome To Grand Adventure, Would you like to start a ("<<fg_white<<"N"<<fg_cyan<<")ew Game or ("<<fg_white<<"L"<<fg_cyan<<")oad a\nsaved game?\n";
    cin>>opt;
    opt[0] = toupper(opt[0]);

    if(opt[0] == 'L')
    {
      string File;
      cout<<fg_white;
      cout<<fg_cyan;
      cout<<"\n\nPlease choose a character to load: ";
      cin>>File;
      PC->Load(File);
      PC->Alive = true;
      StartGame(*PC);


    }

    else if(opt == "Mastermind")
    {
         Mastermind game;
         game.Start();
    }

    else if(opt == "MonsterMash")
    {
      soundSystem->playSound(pop, channelGroup, false, &popChannel);
      Monster mstr;
      string name, opt;
      bool magic;
      int HD, MD, Lvl, GP, Pot, Eth, xp, attackmod, hit;
	  float attack;
      cout<<bg_gray<<fg_yellow<<clr<<"Welcome to the Grand Adventure Monster Creator!"<<endl;
      cout<<"This is a Front-End mainly for the design stage of GA-OOP."<<endl;
      cout<<"This Tool is where Monsters are created and then saved to .mon files."<<endl;
      system("pause");
      system("clear");
      cout<<"Please enter the monsters name: ";
      cin>>name;
      cout<<"\n\nIs this monster a mage? ";
      cin>>opt;
      opt[0] = toupper(opt[0]);
      if(opt[0]=='Y'){magic = true;}
      else{magic = false;}
      cout<<"\n\nPlease enter the monsters base HP: ";
      cin>>HD;
      cout<<"\n\nPlease enter the monster base MP: ";
      cin>>MD;
      cout<<"\n\nPlease enter the monsters Level: ";
      cin>>Lvl;
      cout<<"\n\nPlease Enter the monsters base Gold: ";
      cin>>GP;
      cout<<"\n\nPlease Enter the monsters Potions: ";
      cin>>Pot;
      cout<<"\n\nPlease Enter the monsters Ehters: ";
      cin>>Eth;
      cout<<"\n\nPlease Enter the monsters base XP: ";
      cin>>xp;
      cout<<"\n\nPlease Enter the monsters base Attack: ";
      cin>>attack;
      cout<<"\n\nPlease Enter the monsters base Attack Modifier: ";
      cin>>attackmod;
      cout<<"\n\nPlease Enter the monsters To Hit: ";
      cin>>hit;

      mstr.Init(name, magic, HD, MD, Lvl, GP, Pot, Eth, xp, attack, attackmod, hit);
      mstr.Save(("Mons/"+name));
      system("pause");
      system("clear");
      cout<<fg_yellow;
      cout<<"NAME:      "<<fg_white<<mstr.Name<<fg_yellow<<endl;
      cout<<"HP:        "<<fg_white<<mstr.HP<<"/"<<mstr.HPMax<<fg_yellow<<endl;
      cout<<"MP:        "<<fg_white<<mstr.MP<<"/"<<mstr.MPMax<<fg_yellow<<endl;
      cout<<"LEVEL:     "<<fg_white<<mstr.Level<<fg_yellow<<endl;
      cout<<"GOLD:      "<<fg_white<<mstr.Gold<<fg_yellow<<endl;
      cout<<"POTIONS:   "<<fg_white<<mstr.Potions<<fg_yellow<<endl;
      cout<<"ETHERS:    "<<fg_white<<mstr.Ethers<<fg_yellow<<endl;
      cout<<"XP:        "<<fg_white<<mstr.XP<<fg_yellow<<endl;
      cout<<"DAMAGE:    "<<fg_white<<mstr.Damage<<fg_yellow<<endl;
      cout<<"ATTACK:    "<<fg_white<<mstr.MinAtt<<" - "<<mstr.MaxAtt<<fg_yellow<<endl;
      cout<<"TO HIT:    "<<fg_white<<mstr.ToHit<<fg_yellow<<endl;




    }

    else if(opt == "MonsterView")
    {
      soundSystem->playSound(pop, channelGroup, false, &popChannel);
      cout<<"Choose a monster to view."<<endl;
      cin>>opt;
      Monster mstr;
      mstr.Load(("Mons/"+opt));
      cout<<fg_yellow;
      cout<<"NAME:      "<<fg_white<<mstr.Name<<fg_yellow<<endl;
      cout<<"LEVEL:     "<<fg_white<<mstr.Level<<fg_yellow<<endl;
      cout<<"HP:        "<<fg_white<<mstr.HP<<"/"<<mstr.HPMax<<fg_yellow<<endl;
      cout<<"MP:        "<<fg_white<<mstr.MP<<"/"<<mstr.MPMax<<fg_yellow<<endl;
      cout<<"XP:        "<<fg_white<<mstr.XP<<fg_yellow<<endl;
      cout<<"DAMAGE:    "<<fg_white<<mstr.Damage<<fg_yellow<<endl;
      cout<<"GOLD:      "<<fg_white<<mstr.Gold<<fg_yellow<<endl;
      cout<<"ATTACK:    "<<fg_white<<mstr.MinAtt<<" - "<<mstr.MaxAtt<<fg_yellow<<endl;
      cout<<"POTIONS:   "<<fg_white<<mstr.Potions<<fg_yellow<<endl;
      cout<<"ETHERS:    "<<fg_white<<mstr.Ethers<<fg_yellow<<endl;
      cout<<"Base Attack:   "<<fg_white<<mstr.BAtt<<fg_yellow<<endl;
      system("pause");
    }

    else if(opt == "TestFight")
    {
         soundSystem->playSound(Battle, channelGroup, false, &battleChannel);
         Combat fgt;
         Monster mstr;
         int num = 0;
         cout<<"Enter the monster name";
         cin>>opt;
         opt = "mons/" + opt;
         mstr.Load(opt);
         cout<<"enter the monsters level";
         cin>>num;
         mstr.LvlChg(num);
         PC->Create();
         fgt.Start(*PC, mstr, true);
    }

    else if(opt == "Test")
    {
    int MaxAtt = 0, level = 3;
    float test = 0, BAtt = 25;
    test = BAtt * ((float)level/3);
    MaxAtt = (int)test;
    cout<<MaxAtt;
    }

    else if(opt == "QuestReset")
    {
         cout<<fg_red<<"This will reset your Quest # to 0."<<endl;
         cout<<"Type '"<<fg_white<<"Yes"<<fg_red<<" if you are sure."<<endl;
         cin>>opt;
         if(opt == "Yes"){PC->Quest = 0;}
    }




    else
	{
    PC->Create();
    PC->Alive = true;
    PC->Save(PC->Name);
    StartGame(*PC);
    }

    cout<<"Would you like to play again? ";
   cin>>opt;
   opt[0] = toupper(opt[0]);
   if(opt[0] != 'Y'){Exit = true;}
  }while(!Exit);




    system("PAUSE");
    return EXIT_SUCCESS;
}



void StartGame(Player &PC)
{
 bool GameOver = false;
 do{
    switch(PC.Quest)
    {
       case 0:
            PC.Quest++;

       case 1:
            Interlude(PC);
            Quest1(PC);
            if(!PC.Alive){GameOver = true;break;}
            PC.Quest++;
            PC.Save(PC.Name);

       case 2:
            Interlude(PC);
            Quest2(PC);
            if(!PC.Alive){GameOver = true;break;}
            PC.Quest++;
            PC.Save(PC.Name);

       case 3:
            Interlude(PC);
            Quest3(PC);
            if(!PC.Alive){GameOver = true;break;}
            PC.Quest++;
            PC.Save(PC.Name);

       case 4:
            Interlude(PC);
            Quest4(PC);
            if(!PC.Alive){GameOver = true;break;}
            PC.Quest++;
            PC.Save(PC.Name);

       case 5:
            Interlude(PC);
            Quest5(PC);
            if(!PC.Alive){GameOver = true;break;}
            PC.Quest++;
            PC.Save(PC.Name);

       case 6:
            Interlude(PC);
            Quest6(PC);
            if(!PC.Alive){GameOver = true;break;}
            PC.Quest++;
            PC.Save(PC.Name);

       case 7:

            Interlude(PC);
            Quest7(PC);
            if(!PC.Alive){GameOver = true;break;}
            PC.Quest++;
            PC.Save(PC.Name);

       case 8:
            //cout<<"Quest 8 Coming Soon!"<<endl;
            //system("pause");
            Interlude(PC);
            Quest8(PC);
            if(!PC.Alive){GameOver = true;break;}
            PC.Quest++;
            PC.Save(PC.Name);

       case 9:
            cout<<"Congratulations! You've managed the unthinkable and completed the"<<endl;
            cout<<"GRAND ADVENTURE!"<<endl;
            cout<<"Your Quest Progress has been reset."<<endl;
            PC.Quest = 0;
            PC.Save(PC.Name);
            system("pause");

            //TODO: Actually use the finishing line from 8 to reboot into Quest 1
            //TODO: Maybe actually have a REAL finish.



       default:
            GameOver = true;
            break;
    }
 }while(!GameOver);


}


