#include<fmod.h>
#include "Combat.h"
#include "Player.h"
#include "Mastermind.cpp"
extern bool Shop;
extern FMUSIC_MODULE *Battle, *Quest, *Opening, *KBattle, *pop;
void Quest1(Player &PC)
{
  string direction;
  Combat fgt;
  Monster Goblin, BlackSpider, RockMonster, Demon, DemonLord;
  Goblin.Load("Mons/Goblin");
  BlackSpider.Load("Mons/BlackSpider");
  RockMonster.Load("Mons/RockMonster");
  Demon.Load("Mons/Demon");
  DemonLord.Load("Mons/DemonLord");

  fgt.Randomize();

  //cout<<clr;
  cout<<fg_white<<"\n\n\nPress Any Key To Continue"<<fg_cyan;
  _getch();
FMUSIC_StopAllSongs();
FMUSIC_PlaySong(Quest);
//Quest 1, Story Block 1
cout<<"\n\n   A wizard knocks on your door and you open it to let him in. The wizard"<<endl;
cout<<"looks distressed and has sweat beaded all down his face."<<endl;
cout<<" 'You have to help me!' he says, panting and out of breath. 'Some vile demon"<<endl;
cout<<"stole my jewel of magic recharge. I can`t cast a single spell until it`s"<<endl;
cout<<"returned! PLEASE HELP ME, PLEASE!' With that the poor wizard runs off bawling."<<endl;
cout<<"\nWith a sense of duty you pick up your sword and set out on a magical journey."<<endl;
cout<<fg_white<<"\n\n\nPress Any Key To Continue"<<fg_cyan;
_getch();
cout<<clr;
//Quest 1, Story Block 2
cout<<"  As you walk down the path towards the Forsaken Cave, you see a patrol of Orcs"<<endl;
cout<<"marching by. You quickly hide bihind a conveniently placed boulder and pray to"<<endl;
cout<<"the gods of the sky realm that they don`t see you. Twenty minutes later, just"<<endl;
cout<<"after the Orc Battalion passes, you emerge from your hiding place covered with"<<endl;
cout<<"sweat 'Thank the gods' you say to yourself and you continue on your way."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue\n"<<fg_cyan<<endl;
_getch();
//Quest 1, Story Block 3
cout<<"Suddenly a small pathetic Orc runs up to you with its axe raised. It squeals"<<endl;
cout<<"like a pig being taken to the slaughter. You raise your sword and prepare for"<<endl;
cout<<"the attack!"<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue"<<fg_cyan<<endl;
_getche();
//Quest 1, Fight Block 1
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(Battle);
        fgt.Start(PC, Goblin, true);
        FMUSIC_StopSong(Battle);
        FMUSIC_SetPaused(Quest, FALSE);
cout<<fg_white<<"\n\nPress Any Key To Continue\n\n"<<fg_cyan;
_getche();
if(PC.Alive){
//Quest 1, Story Block 4
cout<<clr;
cout<<"After the fight you continue on your way feeling a little stronger. As you"<<endl;
cout<<"continue on your journey you come up on some woods."<<endl;
cout<<fg_blue<<"Do you wish to go ("<<fg_white<<"T"<<fg_blue<<")hrough or ("<<fg_white<<"A"<<fg_blue<<")round the woods?: "<<fg_white;
cin>>direction;
cout<<fg_cyan;
//Quest 1, Story Block 5A, Through Woods
if((direction[0]=='t')||(direction[0]=='T')){
cout<<clr;
cout<<"You enter the woods and almost immidiatly becomes dark. You pull out your torch"<<endl;
cout<<"and light the pine pitch using your flint and shard of steel. you hear a 'Hiss'"<<endl;
cout<<"coming from behind a bush. You backstep just in time not to be caught in the"<<endl;
cout<<"fangs of a black spider! "<<endl;
cout<<fg_white<<"\n\n\nPress Any Key To Continue\n\n"<<fg_cyan;
_getche();
//Quest 1, Fight Block 2A, In The Woods
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(Battle);
        fgt.Start(PC, BlackSpider, true);
        FMUSIC_StopSong(Battle);
        FMUSIC_SetPaused(Quest, FALSE);
cout<<fg_white<<"\n\n\nPress Any Key To Continue"<<fg_cyan;
_getche();
//Quest 1, Story Block 6A, Through Woods
if(PC.Alive){
cout<<"You continue on your journey and a couple of hours later you break the woods."<<endl;
cout<<"You set up camp out side the Forsaken Cave."<<endl;
}
}
//Quest 1, Story Block 5B, Around Woods
else{
cout<<clr;
cout<<"You decide that the forest is to dark for your liking and decide to go around."<<endl;
cout<<"After walking for about an hour you trip on something and land square on your"<<endl;
cout<<"face.'Oh My God!' you declare, 'It`s a Rock Monster!' "<<endl;
cout<<fg_white<<"\n\n\nPress Any Key To Continue"<<fg_cyan;
_getch();
//Quest 1, Fight Block 2b, Outside The Woods
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(Battle);
        fgt.Start(PC, RockMonster, true);
        FMUSIC_StopSong(Battle);
        FMUSIC_SetPaused(Quest, FALSE);
cout<<fg_white<<"\n\n\nPress Any Key To Continue"<<fg_cyan;
_getch();
//Quest 1, Story Block 6B, Around Woods
if(PC.Alive){
cout<<"You continue on your way and decide to set up camp outside the Forsaken Cave."<<endl;
cout<<"pitch your tent set a fire and go to sleep."<<endl;
}}}
//Quest 1, Story Block 7, In The Cave
if(PC.Alive){
cout<<fg_white<<"\n\nPress Any Key To Continue... "<<fg_cyan;
_getche();
cout<<clr;
cout<<"You enter the cave and you feel as if the air has turned to ice. As you continue"<<endl;
cout<<"through the cave a demon jumps out and swings its claws towards you. You"<<endl;
cout<<"backstep just in time and are pitched in battle."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue... \n\n"<<fg_cyan;
_getche();
//Quest 1, Fight Block 3
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(Battle);
        fgt.Start(PC, Demon, true);
        FMUSIC_StopSong(Battle);
        FMUSIC_SetPaused(Quest, FALSE);
//Quest 1, Story Block 8
cout<<fg_white<<"\n\nPress Any Key To Continue... \n\n"<<fg_cyan;
_getche();
if(PC.Alive){
cout<<clr;
cout<<"You continue you continue into the cave, sweat pouring down your face, despite"<<endl;
cout<<"the cold air, when you see a luminent blue glow coming from a little farther"<<endl;
cout<<"down the tunnel."<<endl;
cout<<fg_white<<"\n\n\nPress Any Key To Continue... "<<fg_cyan;
_getche();
cout<<"  'Finally!', you say to no one in particular. Suddenly the blue glow starts to"<<endl;
cout<<"move towards you. 'Oh Shit!' you exclaim, as the biggest Demonic creature you`ve"<<endl;
cout<<"ever seen steps into view."<<endl;
cout<<fg_white<<"\n\n\nPress Any Key To Continue... "<<fg_cyan;
_getche();
//Quest 1, Final Fight Block
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(KBattle);
        DemonLord.LvlChg(PC.level +1);
        fgt.Start(PC, DemonLord, true);
        FMUSIC_StopSong(KBattle);
        FMUSIC_SetPaused(Quest, FALSE);
cout<<fg_white<<"\n\nPress Any Key To Continue... "<<fg_cyan;
_getche();
//Quest 1, Story Block 9
if(PC.Alive){
cout<<clr;
cout<<"You kill the vile Demon Lord, take the mana stone, and raise your hand"<<endl;
cout<<"victoriously. Then you head back home."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue... \n\n"<<fg_cyan;
_getche();
//Quest 1, Final Story Block
cout<<"When you reach your house the old wizard is waiting for you with bloodshot eyes.\nAs you come up the walk the old wizard looks at you with eyes the size of dinner\nplates 'Did you get it?' he asks hopefully."<<endl;
cout<<fg_blue<<"What do you say? (Y)es ... or (S)orry ..."<<fg_white;
cin>>direction;
cout<<fg_cyan;
if((direction[0]=='n')||(direction[0]=='N')){
cout<<"The wizard sensing his stone nearby lifts his hands and casts a death spell"<<endl;
cout<<"which kills you instantly"<<endl;
cout<<"                 THE END"<<endl;
PC.HP=0;
PC.Alive = false;
}
else{
cout<<"'Yes I found your magical stone' you say. 'Oh Thank you!' says the Wizard, 'Here"<<endl;
cout<<"is your reward.' He hands you º"<<fg_yellow<<"5,000"<<fg_cyan<<" and three potions in exchange for"<<endl;
cout<<"his stone"<<endl;
PC.Potions+=3;
PC.Gold+=5000;
}}}}}




//---------------------------------------------------QUEST-2------------------------------------|
//==============================================================================================|
void Quest2(Player &PC)
{

  string direction;
  Combat fgt;
  Monster Demon, Manticore, Lizardman, GelTroop;
  Demon.Load("Mons/Demon");
  Manticore.Load("Mons/Manticore");
  Lizardman.Load("Mons/Lizardman");
  GelTroop.Load("Mons/GelTroop");



FMUSIC_StopAllSongs();
FMUSIC_PlaySong(Quest);
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 2, Story Block 1
cout<<"After breakfast you step out side to get some fresh air. When you close your"<<endl;
cout<<"door you see a knife in it. The knife holds a note to your door. You rip the"<<endl;
cout<<"note off the door, the note reads:"<<endl;
cout<<fg_white<<"   We Have your best friend and if you ever want to see her again you\n"<<endl;
cout<<"   need to bring º30000 to the spires reach castle by the next full moon.\n"<<fg_cyan<<endl;
cout<<"'º30,000! how will I ever get that much?' You scream after reading the ransom"<<endl;
cout<<"note."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 2, Story Block 2
cout<<clr;
cout<<"You pick up your sword and take off down the path at break neck speed towards"<<endl;
cout<<"Spires Reach Castle. As you are running, you suddenly find yourself getting up"<<endl;
cout<<"out of the dirt and staring right at a High Demon. It raises it`s trident and"<<endl;
cout<<"you are forced into battle!"<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(Battle);
Demon.LvlChg(PC.level);
fgt.Start(PC, Demon, true);
        FMUSIC_StopSong(Battle);
        FMUSIC_SetPaused(Quest, FALSE);
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
cout<<clr;
if(PC.Alive){
//Quest 2, Story Block 3
cout<<"You remove your sword from the demons chest and continue on your way, a little"<<endl;
cout<<"more cautious this time. You finaly reach the castle by about noon the next day."<<endl;
cout<<"You feel refreshed after camping the last night.";
PC.HP=PC.HPMax;
PC.MP=PC.MPMax;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 2, Story Block 4
cout<<"You enter the castle and as you get to the top a larg Manticore stands in your"<<endl;
cout<<"way and raises its weapon with a hateful smirk."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 2, Fight Block 2
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(Battle);
Manticore.LvlChg(PC.level);
fgt.Start(PC, Manticore, false);
        FMUSIC_StopSong(Battle);
        FMUSIC_SetPaused(Quest, FALSE);
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
if(PC.Alive){
//Quest 2, Story Block 5
cout<<"After killing the Manticore you head into the back room to find your friend. You"<<endl;
cout<<"see her hanging in chains on the wall you see a large Lizardman standing with"<<endl;
cout<<"his sword in his hand waiting for you."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 2, Fight Block 3
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(Battle);
Lizardman.LvlChg(PC.level +1);
fgt.Start(PC, Lizardman, false);
        FMUSIC_StopSong(Battle);
        FMUSIC_SetPaused(Quest, FALSE);

cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
if(PC.Alive){
//Quest 2, Story Block 6
cout<<"You free your best friend and make for the door just as a gel troop stands in"<<endl;
cout<<"your way"<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 2, Final Fight Block
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(Battle);
GelTroop.LvlChg(PC.level);
fgt.Start(PC, GelTroop, true);
        FMUSIC_StopSong(Battle);
        FMUSIC_SetPaused(Quest, FALSE);
if(PC.Alive){
//Quest 2, Final Story Block
cout<<"You take your friend and head outside. You run home just as fast as you can go."<<endl;
cout<<"When you reach town, you say goodbye to your friend and go inside your home."<<endl;
}}}}}



//----------------------------------------------QUEST3-----------------------------------------|
//=============================================================================================|
void Quest3(Player &PC)
{

  string direction;
  Combat fgt;
  Monster BlackDragon, Satyr, SatyrCaptain, SatyrCmdr, Clone;
  BlackDragon.Load("Mons/BlackDragon");
  Satyr.Load("Mons/Satyr");
  SatyrCaptain.Load("Mons/SatyrCaptain");
  SatyrCmdr.Load("Mons/SatyrCmdr");

FMUSIC_StopAllSongs();
FMUSIC_PlaySong(Quest);
cout<<fg_white<<"\n\nPress Any Key To Continue..."<<fg_cyan;
_getch();
cout<<clr;
//Quest 3, Story Block 1
cout<<"During breakfast you take the time to stretch your neck suddenly you realizes in"<<endl;
cout<<"shock that your roof appears to be missing. A loud screach tells you exactly who"<<endl;
cout<<"the thief is and you rise, your breakfast forgotten, as you stare in horror at"<<endl;
cout<<"the shadow of a large blue dragon. You can barely make out a figure upon the"<<endl;
cout<<"dragon's back. By the fact that it is being ridden and that it is a handsom"<<endl;
cout<<"animal you can tell it's a mount of the King's Impearial Guard. Your fear turns"<<endl;
cout<<"to dismay as you watch straws, the last remenants of your roof, fall from the"<<endl;
cout<<"talons of the flying beast. "<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 3, Story Block 2
cout<<"The dragon rider approaches you on the back of his powerful steed and speaks."<<endl;
cout<<"'Sorry `bout your roof but His Majesty demands your presence immediatly and we"<<endl;
cout<<"had to get your attention.'  He extends his hand and muttering you climb aboard"<<endl;
cout<<"the dragon.  All of a sudden the dragon takes into the air with such terrifying"<<endl;
cout<<"force you are almost knocked off.  Only your skill keeps you upright and you see"<<endl;
cout<<"the guard give a wicked smile. You then realize that not everyone is happy with"<<endl;
cout<<"you being summoned to see the King."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 3, Story Block 3
cout<<"When you arrive you notice that the castle is especially busy for this early in"<<endl;
cout<<"the morning and are shocked to see both the King and the Queen standing in their"<<endl;
cout<<"chamber clothes.  The King and Queen approach you their faces grave and as the"<<endl;
cout<<"king speaks 'You are the best adventurer we know of and there are tales far and"<<endl;
cout<<"wide describing your great exploits. But now we have a problem which must not go"<<endl;
cout<<"down in song and story for if it were to escape out to my enemies I would lose"<<endl;
cout<<"all I have accomplished. Two days ago my son, and only heir, went out with his"<<endl;
cout<<"friends on a hunting party and never returned.'"<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 3, Story Block 4
cout<<"'Forgive me for being blunt but I do not belive my son still breaths on this"<<endl;
cout<<"world.'  At this the Queen burst into tears and is taken away by her ladies in"<<endl;
cout<<"waiting.  The King seems unaware of her and as soon as it is quiet he continues"<<endl;
cout<<"'I have only one hope of keeping the throne in my family line and that is for"<<endl;
cout<<"my daughter to marry.  Here in lies your purpose for being here.  My daughter`s"<<endl;
cout<<"love has been captured and is being held by a group of satyrs who threaten to"<<endl;
cout<<"remove his organs and send his head home on a pike.  I need you to travel to"<<endl;
cout<<"these satyrs and take my daughter's love back!  My daughter will accompany you"<<endl;
cout<<"she is a skilled Magus and may be useful.'"<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 3, Story Block 5
cout<<"At this a young girl steps out of thin air.  She is about 15 years of age and"<<endl;
cout<<"looks far too choatic to be the powerful Magus you know that she is.  Putting"<<endl;
cout<<"his arm around her shoulders the King begins to speak 'This is my daughter"<<endl;
cout<<"Rachel. She is one-fourth fairy folk and may require a little watching.'  Rachel"<<endl;
cout<<"gives you a sly wink and grabbing your hand begins to chant. Suddenly you are"<<endl;
cout<<"surrounded by a large plume of smoke and find yourself face to face with two"<<endl;
cout<<"large black dragons!  Rachel running off to left is soon gone from your sight as"<<endl;
cout<<"to your horror a black dragon follows after her.  You try to stop it but the"<<endl;
cout<<"other one is upon you with lightning speed."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 3, Fight Block 1
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(KBattle);
fgt.Start(PC, BlackDragon, false);
        FMUSIC_StopSong(KBattle);
        FMUSIC_SetPaused(Quest, FALSE);

if(PC.Alive){
//Quest 3, Story Block 6
cout<<"You turn around quickly searching for Rachel expecting to find the worst, her"<<endl;
cout<<"charred body being feasted upon by one of your enemies.  However you are shocked"<<endl;
cout<<"to find her sitting on a rock and giggling as she crushes a mouse sized black"<<endl;
cout<<"dragon with a large piece of wood. You are a little shaken by the fashion in"<<endl;
cout<<"which this seemingly innocent young girl gleefully kills her foes. Smiling,"<<endl;
cout<<"Rachel puts a single magically potent hand upon your shoulder to ease your"<<endl;
cout<<"rather obvious distress and it takes all of your training just to keep from"<<endl;
cout<<"shuddering away."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 3, Story Block 7
cout<<"as you travel along, your eyes dart back and forth from the gloom ahead to the"<<endl;
cout<<"young Magus at your side.  Finally as though the forest had read your thoughts,"<<endl;
cout<<"you come upon the mouth of a cave.  'I have a plan!' says Rachel 'You stand at"<<endl;
cout<<"the entrance so they can't catch you all at once, and I'll go get Charles!'"<<endl;
cout<<"With that she vanishes and you take your position at the mouth of the cave just"<<endl;
cout<<"as the first guard runs up."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 3, Fight Block 2
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(Battle);
Satyr.LvlChg(PC.level);
fgt.Start(PC, Satyr, false);
if(PC.Alive){
Satyr.LvlChg(PC.level);
fgt.Start(PC, Satyr, false);
if(PC.Alive){
SatyrCmdr.LvlChg(PC.level +1);
fgt.Start(PC, SatyrCmdr, false);
if(PC.Alive){
SatyrCmdr.LvlChg(PC.level +1);
fgt.Start(PC, SatyrCmdr, false);
if(PC.Alive){
SatyrCaptain.LvlChg(PC.level +2);
fgt.Start(PC, SatyrCaptain, false);
if(PC.Alive){
SatyrCaptain.LvlChg(PC.level +2);
fgt.Start(PC, SatyrCaptain, false);
        FMUSIC_StopSong(Battle);
        FMUSIC_SetPaused(Quest, FALSE);

cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
cout<<clr;
//Quest 3, Story Block 8
if(PC.Alive){
cout<<"After having dispatched the last of the Satyr Guards, you are suprised to see"<<endl;
cout<<"one very frail satyr walk towards you. To an untrained warrior this might seem"<<endl;
cout<<"an easy match, but your training, and this man`s absence of fear tells you that"<<endl;
cout<<"this is the Magic user of the clan! Lifting his hands he casts a spell and a"<<endl;
cout<<"mirror image of you decends upon you, sword in hand."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 3, Final Fight Block
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(KBattle);
Clone.Init(PC.Name, true, PC.HPMax, PC.MPMax, 1, 300, PC.Potions, PC.Ethers, PC.XP, (float)PC.MaxAtt, 1, 70);
fgt.Start(PC, Clone, false);
        FMUSIC_StopSong(KBattle);
        FMUSIC_SetPaused(Quest, FALSE);
}
if(PC.Alive){
//Quest 3, Final Story Block
cout<<"You are startled by Rachel's hand at your shoulder, and you must admit you are a"<<endl;
cout<<"little shaken by running a sword through your own chest, and are surprised to"<<endl;
cout<<"find yourself back in the castle.  The guards carry Charles to his chambers and"<<endl;
cout<<"the King approaches 'Thank you noble "<<PC.Name<<"."<<endl;
cout<<"Although I can never begin to repay you maybe this will help.'\n"<<endl;
cout<<fg_yellow<<"Received King's Reward!\n"<<fg_white<<endl;
cout<<"You got:\n\n"<<endl;
cout<<"Plus one to your Windslash level"<<endl;
cout<<"º"<<fg_yellow<<"30,000"<<fg_cyan<<endl;
PC.Gold+=10000;
PC.Magic.windslash++;
}}}}}}}}

//---------------------------------------QUEST4-------------------------------------------------|
//==============================================================================================|
void Quest4(Player &PC)
{
    Combat fgt;
    fgt.Randomize();
    mastermind MasterM;
    Monster Imp;
    Imp.Load("Mons/Imp");

FMUSIC_StopAllSongs();
FMUSIC_PlaySong(Quest);
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
cout<<clr<<fg_cyan;
cout<<"After Breakfast, an Imp enters your home and gives you a puzzel. 'Finish this"<<endl;
cout<<"puzzel or die' says the hellish Imp. You look at the puzzel in dismay you read"<<endl;
cout<<"the cover and discover that it is called 'MASTERMIND'."<<endl;
cout<<"'Hmm' you say 'Lets see....'"<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan;
_getch();
FMUSIC_PlaySong(pop);
FMUSIC_SetPaused(Quest, TRUE);
if(MasterM.Start()){
FMUSIC_StopSong(pop);
FMUSIC_SetPaused(Quest, FALSE);
cout<<"So you got it eh says the Imp. Well I'm true to my word and shall let you live"<<endl;
cout<<"I'll also give you a prize! he waves his hands and you feel a tingle then he"<<endl;
cout<<"turns and leaves."<<endl;
PC.MPMax+=15;
PC.MP=PC.MPMax;
PC.HPMax+=15;
PC.HP=PC.HPMax;
}
else{
     FMUSIC_StopSong(pop);
     FMUSIC_PlaySong(KBattle);
cout<<"you got it wrong and I'm true to my word so now you die chuckles the imp"<<endl;
           fgt.Start(PC, Imp, false);
     FMUSIC_StopSong(KBattle);
     FMUSIC_SetPaused(Quest, FALSE);
if(PC.Alive){
cout<<"After a long and grueling battle you finally smite the hellish creature that"<<endl;
cout<<"slightly resembled an elf. You kick its corpse into the street and commence to"<<endl;
cout<<"cleaning the mess."<<endl;
}
else{
cout<<"After a long and grueling battle you are defeated by the hellish Imp."<<endl;


}
}
}


//-------------------------QUEST5------------------------------------------------------------------|
//=================================================================================================|
void Quest5(Player &PC)
{

     Combat fgt;
     fgt.Randomize();
     Monster FatGuy, Soldier, Commander, DragonSlayer;
     FatGuy.Load("mons/FatGuy");
     Soldier.Load("mons/Soldier");
     Commander.Load("mons/Commander");
     DragonSlayer.Load("mons/DragonSlayer");

FMUSIC_StopAllSongs();
FMUSIC_PlaySong(Quest);
//Quest 5, Story Block 1
cout<<"After Breakfast, you step outside to get somefresh air while taking a walk you"<<endl;
cout<<"see the Warlocks daughter Marie you wave politely and continue on your way."<<endl;
cout<<"As you are walking you pass a post and a poster catches your eye. You walk over"<<endl;
cout<<"and take a look."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 5, Story Block 2
cout<<clr<<"\n\n\n\n\n";
cout<<fg_white<<"                   All Welcome At The Tournament Of Campions"<<endl;
cout<<"To be held at the King`s Colosseum on the third Saturday of March' "<<fg_cyan<<endl;
cout<<"\n\n\n'Hey that`s tommorow' you say 'I better get ready!'"<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 5, Story Block 3
cout<<"The next day at high noon you stand at the entrance to the Kings Colosseum your hand rested o n the hilt of your sword over your shoulder."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
cout<<"A small stocky man walks over to you and says:"<<endl;
	if(PC.Gender=="Male")
	{
	cout<<"'Right this way sir will you be entering the tournament? Well I suppose you"<<endl;
	cout<<"wouldn`t have your sword if you weren`t. Well go on through the door on the"<<endl;
	cout<<"right.'"<<endl;
	}
	else
	{
	cout<<"'Hey there Ma`am are you bringing your husband his sword?'"<<endl;
	cout<<"At this your sword flashes from your bauldric and stops inches from his throat."<<endl;
	cout<<"'Ok... I was only askin`... No need to get voilent... Tournament's that way"<<endl;
	cout<<"through the door on the right.'"<<endl;
	}
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 5, Fight Block, Tournament
cout<<"You enter the door and draw your sword preparing for the battle ahead"<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(Battle);
FatGuy.LvlChg(PC.level);
fgt.Start(PC, FatGuy, false);
        FMUSIC_StopSong(Battle);
        FMUSIC_SetPaused(Quest, FALSE);
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
if(PC.HP>0){
cout<<"The crowd cheers you on as you exit the arena"<<endl;
PC.HP=PC.HPMax;
PC.MP=PC.MPMax;
cout<<"You prepare for your next bout and step into the arena"<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(Battle);
Soldier.LvlChg(PC.level);
fgt.Start(PC, Soldier, false);
        FMUSIC_StopSong(Battle);
        FMUSIC_SetPaused(Quest, FALSE);
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
if(PC.HP>0){
cout<<"The crowd cheers you on as you exit the arena"<<endl;
PC.HP=PC.HPMax;
PC.MP=PC.MPMax;
cout<<"You prepare for your next bout and step into the arena"<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(Battle);
Commander.LvlChg(PC.level);
fgt.Start(PC, Commander, false);
        FMUSIC_StopSong(Battle);
        FMUSIC_SetPaused(Quest, FALSE);
if(PC.HP>0){
cout<<"The crowd cheers you on as you exit the arena"<<endl;
PC.HP=PC.HPMax;
PC.MP=PC.MPMax;
cout<<"You prepare for your next bout and step into the arena"<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(KBattle);
DragonSlayer.LvlChg(PC.level +1);
fgt.Start(PC, DragonSlayer, false);
        FMUSIC_StopSong(KBattle);
        FMUSIC_SetPaused(Quest, FALSE);
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
if(PC.HP>0){
//Quest 5, Story Block 4
cout<<"As you pull your sword from the Dragon slayers chest the crowd begins to throw"<<endl;
cout<<"flowers as you wipe your blade cleen and exit the arena. As you're walking out"<<endl;
cout<<"of the colosseum, the same stockey man walks up to you and says 'Oh so ya` won"<<endl;
cout<<"eh, well heres your reward!'"<<endl;
if(PC.Gender=="Female"){
cout<<"'Here's º"<<fg_yellow<<"15,000"<<fg_cyan<<"'"<<endl;
PC.Gold+=15000;
}
else{
cout<<"'Here's º"<<fg_yellow<<"10,000"<<fg_cyan<<"'"<<endl;
PC.Gold+=10000;
}
cout<<"You accept the money and leave the colosseum."<<endl;
}}}}}


//----------------------------------------QUEST6---------------------------------------------------|
//=================================================================================================|
void Quest6(Player &PC)
{
     Combat fgt;
     fgt.Randomize();
     Player Evee;

                  Evee.MaxAtt = 60;
                  Evee.MinAtt = (Evee.MaxAtt/4);
                  Evee.HPMax = 100;
                  Evee.HP = Evee.HPMax;
                  Evee.MPMax = 30;
                  Evee.MP = Evee.MPMax;
                  Evee.level = 1;
                  Evee.Potions = PC.Potions;
                  Evee.Ethers = PC.Ethers;
                  Evee.Quest = 0;
                  Evee.XP = 0;
                  Evee.XPForNext = Evee.level * 107;
                  Evee.Damage = 0;
                  Evee.Gold = 0;
                  Evee.Magic = 0;


     Monster PapaSam, UncleSam, RedDragon;
     RedDragon.Load("mons/RedDragon");
     PapaSam.Load("mons/PapaSam");
     UncleSam.Load("mons/UncleSam");

FMUSIC_StopAllSongs();
FMUSIC_PlaySong(Quest);
if(Shop)
{
//Quest 6, Story Block 1A
cout<<"After leaving the store, you start walking around town looking for your friend,"<<endl;
cout<<"Jenny. You eventually find her at the lunch table at Uncle Sam's lounge. When"<<endl;
cout<<"Jenny see's you entering the lounge, she stands up and runs to you with a big"<<endl;
cout<<"smile on her face. Just before she reaches you, a stranger cuts in front of her"<<endl;
cout<<"with a knife!"<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 6, Fight Block 1A
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(Battle);
PapaSam.LvlChg(PC.level);
fgt.Start(PC, PapaSam, false);
        FMUSIC_StopSong(Battle);
        FMUSIC_SetPaused(Quest, FALSE);
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
}
else if(!Shop)
{
//Quest 6, Story Block 1B
cout<<"After Breakfast, you start to walk around town, looking for your friend, Jenny."<<endl;
cout<<"You eventually find her at the lunch table at Uncle Sam's lounge. Jenny see's"<<endl;
cout<<"you entering the lounge, and stands up. She runs towards you with a big smile"<<endl;
cout<<"on her face. However just before she reaches you a stranger cuts in front of her";
cout<<"with a knife!"<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 6, Fight Block 1A
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(Battle);
PapaSam.LvlChg(PC.level);
fgt.Start(PC, PapaSam, false);
        FMUSIC_StopSong(Battle);
        FMUSIC_SetPaused(Quest, FALSE);
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
}
if(PC.HP>0)
{
//Quest 6, Story Block 2
cout<<"After killing Uncle Sam's, oddly violent, father, you go by Uncle Sam and his"<<endl;
cout<<"workers, and take Jenny into the nearest forest, where Uncle Sam and his workers";
cout<<"lose sight of you. As you get deeper into the forest you hear a rustling in some";
cout<<"nearby bushes."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 6, Story Block 3
cout<<"You walk toward to the rustling bushes, and when you arrive, you discover a"<<endl;
cout<<"small wolf cub. 'Seems like this little one is lost.' says Jenny. you disagree"<<endl;
cout<<"stating that its probably waiting for its mother and start to move on. However"<<endl;
cout<<"when you yo walk away, it starts following you. You sigh as Jenny bends down to"<<endl;
cout<<"pick up the small cub, She decides to name him Evee."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 6, Story Block 4
cout<<"You and your friends decide to move on. After travelling for a bit Evee starts"<<endl;
cout<<"howling. When you look up, you realize that there are enemies in front of you."<<endl;
cout<<"  OH! damn, it's Uncle Sam!"<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 6, Story Block 5
cout<<"As Uncle Sam moves closer and closer to you and your friends, Evee starts to"<<endl;
cout<<"growl. Suddenly, Evee runs up to Uncle Sam and snaps him on his leg."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
//Quest 6, Fight Block 1A
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(Battle);
fgt.Start(Evee, UncleSam, false);
        FMUSIC_StopSong(Battle);
        FMUSIC_SetPaused(Quest, FALSE);
if(Evee.HP>0){
cout<<"After Evee defeats Uncle Sam You head deeper into the forest.  A few hours later";
cout<<"you break the woods and see a large village.  You and your friends head towards"<<endl;
cout<<"When you arrive you realize that it's the largest village that you have ever"<<endl;
cout<<"been to.  You walk down the main street and see a store with tons of equipment,"<<endl;
cout<<"however you are all to tired to stop in and instead, you and your friends head"<<endl;
cout<<"the Inn to get some rest."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
cout<<"The next day you and your group decide to explore the town a bit, and walk down"<<endl;
cout<<"a little street. A small girl comes running toward you and gives some flowers,"<<endl;
cout<<"and you stand and talk a little.  Suddenly there's a huge explosion off to the"<<endl;
cout<<"west. You tell the little girl to go home, and tell Jenny to head back to the"<<endl;
cout<<"inn while you go and check out the explosion site."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
cout<<"You arrive to find a very odd site. There is a destroyed statue with some"<<endl;
cout<<"strange markings nearby, and surrounding the shattered statue are several"<<endl;
cout<<"charred bodies.  Suddenly you hear the sound of large wings coming from a large"<<endl;
cout<<"tree. Stepping out from behind the tree is a huge winged monster with red eyes."<<endl;
cout<<"The beast flys towards you with angry eyes growing redder and redder."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
_getch();
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(KBattle);
RedDragon.LvlChg(3);
fgt.Start(PC, RedDragon, false);
        FMUSIC_StopSong(KBattle);
        FMUSIC_SetPaused(Quest, FALSE);
if(PC.HP>0){
cout<<"You fall to the ground tired and Evee approaches you, suddenly a large wolf pack";
cout<<"bounds out of the forest. Evee begins to run towards them but stops half way."<<endl;
cout<<"With one final glance as if to say goodbye Evee returns to his family. You dust"<<endl;
cout<<"yourself off, head back to the inn to get Jenny, and return home."<<endl;
}
}
else{
        FMUSIC_SetPaused(Quest, TRUE);
        FMUSIC_PlaySong(Battle);
UncleSam.LvlChg(PC.level);
fgt.Start(PC, UncleSam, false);
        FMUSIC_StopSong(Battle);
        FMUSIC_SetPaused(Quest, FALSE);
if(PC.HP>0){
cout<<"You run to Evee and try to help him out, however you are too late to save him."<<endl;
cout<<"You lost Evee, and you get really angry.  Saddened you slowly make your way"<<endl;
cout<<"home and have a funeral befitting a warrior as great as the wolf cub Evee."<<endl;
}
}
}
}


//-----------------QUEST7--------------------------------------------------------------------------|
//=================================================================================================|
void Quest7(Player &PC)
{

     Combat fgt;
     fgt.Randomize();
     Monster ArmedMugger, Azurith, Ricker, BulkyGuard, Troll;
     Azurith.Load("mons/Azurith");
     Ricker.Load("mons/Ricker");
     BulkyGuard.Load("mons/BulkyGuard");
     Troll.Load("mons/Troll");
     ArmedMugger.Load("mons/ArmedMugger");


FMUSIC_StopAllSongs();
FMUSIC_PlaySong(Quest);

string cont;
//opening
cout<<"You laze around the house until about noon, when you decide that you are kind of hungry."<<endl;
cout<<"you figure that you can either fix something to eat at home, or you can go out to the tavern and get a good meal. What do you want to do, go to the (T)avern, or eat at (H)ome?";
cin>>cont;
		//tavern
		if((cont[0]=='T')||(cont[0]=='t')){
		cout<<"You stand up and walk into your room where your money sack is, you pick it up and shake it to make sure that there is something in it.  The pouch feels light but you are sure that you have enough to buy something to eat."<<endl;
	 	cout<<"As you are walking down the road, you see the old warlock. You can change (D)irection and go around the old man, or you can (C)ontinue on your current course.What do you do?";
	 	cin>>cont;
	 		//around warlock
	 		if((cont[0]=='D')||(cont[0]=='d')){
	 		cout<<"You decide to change course and take the longer way through a dark ally.  Halfway through you feel a sharp prod on your lower back. 'Gimmie all yer money!' Declares the mugger.  You turn around and back hand him where you thought his head should be, but you strike the solid steel of a breatsplate.  You look up to find that the burly man is over seven feet tall."<<endl;
                 FMUSIC_SetPaused(Quest, TRUE);
                 FMUSIC_PlaySong(Battle);
                 ArmedMugger.LvlChg(PC.level);
                 fgt.Start(PC, ArmedMugger, false);
                 FMUSIC_StopSong(Battle);
                 FMUSIC_SetPaused(Quest, FALSE);
	 			if(PC.HP>0){
	 			cout<<"The mugger crumples in pain and you kick him out of your way and continue through the ally.";
	 			}
	 			}
	 		//warlock
	 		else if((cont[0]=='C') || (cont[0]=='c')){
	 		cout<<"You decide you will brave it and so continue on your way.  The Warlock smiles at you. 'Hello boy.' he says in a gruff voice. 'Off to lunch eh? Well here have an ether.' He hands you an ether on the house."<<endl;
	 		PC.Ethers+=1;
	 		}

	 	if(PC.HP>0){
	 	cout<<"When you finally reach the tavern, you walk up to the Bar. Will you order anything(y/n)? ";
	 	cin>>cont;
            cont[0] = toupper(cont[0]);
	 		if(cont[0]=='y'){
	 		cout<<"(A) Ale             º100"<<endl;
	 		cout<<"(B) Sandwich        º200"<<endl;
	 		cout<<"(C) Hot Meal        º500"<<endl;
	 		cout<<"(D) Dinner plate    º700"<<endl;
	 		cout<<"(E) Hotplate&Wine   º900"<<endl;
	 		cout<<"(F) Buffet Table   º1500"<<endl;
	 		cout<<"(G) Never Mind"<<endl;
	 		cout<<"wich one do you order?";
	 		cin>>cont;
	 			if(((cont[0]=='A')&&(PC.Gold>=100)) || ((cont[0]=='a')&&(PC.Gold>=100))){
	 			cout<<"You slam the ale. Hp restored"<<endl;
	 			PC.HP=PC.HPMax;
	 			}
	 			else if(((cont[0]=='B')&&(PC.Gold>=200)) || ((cont[0]=='b')&&(PC.Gold>=200))){
	 			cout<<"You devour the sandwich. Mp restored"<<endl;
	 			PC.MP=PC.MPMax;
	 			}
	 			else if(((cont[0]=='C')&&(PC.Gold>=500))||((cont[0]=='c')&&(PC.Gold>=500))){
	 			cout<<"You savor the hot meal and enjoy every bite. Hp & Mp restored"<<endl;
	 			PC.HP=PC.HPMax;
	 			PC.MP=PC.MPMax;
	 			}
	 			else if(((cont[0]=='D')&&(PC.Gold>=700)) || ((cont[0]=='d')&&(PC.Gold>=700))){
	 			cout<<"You eat your dinner politly. Hp max +10"<<endl;
	 			PC.HPMax+=10;
                PC.HP=PC.HPMax;
                }
	 			else if(((cont[0]=='E')&&(PC.Gold>=900))||((cont[0]=='e')&&(PC.Gold>=900))){
	 			cout<<"You eat your food and drink your wine. Mp max +10."<<endl;
	 			PC.MPMax+=10;
	 			PC.HP=PC.MPMax;
	 			}
	 			else if(((cont[0]=='F')&&(PC.Gold>=1500))||((cont[0]=='f')&&(PC.Gold>=1500))){
	 			cout<<"You spend three hours stuffing your face at the buffet table. Hp&Mp max +10."<<endl;
	 			PC.MPMax+=10;
	 			PC.HPMax+=10;
	 			PC.HP=PC.HPMax;
	 			PC.MP=PC.MPMax;
	 			}
	 			else if((cont[0]=='G') || (cont[0]=='g')){
	 			cout<<"You decide not to eat anything"<<endl;
	 			}
	 			else{
	 			cout<<"not enough º"<<endl;
	 			}
	 			}
	 			cout<<"After you order and eat, you leave the tavern and begin to head home.  As you are at the door a giant Troll attacks you."<<endl;
	 			   FMUSIC_SetPaused(Quest, TRUE);
                   FMUSIC_PlaySong(Battle);
                 Troll.LvlChg(PC.level -5);
                 fgt.Start(PC, Troll, false);
                   FMUSIC_StopSong(Battle);
                   FMUSIC_SetPaused(Quest, FALSE);
	 			if(PC.HP>0){
	 			cout<<"After dispatching the Troll you start to continue on your way, when a glint catches your eye. Thinking it maybe gold you bend down to pick it up. instead you discover an od crest (¤)."<<endl;
	 			cout<<"Who will you take it to?"<<endl;
	 			}

	 		else{
	 		cout<<"You decide not buy anything."<<endl;
	 		}

	 		 } }
	 	else if((cont[0]=='H')||(cont[0]=='h')){
	 		//home
	 		cout<<"You decide not to leave the house but rather to eat at home. You fix a sandwich and get a mug of water. You sit down on your bench and eat your sandwich but before you can get a taste of the water a troll bashes through your door, for no reason whatsoever except, to club you to death!"<<endl;
	 			   FMUSIC_SetPaused(Quest, TRUE);
                   FMUSIC_PlaySong(Battle);
                  Troll.LvlChg(PC.level -5);
                  fgt.Start(PC, Troll, false);
                   FMUSIC_StopSong(Battle);
                   FMUSIC_SetPaused(Quest, FALSE);
	 			if (PC.HP>0){
	 			cout<<"After defeating the Troll you begin to clean up the mess. Yuk you say as you pick up the Troll's arm and throw it out the door. As you are dragging the body to the door he drops a this crest (¤). who do you want to take it to?"<<endl;
	 			} }
	 	cout<<"Old (W)arlock or (M)arie? ";
	 	cin>>cont;
	 	if((cont[0]=='W')||(cont[0]=='w')){
	 				//warlock
	 				cout<<"You immediatly take the crest to the old store owner and show to him. Well. If I know anything I'd say that this is the crest of the dark one Kagos. Where did you find it?"<<endl;
					cout<<"A Troll attacked me and he was carrying it"<<endl;
	 				cout<<"Hmmm? I'd say Youd better get to the bottom of this.  Your life may be at stake."<<endl;
	 				}
	 	else{// if((cont[0]=='M')||(cont[0]=='m')){
	 				//marie
	 				cout<<"You take the crest to Marie and she gasps aloud. Where did you get that?!"<<endl;
	 				cout<<"You tell her how you were attacked by a Troll and found it on him. You must get to the bottom of this your life IS at stake!"<<endl;
	 				}
	 			if(PC.HP>0){
	 			cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
				_getch();
	 			cout<<"You figure its time to start your quest. you run out towards the Dark Ones Tower."<<endl;
	 			cout<<"When you finally reach the tower after an uneventul trip you find an extremely large gaurd patroling the tower's gate as you aproach he draws his sword."<<endl;
				cout<<"What do you do (A)ttack the gaurd or (F)lash (¤) coin at him? ";
	 			cin>>cont;
	 				if((cont[0]=='A')||(cont[0]=='a'))
	 				//Attack
	 				cout<<"you jump in swinging your sword!"<<endl;
	 				   FMUSIC_SetPaused(Quest, TRUE);
                       FMUSIC_PlaySong(Battle);
                      BulkyGuard.LvlChg(PC.level);
                      fgt.Start(PC, BulkyGuard, false);
                       FMUSIC_StopSong(Battle);
                       FMUSIC_SetPaused(Quest, FALSE);
	 			 	}
	 			 	else{// if((cont[0]=='F')||(cont[0]=='f')){
	 			 	cout<<"You flash the gaurd the crest and he waves you in."<<endl;
	 				}
	 			if(PC.HP>0){
	 			cout<<"You enter the tower and run straight towards the top when you blast through the door an old man spins around and hurls a large ball of flame at you. You dodge and are pitched in a new type of battle!"<<endl;
	 			     FMUSIC_SetPaused(Quest, TRUE);
                     FMUSIC_PlaySong(KBattle);
                   Azurith.LvlChg(PC.level +1);
                  fgt.Start(PC, Azurith, false);
                     FMUSIC_StopSong(KBattle);
                     FMUSIC_SetPaused(Quest, FALSE);
	 			if(PC.HP>0){
	 				cout<<"After a grueling you emerge from the tower victoriously. as you stumble away you are shocked to see the wizards apprentice. You will die! h exclaims."<<endl;
	 				   FMUSIC_SetPaused(Quest, TRUE);
                       FMUSIC_PlaySong(KBattle);
                      Ricker.LvlChg(PC.level);
                      fgt.Start(PC, Ricker, false);
                       FMUSIC_StopSong(KBattle);
                       FMUSIC_SetPaused(Quest, FALSE);
	 				 	if(PC.HP>0){
	 				 	cout<<"After another grueling battle with another wizard you straggle home, Mission accomplished, for some much needed rest."<<endl;
	 				 	}
	 				 	}
	 				 	}
	 				 	}


//--------------------------------------------SHOP-------------------------------------------------|
//=================================================================================================|
void Store(Player &PC)
{
int randomstore;
Combat fgt;
fgt.Randomize();
string choice, yes;
randomstore=fgt.Randoms(4);
if(randomstore==2){
cout<<"You walk in the store and your breath catches in your throat"<<endl;
if(PC.Gender[0]=='M'){
cout<<"as you stare not at the lovely smile of Marie, the Warlock`s daughter, but at"<<endl;
cout<<"the endless wrinkles which cover the old magus` head.\n"<<endl;
}
else if(PC.Gender[0]=='F'){
cout<<"as you stare not at your good friend Marie, the Warlock`s daughter, but at the"<<endl;
cout<<"endless wrinkles which cover the old magus` head.\n"<<endl;
}
cout<<"You try to back up but his hands are too fast and you feel terrifying pain as"<<endl;
cout<<"your body is magically ripped apart and the old magus searches for anything"<<endl;
cout<<"suspicious ("<<fg_white<<"-10hp"<<fg_cyan<<")."<<endl;
PC.HP-=10;
}
else{
cout<<"You walk into the store"<<endl;
if(PC.Gender[0]=='M'){
cout<<"and are fascinated by the breath taking beauty of Marie, the Warlock`s daughter.\n"<<endl;
}
else{
cout<<"and smile at your close friend Marie, the Warlock`s daughter.\n"<<endl;
}
}
if(PC.HP>0){
char no;
do{
cout<<"("<<fg_white<<"A"<<fg_cyan<<")   Potion                º"<<fg_yellow<<"50"<<fg_cyan<<endl;
cout<<"("<<fg_white<<"B"<<fg_cyan<<")   Blade Sharpening      º"<<fg_yellow<<"1000"<<fg_cyan<<endl;
cout<<"("<<fg_white<<"C"<<fg_cyan<<")   Exercise              º"<<fg_yellow<<"5000"<<fg_cyan<<endl;
cout<<"("<<fg_white<<"D"<<fg_cyan<<")   Ether                 º"<<fg_yellow<<"100"<<fg_cyan<<endl;
cout<<"("<<fg_white<<"E"<<fg_cyan<<")   Mana Meditation       º"<<fg_yellow<<"5000"<<fg_cyan<<endl;
cout<<"("<<fg_white<<"F"<<fg_cyan<<")   Spells                ºN/A\n"<<endl;
cout<<"e("<<fg_white<<"X"<<fg_cyan<<")it the store"<<endl;
cout<<fg_blue<<"Well, what would you like?("<<fg_yellow<<PC.Gold<<fg_blue<<")"<<fg_white<<endl;
cin>>choice;
cout<<fg_cyan;
if((choice[0]=='a')||(choice[0]=='A')){
if(PC.Gold>=50){
cout<<"Potions give back 10 hit points and costs º"<<fg_yellow<<"50"<<fg_cyan<<".  You have º"<<fg_yellow<<PC.Gold<<fg_cyan<<" and currently have "<<fg_white<<PC.Potions<<fg_cyan<<" potions."<<endl;
cout<<"Do you buy(y/n)? ";
cin>>yes;
if((yes[0]=='y')||(yes[0]=='Y')){
PC.Gold-=50;
PC.Potions++;
}
}
else{
cout<<"You don't have enough money."<<endl;
}
}
else if((choice[0]=='b')||(choice[0]=='B')){
if(PC.Gold>=1000){
cout<<"Blade Sharpening increases your attack by 15 points and costs º1000."<<endl;
cout<<"You have º"<<fg_yellow<<PC.Gold<<fg_cyan<<" and do "<<fg_white<<PC.MaxAtt<<fg_cyan<<" damage."<<endl;
cout<<"Do you buy(y/n)? ";
cin>>yes;
if((yes[0]=='y')||(yes[0]=='Y')){
PC.Gold-=1000;
PC.MaxAtt+=15;
}
}
else{
cout<<"You don't have enough money."<<endl;
}
}
else if((choice[0]=='c')||(choice[0]=='C')){
if(PC.Gold>=5000){
cout<<"Exercise toughens your body and raises your max hit points by 15.  It cost º5000.  You have º"<<fg_yellow<<PC.Gold<<fg_cyan<<" and your max HP is "<<PC.HPMax<<endl;
cout<<"Do you buy(y/n)? ";
cin>>yes;
if((yes[0]=='y')||(yes[0]=='Y')){
PC.Gold-=5000;
PC.HPMax+=15;
PC.HP=PC.HPMax;
}
}
else{
cout<<"You don't have enough money."<<endl;
}
}
else if((choice[0]=='d')||(choice[0]=='D')){
if(PC.Gold>=100){
cout<<"By infusing a small potion with high concentrations of mana we are capable of\ncreating a potion that can restore 10 Magic Points. It costs º"<<fg_yellow<<"100"<<fg_cyan<<". You have º"<<fg_yellow<<PC.Gold<<fg_cyan<<"and "<<fg_white<<PC.Ethers<<fg_cyan<<" ethers."<<endl;
cout<<"Do you buy(y/n)? ";
cin>>yes;
if((yes[0]=='y')||(yes[0]=='Y')){
PC.Gold-=100;
PC.Ethers++;
}
}
else{
cout<<"You do not have enough money."<<endl;
}
}
else if((choice[0]=='e')||(choice[0]=='E')){
if(PC.Gold>=5000){
cout<<"Though a process of submerging yourself in a tank full of Mana for extended periods of time you can increase your ability to control the arcane forces."<<endl;
cout<<"Do you buy(y/n)? ";
cin>>yes;
if((yes[0]=='y')||(yes[0]=='Y')){
PC.Gold-=5000;
PC.MPMax+=15;
PC.MP=PC.MPMax;
}
}
else{
cout<<"You do not have enough money."<<endl;
}
}
else if((choice[0]=='f')||(choice[0]=='F')) {
cout<<"We have a wide variety of spells here."<<endl;
cout<<"("<<fg_white<<"A"<<fg_cyan<<")   Quake     "<<PC.Magic.quake<<"/10         º2500"<<endl;
cout<<"("<<fg_white<<"B"<<fg_cyan<<")   Fire      "<<PC.Magic.fire<<"/10          º3500"<<endl;
cout<<"("<<fg_white<<"C"<<fg_cyan<<")   Bolt      "<<PC.Magic.bolt<<"/10          º4500"<<endl;
cout<<"("<<fg_white<<"D"<<fg_cyan<<")   Ice       "<<PC.Magic.ice<<"/10           º5500"<<endl;
cout<<"("<<fg_white<<"E"<<fg_cyan<<")   Cure      "<<PC.Magic.cure<<"/30          º2000"<<endl;
cout<<"("<<fg_white<<"F"<<fg_cyan<<")   Drain     "<<PC.Magic.drain<<"/10         º4000"<<endl;
cout<<"("<<fg_white<<"G"<<fg_cyan<<")   Rasp      "<<PC.Magic.rasp<<"/10          º5000"<<endl;
cout<<"("<<fg_white<<"H"<<fg_cyan<<")   Windslash "<<PC.Magic.windslash<<"/15         º6500"<<endl;
//cout<<"("<<fg_white<<"I"<<fg_cyan<<")   Confusion "<<confusion<<"/30        º10000"<<endl;
//cout<<"("<<fg_white<<"J"<<fg_cyan<<")   Death    "<<death<<"/100        º20000"<<endl;
cout<<"("<<fg_white<<"R"<<fg_cyan<<")eturn to the menu"<<endl;
cout<<fg_blue<<"Well what do you want? "<<fg_white;
cin>>choice;
cout<<fg_cyan;
if((choice[0]=='a')||(choice[0]=='A')){
if((PC.Gold>=2500)&&(PC.Magic.quake<10)){
	cout<<"Quake is a weak physical attack."<<endl;
cout<<"It uses Mana to summon an earth quake and damage your foe."<<endl;
cout<<"Do you buy(y/n)? ";
cin>>yes;
if((yes[0]=='y')||(yes[0]=='Y')){
PC.Gold-=2500;
PC.Magic.quake++;
}
}
else{
cout<<"You don't have enough money."<<endl;
}
}
else if((choice[0]=='b')||(choice[0]=='B')){
if(PC.Gold>=3500){
cout<<"Mana fire is powerful enough to burn on top of a gravelly road."<<endl;
cout<<"Do you buy(y/n)? ";
cin>>yes;
if(((yes[0]=='y')||(yes[0]=='Y'))&&(PC.Magic.fire<10)){
PC.Gold-=3500;
PC.Magic.fire++;
}
}
else{
cout<<"You don't have enough money."<<endl;
}
}
else if((choice[0]=='c')||(choice[0]=='C')){
if(PC.Gold>=4500){
cout<<"Mana bolt is a powerful spell which discharges massive amounts of energy into"<<endl;
cout<<"the directed object."<<endl;
cout<<"Do you buy(y/n)? ";
cin>>yes;
if(((yes[0]=='y')||(yes[0]=='Y'))&&(PC.Magic.bolt<10)){
PC.Gold-=4500;
PC.Magic.bolt++;
}
}
else{
cout<<"You don't have enough money."<<endl;
}
}
else if((choice[0]=='d')||(choice[0]=='D')){
if(PC.Gold>=5500){
cout<<"Mana in ice form is the coldest substance known to man or beast."<<endl;
cout<<"It is unmeltable except by mana fire."<<endl;
cout<<"Do you buy(y/n)? ";
cin>>yes;
if(((yes[0]=='y')||(yes[0]=='Y'))&&(PC.Magic.ice<10)){
PC.Gold-=5500;
PC.Magic.ice++;
}
}
else{
cout<<"You do not have enough money."<<endl;
}
}
else if((choice[0]=='e')||(choice[0]=='E')){
if(PC.Gold>=2000){
cout<<"Mana can be used to replace damaged parts by changing it to mimic the injured"<<endl;
cout<<"beings life blood."<<endl;
cout<<"Do you buy(y/n)? ";
cin>>yes;
if(((yes[0]=='y')||(yes[0]=='Y'))&&(PC.Magic.cure<30)){
PC.Gold-=2000;
PC.Magic.cure++;
}
}
else{
cout<<"You do not have enough money."<<endl;
}
}
else if((choice[0]=='f')||(choice[0]=='F')){
if(PC.Gold>=2000){
cout<<"Not only can Mana be used to mimic ones life blood but it can be used to remove"<<endl;
cout<<"ones life blood and pass it to the caster of this spell."<<endl;
cout<<"Do you buy(y/n)? ";
cin>>yes;
if(((yes[0]=='y')||(yes[0]=='Y'))&&(PC.Magic.drain<10)){
PC.Gold-=4000;
PC.Magic.drain++;
}
}
else{
cout<<"You do not have enough money."<<endl;
}
}
else if((choice[0]=='g')||(choice[0]=='G')){
if(PC.Gold>=5000){
cout<<"Like the drain spell this one also takes the life blood out of a foe, however"<<endl;
cout<<"it also converts the life blood to Mana."<<endl;
cout<<"Do you buy(y/n)? ";
cin>>yes;
if(((yes[0]=='y')||(yes[0]=='Y'))&&(PC.Magic.rasp<10)){
PC.Gold-=5000;
PC.Magic.rasp++;
}
}
else{
cout<<"You do not have enough money."<<endl;
}
}
else if((choice[0]=='h')||(choice[0]=='H')){
if(PC.Gold>=6500){
cout<<"This is the most powerful attack Mana is capable of doing."<<endl;
cout<<"Do you buy(y/n)? ";
cin>>yes;
if(((yes[0]=='y')||(yes[0]=='Y'))&&(PC.Magic.windslash<15)){
PC.Gold-=6500;
PC.Magic.windslash++;
}
}
else{
cout<<"You do not have enough money."<<endl;
}
}
/*
else if((choice[0]=='i')||(choice[0]=='I')){
if(gold>=10000){
cout<<"A Warriors darkest day is the day his blade is used against him."<<endl;
cout<<"This spell makes it just such a day, it only works well on high levels though."<<endl;
cout<<"Do you buy(y/n)? ";
cin>>yes;
if(((yes[0]=='y')||(yes[0]=='Y'))&&(confusion<30)){
gold-=10000;
confusion++;
}
}
else{
cout<<"You do not have enough money."<<endl;
}
}
*/
/*
else if((choice[0]=='j')||(choice[0]=='J')){
if(gold>=20000){
cout<<"The darkest spell a mage can wield."<<endl;
cout<<"This uses mana to corrupt the targeted foes life blood."<<endl;
cout<<"It can only be used by a powerful Magus because it will almost always miss"<<endl;
cout<<"unless at a high level."<<endl;
cout<<"Do you buy(y/n)? ";
cin>>yes;
if(((yes[0]=='y')||(yes[0]=='Y'))&&(death<=100)){
gold-=20000;
death++;
}
}
else{
cout<<"You do not have enough money."<<endl;
}
}
*/
}

cout<<"Anything else? ";
cin>>no;
} while((no=='y')||(no=='Y'));
cout<<"Thank's for coming!"<<endl;
}
}

void Interlude(Player &PC)
{
    string gostore;
    cout<<fg_cyan;
    Shop = false;
	cout<<"\n\n\n   You wake up one morning with the sun. After yawning and stretching you look\naround your two room house. Your bed is messy and your down pillow is on the\nfloor. You look in your looking glass and you aren`t to suprised to discover\nthat you look rather scruffy. You put on your buckskin pants and tunic and go\ninto the kitchen to fix breakfast. When you open the cupboard you find two\npotions.\n"<<endl;
	PC.Potions+=2;
	PC.HP=PC.HPMax;
	PC.MP=PC.MPMax;
	cout<<fg_white<<"\n\nPress Any Key To Continue\n\n"<<fg_cyan<<endl;
	_getch();
	cout<<"   You consider stopping by the local store.  The old Warlock who owns it is a\nreal grouch but usually it's his daughter who's minding the store and she\nusually lets you in without the intense pain of the search spell the Warlock\nuses to search for theives.\n"<<endl;
	cout<<fg_blue<<"So will you go? "<<fg_white;
	cin>>gostore;
	cout<<fg_cyan;
	if((gostore[0]=='y')||(gostore[0]=='Y')){
    Shop = true;
	Store(PC);
	}
}


//-----------------QUEST8--------------------------------------------------------------------------|
//=================================================================================================|
void Quest8(Player &PC)
{
    Combat fgt;
    fgt.Randomize();
    Monster KagosGirl, KagosDemon, KagosRobed;
    KagosGirl.Load("mons/KagosGirl");
    KagosDemon.Load("mons/KagosDemon");
    KagosRobed.Load("mons/KagosRobed");


	int sword, pbag, ebag, mkeeper;
	string choice;
	cout<<"You step outside your house and are suddenly assulted with the smell of perfumes";
	cout<<"and spices.  The ripples of the air around you and the chill that clutches at"<<endl;
	cout<<"your heart tell you that you are in the presense of Kagos the demon. Just as you";
	cout<<"draw your sword you hear soft girlish laughter and Kagos surprises you by"<<endl;
	cout<<"appearing behind you and removing your sword from your hand. You turn and come"<<endl;
	cout<<"face to face with a small girl of about 17 years."<<endl;
	cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
	_getch();
	cout<<"She gives you a shy smile and also relieves you of your sack of potions and"<<endl;
	cout<<"ethers. You scream to yourself that you should resist but your eyes are held"<<endl;
	cout<<"captive by the young girls beautiful face and shy demeanor Suddenly the girl`s"<<endl;
	cout<<"wonderful green eyes begin to glow with a soft blue light and her slightly"<<endl;
	cout<<"curled red hair looks charged with energy. You raise your hands and prepair"<<endl;
	cout<<"for battle, for Kagos, in her childish nature has decided to burn you to cinders";
	cout<<"with her powerful magic."<<endl;

	sword=PC.MaxAtt;
	pbag=PC.Potions;
	ebag=PC.Ethers;
	mkeeper=PC.MPMax;

	PC.MaxAtt=15;
	PC.Potions=0;
	PC.Ethers=0;
	PC.MP=5;

	cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
	_getch();
	//KagosBattle("Kagos", max, a, amax, 100, 30000, 1000, pnum, 30000, level, totalexp, gold, 30000, 30000, gain, m, mcap, num, 20, 10, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash, name);
	fgt.Start(PC, KagosGirl, false);
	PC.Ethers=ebag;
	PC.Potions=pbag;
	PC.MaxAtt=sword;
	PC.MP=mkeeper;
	cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl;
	_getch();
	if(PC.Alive)
	{
		cout<<"Kagos writhes and releases a single scream and fades like darkness in the morning light."<<endl;
		cout<<"Suddenly you here the thundering footfalls of a giant.  Towering above all he looks down"<<endl;
		cout<<"at you and booms 'Heh heh heh Kagos.  You wont fool me this time!'  Upon making this"<<endl;
		cout<<"statment he promtly grinds you into the sod."<<endl<<endl;
		//Dead();
		cout<<"The next thing you see is a soft light and feel a sense of peace around you.  Suddenly"<<endl;
		cout<<"a clawed hand grabs at you and a voice, like the cries of a thousand fallen innocents,"<<endl;
		cout<<"screams at you 'Now Great "<<PC.Name<<" you will feel the pain and sorrow of millions."<<endl;
		cout<<"You will know hunger, disease, and fear.  You will have your eyes pulled from your sockets"<<endl;
		cout<<"and will be fed them on a platter of flesh and bone.  And then "<<PC.Name<<" my mighty"<<endl;
		cout<<"warrior you will serve our Dark Lord.'  And with that you are pulled down into a darkness"<<endl;
		cout<<"that has never been touched by light.  Into a darkness where there waits He who was in glory,"<<endl;
		cout<<"He who was once beloved, and He who feasts upon the sorrow of the world."<<endl;
	}
	else if(!PC.Alive)
	{
		PC.HP= PC.HPMax;
		cout<<"As you feel your life ebbing away you hear a far off chanting.  Suddenly you find yourself on"<<endl;
		cout<<"an island among a sea of fire.  The sky is dark and full of thunder and lightning.  'Welcome.'"<<endl;
		cout<<"says a cool voice devoid of all emotion.  Looking up you see a man in a blood red cloak.  He"<<endl;
		cout<<"is frail but a power radiates from him that you can not explain.  'You should be honored"<<endl;
		cout<<PC.Name<<"' says a voice that mimics the sound of screaming children.  You turn around and"<<endl;
		cout<<"stare face to face with the true form of Kagos.  It is a massive beast with two twisted horns"<<endl;
		cout<<"atop its gray slimy head.  It has horrible wounds and the smell of gore that comes from its huge"<<endl;
		cout<<"mouth is almost overwhelming.  You draw your sword and prepare to meet the foul beast.  the "<<endl;
		cout<<"cloaked man laughs and says 'Don`t even try it!  Kagos will kill you and if doesn't you'll never"<<endl;
		cout<<" get off the Island of Tacak!'  At this Kagos realises a horrible laugh, looking around you see"<<endl;
		cout<<"a small tomb with doors of bone and flesh that you could get inside of and seek an escape, you"<<endl;
		cout<<"could attempt to kill Kagos or the cloaked man, or you could stall them till something good comes along."<<endl<<endl;
		cout<<"Do you"<<endl;
		cout<<"(T)alk for awhile"<<endl;
		cout<<"(F)ight Kagos"<<endl;
		cout<<"(A)ttack the cloaked man"<<endl;
		cout<<"(R)un for the Tomb"<<endl;
		cout<<"Well?";
		cin>>choice;
		if((choice[0]=='t')||(choice[0]=='T'))
		{
			cout<<"You choose talk for a while till something promising comes along.  How ever Kagos has"<<endl;
			cout<<"other plans and promptly bites you in half."<<endl;
			//Dead();
		}
		else if((choice[0]=='f')||(choice[0]=='F'))
		{
			cout<<"You draw your sword and attack Kagos.  He is more than ready to meet the challenge and"<<endl;
			cout<<"this time he isn't a little girl."<<endl;
			fgt.Start(PC, KagosDemon, false);
			//KagosBattle("Kagos", max, a, amax, 1001, 30000, 1000, pnum, 30000, level, totalexp, gold, 30000, 30000, gain, m, mcap, num, 20, 10, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash, name);
			if(PC.Alive)
			{
				cout<<"As your sword cuts through Kagos breast, you feel the familiar warm gush of blood"<<endl;
				cout<<"on your hands.  You see the cloaked man reach for your arm and you feel the burning"<<endl;
				cout<<"of a thousand hells.  'No,' you correct yourself as you stare into his eyes, 'not"<<endl;
				cout<<"a thousand hells.  Just the Master of one hell.'  He chuckles a chilling laugh"<<endl;
				cout<<"and...  You yourself in bed alone and sweating from a heat you can`t identify suddenly"<<endl;
				cout<<"there is a knock at the door."<<endl;
				cout<<"A wizard knocks on your door and you open the door and let him in.  The wizard looks"<<endl;
				cout<<"distressed and has sweat beaded all down his face.   'You have to help me!' says the"<<endl;
				cout<<"wizard panting and out of breath.   'Some vile demon stole my Mana Stone. I can`t"<<endl;
                cout<<"cast a single spell until it`s returned!' he wailed. 'PLEEEAASSEE HHEEELLLP MEEE,"<<endl;
                cout<<"PLEEEAAASSSE!'With that the poor old wizard ran off bawling.	With a sense of duty"<<endl;
                cout<<"you pick up your sword and set out on a magical journey."<<endl;
				cout<<"'Wait a minute!' you say 'Haven't I done this before!'  And so shrugging you set"<<endl;
				cout<<"out on your quest to get back the wizard`s stone."<<endl;
			}
		}
		else if((choice[0]=='a')||(choice[0]=='A'))
		{
			cout<<"You whirl around to attack the cloaked man.  Almost as if he has read your mind"<<endl;
			cout<<"he is prepaired and raises his hand reaches out to touch your face.  You duck with"<<endl;
			cout<<"all your speed and hear Kagos scream as his head is melted into a oozing yellow mass."<<endl;
			cout<<"Drawing your sword you spin around just as the cloaked man vanishes.  Screaming with"<<endl;
			cout<<"what vocal cords he has left Kagos blindly launches himself at you with surprising"<<endl;
			cout<<"accuracy for a headless fiend."<<endl;
			fgt.Start(PC, KagosRobed, false);
			//KagosBattle("Kagos", max, a, amax, 501, 20000, 1000, pnum, 30000, level, totalexp, gold, 30000, 30000, gain, m, mcap, num, 20, 10, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash, name);
			if(PC.Alive)
			{
				cout<<"As your sword cuts through Kagos breast, you feel the familiar warm gush of blood"<<endl;
				cout<<"on your hands.  You see the cloaked man reach for your arm and you feel the burning of"<<endl;
				cout<<"a thousand hells.  'No,' you correct yourself as you stare into his eyes, 'not"<<endl;
				cout<<"a thousand hells.  Just the Master of one hell.'  He chuckles a chilling laugh and..."<<endl;
				cout<<"You yourself in bed alone and sweating from a heat you can`t identify suddenly"<<endl;
				cout<<"there is a knock at the door."<<endl;
				cout<<"A wizard knocks on your door and you open the door and let him in.  The wizard"<<endl;
				cout<<"looks distressed and has sweat beaded all down his face.   'You have to help me!'"<<endl;
				cout<<"says the wizard panting and out of breath.   'Some vile demon stole my Mana Stone."<<endl;
				cout<<"I can`t cast a single spell until it`s returned!' he wailed. 'PLEEEAASSEE"<<endl;
				cout<<"HHEEELLLP MEEE, PLEEEAAASSSE!'With that the poor old wizard ran off bawling."<<endl;
				cout<<"With a sense of duty you pick up your sword and set out on a magical journey."<<endl;
				cout<<"'Wait a minute!' you say 'Haven't I done this before!'  And so shrugging you"<<endl;
				cout<<"set out on your quest to get back the wizard`s stone."<<endl;
			}
		}
		else if((choice[0]=='r')||(choice[0]=='R'))
		{
			cout<<"You choose to run into the tomb and attempt to find an escape.  How ever"<<endl;
			cout<<"Kagos has other plans and promptly bites you in half."<<endl;
			//Dead();
		}
	}
}
