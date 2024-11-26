//#include "stdafx.h"
#include<iostream> 
#include"lvprandom.h" 
#include<conio.h>
#include"battle.h" 
#include<string>
#include"Console.h"
#include<fmod.h>
#include "Player.h"
using namespace::std;
namespace con=JadedHoboConsole;
using namespace con;


//-----------------MONSTER_BATTLE------------------------------------------------------------------| 
//=================================================================================================|
void MBattle(string MonName, int &max, int &a, int &amax, int mmax, int b,
			 int &pnum, int exp, int &level, int &totalexp, int &gold,
			 int mgold, int mpotion, int &gain, int &m, int &mcap, int &num,
			 int fire, int ice, int bolt, int cure, int drain, int rasp,
			 int death, int quake, int confusion, int windslash)
{ 
string battle;
char again, y, answer, spell; 
int tip, top, tt=100, pamax=1+lvprandom(20), att, pmax=1+lvprandom(20), c, d, lmcap=mcap, lamax=amax, lmax=max, lpnum=pnum, points, temp; 
do{ 
att=0; 
c=lvprandom(max);
d=lvprandom(mmax); 
cout<<"\n";
cout<<fg_cyan;
cout<<"The monster is:"<<endl; 
cout<<fg_red;
cout<<fg_red<<MonName<<fg_cyan<<endl; 
cin>>battle;
cout<<fg_cyan;
	if((battle[0]=='f')||(battle[0]=='F')){ 
		MFight(); 
		cout<<fg_red<<MonName<<fg_cyan<<" does "<<d<<" damage."<<endl; 
		cout<<"You do "<<c<<" damage."<<endl; 
		a-=d; 
		b-=c; 
			if(b<=0){ 
				cout<<"You kill "<<fg_red<<MonName<<fg_cyan<<" and raise your hand victoriously"<<endl; 
				gold+=mgold; 
//				//Victory(); 
				cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
				totalexp+=exp; 
				pnum+=mpotion; 
				again='n'; 
			}  
			else if(a<=0){ 
				cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
				cout<<"THE END"<<endl; 
//				//Dead(); 
				again='n'; 
				break; 
				break;  
			}  
			else{ 
				again='y'; 
			}  
		}  
	else if((battle[0]=='d')||(battle[0]=='D')){ 
		cout<<fg_red<<MonName<<fg_cyan<<" does "<<d<<" damage."<<endl; 
		cout<<"You block "<<c<<" damage."<<endl; 
//		defend(); 
                if(c>=d){d=0;}
                else{d-=c;}
		a-=d; 
		    if(a>amax){ 
			    a=amax; 
				again='y'; 
		    }  
		 	else if(a<=0){ 
				cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
				cout<<"THE END"<<endl; 
//				//Dead(); 
				again='n'; 
				break; 
				break; 
			}  
			else{ 
				again='y'; 
			}  
		}  
	else if((battle[0]=='r')||(battle[0]=='R')){ 
		tip=lvprandom(2); 
			if(tip==0){ 
				cout<<"You run for your cowardly life from "<<fg_red<<MonName<<fg_cyan<<endl; 
//				//Run(); 
				again='n'; 
				y='y';  
			}  
			else if(tip==1){ 
				cout<<"You can't get away."<<endl; 
    			cout<<fg_red<<MonName<<fg_cyan<<" does "<<d<<" damage."<<endl; 
//    			//caway(); 
    			a-=d; 
    			if(a<=0){ 
    				cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
    				cout<<"THE END"<<endl; 
//    				//Dead(); 
    				again='y'; 
    				break; 
					break; 
				}  
				else{ 
					again='y'; 
				}  
			}  
	}  
	else if((battle[0]=='m')||(battle[0]=='M')){ 
		 do{ 
		 cout<<"("<<fg_white<<"A"<<fg_cyan<<")   Quake     "<<quake<<"/10   4MP"<<endl; 
		 cout<<"("<<fg_white<<"B"<<fg_cyan<<")   Fire      "<<fire<<"/10   6MP"<<endl; 
		 cout<<"("<<fg_white<<"C"<<fg_cyan<<")   Bolt      "<<bolt<<"/10   8MP"<<endl; 
		 cout<<"("<<fg_white<<"D"<<fg_cyan<<")   Ice       "<<ice<<"/10   10MP"<<endl; 
		 cout<<"("<<fg_white<<"E"<<fg_cyan<<")   Cure      "<<cure<<"/30   5MP"<<endl; 
		 cout<<"("<<fg_white<<"F"<<fg_cyan<<")   Drain     "<<drain<<"/10  10MP"<<endl; 
		 cout<<"("<<fg_white<<"G"<<fg_cyan<<")   Rasp      "<<rasp<<"/10   20MP"<<endl; 
		 cout<<"("<<fg_white<<"H"<<fg_cyan<<")   Windslash "<<windslash<<"/15   15MP"<<endl; 
		 cout<<"("<<fg_white<<"I"<<fg_cyan<<")   Confusion "<<confusion<<"/30   15MP"<<endl; 
		 cout<<"("<<fg_white<<"J"<<fg_cyan<<")   Death    "<<death<<"/100   20MP"<<endl; 
		 cout<<"("<<fg_white<<"R"<<fg_cyan<<")eturn"<<endl; 
		 cout<<fg_blue<<"What spell do you wish to cast?"<<fg_white; 
		 cin>>battle; 
		 cout<<fg_cyan;
			if((battle[0]=='a')||(battle[0]=='A')){ 
				if((quake>0)&&(mcap>=4)){ 
					m-=4; 
					c=10*quake; 
					cout<<fg_red<<MonName<<fg_cyan<<" does "<<d<<" damage."<<endl; 
					cout<<"You cast quake and do "<<c<<" damage."<<endl; 
//					//magic(); 
					a-=d; 
					b-=c; 
						if(b<=0){ 
							cout<<"You kill "<<fg_red<<MonName<<fg_cyan<<" and raise your hand victoriously"<<endl; 
							gold+=mgold; 
//							//Victory(); 
							cout<<"You get "<<fg_white<<fg_white<<exp<<fg_cyan<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
							totalexp+=exp; 
							pnum+=mpotion; 
							again='n'; 
							spell='y'; 
						}  
						else if(a<=0){ 
							cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
							cout<<"THE END"<<endl; 
//							//Dead(); 
							again='n'; 
							spell='y'; 
							break;  
						}  
					else{ 
						again='y'; 
						spell='y'; 
					}  
				}  
				else if(m<4){ 
					cout<<"Not enough mana!"<<endl; 
					spell='n'; 
				}  
				 
				else{ 
					cout<<"You are not trained in the casting of that spell."<<endl; 
					spell='n'; 
				}  
			}  
			else if((battle[0]=='b')||(battle[0]=='B')){ 
				if((fire>0)&&(mcap>=6)){ 
					m-=6; 
					top=fire*5; 
					c=top+lvprandom(51); 
					cout<<fg_red<<MonName<<fg_cyan<<" does "<<d<<" damage."<<endl; 
					cout<<"You cast fire and do "<<c<<" damage."<<endl; 
//					//magic(); 
					a-=d; 
					b-=c; 
						if(b<=0){ 
							cout<<"You kill "<<fg_red<<MonName<<fg_cyan<<" and raise your hand victoriously"<<endl; 
							gold+=mgold; 
//							//Victory(); 
							cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
							totalexp+=exp; 
							pnum+=mpotion; 
							again='n'; 
							spell='y'; 
						}  
						else if(a<=0){ 
							cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
							cout<<"THE END"<<endl; 
//							//Dead(); 
							again='n'; 
							spell='y'; 
							break;  
						}  
						else{ 
							again='y'; 
							spell='y'; 
						}  
				}  
				else if(m<6){ 
					cout<<"Not enough mana!"<<endl; 
					spell='n'; 
				}  
				else{ 
					cout<<"You are not trained in the casting of that spell."<<endl; 
					spell='n'; 
				}  
			}  
			else if((battle[0]=='c')||(battle[0]=='C')){ 
				if((bolt>0)&&(mcap>=8)){ 
					m-=8; 
					top=bolt*5; 
					c=top+lvprandom(61); 
					cout<<fg_red<<MonName<<fg_cyan<<" does "<<d<<" damage."<<endl; 
					cout<<"You cast bolt and do "<<c<<" damage."<<endl; 
//					//magic(); 
					a-=d; 
					b-=c; 
						if(b<=0){ 
							cout<<"You kill "<<fg_red<<MonName<<fg_cyan<<" and raise your hand victoriously"<<endl; 
							gold+=mgold; 
//							//Victory(); 
							cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
							totalexp+=exp; 
							pnum+=mpotion; 
							again='n'; 
							spell='y'; 
						}  
						else if(a<=0){ 
							cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
							cout<<"THE END"<<endl; 
//							//Dead(); 
							again='n'; 
							spell='y'; 
							break;  
						}  
						else{ 
							again='y'; 
							spell='y'; 
						}  
				}  
				else if(m<8){ 
					cout<<"Not enough mana!"<<endl; 
					spell='n'; 
				}  
				else{ 
					cout<<"You are not trained in the casting of that spell."<<endl; 
					spell='n'; 
				}  
			}  
			else if((battle[0]=='d')||(battle[0]=='D')){ 
				if((ice>0)&&(mcap>=10)){ 
					m-=10; 
					top=ice*5; 
					c=top+lvprandom(71); 
					cout<<fg_red<<MonName<<fg_cyan<<" does "<<d<<" damage."<<endl; 
					cout<<"You cast ice and do "<<c<<" damage."<<endl; 
//					//magic(); 
					a-=d; 
					b-=c; 
						if(b<=0){ 
							cout<<"You kill "<<fg_red<<MonName<<fg_cyan<<" and raise your hand victoriously"<<endl; 
							gold+=mgold; 
//							//Victory(); 
							cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
							totalexp+=exp; 
							pnum+=mpotion; 
							again='n'; 
							spell='y'; 
						}  
						else if(a<=0){ 
							cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
							cout<<"THE END"<<endl; 
//							//Dead(); 
							again='n'; 
							spell='y'; 
							break;  
						}  
						else{ 
							again='y'; 
							spell='y'; 
						}  
				}  
				else if(m<10){ 
					cout<<"Not enough mana!"<<endl; 
					spell='n'; 
				}  
				else{ 
					cout<<"You are not trained in the casting of that spell."<<endl; 
					spell='n'; 
				}  
			}  
			else if((battle[0]=='e')||(battle[0]=='E')){ 
				if((cure>0)&&(mcap>=5)){ 
					int la; 
					m-=5; 
					la=a; 
					top=cure*5; 
					a+=top; 
						if(a<=amax){
							cout<<"You cure "<<top<<" damage."<<endl; 
//							//magic(); 
						}  
						else{ 
							cout<<"You cure "<<(amax-la)<<" damage."<<endl; 
//							//magic(); 
							a=amax; 
						}  
					spell='y'; 
					again='y'; 
				}  
				else if(m<5){ 
					cout<<"Not enough mana!"<<endl; 
					spell='n'; 
				}  
				else{ 
					cout<<"You are not trained in the casting of that spell."<<endl; 
					spell='n'; 
					again='y'; 
				}  
			}  
			else if((battle[0]=='f')||(battle[0]=='F')){ 
				if((drain>0)&&(mcap>=10)){ 
					m-=10; 
					top=drain*5; 
					c=1+lvprandom(top); 
					cout<<fg_red<<MonName<<fg_cyan<<" does "<<d<<" damage."<<endl; 
					cout<<"You do "<<c<<" damage and use it to heal your wounds."<<endl; 
//					//magic(); 
					a+=c; 
					if(a>amax){a=amax;}  
					a-=d; 
					b-=c; 
						if(b<=0){ 
							cout<<"You kill "<<fg_red<<MonName<<fg_cyan<<" and raise your hand victoriously"<<endl; 
							gold+=mgold; 
//							//Victory(); 
							cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
							totalexp+=exp; 
							pnum+=mpotion; 
							again='n'; 
							spell='y'; 
						}		
						else if(a<=0){ 
							cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
							cout<<"THE END"<<endl; 
//							//Dead(); 
							again='n'; 
							spell='y'; 
							break;  
						}	
						else{ 
							again='y'; 
							spell='y'; 
						}
				}  
				else if(m<10){ 
					cout<<"Not enough mana!"<<endl; 
					spell='n'; 
				}
				else{ 
					cout<<"You are not trained in the casting of that spell."<<endl; 
					spell='n'; 
				} 
		}  
		else if((battle[0]=='g')||(battle[0]=='G')){ 
			if((rasp>0)&&(mcap>=20)){ 
				m-=20; 
				top=rasp*5; 
				c=1+lvprandom(top); 
				cout<<fg_red<<MonName<<fg_cyan<<" does "<<d<<" damage."<<endl; 
				cout<<"You do "<<c<<" damage and use it to replenish your magic supply."<<endl; 
//				//magic(); 
				m+=c; 
				if(m>mcap){m=mcap;}  
				a-=d; 
				b-=c; 
					if(b<=0){ 
						cout<<"You kill "<<fg_red<<MonName<<fg_cyan<<" and raise your hand victoriously"<<endl; 
						gold+=mgold; 
//						//Victory(); 
						cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
						totalexp+=exp; 
						pnum+=mpotion; 
						again='n'; 
						spell='y'; 
					}
					else if(a<=0){ 
						cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
						cout<<"THE END"<<endl; 
//						//Dead(); 
						again='n'; 
						spell='y'; 
						break;  
					}  
					else{ 
						again='y'; 
						spell='y'; 
				}
			}  
			else if(m<20){ 
				cout<<"Not enough mana!"<<endl; 
				spell='n'; 
			}  
			else{ 
				cout<<"You are not trained in the casting of that spell."<<endl; 
				spell='n'; 
			}  
		}  
		else if((battle[0]=='h')||(battle[0]=='H')){ 
				if((windslash>0)&&(mcap>=15)){ 
					m-=15; 
					c=20*windslash; 
					cout<<fg_red<<MonName<<fg_cyan<<" does "<<d<<" damage."<<endl; 
					cout<<"You cast windslash and do "<<c<<" damage."<<endl; 
//					//magic(); 
					a-=d; 
					b-=c; 
						if(b<=0){ 
							cout<<"You kill "<<fg_red<<MonName<<fg_cyan<<" and raise your hand victoriously"<<endl; 
							gold+=mgold; 
//							//Victory(); 
							cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
							totalexp+=exp; 
							pnum+=mpotion; 
							again='n'; 
							spell='y'; 
						}  
						else if(a<=0){ 
							cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
							cout<<"THE END"<<endl; 
//							//Dead(); 
							again='n'; 
							spell='y'; 
							break;  
						}  
						else{ 
							again='y'; 
							spell='y'; 
						}  
				}  
				else if(m<15){ 
					cout<<"Not enough mana!"<<endl; 
					spell='n'; 
				}  
				else{ 
					cout<<"You are not trained in the casting of that spell."<<endl; 
					spell='n'; 
				}  
			}  
			else if((battle[0]=='i')||(battle[0]=='I')){ 
				if((confusion>0)&&(m>=15)){ 
					m-=15; 
					top=lvprandom(32-confusion); 
						if(top!=0){ 
							cout<<"Confusion fails to rot "<<fg_red<<MonName<<fg_cyan<<"'s mind!"<<endl; 
//							//caway(); 
							cout<<fg_red<<MonName<<fg_cyan<<" does "<<d<<" damage."<<endl; 
							a-=d; 
						}  
						else if(top==0){ 
							cout<<"Confusion forces "<<fg_red<<MonName<<fg_cyan<<" to cut it's own flesh!"<<endl; 
//							//magic(); 
							cout<<fg_red<<MonName<<fg_cyan<<" does "<<d<<" damage to "<<fg_red<<MonName<<fg_cyan<<"!"<<endl; 
							b-=d; 
						}  
						if(b<=0){ 
							cout<<"You kill "<<fg_red<<MonName<<fg_cyan<<" and raise your hand victoriously"<<endl; 
							gold+=mgold; 
//							//Victory(); 
							cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
							totalexp+=exp; 
							pnum+=mpotion; 
							again='n'; 
							spell='y'; 
						}  
						else if(a<=0){ 
							cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
							cout<<"THE END"<<endl; 
//							//Dead(); 
							again='n'; 
							spell='y'; 
							break;  
						}  
						else{ 
							again='y'; 
							spell='y'; 
						}  
				}  
				else if(m<15){ 
					cout<<"Not enough mana!"<<endl; 
					spell='n'; 
				}  
				else{ 
					cout<<"You are not trained in the casting of that spell."<<endl; 
					smallperson(); 
					spell='n'; 
				}  
			}  
			else if((battle[0]=='j')||(battle[0]=='J')){ 
				if((death>0)&&(m>=20)){ 
					m-=20; 
					top=lvprandom(102-death); 
						if(top!=0){ 
							cout<<"Death fails to hear your summons!"<<endl; 
//							//caway(); 
							cout<<fg_red<<MonName<<fg_cyan<<" does "<<d<<" damage."<<endl; 
							a-=d; 
						}  
						else if(top==0){ 
							cout<<"Death appears before you and kills "<<fg_red<<MonName<<fg_cyan<<" in a grusome display of gore!"<<endl; 
//							//magic(); 
							b=0; 
						}  
						if(b<=0){ 
							cout<<fg_red<<MonName<<fg_cyan<<" falls dead and you raise your hand victoriously"<<endl; 
							gold+=mgold; 
//							//Victory(); 
							cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
							totalexp+=exp; 
							pnum+=mpotion; 
							again='n'; 
							spell='y'; 
						}  
						else if(a<=0){ 
							cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
							cout<<"THE END"<<endl; 
//							//Dead(); 
							again='n'; 
							spell='y'; 
							break;  
						}  
						else{ 
							again='y'; 
							spell='y'; 
						}  
				}  
				else if(m<20){ 
					cout<<"Not enough mana!"<<endl; 
					spell='n'; 
				}  
				else{ 
					cout<<"You are not trained in the casting of that spell."<<endl; 
					smallperson(); 
					spell='n'; 
				}  
			}  
		else{ 
			spell='n'; 
		}  
		} while(spell=='n');	 
	}  
	else if((battle[0]=='u')||(battle[0]=='U')){ 
		cout<<"("<<fg_white<<"E"<<fg_cyan<<")ther"<<endl; 
		cout<<"("<<fg_white<<"P"<<fg_cyan<<")otion"<<endl; 
		cout<<fg_white;
		cin>>battle; 
		cout<<fg_cyan;
			if((battle[0]=='p')||(battle[0]=='P')){ 
				cout<<"You use a potion."<<endl; 
//				//drinkpotion(); 
					if(a>=amax){ 
						cout<<"You don't need it!"<<endl; 
						smallperson(); 
						again='y';			 
					} 
		
					else if(pnum>=1){ 
					a+=10; 
					if(a>amax){a=amax;}  
					pnum--; 
					again='y'; 
			 
					}  
			 
					else if(pnum<1){ 
						cout<<"You don't have any."<<endl; 
						smallperson(); 
						again='y'; 
					}  
	}  
	else if((battle[0]=='e')||(battle[0]=='E')){ 
 
			if(num>=1){ 
//				//drinkpotion();
				cout<<"You use a ether."<<endl; 
				m+=10; 
				if(m>mcap){m=mcap;}  
				num--; 
				again='y'; 
				 
			}  
			else if(m>=mcap){ 
				cout<<"You don't need it!"<<endl; 
				smallperson(); 
				again='y';			 
			}  
			else if(num<1){ 
				cout<<"You don't have any."<<endl; 
				smallperson(); 
				again='y'; 
			}  
	}  
	}  
	else{ 
		cout<<"That won't do anything."<<endl; 
		smallperson(); 
		again='y'; 
	}  
} while(again=='y'); 
	for(;totalexp>=gain;){ 
	totalexp-=gain; 
	level++; 
	gain=level*tt; 
	cout<<"You have gained a level."<<endl; 
//		//Victory(); 
		do{ 
			points=35; 
			cout<<"Now you have "<<points<<" points."<<endl; 
			cout<<"How many points do you want to add to your life? "<<endl; 
			cin>>temp; 
				if(temp>points){ 
					cout<<"You don't have that many points!"<<endl; 
					answer='n'; 
				}  
				else{ 
					amax+=temp; 
					a=amax; 
					points-=temp; 
					cout<<"Now you have "<<points<<" points."<<endl; 
					cout<<"How many points do you want to add to your attack? "<<endl; 
					cin>>temp; 
						if(temp>points){ 
							cout<<"You don't have that many points!"<<endl; 
							answer='n'; 
						}  
						else{ 
							max+=temp; 
							points-=temp; 
							cout<<"Now you have "<<points<<" points."<<endl; 
							cout<<"How many points do you want to add to your Magic? "<<endl; 
							cin>>temp; 
								if(temp>points){ 
									cout<<"You don't have that many points!"<<endl; 
									answer='n'; 
								}  
								else{ 
									mcap+=temp; 
									points-=temp; 
									pnum+=points;
									cout<<fg_white;
									cout<<"Life:    "<<amax<<endl; 
									cout<<"Attack:  "<<(max-1)<<endl; 
									cout<<"Potions: "<<pnum<<endl; 
									cout<<"Mana:    "<<mcap<<endl; 
									cout<<endl; 
									cout<<fg_blue<<"Are these stats OK? "<<fg_white; 
									cin>>answer;
									cout<<fg_cyan;
								}  
								if(answer=='n'){ 
									amax=lamax; 
									max=lmax; 
									pnum=lpnum; 
									mcap=lmcap; 
								}  
						}  
				}  
		} while(answer=='n'); 
	}  
}  
//---------------------------------EEVEE_BATTLE----------------------------------------------------|
//=================================================================================================| 
void MBattle2(string MonName, int &emax, int &eveea, int &eamax, int mmax, int b, int &pnum, int exp, int &elevel, int &etotalexp, int &gold, int mgold, int mpotion, int &egain, string name)
{ 
char  again, y, answer;
string battle; 
int tip, tt=100, pamax=1+lvprandom(20), pmax=1+lvprandom(20), c, d, lamax=eamax, lemax=emax, lpnum=pnum, points, temp; 
do{ 
	c=lvprandom(emax); 
	d=lvprandom(mmax); 
	cout<<"The monster is:"<<endl; 
	cout<<fg_red<<MonName<<fg_cyan<<endl; 
	cout<<"Evee has "<<eveea<< " life."<<endl; 
	cout<<"Evee is at level "<<fg_white<<elevel<<fg_cyan<<", and has "<<fg_white<<etotalexp<<fg_cyan<<" exp, "<<fg_yellow<<gold<<fg_cyan<<" gold, and "<<fg_white<<pnum<<fg_cyan<<" potions."<<endl; 
	cout<<"What do you want Evee to do?"<<endl; 
	cout<<"("<<fg_white<<"F"<<fg_cyan<<")ight"<<endl; 
	cout<<"("<<fg_white<<"R"<<fg_cyan<<")un"<<endl; 
	cout<<"("<<fg_white<<"D"<<fg_cyan<<")efend"<<endl; 
	cout<<"("<<fg_white<<"U"<<fg_cyan<<")se Item"<<endl; 
	cout<<"Well?"<<endl; 
	cin>>battle; 
		if((battle[0]=='f')||(battle[0]=='F')){ 
		MFight(); 
		cout<<fg_red<<MonName<<fg_cyan<<" does "<<d<<" damage."<<endl; 
		cout<<"Evee does "<<c<<" damage."<<endl; 
		eveea-=d; 
		b-=c; 
			if(b<=0){ 
			cout<<"Evee kills "<<fg_red<<MonName<<fg_cyan<<" and you raise your hand victoriously"<<endl; 
			gold+=mgold; 
//			//Victory(); 
			cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
			etotalexp+=exp; 
			pnum+=mpotion; 
			again='n'; 
			}  
			else if(eveea<=0){ 
			cout<<"Evee was knocked unconcious by "<<fg_red<<MonName<<fg_cyan<<endl; 
			 
			     
			again='n'; 
			break; 
			break;  
			}  
			else{ 
			again='y'; 
			}  
		}  
		else if((battle[0]=='d')||(battle[0]=='D')){ 
		cout<<fg_red<<MonName<<fg_cyan<<" does "<<d<<" damage."<<endl; 
		cout<<"Evee blocks "<<c<<" damage."<<endl; 
//		defend(); 
		d-=c; 
		eveea-=d; 
		    if(eveea>eamax){ 
		    eveea=eamax; 
		    again='y'; 
		    }  
		 	else if(eveea<=0){ 
			cout<<"Evee has been knocked unconcious by "<<fg_red<<MonName<<fg_cyan<<endl; 
			 
			 
			again='n'; 
			break; 
			break; 
			}  
			else{ 
			again='y'; 
			}  
		}  
		else if((battle[0]=='r')||(battle[0]=='R')){ 
		tip=lvprandom(2); 
			if(tip==0){ 
			cout<<"You and Evee run for your cowardly life from "<<fg_red<<MonName<<fg_cyan<<endl; 
//			////Run(); 
			again='n'; 
			y='y';  
			}  
			else if(tip==1){ 
			cout<<"You and Evee can't get away."<<endl; 
    		cout<<fg_red<<MonName<<fg_cyan<<" does "<<d<<" damage."<<endl; 
//  		//caway(); 
    		eveea-=d; 
    			if(eveea<=0){ 
    			cout<<"Evee has been knocked unconcious by "<<fg_red<<MonName<<fg_cyan<<endl; 
    			 
    			again='y'; 
    			break; 
				break; 
				}  
				else{ 
				again='y'; 
				}  
			}  
		}  
 
		else if((battle[0]=='u')||(battle[0]=='U')){ 
	 
		cout<<"(P)otion"<<endl; 
		cin>>battle; 
		if((battle[0]=='p')||(battle[0]=='P')){ 
		cout<<"You give Evee a potion."<<endl; 
//			////drinkpotion(); 
			if(pnum>=1){ 
				 
				eveea+=10; 
				if(eveea>eamax){ 
				eveea=emax; 
				}  
				pnum--; 
				again='y'; 
			 
			}  
			else if(eveea>=eamax){ 
			cout<<"Evee doesn't need it!"<<endl; 
			 
			again='y';			 
			}  
			else if(pnum<1){ 
			cout<<"You don't have any."<<endl; 
			 
			again='y'; 
			}  
		}  
		 
		}  
} while(again=='y'); 
	for(;etotalexp>=egain;){ 
	etotalexp-=egain; 
	elevel++; 
	egain=elevel*tt; 
	cout<<"You have gained a level."<<endl; 
//		//Victory(); 
		do{ 
			points=35; 
			cout<<"Now Evee has "<<points<<" points."<<endl; 
			cout<<"How many points do you want Evee to add to his life? "<<endl; 
			cin>>temp; 
				if(temp>points){ 
				cout<<"Evee don't have that many points!"<<endl; 
				answer='n'; 
				}  
				else{ 
				eamax+=temp; 
				eveea=eamax; 
				points-=temp; 
				cout<<"Now Evee has "<<points<<" points."<<endl; 
				cout<<"How many points do you want Evee to add to his attack? "<<endl; 
				cin>>temp; 
					if(temp>points){ 
					cout<<"Evee doesn't have that many points!"<<endl; 
					answer='n'; 
					}  
					else{ 
					emax+=temp; 
					points-=temp; 
		            	pnum+=points; 
						cout<<"Life:    "<<eamax<<endl; 
						cout<<"Attack:  "<<(emax-1)<<endl; 
						cout<<"Potions: "<<pnum<<endl; 
						cout<<endl; 
						cout<<"Are these stats OK? "; 
						cin>>answer;		 
						}  
						if(answer=='n'){ 
						eamax=lamax; 
						emax=lemax; 
						pnum=lpnum; 
						}  
				}  
				 
		} while(answer=='n'); 
	}  
}  
//---------------------------------WIZARDS_BATTLE--------------------------------------------------| 
//=================================================================================================|
void KagosBattle(string MonName, int &max, int &a, int &amax, int kagosd, int Kagosa, int Kagosm, int &pnum, int exp, int &level, int &totalexp, int &gold, int mgold, int mpotion, int &gain, int &m, int &mcap, int &num, int Kagosp, int Kagose, int fire, int ice, int bolt, int cure, int drain, int rasp, int death, int quake, int confusion, int windslash, string name){ 
char battle, again, y, answer, spell; 
int tip, top, tt=100, pamax=1+lvprandom(20), pmax=1+lvprandom(20), c,/* d,*/ lmcap=mcap, rbattle, lamax=amax, lmax=max, lpnum=pnum, points, temp, att ; 
do{ 
	att=0; 
	rbattle=lvprandom(5); 
	c=lvprandom(max); 
	kagosd=lvprandom(kagosd); 
	cout<<"The monster is:"<<endl; 
	cout<<fg_red<<MonName<<fg_cyan<<endl; 
	cout<<"You have "<<fg_red<<exp<<fg_cyan<< " life."<<endl; 
	cout<<"Your at level "<<level<<", and have "<<fg_white<<totalexp<<fg_cyan<<" exp, "<<fg_yellow<<gold<<fg_cyan<<" gold, "<<m<<" Mana, and "<<pnum<<" potions."<<endl; 
	cout<<"What do you want to do?"<<endl; 
	cout<<"("<<fg_white<<"F"<<fg_cyan<<")ight"<<endl; 
	cout<<"("<<fg_white<<"R"<<fg_cyan<<")un"<<endl; 
	cout<<"("<<fg_white<<"D"<<fg_cyan<<")efend"<<endl; 
	cout<<"("<<fg_white<<"M"<<fg_cyan<<")agic"<<endl; 
	cout<<"("<<fg_white<<"U"<<fg_cyan<<")se Item"<<endl; 
	cout<<"Well?"<<endl; 
	cin>>battle; 
		if(battle=='f'){ 
		MFight(); 
		if((rbattle==0)||(rbattle==3)){
		cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl;
		a-=kagosd;
		}
		else if(rbattle==1){
		rbattle=lvprandom(3);
			if((rbattle==0)||(rbattle==2)){
				cout<<fg_red<<MonName<<fg_cyan<<" used a potion!"<<endl; 
		  		    if(Kagosp>0){
				       Kagosa+=10;
				    }
				    else{
				    cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!";
				    }
			}
			else{
				cout<<fg_red<<MonName<<fg_cyan<<" used an ether!"<<endl; 
				    if(Kagose>0){
				        Kagosm+=10;
				    }
				    else{
				        cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!";
				    }
			}
		}
		else{
		cout<<fg_red<<MonName<<fg_cyan<<" uses a spell!"<<endl;
		rbattle=lvprandom(6);
			if((rbattle==0)||(rbattle==5)){ 
			    if(Kagosm>=5){
			        cout<<fg_red<<MonName<<fg_cyan<<" uses cure and heals 20!"<<endl;
    			        Kagosa+=20;
			        Kagosm-=5;
			    }
			    else{
			        cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl;
			    }
			}  
			 
			if(rbattle==1){ 
			    if(Kagosm>=10){
			        cout<<fg_red<<MonName<<fg_cyan<<" uses drain does "<<kagosd<<" and heals "<<kagosd<<" HP!"<<endl;
			        a-=kagosd;
			        Kagosa+=kagosd;
			        Kagosm-=5;
			    }
			    else{
			        cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl;
			    }
			}  
			if(rbattle==2){ 
			    if(Kagosm>=15){
  		   	        cout<<fg_red<<MonName<<fg_cyan<<" uses rasp does "<<kagosd<<" and heals "<<kagosd<<" MP!"<<endl;
				a-=kagosd;
				Kagosm+=kagosd;
				Kagosm-=5;
			    }
			    else{
			        cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl;
			    }
			}  
			if(rbattle==3){ 
			    if(Kagosm>=20){
			        cout<<fg_red<<MonName<<fg_cyan<<" uses seduction and seduces"<<name<<endl;
				Kagosm-=20;
				att=1;
			    }
			    else{
			        cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl;
			    }
			}  
		}
		if(att==0){
		    cout<<"You do "<<c<<" damage."<<endl;
		    Kagosa-=c;
		}  
		else{ 
		    cout<<name<<" does "<<c<<" to "<<name;
		    a-=c;
		}  
			if(Kagosa<=0){ 
   			     cout<<"You kill "<<fg_red<<MonName<<fg_cyan<<" and raise your hand victoriously"<<endl;
			     gold+=mgold;
//			//Victory();
			     cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl;
			     totalexp+=exp;
			     pnum+=mpotion;
			     again='n';
			}  
			else if(a<=0){ 
			     cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl;
			     cout<<"THE END"<<endl;
//			//Dead();
			     again='n';
			     break;
			     break;
			}  
			else{ 
			      again='y';
			}  
		}  
		else if(battle=='d'){ 
		if((rbattle==0)||(rbattle==3)){ 
			cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
   			}
			else if(rbattle==1){ 
			rbattle=lvprandom(3); 
				if((rbattle==0)||(rbattle==2)){ 
				cout<<fg_red<<MonName<<fg_cyan<<" used a potion!"<<endl; 
				if(Kagosp>0){ 
				Kagosa+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				}  
				else{ 
				cout<<fg_red<<MonName<<fg_cyan<<" used an ether!"<<endl; 
				if(Kagose>0){ 
				Kagosm+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				} 			 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses a spell!"<<endl; 
			rbattle=lvprandom(6); 
			if((rbattle==0)||(rbattle==5)){ 
			if(Kagosm>=5){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses cure and heals 20!"<<endl; 
			Kagosa+=20; 
			Kagosm-=5;
			att=2;
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			att=2;
			}  
			}  
			 
			if(rbattle==1){ 
			if(Kagosm>=10){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses drain does "<<kagosd<<" and heals "<<kagosd<<" HP!"<<endl; 
			a-=kagosd; 
			Kagosa+=kagosd; 
			Kagosm-=5;
			att=2;
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==2){ 
			if(Kagosm>=15){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses rasp does "<<kagosd<<" and heals "<<kagosd<<" MP!"<<endl; 
			a-=kagosd; 
			Kagosm+=kagosd; 
			Kagosm-=5;
			att=2;
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			att=2;
			}  
			}  
			if(rbattle==3){ 
			if(Kagosm>=20){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses seduction and seduces"<<name<<endl; 
			Kagosm-=20; 
			att=1; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl;
			att=2;
			}  
			}  
			}  
		if(att==0){
		cout<<"You block "<<c<<" damage."<<endl; 
//		defend(); 
           	kagosd-=c;
		if(kagosd<=0){kagosd=0;}
		a-=kagosd;
		}
		else if(att==2){
		cout<<"You are unable to block Magic!"<<endl;
		}
		else{ 
		cout<<name<<" does "<<c<<" to "<<name; 
		a-=c; 
		}  
		 
		    if(a>amax){ 
		    a=amax; 
		    again='y'; 
		    }  
		 	else if(a<=0){ 
			cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
			cout<<"THE END"<<endl; 
//			//Dead(); 
			again='n'; 
			break; 
			break; 
			}  
			else{ 
			again='y'; 
			}  
		}  
		else if(battle=='r'){ 
		tip=lvprandom(2); 
			if(tip==0){ 
			cout<<"You run for your cowardly life from "<<fg_red<<MonName<<fg_cyan<<endl; 
//			//Run(); 
			again='n'; 
			y='y';  
			}  
			else if(tip==1){ 
			cout<<"You can't get away."<<endl; 
    		if((rbattle==0)||(rbattle==3)){ 
			cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
			a-=kagosd; 
			}  
			else if(rbattle==1){ 
			rbattle=lvprandom(3); 
				if((rbattle==0)||(rbattle==2)){ 
				cout<<fg_red<<MonName<<fg_cyan<<" used a potion!"<<endl; 
				if(Kagosp>0){ 
				Kagosa+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				}  
				else{ 
				cout<<fg_red<<MonName<<fg_cyan<<" used an ether!"<<endl; 
				if(Kagose>0){ 
				Kagosm+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				} 			 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses a spell!"<<endl; 
			rbattle=lvprandom(6); 
			if((rbattle==0)||(rbattle==5)){ 
			if(Kagosm>=5){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses cure and heals 20!"<<endl; 
			Kagosa+=20; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			 
			if(rbattle==1){ 
			if(Kagosm>=10){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses drain does "<<kagosd<<" and heals "<<kagosd<<" HP!"<<endl; 
			a-=kagosd; 
			Kagosa+=kagosd; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==2){ 
			if(Kagosm>=15){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses rasp does "<<kagosd<<" and heals "<<kagosd<<" MP!"<<endl; 
			a-=kagosd; 
			Kagosm+=kagosd; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==3){ 
			if(Kagosm>=20){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses seduction and seduces"<<name<<endl; 
			Kagosm-=20; 
			att=1; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			}  
		if(att==0){
		}  
		else{ 
		cout<<name<<" does "<<c<<" to "<<name; 
		a-=c; 
		}  
//    		//caway(); 
    			if(a<=0){ 
    			cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
    			cout<<"THE END"<<endl; 
//    			//Dead(); 
    			again='y'; 
    			break; 
				break; 
				}  
				else{ 
				again='y'; 
				}  
			}  
		}  
		else if(battle=='m'){ 
		 do{ 
		 cout<<"("<<fg_white<<"A"<<fg_cyan<<")   Quake     "<<quake<<"/10   4MP"<<endl; 
		 cout<<"("<<fg_white<<"B"<<fg_cyan<<")   Fire      "<<fire<<"/10   6MP"<<endl; 
		 cout<<"("<<fg_white<<"C"<<fg_cyan<<")   Bolt      "<<bolt<<"/10   8MP"<<endl; 
		 cout<<"("<<fg_white<<"D"<<fg_cyan<<")   Ice       "<<ice<<"/10   10MP"<<endl; 
		 cout<<"("<<fg_white<<"E"<<fg_cyan<<")   Cure      "<<cure<<"/30   5MP"<<endl; 
		 cout<<"("<<fg_white<<"F"<<fg_cyan<<")   Drain     "<<drain<<"/10  10MP"<<endl; 
		 cout<<"("<<fg_white<<"G"<<fg_cyan<<")   Rasp      "<<rasp<<"/10   20MP"<<endl; 
		 cout<<"("<<fg_white<<"H"<<fg_cyan<<")   Windslash "<<windslash<<"/15   15MP"<<endl; 
		 cout<<"("<<fg_white<<"I"<<fg_cyan<<")   Confusion "<<confusion<<"/30   15MP"<<endl; 
		 cout<<"("<<fg_white<<"J"<<fg_cyan<<")   Death    "<<death<<"/100   20MP"<<endl; 
		 cout<<"("<<fg_white<<"R"<<fg_cyan<<")eturn"<<endl; 
		 cout<<fg_blue<<"What spell do you wish to cast? "<<fg_white; 
		 cin>>battle; 
		 cout<<fg_cyan;
			if(battle=='a'){ 
				if((quake>0)&&(mcap>=4)){ 
				m-=4; 
				c=10*quake; 
				cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
				cout<<"You cast quake and do "<<c<<" damage."<<endl; 
				Kagosa-=c;
				a-=kagosd;
				//magic(); 
				if((rbattle==0)||(rbattle==3)){ 
				cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
				a-=kagosd;
			}  
			else if(rbattle==1){ 
			rbattle=lvprandom(3); 
				if((rbattle==0)||(rbattle==2)){ 
				cout<<fg_red<<MonName<<fg_cyan<<" used a potion!"<<endl; 
				if(Kagosp>0){ 
				Kagosa+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				}  
				else{ 
				cout<<fg_red<<MonName<<fg_cyan<<" used an ether!"<<endl; 
				if(Kagose>0){ 
				Kagosm+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				} 			 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses a spell!"<<endl; 
			rbattle=lvprandom(6); 
			if((rbattle==0)||(rbattle==5)){ 
			if(Kagosm>=5){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses cure and heals 20!"<<endl; 
			Kagosa+=20; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			 
			if(rbattle==1){ 
			if(Kagosm>=10){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses drain does "<<kagosd<<" and heals "<<kagosd<<" HP!"<<endl; 
			a-=kagosd; 
			Kagosa+=kagosd; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==2){ 
			if(Kagosm>=15){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses rasp does "<<kagosd<<" and heals "<<kagosd<<" MP!"<<endl; 
			a-=kagosd; 
			Kagosm+=kagosd; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==3){ 
			if(Kagosm>=20){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses seduction and seduces"<<name<<endl; 
			Kagosm-=20; 
			att=1; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			}  
		if(att==0){
		}  
		else{ 
		cout<<name<<" does "<<c<<" to "<<name; 
		a-=c; 
		}  
			Kagosa-=c; 
			if(Kagosa<=0){ 
			cout<<"You kill "<<fg_red<<MonName<<fg_cyan<<" and raise your hand victoriously"<<endl; 
			gold+=mgold; 
//			//Victory(); 
			cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
				totalexp+=exp; 
			pnum+=mpotion; 
			again='n'; 
			spell='y'; 
			}  
			else if(a<=0){ 
			cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
			cout<<"THE END"<<endl; 
//			//Dead(); 
			again='n'; 
			spell='y'; 
			break;  
			}  
			else{ 
			again='y'; 
			spell='y'; 
			}  
			}  
				else if(m<4){ 
				cout<<"Not enough mana!"<<endl; 
				spell='n'; 
				}  
				 
				else{ 
				cout<<"You are not trained in the casting of that spell."<<endl; 
				spell='n'; 
				}  
			}  
			else if(battle=='b'){ 
				if((fire>0)&&(mcap>=6)){ 
				m-=6; 
				top=fire*5; 
				c=top+lvprandom(51); 
				cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
			cout<<"You cast fire and do "<<c<<" damage."<<endl; 
//			//magic(); 
	 
			Kagosa-=c; 
			if(Kagosa<=0){ 
			cout<<"You kill "<<fg_red<<MonName<<fg_cyan<<" and raise your hand victoriously"<<endl; 
			gold+=mgold; 
//			//Victory(); 
			cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
				totalexp+=exp; 
			pnum+=mpotion; 
			again='n'; 
			spell='y'; 
			}  
			else if(a<=0){ 
			cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
			cout<<"THE END"<<endl; 
//			//Dead(); 
			again='n'; 
			spell='y'; 
			break;  
			}  
			else{ 
			again='y'; 
			spell='y'; 
				}  
				}  
				else if(m<6){ 
				cout<<"Not enough mana!"<<endl; 
				spell='n'; 
				}  
				else{ 
				cout<<"You are not trained in the casting of that spell."<<endl; 
				spell='n'; 
				}  
			}  
			else if(battle=='c'){ 
				if((bolt>0)&&(mcap>=8)){ 
				m-=8; 
				top=bolt*5; 
				c=top+lvprandom(61); 
					cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
			cout<<"You cast bolt and do "<<c<<" damage."<<endl; 
//			//magic(); 
			if((rbattle==0)||(rbattle==3)){ 
			cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
		 
			}  
			else if(rbattle==1){ 
			rbattle=lvprandom(3); 
				if((rbattle==0)||(rbattle==2)){ 
				cout<<fg_red<<MonName<<fg_cyan<<" used a potion!"<<endl; 
				if(Kagosp>0){ 
				Kagosa+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				}  
				else{ 
				cout<<fg_red<<MonName<<fg_cyan<<" used an ether!"<<endl; 
				if(Kagose>0){ 
				Kagosm+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				} 			 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses a spell!"<<endl; 
			rbattle=lvprandom(6); 
			if((rbattle==0)||(rbattle==5)){ 
			if(Kagosm>=5){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses cure and heals 20!"<<endl; 
			Kagosa+=20; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			 
			if(rbattle==1){ 
			if(Kagosm>=10){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses drain does "<<kagosd<<" and heals "<<kagosd<<" HP!"<<endl; 
			a-=kagosd; 
			Kagosa+=kagosd; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==2){ 
			if(Kagosm>=15){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses rasp does "<<kagosd<<" and heals "<<kagosd<<" MP!"<<endl; 
			a-=kagosd; 
			Kagosm+=kagosd; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==3){ 
			if(Kagosm>=20){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses seduction and seduces"<<name<<endl; 
			Kagosm-=20; 
			att=1; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			}  
		if(att==0){
		 
		}  
		else{ 
		cout<<name<<" does "<<c<<" to "<<name; 
		a-=c; 
		}  
			Kagosa-=c; 
			if(Kagosa<=0){ 
			cout<<"You kill "<<fg_red<<MonName<<fg_cyan<<" and raise your hand victoriously"<<endl; 
			gold+=mgold; 
//			//Victory(); 
			cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
				totalexp+=exp; 
			pnum+=mpotion; 
			again='n'; 
			spell='y'; 
			}  
			else if(a<=0){ 
			cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
			cout<<"THE END"<<endl; 
//			//Dead(); 
			again='n'; 
			spell='y'; 
			break;  
			}  
			else{ 
			again='y'; 
			spell='y'; 
				}  
				}  
					else if(m<8){ 
				cout<<"Not enough mana!"<<endl; 
				spell='n'; 
				}  
				else{ 
				cout<<"You are not trained in the casting of that spell."<<endl; 
				spell='n'; 
				}  
			}  
			else if(battle=='d'){ 
				if((ice>0)&&(mcap>=10)){ 
				m-=10; 
				top=ice*5; 
				c=top+lvprandom(71); 
					cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
					cout<<"You cast ice and do "<<c<<" damage."<<endl; 
//			//magic(); 
			if((rbattle==0)||(rbattle==3)){ 
			cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
		 
			}  
			else if(rbattle==1){ 
			rbattle=lvprandom(3); 
				if((rbattle==0)||(rbattle==2)){ 
				cout<<fg_red<<MonName<<fg_cyan<<" used a potion!"<<endl; 
				if(Kagosp>0){ 
				Kagosa+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				}  
				else{ 
				cout<<fg_red<<MonName<<fg_cyan<<" used an ether!"<<endl; 
				if(Kagose>0){ 
				Kagosm+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				} 			 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses a spell!"<<endl; 
			rbattle=lvprandom(6); 
			if((rbattle==0)||(rbattle==5)){ 
			if(Kagosm>=5){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses cure and heals 20!"<<endl; 
			Kagosa+=20; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			 
			if(rbattle==1){ 
			if(Kagosm>=10){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses drain does "<<kagosd<<" and heals "<<kagosd<<" HP!"<<endl; 
			a-=kagosd; 
			Kagosa+=kagosd; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==2){ 
			if(Kagosm>=15){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses rasp does "<<kagosd<<" and heals "<<kagosd<<" MP!"<<endl; 
			a-=kagosd; 
			Kagosm+=kagosd; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==3){ 
			if(Kagosm>=20){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses seduction and seduces"<<name<<endl; 
			Kagosm-=20; 
			att=1; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			}  
		if(att==0){
		}  
		else{ 
		cout<<name<<" does "<<c<<" to "<<name; 
		a-=c; 
		}  
			Kagosa-=c; 
			if(Kagosa<=0){ 
			cout<<"You kill "<<fg_red<<MonName<<fg_cyan<<" and raise your hand victoriously"<<endl; 
			gold+=mgold; 
			//Victory(); 
			cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
			totalexp+=exp; 
			pnum+=mpotion; 
			again='n'; 
			spell='y'; 
			}  
			else if(a<=0){ 
			cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
			cout<<"THE END"<<endl; 
			//Dead(); 
			again='n'; 
			spell='y'; 
			break;  
			}  
			else{ 
			again='y'; 
			spell='y'; 
				}  
				}  
					else if(m<10){ 
				cout<<"Not enough mana!"<<endl; 
				spell='n'; 
				}  
				else{ 
				cout<<"You are not trained in the casting of that spell."<<endl; 
				spell='n'; 
				}  
			}  
			else if(battle=='e'){ 
				if((cure>0)&&(mcap>=5)){ 
				int la; 
				m-=5; 
				la=a; 
				top=cure*5; 
				a+=top; 
				if(a<=amax){ 
				cout<<"You cure "<<top<<" damage."<<endl; 
				//magic(); 
				}  
				else{ 
				cout<<"You cure "<<(amax-la)<<" damage."<<endl; 
				//magic(); 
				a=amax; 
				}  
				spell='y'; 
				again='y'; 
				}  
					else if(m<5){ 
				cout<<"Not enough mana!"<<endl; 
				spell='n'; 
				}  
				else{ 
				cout<<"You are not trained in the casting of that spell."<<endl; 
				spell='n'; 
				again='y'; 
				}  
			}  
			else if(battle=='f'){ 
				if((drain>0)&&(mcap>=10)){ 
				m-=10; 
				top=drain*5; 
				c=1+lvprandom(top); 
				cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
				cout<<"You do "<<c<<" damage and use it to heal your wounds."<<endl; 
				//magic(); 
				a+=c; 
				if(a>amax){ 
				a=amax; 
				}  
				if((rbattle==0)||(rbattle==3)){ 
			cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
		 
			}  
			else if(rbattle==1){ 
			rbattle=lvprandom(3); 
				if((rbattle==0)||(rbattle==2)){ 
				cout<<fg_red<<MonName<<fg_cyan<<" used a potion!"<<endl; 
				if(Kagosp>0){ 
				Kagosa+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				}  
				else{ 
				cout<<fg_red<<MonName<<fg_cyan<<" used an ether!"<<endl; 
				if(Kagose>0){ 
				Kagosm+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				} 			 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses a spell!"<<endl; 
			rbattle=lvprandom(6); 
			if((rbattle==0)||(rbattle==5)){ 
			if(Kagosm>=5){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses cure and heals 20!"<<endl; 
			Kagosa+=20; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			 
			if(rbattle==1){ 
			if(Kagosm>=10){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses drain does "<<kagosd<<" and heals "<<kagosd<<" HP!"<<endl; 
			a-=kagosd; 
			Kagosa+=kagosd; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==2){ 
			if(Kagosm>=15){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses rasp does "<<kagosd<<" and heals "<<kagosd<<" MP!"<<endl; 
			a-=kagosd; 
			Kagosm+=kagosd; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==3){ 
			if(Kagosm>=20){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses seduction and seduces"<<name<<endl; 
			Kagosm-=20; 
			att=1; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			}  
		if(att==0){
		}  
		else{ 
		cout<<name<<" does "<<c<<" to "<<name; 
		a-=c; 
		}  
			Kagosa-=c; 
			if(Kagosa<=0){ 
			cout<<"You kill "<<fg_red<<MonName<<fg_cyan<<" and raise your hand victoriously"<<endl; 
			gold+=mgold; 
			//Victory(); 
			cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
				totalexp+=exp; 
			pnum+=mpotion; 
			again='n'; 
			spell='y'; 
			}  
			else if(a<=0){ 
			cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
			cout<<"THE END"<<endl; 
			//Dead(); 
			again='n'; 
			spell='y'; 
			break;  
			}  
			else{ 
			again='y'; 
			spell='y'; 
				}  
				}  
					else if(m<10){ 
				cout<<"Not enough mana!"<<endl; 
				spell='n'; 
				}  
				else{ 
				cout<<"You are not trained in the casting of that spell."<<endl; 
				spell='n'; 
				}  
			}  
			else if(battle=='g'){ 
				if((rasp>0)&&(mcap>=20)){ 
				m-=20; 
					top=rasp*5; 
				c=1+lvprandom(top); 
				cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
				cout<<"You do "<<c<<" damage and use it to replenish your magic supply."<<endl; 
//				//magic(); 
				m+=c; 
				if(m>mcap){ 
				m=mcap; 
				}  
				if((rbattle==0)||(rbattle==3)){ 
			cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
			 
			}  
			else if(rbattle==1){ 
			rbattle=lvprandom(3); 
				if((rbattle==0)||(rbattle==2)){ 
				cout<<fg_red<<MonName<<fg_cyan<<" used a potion!"<<endl; 
				if(Kagosp>0){ 
				Kagosa+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				}  
				else{ 
				cout<<fg_red<<MonName<<fg_cyan<<" used an ether!"<<endl; 
				if(Kagose>0){ 
				Kagosm+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				} 			 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses a spell!"<<endl; 
			rbattle=lvprandom(6); 
			if((rbattle==0)||(rbattle==5)){ 
			if(Kagosm>=5){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses cure and heals 20!"<<endl; 
			Kagosa+=20; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			 
			if(rbattle==1){ 
			if(Kagosm>=10){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses drain does "<<kagosd<<" and heals "<<kagosd<<" HP!"<<endl; 
			a-=kagosd; 
			Kagosa+=kagosd; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==2){ 
			if(Kagosm>=15){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses rasp does "<<kagosd<<" and heals "<<kagosd<<" MP!"<<endl; 
			a-=kagosd; 
			Kagosm+=kagosd; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==3){ 
			if(Kagosm>=20){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses seduction and seduces"<<name<<endl; 
			Kagosm-=20; 
			att=1; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			}  
		if(att==0){
		}  
		else{ 
		cout<<name<<" does "<<c<<" to "<<name; 
		a-=c; 
		}  
			Kagosa-=c; 
			if(Kagosa<=0){ 
			cout<<"You kill "<<fg_red<<MonName<<fg_cyan<<" and raise your hand victoriously"<<endl; 
			gold+=mgold; 
//			//Victory(); 
			cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
				totalexp+=exp; 
			pnum+=mpotion; 
			again='n'; 
			spell='y'; 
			}  
			else if(a<=0){ 
			cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
			cout<<"THE END"<<endl; 
//			//Dead(); 
			again='n'; 
			spell='y'; 
			break;  
			}  
			else{ 
			again='y'; 
			spell='y'; 
				}  
				}  
					else if(m<20){ 
				cout<<"Not enough mana!"<<endl; 
				spell='n'; 
				}  
				else{ 
				cout<<"You are not trained in the casting of that spell."<<endl; 
				spell='n'; 
				}  
			}  
			else if(battle=='h'){ 
				if((windslash>0)&&(mcap>=15)){ 
					m-=15; 
				c=20*windslash; 
				cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
			cout<<"You cast windslash and do "<<c<<" damage."<<endl; 
			//magic(); 
			if((rbattle==0)||(rbattle==3)){ 
			cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
		 
			}  
			else if(rbattle==1){ 
			rbattle=lvprandom(3); 
				if((rbattle==0)||(rbattle==2)){ 
				cout<<fg_red<<MonName<<fg_cyan<<" used a potion!"<<endl; 
				if(Kagosp>0){ 
				Kagosa+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				}  
				else{ 
				cout<<fg_red<<MonName<<fg_cyan<<" used an ether!"<<endl; 
				if(Kagose>0){ 
				Kagosm+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				} 			 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses a spell!"<<endl; 
			rbattle=lvprandom(6); 
			if((rbattle==0)||(rbattle==5)){ 
			if(Kagosm>=5){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses cure and heals 20!"<<endl; 
			Kagosa+=20; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			 
			if(rbattle==1){ 
			if(Kagosm>=10){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses drain does "<<kagosd<<" and heals "<<kagosd<<" HP!"<<endl; 
			a-=kagosd; 
			Kagosa+=kagosd; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==2){ 
			if(Kagosm>=15){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses rasp does "<<kagosd<<" and heals "<<kagosd<<" MP!"<<endl; 
			a-=kagosd; 
			Kagosm+=kagosd; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==3){ 
			if(Kagosm>=20){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses seduction and seduces"<<name<<endl; 
			Kagosm-=20; 
			att=1; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			}  
		if(att==0){
		}  
		else{ 
		cout<<name<<" does "<<c<<" to "<<name; 
		a-=c; 
		}  
			Kagosa-=c; 
			if(Kagosa<=0){ 
			cout<<"You kill "<<fg_red<<MonName<<fg_cyan<<" and raise your hand victoriously"<<endl; 
			gold+=mgold; 
			//Victory(); 
			cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
				totalexp+=exp; 
			pnum+=mpotion; 
			again='n'; 
			spell='y'; 
			}  
			else if(a<=0){ 
			cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
			cout<<"THE END"<<endl; 
			//Dead(); 
			again='n'; 
			spell='y'; 
			break;  
			}  
			else{ 
			again='y'; 
			spell='y'; 
				}  
				}  
					else if(m<15){ 
				cout<<"Not enough mana!"<<endl; 
				spell='n'; 
				}  
				else{ 
				cout<<"You are not trained in the casting of that spell."<<endl; 
				spell='n'; 
				}  
			}  
			else if(battle=='i'){ 
				if((confusion>0)&&(mcap>=15)){ 
				m-=15; 
				top=lvprandom(32-confusion); 
			if(top!=0){ 
			cout<<"Confusion fails to rot "<<fg_red<<MonName<<fg_cyan<<"'s mind!"<<endl; 
			//caway(); 
					cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
			if((rbattle==0)||(rbattle==3)){ 
					cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
			}  
			else if(rbattle==1){ 
			rbattle=lvprandom(3); 
				if((rbattle==0)||(rbattle==2)){ 
				cout<<fg_red<<MonName<<fg_cyan<<" used a potion!"<<endl; 
				if(Kagosp>0){ 
				Kagosa+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				}  
				else{ 
				cout<<fg_red<<MonName<<fg_cyan<<" used an ether!"<<endl; 
				if(Kagose>0){ 
				Kagosm+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				} 			 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses a spell!"<<endl; 
			rbattle=lvprandom(6); 
			if((rbattle==0)||(rbattle==5)){ 
			if(Kagosm>=5){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses cure and heals 20!"<<endl; 
			Kagosa+=20; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			 
			if(rbattle==1){ 
			if(Kagosm>=10){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses drain does "<<kagosd<<" and heals "<<kagosd<<" HP!"<<endl; 
			a-=kagosd; 
			Kagosa+=kagosd; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==2){ 
			if(Kagosm>=15){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses rasp does "<<kagosd<<" and heals "<<kagosd<<" MP!"<<endl; 
			a-=kagosd; 
			Kagosm+=kagosd; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==3){ 
			if(Kagosm>=20){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses seduction and seduces"<<name<<endl; 
			Kagosm-=20; 
			att=1; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			}  
		if(att==0){
		}  
		else{ 
		cout<<name<<" does "<<c<<" to "<<name; 
		a-=c; 
		}  
			}  
			else if(top==0){ 
			cout<<"Confusion forces "<<fg_red<<MonName<<fg_cyan<<" to cut it's own flesh!"<<endl; 
			//magic(); 
			cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage to "<<fg_red<<MonName<<fg_cyan<<"!"<<endl; 
			Kagosa-=kagosd; 
			}  
			if(Kagosa<=0){ 
			cout<<"You kill "<<fg_red<<MonName<<fg_cyan<<" and raise your hand victoriously"<<endl; 
			gold+=mgold; 
			//Victory(); 
			cout<<"You get "<<fg_white<<exp<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
				totalexp+=exp; 
			pnum+=mpotion; 
			again='n'; 
			spell='y'; 
			}  
			else if(a<=0){ 
			cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
			cout<<"THE END"<<endl; 
			//Dead(); 
			again='n'; 
			spell='y'; 
			break;  
			}  
			else{ 
			again='y'; 
			spell='y'; 
				}  
				}  
					else if(m<15){ 
				cout<<"Not enough mana!"<<endl; 
				spell='n'; 
				}  
				else{ 
				cout<<"You are not trained in the casting of that spell."<<endl; 
				smallperson(); 
				spell='n'; 
				}  
			}  
			else if(battle=='j'){ 
				if((death>0)&&(mcap>=20)){ 
				m-=20; 
						top=lvprandom(102-death); 
			if(top!=0){ 
			cout<<"Death fails to hear your summons!"<<endl; 
			//caway(); 
					cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
			if((rbattle==0)||(rbattle==3)){ 
			cout<<fg_red<<MonName<<fg_cyan<<" does "<<kagosd<<" damage."<<endl; 
			a-=kagosd; 
			}  
			else if(rbattle==1){ 
			rbattle=lvprandom(3); 
				if((rbattle==0)||(rbattle==2)){ 
				cout<<fg_red<<MonName<<fg_cyan<<" used a potion!"<<endl; 
				if(Kagosp>0){ 
				Kagosa+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				}  
				else{ 
				cout<<fg_red<<MonName<<fg_cyan<<" used an ether!"<<endl; 
				if(Kagose>0){ 
				Kagosm+=10; 
				}  
				else{ 
				cout<<"But "<<fg_red<<MonName<<fg_cyan<<" doesn't have any!"; 
				}  
				} 			 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses a spell!"<<endl; 
			rbattle=lvprandom(6); 
			if((rbattle==0)||(rbattle==5)){ 
			if(Kagosm>=5){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses cure and heals 20!"<<endl; 
			Kagosa+=20; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			 
			if(rbattle==1){ 
			if(Kagosm>=10){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses drain does "<<kagosd<<" and heals "<<kagosd<<" HP!"<<endl; 
			a-=kagosd; 
			Kagosa+=kagosd; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==2){ 
			if(Kagosm>=15){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses rasp does "<<kagosd<<" and heals "<<kagosd<<" MP!"<<endl; 
			a-=kagosd; 
			Kagosm+=kagosd; 
			Kagosm-=5; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			if(rbattle==3){ 
			if(Kagosm>=20){ 
			cout<<fg_red<<MonName<<fg_cyan<<" uses seduction and seduces"<<name<<endl; 
			Kagosm-=20; 
			att=1; 
			}  
			else{ 
			cout<<fg_red<<MonName<<fg_cyan<<" needs MP!"<<endl; 
			}  
			}  
			}  
		if(att==0){
		}  
		else{ 
		cout<<name<<" does "<<c<<" to "<<name; 
		a-=c; 
		}  
			}  
			else if(top==0){ 
			cout<<"Death appears before you and kills "<<fg_red<<MonName<<fg_cyan<<" in a grusome display of gore!"<<endl; 
			//magic(); 
			Kagosa=0; 
			}  
			if(Kagosa<=0){ 
			cout<<fg_red<<MonName<<fg_cyan<<" falls dead and you raise your hand victoriously"<<endl; 
			gold+=mgold; 
			//Victory(); 
			cout<<"You get "<<fg_white<<fg_white<<exp<<fg_cyan<<fg_cyan<<" exp and "<<fg_yellow<<mgold<<fg_cyan<<" gold and "<<fg_white<<mpotion<<fg_cyan<<" potions."<<endl; 
				totalexp+=exp; 
			pnum+=mpotion; 
			again='n'; 
			spell='y'; 
			}  
			else if(a<=0){ 
			cout<<"You have been slain by "<<fg_red<<MonName<<fg_cyan<<endl; 
			cout<<"THE END"<<endl; 
			//Dead(); 
			again='n'; 
			spell='y'; 
			break;  
			}  
			else{ 
			again='y'; 
			spell='y'; 
				}  
				}  
					else if(m<20){ 
				cout<<"Not enough mana!"<<endl; 
				spell='n'; 
				}  
				else{ 
				cout<<"You are not trained in the casting of that spell."<<endl; 
				smallperson(); 
				spell='n'; 
				}  
			}  
			else{ 
			spell='y'; 
			}  
		 } while(spell=='n');	 
		}  
		else if(battle=='u'){ 
		cout<<"("<<fg_white<<"E"<<fg_cyan<<")ther"<<endl; 
		cout<<"("<<fg_white<<"P"<<fg_cyan<<")otion"<<endl; 
		cout<<fg_blue<<"Which Item? "<<fg_white;
		cin>>battle; 
		cout<<fg_cyan;
		if(battle=='p'){ 
		cout<<"You use a potion."<<endl; 
			//drinkpotion(); 
			if(pnum>=1){ 
				 
				a+=10; 
				if(a>amax){ 
				a=amax; 
				}  
				pnum--; 
				again='y'; 
			 
			}  
			else if(a>=amax){ 
			cout<<"You don't need it!"<<endl; 
			smallperson(); 
			again='y';			 
			}  
			else if(pnum<1){ 
			cout<<"You don't have any."<<endl; 
			smallperson(); 
			again='y'; 
			}  
		}  
		else if(battle=='e'){ 
		cout<<"You use a ether."<<endl; 
//			//drinkpotion(); 
			if(num>=1){ 
			 
				m+=10; 
				if(m>mcap){ 
				m=mcap; 
				}  
				num--; 
				again='y'; 
				 
			}  
			else if(m>=mcap){ 
			cout<<"You don't need it!"<<endl; 
			smallperson(); 
			again='y';			 
			}  
			else if(num<1){ 
			cout<<"You don't have any."<<endl; 
			smallperson(); 
			again='y'; 
			}  
		}  
		}  
		else{ 
		cout<<"That won't do anything."<<endl; 
		smallperson(); 
		again='y'; 
		}  
} while(again=='y'); 
	for(;totalexp>=gain;){ 
	totalexp-=gain; 
	level++; 
	gain=level*tt; 
	cout<<fg_white<<"You have gained a level!"<<fg_cyan<<endl; 
//		//Victory(); 
		do{ 
			points=35; 
			cout<<"Now you have "<<points<<" points."<<endl; 
			cout<<"How many points do you want to add to your life? "<<endl; 
			cin>>temp; 
				if(temp>points){ 
				cout<<fg_red<<"You don't have that many points!"<<fg_cyan<<endl; 
				answer='n'; 
				}  
				else{ 
				amax+=temp; 
				a=amax; 
				points-=temp; 
				cout<<"Now you have "<<fg_white<<points<<fg_cyan<<" points."<<endl; 
				cout<<"How many points do you want to add to your attack? "<<endl; 
				cin>>temp; 
					if(temp>points){ 
					cout<<fg_red<<"You don't have that many points!"<<fg_cyan<<endl; 
					answer='n'; 
					}  
					else{ 
					max+=temp; 
					points-=temp; 
					cout<<"Now you have "<<fg_white<<points<<fg_cyan<<" points."<<endl; 
				    cout<<"How many points do you want to add to your Magic? "<<endl; 
				    cin>>temp; 
				    	if(temp>points){ 
						cout<<fg_red<<"You don't have that many points!"<<fg_cyan<<endl; 
						answer='n'; 
						}  
						else{ 
						mcap+=temp; 
						points-=temp; 
		            			pnum+=points;
						cout<<"Life:    "<<amax<<endl; 
						cout<<"Attack:  "<<(max-1)<<endl; 
						cout<<"Potions: "<<pnum<<endl; 
						cout<<"Mana:    "<<mcap<<endl; 
						cout<<endl; 
						cout<<fg_blue<<"Are these stats OK? "<<fg_white; 
						cin>>answer;
						cout<<fg_cyan;
						}  
						if(answer=='n'){ 
						amax=lamax; 
						max=lmax; 
						pnum=lpnum; 
						mcap=lmcap; 
						}  
				}  
				}  
		} while(answer=='n'); 
	}  
} 
 
//--------------------MATSERMIND-------------------------------------------------------------------| 
//=================================================================================================|                  
void mastermind(int &win) 
                { 
int guess=1; 
string answer; 
	randomize(); 
	int g1,g2,g3,cc=0,pc=0; 
	int p1,p2,p3;p1=1+lvprandom(5),p2=1+lvprandom(5),p3=1+lvprandom(5); 
	cout<<fg_yellow<<"                       WELCOME TO MASTERMIND!"<<fg_blue<<endl; 
	cout<<endl; 
	cout<<"Would you like instructions? "<<fg_white;
	cin>>answer;
	cout<<fg_cyan<<"\n\n\n";
	if((answer[0]=='y')||(answer[0]=='Y'))
	{
		cout<<"There are five numbers and three pegs. The object of the game is to guess which\nnumber is on which peg.";
		cout<<fg_white<<"\n\n  Press Any Key To Continue...\n\n\n"<<fg_cyan;
		_getch();
	}
	cout<<endl; 

	do{ 
		p1=1+lvprandom(5),p2=1+lvprandom(5),p3=1+lvprandom(5); 
	} while((p1==p2)||(p1==p3)||(p2==p3)); 
	for(;guess<10;guess++){ 
		cout<<"Guess "<<guess<<endl; 
		cout<<"     First peg:  "; 
		cin>>g1; 
		cout<<"     Second peg:  "; 
		cin>>g2; 
		cout<<"     Third peg:  "; 
		cin>>g3; 
		if(g1==p1){ 
			pc++; 
			cc++;}  
		if(g2==p2){ 
			pc++; 
			cc++;}  
		if(g3==p3){ 
			pc++; 
			cc++;} 		 
		if((g1==p2)||(g1==p3)) 
			cc++; 
		if((g2==p1)||(g2==p3)) 
			cc++; 
		if((g3==p1)||(g3==p2)) 
			cc++; 
		if((g1==p1)&&(g2==p2)&&(g3==p3)){ 
			cout<<"You win!"<<endl; 
			cout<<endl; 
			break;}  
		cout<<"You have "<<pc<<" correct peg(s) and "<<cc<<" correct color(s)."<<endl; 
		cout<<endl; 
		cc=0,pc=0;}  
	cout<<"It took you "<<guess<<" guesses.   "; 
	if(guess==10){ 
		cout<<"'Nooo! I lost' you whine."<<endl; 
	    win=0; 
        } 	 
	if((guess>=5)&&(guess<=9)){ 
		cout<<"'Damn that was hard!' you say. "<<endl; 
	    win=1; 
		}  
	if(guess<=4){ 
		cout<<"'I Got it!' you declare."<<endl; 
	    win=1; 
		} 	 
	}  
 
//-----------------------QUESTS------------------------------------------------------------| 
//======================STARTOFQUESTS======================================================| 
//_______________________QUEST_1___________________________________________________________| 
//=========================================================================================|
void quest1(string &name, int &pnum, int &max, int &totalexp, int &amax, int &a,
			int &gold, int &level, int &gain, int &m, int &mcap, int &num, int fire,
			int ice, int bolt, int cure, int drain, int rasp, int death, int quake,
			int confusion, int windslash)
{ 
string direction;

cout<<clr;
cout<<fg_white<<"\n\n\nPress Any Key To Continue"<<fg_cyan;
_getch();

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
cout<<"marching by. You quickly hide bihind a conveniantly placed boulder and pray to"<<endl;
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
MBattle("Goblin", max, a, amax, 15, 70, pnum, 25, level, totalexp, gold, 250, 1, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash);                   
cout<<fg_white<<"\n\nPress Any Key To Continue\n\n"<<fg_cyan;   
_getche();
if(a>0){ 
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
MBattle("BlackSpider", max, a, amax, 20, 145, pnum, 125, level, totalexp, gold, 100, 2, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
cout<<fg_white<<"\n\n\nPress Any Key To Continue"<<fg_cyan;
_getche();
//Quest 1, Story Block 6A, Through Woods
if(a>0){ 
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
MBattle("RockMonster", max, a, amax, 7, 300, pnum, 150, level, totalexp, gold, 15, 1, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash);  
cout<<fg_white<<"\n\n\nPress Any Key To Continue"<<fg_cyan;
_getch();
//Quest 1, Story Block 6B, Around Woods
if(a>0){ 
cout<<"You continue on your way and decide to set up camp outside the Forsaken Cave."<<endl;
cout<<"pitch your tent set a fire and go to sleep."<<endl; 
}}}  
//Quest 1, Story Block 7, In The Cave 
if(a>0){ 
cout<<fg_white<<"\n\nPress Any Key To Continue... "<<fg_cyan; 
_getche();
cout<<clr;
cout<<"You enter the cave and you feel as if the air has turned to ice. As you continue"<<endl;
cout<<"through the cave a demon jumps out and swings its claws towards you. You"<<endl;
cout<<"backstep just in time and are pitched in battle."<<endl; 
cout<<fg_white<<"\n\nPress Any Key To Continue... \n\n"<<fg_cyan; 
_getche();
//Quest 1, Fight Block 3
MBattle("Demon", max, a, amax, 25, 125, pnum, 175, level, totalexp, gold, 1000, 3, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash);   
//Quest 1, Story Block 8 
cout<<fg_white<<"\n\nPress Any Key To Continue... \n\n"<<fg_cyan; 
_getche(); 
if(a>0){ 
cout<<clr; 
cout<<"You continue you continue into the cave, sweat pouring down your face, despite"<<endl;
cout<<"the cold air, when you see a luminent blue glow coming from a little farther"<<endl;
cout<<"down the tunnel."<<endl;
cout<<fg_white<<"\n\n\nPress Any Key To Continue... "<<fg_cyan; 
_getche();
cout<<"  'Finally!', you say to no one in particular. Suddenly the blue glow starts to"<<endl;
cout<<"move towards you. 'Oh Shit!' you exclame, as the biggest Demonic creature you`ve"<<endl;
cout<<"ever seen stepsinto view."<<endl;    
cout<<fg_white<<"\n\n\nPress Any Key To Continue... "<<fg_cyan; 
_getche();
//Quest 1, Final Fight Block
MBattle("Demon Lord", max, a, amax, 30, 300, pnum, 500, level, totalexp, gold, 2500, 5, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
cout<<fg_white<<"\n\nPress Any Key To Continue... "<<fg_cyan; 
_getche();
//Quest 1, Story Block 9	
if(a>0){                                                                                                                                                      
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
a=0;                                                                                                                                                                          
}
else{ 
cout<<"'Yes I found your magical stone' you say. 'Oh Thank you!' says the Wizard, 'Here"<<endl;
cout<<"is your reward.' He hands you �"<<fg_yellow<<"5,000"<<fg_cyan<<" and three potions in exchange for"<<endl;
cout<<"his stone"<<endl; 
pnum+=3; 
gold+=5000; 
}}}}}
//---------------------------------------------------QUEST-2------------------------------------| 
//==============================================================================================|
void quest2(string name, int &pnum, int &max, int &totalexp, int &amax, int &a, int &gold,
			int &level, int &gain, int &m, int &mcap, int &num, int fire, int ice,
			int bolt, int cure, int drain, int rasp, int death, int quake, int confusion,
			int windslash) 
{ 
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
//Quest 2, Story Block 1
cout<<"After breakfast you step out side to get some fresh air. When you close your"<<endl;
cout<<"door you see a knife in it. The knife holds a note to your door. You rip the"<<endl;
cout<<"note off the door, the note reads:"<<endl;
cout<<fg_white<<"   We Have your best friend and if you ever want to see her again you\n"<<endl;
cout<<"   need to bring �30000 to the spires reach castle by the next full moon.\n"<<fg_cyan<<endl;  
cout<<"'�30,000! how will I ever get that much?' You scream after reading the ransom"<<endl;
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
//Quest 2, Fight Block 1 
MBattle("High Demon", max, a, amax, 75, 350, pnum, 350, level, totalexp, gold, 300, lvprandom(6), gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
cout<<clr;
if(a>0){
//Quest 2, Story Block 3
cout<<"You remove your sword from the demons chest and continue on your way, a little"<<endl;
cout<<"more cautious this time. You finaly reach the castle by about noon the next day."<<endl;
cout<<"You feel refreshed after camping the last night.";
a=amax;
m=mcap; 
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
//Quest 2, Story Block 4
cout<<"You enter the castle and as you get to the top a larg Manticore stands in your"<<endl;
cout<<"way and raises its weapon with a hateful smirk."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
//Quest 2, Fight Block 2
MBattle("Manticore", max, a, amax, 75, 250, pnum, 500, level, totalexp, gold, 1000, 5, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
if(a>0){ 
//Quest 2, Story Block 5
cout<<"After killing the Manticore you head into the back room to find your friend. You"<<endl;
cout<<"see her hanging in chains on the wall you see a large Lizardman standing with"<<endl;
cout<<"his sword in his hand waiting for you."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
//Quest 2, Fight Block 3
MBattle("LizardMan", max, a, amax, 75, 600, pnum, 1000, level, totalexp, gold, 200, 5, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
if(a>0){
//Quest 2, Story Block 6
cout<<"You free your best friend and make for the door just as a gel troop stands in"<<endl;
cout<<"your way"<<endl; 
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
//Quest 2, Final Fight Block
MBattle("Gel Troop", max, a, amax, 30, 200, pnum, 500, level, totalexp, gold, 100, 1, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
if(a>0){
//Quest 2, Final Story Block
cout<<"You take your friend and head outside. You run home just as fast as you can go."<<endl; 					
cout<<"When you reach town, you say goodbye to your friend and go inside your home."<<endl; 
}}}}}  
//----------------------------------------------QUEST3-----------------------------------------| 
//=============================================================================================|
void quest3(string name, int &pnum, int &max, int &totalexp, int &amax, int &a, int &gold,
			int &level, int &gain, int &m, int &mcap, int &num, int fire, int ice,
			int bolt, int cure, int drain, int rasp, int death, int quake, int confusion,
			int windslash) 
{ 
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
cout<<"'Forgive me for being me for blunt but I do not belive my son still breaths on this world.'  At this the Queen burst into tears and is taken away by her ladies in waiting.  The King seems unaware of her and as soon as it is quite he continues 'I have only one hope of keeping the throne in my family line and that is for my daughter to marry.  Here in lies your purpose for being here.  My daughter`s love has been captured and is being held by a group of satyrs who threaten to remove his organs and send his head home on a pike.  I need you to travel to these satyrs and take my daughter's love back!  My daughter will accompany you see is a skilled Magus and may be useful.'"<<endl; 
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
MBattle("Black Dragon", max, a, amax, 265, 800, pnum, 5000, level, totalexp, gold, 20000, 2, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
if(a>0){ 
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
MBattle("Satyr Guard", max, a, amax, 21, 100, pnum, 100, level, totalexp, gold, 100, 1, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
if(a>0){ 
MBattle("Better Satyr Guard", max, a, amax, 26, 150, pnum, 300, level, totalexp, gold, 200, 2, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
if(a>0){ 
MBattle("Satyr Commander", max, a, amax, 31, 200, pnum, 600, level, totalexp, gold, 2000, 4, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
if(a>0){ 
MBattle("Satyr Commander", max, a, amax, 31, 200, pnum, 600, level, totalexp, gold, 2000, 4, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
if(a>0){ 
MBattle("SatyrLeader", max, a, amax, 36, 250, pnum, 1200, level, totalexp, gold, 10000, 10, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
if(a>0){ 
MBattle("SatyrLeader", max, a, amax, 36, 250, pnum, 1200, level, totalexp, gold, 10000, 10, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
cout<<clr;
//Quest 3, Story Block 8
if(a>0){ 
cout<<"After having dispatched the last of the Satyr Guards, you are suprised to see"<<endl;
cout<<"one very frail satyr walk towards you. To an untrained warrior this might seem"<<endl;
cout<<"an easy match, but your training, and this man`s absence of fear tells you that"<<endl;
cout<<"this is the Magic user of the clan! Lifting his hands he casts a spell and a"<<endl;
cout<<"mirror image of you decends upon you, sword in hand."<<endl;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
//Quest 3, Final Fight Block
MBattle(name, max, a, amax, max, a, pnum, totalexp, level, totalexp, gold, gold, pnum, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
}  
if(a>0){ 
//Quest 3, Final Story Block
cout<<"You are startled by Rachel's hand at your shoulder, and you must admit you are a"<<endl;
cout<<"little shaken by running a sword through your own chest, and are surprised to"<<endl;
cout<<"find yourself back in the castle.  The guards carry Charles to his chambers and"<<endl;
cout<<"the King approaches 'Thank you noble "<<name<<"."<<endl;
cout<<"Although I can never begin to repay you maybe this will help.'\n"<<endl; 
cout<<fg_yellow<<"Received King's Reward!\n"<<fg_white<<endl; 
cout<<"You got:\n\n"<<endl; 
cout<<"Plus one to your Confusion level"<<endl; 
cout<<"�"<<fg_yellow<<"30,000"<<fg_cyan<<endl; 
gold+=30000; 
confusion++; 
if(confusion>30){ 
confusion=30; 
}}}}}}}}}  
//---------------------------------------QUEST4-------------------------------------------------| 
//==============================================================================================|
void quest4(string name, int &pnum, int &max, int &totalexp, int &amax, int &a, 
			int &gold, int &level, int &gain, int &m, int &mcap, int &num, int fire, int ice,
			int bolt, int cure, int drain, int rasp, int death, int quake, int confusion,
			int windslash) 
{  
int win=0; 
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
cout<<clr<<fg_cyan; 
cout<<"After Breakfast, an Imp enters your home and gives you a puzzel. 'Finish this"<<endl;
cout<<"puzzel or die' says the hellish Imp. You look at the puzzel in dismay you read"<<endl;
cout<<"the cover and discover that it is called 'MASTERMIND'."<<endl;
cout<<"'Hmm' you say 'Lets see....'"<<endl; 
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan; 
_getch();
mastermind(win); 
if(win==1){ 
cout<<"So you got it eh says the Imp. Well I'm true to my word and shall let you live"<<endl;
cout<<"I'll also give you a prize! he waves his hands and you feel a tingle then he"<<endl;
cout<<"turns and leaves."<<endl; 
mcap+=15; 
m=mcap;
amax+=15; 
a=amax; 
}  
else if(win==0){ 
cout<<"you got it wrong and I'm true to my word so now you die chuckles the imp"<<endl;	 
MBattle("Imp", max, a, amax, 120, 1000, pnum, 2500, level, totalexp, gold, 1000, 6, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
if(a>0){ 
cout<<"After a long and grueling battle you finally smite the hellish creature that"<<endl;
cout<<"slightly resembled an elf. You kick its corpse into the street and commence to"<<endl;
cout<<"cleaning the mess."<<endl; 
}  
else{ 
cout<<"After a long and grueling battle you are smited by the hellish Imp and in turn"<<endl;
cout<<"have lost the game."<<endl;  
cout<<"                                   THE    END!"; 
}  
}  
}  
 
//-------------------------QUEST5------------------------------------------------------------------| 
//=================================================================================================|
void quest5(string &name, int &pnum, int &max, int &totalexp, int &amax, int &a, int &gold,
			int &level, int &gain, int &m, int &mcap, int &num, int fire, int ice,
			int bolt, int cure, int drain, int rasp, int death, int quake, int confusion,
			int windslash, int sex)
{
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
	if(sex=='m') 
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
MBattle("Fat Guy", max, a, amax, 11,  500, pnum, 5000, level, totalexp, gold, 1000, 1, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
if(a>0){
cout<<"The crowd cheers you on as you exit the arena"<<endl; 
a=amax; 
m=mcap; 
cout<<"You prepare for your next bout and step into the arena"<<endl; 
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
MBattle("Soldier", max, a, amax, 16,  600, pnum, 6000, level, totalexp, gold, 2000, 2, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
if(a>0){ 
cout<<"The crowd cheers you on as you exit the arena"<<endl; 
a=amax; 
m=mcap; 
cout<<"You prepare for your next bout and step into the arena"<<endl; 
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
MBattle("Commander", max, a, amax, 21,  700, pnum, 7000, level, totalexp, gold, 3000, 4, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
if(a>0){ 
cout<<"The crowd cheers you on as you exit the arena"<<endl; 
a=amax; 
m=mcap; 
cout<<"You prepare for your next bout and step into the arena"<<endl; 
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
MBattle("Dragon Slayer", max, a, amax, 26,  1000, pnum, 8000, level, totalexp, gold, 5000, 7, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
if(a>0){
//Quest 5, Story Block 4
cout<<"As you pull your sword from the Dragon slayers chest the crowd begins to throw"<<endl;
cout<<"flowers as you wipe your blade cleen and exit the arena. As you're walking out"<<endl;
cout<<"of the colosseum, the same stockey man walks up to you and says 'Oh so ya` won"<<endl;
cout<<"eh, well heres your reward!'"<<endl; 
if(sex=='f'){ 
cout<<"'Here's �"<<fg_yellow<<"15,000"<<fg_cyan<<"'"<<endl; 
gold+=15000; 
}  
else{ 
cout<<"'Here's �"<<fg_yellow<<"10,000"<<fg_cyan<<"'"<<endl; 
gold+=10000;
}  
cout<<"You accept the money and leave the colosseum."<<endl; 
}}}}}  
//----------------------------------------QUEST6---------------------------------------------------| 
//=================================================================================================|
void quest6(string &name, int &pnum, int &max, int &totalexp, int &amax, int &a, int &gold,
			int &level, int &gain, int &m, int &mcap, int &num, int fire, int ice,
			int bolt, int cure, int drain, int rasp, int death, int quake, int confusion,
			int windslash, int sex, string gostore, int &eveea, int &emax, int &eamax,
			int &elevel, int &etotalexp, int &egain) 
{ 
if((gostore[0]=='y')||(gostore[0]=='Y'))
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
MBattle("Uncle Sam's father", max, a, amax, 16, 200, pnum, 20, level, totalexp, gold, 200, 1, gain, m, mcap, num,  fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
}  
else if((gostore[0]=='n')||(gostore[0]=='N'))
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
MBattle("Uncle Sam's father", max, a, amax, 16, 200, pnum, 20, level, totalexp, gold, 200, 1, gain, m, mcap, num,  fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
}  
if(a>0)
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
MBattle2("Uncle Sam", emax, eveea, eamax, 26, 150, pnum, 50, elevel, etotalexp, gold, 500, 10, egain, name); 
if(eveea>0){ 
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
MBattle("Flying Monster", max, a, amax, 150, 5000, pnum, 1000, level, totalexp, gold, 1250, 10, gain, m, mcap, num,  fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
if(a>0){ 
cout<<"You fall to the ground tired and Evee approaches you, suddenly a large wolf pack";
cout<<"bounds out of the forest. Evee begins to run towards them but stops half way."<<endl;
cout<<"With one final glance as if to say goodbye Evee returns to his family. You dust"<<endl;
cout<<"yourself off, head back to the inn to get Jenny, and return home."<<endl; 
}  
}  
else{ 
MBattle("Uncle Sam", max, a, amax, 26, 150, pnum, 50, level, totalexp, gold, 500, 10, gain, m, mcap, num,  fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
if(a>0){ 
cout<<"You run to Evee and try to help him out, however you are too late to save him."<<endl;
cout<<"You lost Evee, and you get really angry.  Saddened you slowly make your way"<<endl;
cout<<"home and have a funeral befitting a warrior as great as the wolf cub Evee."<<endl; 
}  
}  
}  
}  
//------------------------QUEST7-------------------------------------------------------------| 
//===========================================================================================|
void quest7(string &name, int &pnum, int &max, int &totalexp, int &amax, int &a, int &gold,
			int &level, int &gain, int &m, int &mcap, int &num, int fire, int ice, int bolt,
			int cure, int drain, int rasp, int death, int quake, int confusion, int windslash,
			int sex){ 
int sword, pbag, ebag, mkeeper; 
char choice; 
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
sword=max; 
max=15; 
pbag=pnum; 
ebag=num; 
mkeeper=m; 
m=5; 
pnum=0; 
num=0; 
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch();
KagosBattle("Kagos", max, a, amax, 100, 30000, 1000, pnum, 30000, level, totalexp, gold, 30000, 30000, gain, m, mcap, num, 20, 10, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash, name); 
num=ebag; 
pnum=pbag; 
max=sword; 
m=mkeeper;
cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
_getch(); 
if(a>0){ 
cout<<"Kagos writhes and releases a single scream and fades like darkness in the morning light.  Suddenly you here the thundering footfalls of a giant.  Towering above all he looks down at you and booms 'Heh heh heh Kagos.  You wont fool me this time!'  Upon making this statment he promtly grinds you into the sod."<<endl; 
//Dead(); 
cout<<"The next thing you see is a soft light and feel a sense of peace around you.  Suddenly a clawed hand grabs at you and a voice, like the cries of a thousand fallen innocents, screams at you 'Now Great "<<name<<" you will feel the pain and sorrow of millions.  You will know hunger, disease, and fear.  You will have your eyes pulled from your sockets and will be fed them on a platter of flesh and bone.  And then "<<name<<" my mighty warrior you will serve our Dark Lord.'  And with that you are pulled down into a darkness that has never been touched by light.  Into a darkness where there waits He who was in glory, He who was once beloved, and He who feasts upon the sorrow of the world."<<endl; 
}  
else if(a<=0){ 
a=amax; 
cout<<"As you feel your life ebbing away you hear a far off chanting.  Suddenly you find yourself on an island among a sea of fire.  The sky is dark and full of thunder and lightning.  'Welcome.' says a cool voice devoid of all emotion.  Looking up you see a man in a blood red cloak.  He is frail but a power radiates from him that you can not explain.  'You should be honored "<<name<<"' says a voice that mimics the sound of screaming children.  You turn around and stare face to face with the true form of Kagos.  It is a massive beast with two twisted horns atop its gray slimy head.  It has horrible wounds and the smell of gore that comes from its huge mouth is almost overwhelming.  You draw your sword and prepare to meet the foul beast.  the cloaked man laughs and says 'Don`t even try it!  Kagos will kill you and if doesn't you'll never get of the Island of Tacak!'  At this Kagos realises a horrible laugh, looking around you see a small tomb with doors of bone and flesh that you could get inside of and seek an escape, you could attempt to kill Kagos or the cloaked man, or you could stall them till something good comes along."<<endl; 
cout<<"Do you"<<endl; 
cout<<"(T)alk for awhile"<<endl; 
cout<<"(F)ight Kagos"<<endl; 
cout<<"(A)ttack the cloaked man"<<endl; 
cout<<"(R)un for the Tomb"<<endl; 
cout<<"Well?"; 
cin>>choice; 
if((choice=='t')||(choice=='T')){ 
cout<<"You choose talk for a while till something promising comes along.  How ever Kagos has other plans and promptly bites you in half."<<endl; 
//Dead(); 
}  
else if((choice=='f')||(choice=='F')){ 
cout<<"You draw your sword and attack Kagos.  He is more than ready to meet the challenge and this time he isn't a little girl."<<endl; 
KagosBattle("Kagos", max, a, amax, 1001, 30000, 1000, pnum, 30000, level, totalexp, gold, 30000, 30000, gain, m, mcap, num, 20, 10, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash, name); 
if(a>0){ 
cout<<"As your sword cuts through Kagos breast, you feel the familiar warm gush of blood on your hands.  You see the cloaked man reach for your arm and you feel the burning of a thousand hells.  'No,' you correct yourself as you stare into his eyes, 'not a thousand hells.  Just the Master of one hell.'  He chuckles a chilling laugh and...  You yourself in bed alone and sweating from a heat you can`t identify suddenly there is a knock at the door."<<endl; 
cout<<"A wizard knocks on your door and you open the door and let him in.  The wizard looks distressed and has sweat beaded all down his face.   'You have to help me!' says the wizard panting and out of breath.   'Some vile demon stole my jewel of magic recharge. I can`t cast a single spell until it`s returned!' he wailed. 'PLEEEAASSEE HHEEELLLP MEEE, PLEEEAAASSSE!'With that the poor old wizard ran off bawling.	With a sense of duty you pick up your sword and set out on a magical journey."<<endl; 
cout<<"'Wait a minute!' you say 'Haven't I done this before!'  And so shrugging you set out on your quest to get back the wizard`s stone."<<endl;  
}  
}  
else if((choice=='a')||(choice=='A')){ 
cout<<"You whirl around to attack the cloaked man.  Almost as if he has read your mind he is prepaired and raises his hand reaches out to touch your face.  You duck with all your speed and hear Kagos scream as his head is melted into a oozing yellow mass.  Drawing your sword you spin around just as the cloaked man vanishes.  Screaming with what vocal cords he has left Kagos blindly launches himself at you with surprising accuracy for a headless fiend."<<endl; 
KagosBattle("Kagos", max, a, amax, 501, 20000, 1000, pnum, 30000, level, totalexp, gold, 30000, 30000, gain, m, mcap, num, 20, 10, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash, name); 
}  
else if((choice=='r')||(choice=='R')){ 
cout<<"You choose to run into the tomb and attempt to find an escape.  How ever Kagos has other plans and promptly bites you in half."<<endl; 
//Dead(); 
}  
}  
}  
//-----------------QUEST8--------------------------------------------------------------------------| 
//=================================================================================================|
void quest8(string name, int &pnum, int &max, int &totalexp, int &amax, int &a, int &gold, int &level, int &gain, int &m, int &mcap, int &num, int fire, int ice, int bolt, int cure, int drain, int rasp, int death, int quake, int confusion, int windslash) 
{ 
char cont; 
//opening 
cout<<"You laze around the house until about noon, when you decide that you are kind of hungry."<<endl; 
cout<<"you figure that you can either fix something to eat at home, or you can go out to the tavern and get a good meal. What do you want to do, go to the (T)avern, or eat at (H)ome?"; 
cin>>cont; 
		//tavern 
		if((cont=='T')||(cont=='t')){ 
		cout<<"You stand up and walk into your room where your money sack is, you pick it up and shake it to make sure that there is something in it.  The pouch feels light but you are sure that you have enough to buy something to eat."<<endl; 
	 	cout<<"As you are walking down the road, you see the old warlock. You can change (D)irection and go around the old man, or you can (C)ontinue on your current course.What do you do?"; 
	 	cin>>cont; 
	 		//around warlock 
	 		if((cont=='D')||(cont=='d')){	 
	 		cout<<"You decide to change course and take the longer way through a dark ally.  Halfway through you feel a sharp prod on your lower back. 'Gimmie all yer money!' Declares the mugger.  You turn around and back hand him where you thought his head should be, but you strike the solid steel of a breatsplate.  You look up to find that the burly man is over seven feet tall."<<endl; 
	 		MBattle("Armoured Mugger", max, a, amax, 86, 1500, pnum, 1000, level, totalexp, gold, 300, 3, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
	 			if(a>0){ 
	 			cout<<"The mugger crumples in pain and you kick him out of your way and continue through the ally."; 
	 			}  
	 			}  
	 		//warlock 
	 		else if((cont=='C') || (cont=='c')){ 
	 		cout<<"You decide you will brave it and so continue on your way.  The Warlock smiles at you. 'Hello boy.' he says in a gruff voice. 'Off to lunch eh? Well here have an ether.' He hands you an ether on the house."<<endl; 
	 		num+=1; 
	 		}  
	 	 
	 	if(a>0){ 
	 	cout<<"When you finally reach the tavern, you walk up to the Bar. Will you order anything(y/n)? "; 
	 	cin>>cont;  
	 		if(cont=='y'){ 
	 		cout<<"(A) Ale             �100"<<endl; 
	 		cout<<"(B) Sandwich        �200"<<endl;  
	 		cout<<"(C) Hot Meal        �500"<<endl; 
	 		cout<<"(D) Dinner plate    �700"<<endl; 
	 		cout<<"(E) Hotplate&Wine   �900"<<endl; 
	 		cout<<"(F) Buffet Table   �1500"<<endl; 
	 		cout<<"(G) Never Mind"<<endl; 
	 		cout<<"wich one do you order?"; 
	 		cin>>cont; 
	 			if(((cont=='A')&&(gold>=100)) || ((cont=='a')&&(gold>=100))){ 
	 			cout<<"You slam the ale. Hp restored"<<endl; 
	 			a=amax; 
	 			}  
	 			else if(((cont=='B')&&(gold>=200)) || ((cont=='b')&&(gold>=200))){ 
	 			cout<<"You devour the sandwich. Mp restored"<<endl; 
	 			m=mcap; 
	 			}  
	 			else if(((cont=='C')&&(gold>=500))||((cont=='c')&&(gold>=500))){ 
	 			cout<<"You savor the hot meal and enjoy every bite. Hp & Mp restored"<<endl; 
	 			m=mcap; 
	 			a=amax; 
	 			}  
	 			else if(((cont=='D')&&(gold>=700)) || ((cont=='d')&&(gold>=700))){ 
	 			cout<<"You eat your dinner politly. Hp max +10"<<endl; 
	 			amax+=10; 
	 			a=amax; 
	 			}  
	 			else if(((cont=='E')&&(gold>=900))||((cont=='e')&&(gold>=900))){ 
	 			cout<<"You eat your food and drink your wine. Mp max +10."<<endl; 
	 			mcap+=10; 
	 			m=mcap; 
	 			}  
	 			else if(((cont=='F')&&(gold>=1500))||((cont=='f')&&(gold>=1500))){ 
	 			cout<<"You spend three hours stuffing your face at the buffet table. Hp&Mp max +10."<<endl; 
	 			mcap+=10; 
	 			amax+=10; 
	 			a=amax; 
	 			m=mcap; 
	 			}  
	 			else if((cont=='G') || (cont=='g')){ 
	 			cout<<"You decide not to eat anything"<<endl; 
	 			}  
	 			else{ 
	 			cout<<"not enough �"<<endl; 
	 			}  
	 			} 	 		 
	 			cout<<"After you order and eat, you leave the tavern and begin to head home.  As you are at the door a giant Troll attacks you."<<endl; 
	 			MBattle("Troll", max, a, amax, 91, 2000, pnum, 1000, level, totalexp, gold, 300, 3, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
	 			if(a>0){ 
	 			cout<<"After dispatching the Troll you start to continue on your way, when a glint catches your eye. Thinking it maybe gold you bend down to pick it up. instead you discover an od crest (�)."<<endl; 
	 			cout<<"Who will you take it to?"<<endl; 
	 			}  
	 			 
	 		else{ 
	 		cout<<"You decide not buy anything."<<endl; 
	 		}  
	 		  
	 		 } }  
	 	else if((cont=='H')||(cont=='h')){ 
	 		//home 
	 		cout<<"You decide not to leave the house but rather to eat at home. You fix a sandwich and get a mug of water. You sit down on your bench and eat your sandwich but before you can get a taste of the water a troll bashes through your door, for no reason whatsoever except, to club you to death!"<<endl; 
	 			MBattle("Troll", max, a, amax, 75, 1000, pnum, 1000, level, totalexp, gold, 300, 3, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash);	 
	 			if (a>0){ 
	 			cout<<"After defeating the Troll you begin to clean up the mess. Yuk you say as you pick up the Troll's arm and throw it out the door. As you are dragging the body to the door he drops a this crest (�). who do you want to take it to?"<<endl; 
	 			} }  
	 	cout<<"Old (W)arlock or (M)arie? ";  
	 	cin>>cont; 
	 	if((cont=='W')||(cont=='w')){ 
	 				//warlock 
	 				cout<<"You immediatly take the crest to the old store owner and show to him.Well. If I know anything I'd say that this is the crest of the dark one Kagos. Where did you find it?"<<endl; 
					cout<<"A Troll attacked me and he was carrying it"<<endl; 
	 				cout<<"Hmmm? I'd say Youd better get o the bottom of this.  Your life may be at stake."<<endl; 
	 				} 			   
	 	else if((cont=='M')||(cont=='m')){ 
	 				//marie 
	 				cout<<"You take the crest to Marie and she gasps aloud. Where did you get that?!"<<endl; 
	 				cout<<"You tell her how you were attacked by a Troll and found it on him. You must get to the bottom of this your life IS at stake!"<<endl; 
	 				}  
	 			if(a>0){ 
	 			cout<<fg_white<<"\n\nPress Any Key To Continue...\n\n"<<fg_cyan<<endl; 
				_getch();
	 			cout<<"You figure its time to start your quest. you run out towards the Dark Ones Tower."<<endl; 
	 			cout<<"When you finally reach the tower after an uneventul trip you find an extremely large gaurd patroling the tower's gate as you aproach he draws his sword."<<endl; 
				cout<<"What do you do (A)ttack the gaurd or (F)lash (�) coin at him? "; 
	 			cin>>cont; 
	 				if((cont=='A')||(cont=='a')) 
	 				//Attack 
	 				cout<<"you jump in swinging your sword!"<<endl; 
	 				MBattle("Bulky Gaurd", max, a, amax, 75, 1000, pnum, 1000, level, totalexp, gold, 300, 3, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
	 			 	}  
	 			 	else if((cont=='F')||(cont=='f')){ 
	 			 	cout<<"You flash the gaurd the crest and he waves you in."<<endl; 
	 				}  
	 			if(a>0){ 
	 			cout<<"You enter the tower and run straight towards the top when you blast through the door an old man spins around and hurls a large ball of flame at you. You dodge and are pitched in a new type of battle!"<<endl; 
	 			 KagosBattle("Azurith", max, a, amax, 101, 6000, 20000, pnum, 6000, level, totalexp, gold, 40000, 200, gain, m, mcap, num, 200, 200, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash, name); 
	 						 
	 			if(a>0){ 
	 				cout<<"After a grueling you emerge from the tower victoriously. as you stumble away you are shocked to see the wizards apprentice. You will die! h exclaims."<<endl; 
	 				KagosBattle("Ricker", max, a, amax, 51, 3000, 10000, pnum, 1000, level, totalexp, gold, 1000, 10, gain, m, mcap, num, 10, 20, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash, name); 
	 				 	if(a>0){ 
	 				 	cout<<"After another grueling battle with another wizard you straggle home, Mission accomplished, for some much needed rest."<<endl; 
	 				 	}  
	 				 	}  
	 				 	}  
	 				 	}  
//--------------------------------------------SHOP-------------------------------------------------| 
//=================================================================================================|
void Store(int &a, int &amax, int &max, int &gold, int &pnum, char sex, int &m, int &mcap, int &num, int &fire, int &ice, int &bolt, int &cure, int &drain, int &rasp, int &death, int &quake, int &confusion, int &windslash)
{ 
int randomstore; 
randomize(); 
string choice, yes; 
randomstore=lvprandom(4); 
if(randomstore==2){ 
cout<<"You walk in the store and your breath catches in your throat"<<endl; 
if(sex=='m'){ 
cout<<"as you stare not at the lovely smile of Marie, the Warlock`s daughter, but at"<<endl;
cout<<"the endless wrinkles which cover the old magus` head.\n"<<endl; 
}  
else if(sex=='f'){ 
cout<<"as you stare not at your good friend Marie, the Warlock`s daughter, but at the"<<endl;
cout<<"endless wrinkles which cover the old magus` head.\n"<<endl; 
}  
cout<<"You try to back up but his hands are too fast and you feel terrifying pain as"<<endl;
cout<<"your body is magically ripped apart and the old magus searches for anything"<<endl;
cout<<"suspicious ("<<fg_white<<"-10hp"<<fg_cyan<<")."<<endl; 
a-=10; 
}  
else{ 
cout<<"You walk into the store"<<endl; 
if(sex=='m'){ 
cout<<"and are fascinated by the breath taking beauty of Marie, the Warlock`s daughter.\n"<<endl; 
}  
else{ 
cout<<"and smile at your close friend Marie, the Warlock`s daughter.\n"<<endl; 
}  
}  
if(a>0){ 
char no; 
do{ 
cout<<"("<<fg_white<<"A"<<fg_cyan<<")   Potion                �"<<fg_yellow<<"50"<<fg_cyan<<endl; 
cout<<"("<<fg_white<<"B"<<fg_cyan<<")   Blade Sharpening      �"<<fg_yellow<<"1000"<<fg_cyan<<endl; 
cout<<"("<<fg_white<<"C"<<fg_cyan<<")   Exercise              �"<<fg_yellow<<"5000"<<fg_cyan<<endl; 
cout<<"("<<fg_white<<"D"<<fg_cyan<<")   Ether                 �"<<fg_yellow<<"100"<<fg_cyan<<endl; 
cout<<"("<<fg_white<<"E"<<fg_cyan<<")   Mana Meditation       �"<<fg_yellow<<"5000"<<fg_cyan<<endl; 
cout<<"("<<fg_white<<"F"<<fg_cyan<<")   Spells                튞/A\n"<<endl; 
cout<<"e("<<fg_white<<"X"<<fg_cyan<<")it the store"<<endl;
cout<<fg_blue<<"Well, what would you like?("<<fg_yellow<<gold<<fg_blue<<")"<<fg_white<<endl; 
cin>>choice;
cout<<fg_cyan; 
if((choice[0]=='a')||(choice[0]=='A')){ 
if(gold>=50){ 
cout<<"Potions give back 10 hit points and costs �"<<fg_yellow<<"50"<<fg_cyan<<".  You have �"<<fg_yellow<<gold<<fg_cyan<<" and currently have "<<fg_white<<pnum<<fg_cyan<<" potions."<<endl; 
cout<<"Do you buy(y/n)? "; 
cin>>yes; 
if((yes[0]=='y')||(yes[0]=='Y')){ 
gold-=50; 
pnum++; 
}  
}  
else{ 
cout<<"You don't have enough money."<<endl; 
}  
}  
else if((choice[0]=='b')||(choice[0]=='B')){ 
if(gold>=1000){ 
cout<<"Blade Sharpening increases your attack by 15 points and costs �1000."<<endl;
cout<<"You have �"<<fg_yellow<<gold<<fg_cyan<<" and do "<<fg_white<<max<<fg_cyan<<" damage."<<endl; 
cout<<"Do you buy(y/n)? "; 
cin>>yes; 
if((yes[0]=='y')||(yes[0]=='Y')){ 
gold-=1000; 
max+=15; 
}  
}  
else{ 
cout<<"You don't have enough money."<<endl; 
}  
}  
else if((choice[0]=='c')||(choice[0]=='C')){ 
if(gold>=5000){ 
cout<<"Exercise toughens your body and raises your max hit points by 15.  It cost �5000.  You have �"<<fg_yellow<<gold<<fg_cyan<<" and your max HP is "<<amax<<endl; 
cout<<"Do you buy(y/n)? "; 
cin>>yes; 
if((yes[0]=='y')||(yes[0]=='Y')){ 
gold-=5000; 
amax+=15; 
a=amax; 
}  
}  
else{ 
cout<<"You don't have enough money."<<endl; 
}  
}  
else if((choice[0]=='d')||(choice[0]=='D')){ 
if(gold>=100){ 
cout<<"By infusing a small potion with high concentrations of mana we are capable of\ncreating a potion that can restore 10 Magic Points. It costs �"<<fg_yellow<<"100"<<fg_cyan<<". You have �"<<fg_yellow<<gold<<fg_cyan<<"and "<<fg_white<<num<<fg_cyan<<" ethers."<<endl; 
cout<<"Do you buy(y/n)? "; 
cin>>yes; 
if((yes[0]=='y')||(yes[0]=='Y')){ 
gold-=100; 
num++; 
}  
}  
else{ 
cout<<"You do not have enough money."<<endl; 
}  
}  
else if((choice[0]=='e')||(choice[0]=='E')){ 
if(gold>=5000){ 
cout<<"Though a process of submerging yourself in a tank full of Mana for extended periods of time you can increase your ability to control the arcane forces."<<endl; 
cout<<"Do you buy(y/n)? "; 
cin>>yes; 
if((yes[0]=='y')||(yes[0]=='Y')){ 
gold-=5000; 
mcap+=15; 
m=mcap; 
}  
}  
else{ 
cout<<"You do not have enough money."<<endl; 
}  
}  
else if((choice[0]=='f')||(choice[0]=='F')) { 
cout<<"We have a wide variety of spells here."<<endl; 
cout<<"("<<fg_white<<"A"<<fg_cyan<<")   Quake     "<<quake<<"/10         �2500"<<endl; 
cout<<"("<<fg_white<<"B"<<fg_cyan<<")   Fire      "<<fire<<"/10          �3500"<<endl; 
cout<<"("<<fg_white<<"C"<<fg_cyan<<")   Bolt      "<<bolt<<"/10          �4500"<<endl; 
cout<<"("<<fg_white<<"D"<<fg_cyan<<")   Ice       "<<ice<<"/10           �5500"<<endl; 
cout<<"("<<fg_white<<"E"<<fg_cyan<<")   Cure      "<<cure<<"/30          �2000"<<endl; 
cout<<"("<<fg_white<<"F"<<fg_cyan<<")   Drain     "<<drain<<"/10         �4000"<<endl; 
cout<<"("<<fg_white<<"G"<<fg_cyan<<")   Rasp      "<<rasp<<"/10          �5000"<<endl; 
cout<<"("<<fg_white<<"H"<<fg_cyan<<")   Windslash "<<windslash<<"/15         �6500"<<endl; 
cout<<"("<<fg_white<<"I"<<fg_cyan<<")   Confusion "<<confusion<<"/30        �10000"<<endl; 
cout<<"("<<fg_white<<"J"<<fg_cyan<<")   Death    "<<death<<"/100        �20000"<<endl; 
cout<<"("<<fg_white<<"R"<<fg_cyan<<")eturn to the menu"<<endl;
cout<<fg_blue<<"Well what do you want? "<<fg_white; 
cin>>choice;
cout<<fg_cyan; 
if((choice[0]=='a')||(choice[0]=='A')){ 
if((gold>=2500)&&(quake<10)){ 
	cout<<"Quake is a weak physical attack."<<endl;
cout<<"It uses Mana to summon an earth quake and damage your foe."<<endl; 
cout<<"Do you buy(y/n)? "; 
cin>>yes; 
if((yes[0]=='y')||(yes[0]=='Y')){ 
gold-=2500; 
quake++; 
}  
}  
else{ 
cout<<"You don't have enough money."<<endl; 
}  
}  
else if((choice[0]=='b')||(choice[0]=='B')){ 
if(gold>=3500){ 
cout<<"Mana fire is powerful enough to burn on top of a gravelly road."<<endl; 
cout<<"Do you buy(y/n)? "; 
cin>>yes; 
if(((yes[0]=='y')||(yes[0]=='Y'))&&(fire<10)){ 
gold-=3500; 
fire++; 
}  
}  
else{ 
cout<<"You don't have enough money."<<endl; 
}  
}  
else if((choice[0]=='c')||(choice[0]=='C')){ 
if(gold>=4500){ 
cout<<"Mana bolt is a powerful spell which discharges massive amounts of energy into"<<endl;
cout<<"the directed object."<<endl; 
cout<<"Do you buy(y/n)? "; 
cin>>yes; 
if(((yes[0]=='y')||(yes[0]=='Y'))&&(bolt<10)){ 
gold-=4500; 
bolt++; 
}  
}  
else{ 
cout<<"You don't have enough money."<<endl; 
}  
}  
else if((choice[0]=='d')||(choice[0]=='D')){ 
if(gold>=5500){ 
cout<<"Mana in ice form is the coldest substance known to man or beast."<<endl;
cout<<"It is unmeltable except by mana fire."<<endl; 
cout<<"Do you buy(y/n)? "; 
cin>>yes; 
if(((yes[0]=='y')||(yes[0]=='Y'))&&(ice<10)){ 
gold-=5500; 
ice++; 
}  
}  
else{ 
cout<<"You do not have enough money."<<endl; 
}  
}  
else if((choice[0]=='e')||(choice[0]=='E')){ 
if(gold>=2000){ 
cout<<"Mana can be used to replace damaged parts by changing it to mimic the injured"<<endl;
cout<<"beings life blood."<<endl; 
cout<<"Do you buy(y/n)? "; 
cin>>yes; 
if(((yes[0]=='y')||(yes[0]=='Y'))&&(cure<30)){ 
gold-=2000; 
cure++; 
}  
}  
else{ 
cout<<"You do not have enough money."<<endl; 
}  
}  
else if((choice[0]=='f')||(choice[0]=='F')){ 
if(gold>=2000){ 
cout<<"Not only can Mana be used to mimic ones life blood but it can be used to remove"<<endl;
cout<<"ones life blood and pass it to the caster of this spell."<<endl; 
cout<<"Do you buy(y/n)? "; 
cin>>yes; 
if(((yes[0]=='y')||(yes[0]=='Y'))&&(drain<10)){ 
gold-=4000; 
drain++; 
}  
}  
else{ 
cout<<"You do not have enough money."<<endl; 
}  
}  
else if((choice[0]=='g')||(choice[0]=='G')){ 
if(gold>=5000){ 
cout<<"Like the drain spell this one also takes the life blood out of a foe, however"<<endl;
cout<<"it also converts the life blood to Mana."<<endl; 
cout<<"Do you buy(y/n)? "; 
cin>>yes; 
if(((yes[0]=='y')||(yes[0]=='Y'))&&(rasp<10)){ 
gold-=5000; 
rasp++; 
}  
}  
else{ 
cout<<"You do not have enough money."<<endl; 
}  
}  
else if((choice[0]=='h')||(choice[0]=='H')){ 
if(gold>=6500){ 
cout<<"This is the most powerful attack Mana is capable of doing."<<endl; 
cout<<"Do you buy(y/n)? "; 
cin>>yes; 
if(((yes[0]=='y')||(yes[0]=='Y'))&&(windslash<15)){ 
gold-=6500; 
windslash++; 
}  
}  
else{ 
cout<<"You do not have enough money."<<endl; 
}  
}  
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
}  
cout<<"Anything else? "; 
cin>>no; 
} while((no=='y')||(no=='Y')); 
cout<<"Thank's for coming!"<<endl;
}  
}  
//-------------------------------------------------------------| 
//-------------------------------------------------------------| 
//-----------------FOR TESTING ONLY----------------------------| 
void TEMPORARY(int &randomquest){ 
int randomq; 
cout<<"Which Quest? "; 
cin>>randomq; 
randomquest=randomq; 
}  
//-----------------FOR TESTING ONLY----------------------------| 
//-------------------------------------------------------------| 
//-------------------------------------------------------------| 
//-----------------------------------------------INT MAIN----------------------------------------|
int main() 
{ 
//VARIABLES---| 
string name, gender, cont, gostore; 
char sex, answer, x; 
int max=0, amax=0, pnum=0, totalexp=0, a=0, egain=100, gain=100, level=1, q1= 0, randomquest, eveea=101, eamax=101, emax=20, elevel=1, etotalexp=0, gold=100, points, temp, m=0, mcap=0, num=0, fire=0, ice=0, bolt=0, cure=0, drain=0, rasp=0, death=0, quake=0, confusion=0, windslash=0; 
//FMOD INITIALIZATION=========================================|
if (FSOUND_GetVersion() < FMOD_VERSION)
    {
        printf("Error : You are using the wrong DLL version!  You should be using FMOD %.02f\n", FMOD_VERSION);
        exit(1);
    }
if (!FSOUND_Init(44100, 32, 0))
	{
		cout<<fg_red<<FSOUND_GetError();
		exit(1);
	}
FMUSIC_MODULE *Battle = 0, *Quest = 0, *Opening = 0, *KBattle = 0, *pop = 0;
Battle = FMUSIC_LoadSong("music/battle.mid");
Quest = FMUSIC_LoadSong("music/quest.mid");
Opening = FMUSIC_LoadSong("music/opener.mid");
KBattle = FMUSIC_LoadSong("music/kbattle.mid");
pop = FMUSIC_LoadSong("music/pop.mid");

//--RANDOMIZING----------| 
    randomize(); 
	randomquest=0;	 
		 
//-------------------THE-BEGINING------------------------------------------------------------------|
//=================================================================================================|
//_________________________________________________________________________________________________|	
	//arch();
	FMUSIC_PlaySong(Opening);
	cout<<fg_cyan;
	cout<<"                           Greetings Adventurer!"<<endl;
	cout<<"\n  I will be your guide and narrator through this wonderful game. I am your"<<endl;
	cout<<"eyes in this world and so will give you the best description I can.\n"<<endl;
	cout<<"Please keep in mind, not answering questions correctly can lead to"<<endl;
	cout<<"unpredictable results. Please answer all questions carefully."<<endl;
	cout<<fg_blue<<"\nSo what is your name then? "<<fg_white; 
	cin>>name;
	cout<<fg_cyan<<endl;
//-------------Name-Codes------------------------|
if(name=="Harold"){ 
cout<<"Oh!  Harold it's great to see you again.  Just since your here I'll give you"<<endl;
cout<<"200 extra points!\n"<<endl; 
}  
else if(name=="Sang"){ 
cout<<"Oh!  It's you Sang, here I'll give you 5 potions and 100 extra points!\n"<<endl; 
pnum+=5; 
num+=2; 
}  
else if(name=="Aaron"){ 
cout<<"Oh!  It's you Aaron, here I'll give you level ten ice!\n"<<endl; 
ice += 10; 
}  
else if(name=="John"){ 
cout<<"Oh!  It's you John.  You Jackass you still owe me �200 for losing them in"<<endl;
cout<<"the stupid soda machines!\n"<<endl; 
cout<<"JOHN: \"Can I borrow �100.\""<<endl; 
cout<<"What, oh sure.... Hey wait a minute come back here you jackass!\n"<<endl; 
cout<<"John runs away with the gold!\n"<<endl; 
gold+=100; 
name="Jackass"; 
}  
else if(name=="Olga"){ 
cout<<"MY GOD! Olga you have got to be the manliest woman I have ever seen!\n"<<endl; 
}  
else if(name=="Yeroshek"){ 
cout<<"Uh Oh!  It's the boss!  Better put on a good show! Here take 500 ability points"<<endl;
cout<<"and these spells just don't give me an F!\n"<<endl; 
ice++; 
death++; 
windslash++; 
cure++; 
bolt++; 
fire++; 
drain++; 
rasp++; 
confusion++; 
}  
//--------------End-Name-Codes-----------------------------------------------------|	
	cout<<fg_blue<<"Ok "<<name<<", Are you male or female? "<<fg_white; 
	cin>>gender;
	sex = gender[0];
	cout<<clr<<fg_cyan;
		if((sex=='m')||(sex=='M')){ 
		cout<<"Welcome young Lad to your Grand Adventure!\n\n"<<endl; 
		sex='m';
		}  
		else if((sex=='f')||(sex=='F')){ 
		cout<<"Welcome young Lass to your Grand Adventure!\n\n"<<endl; 
		sex='f';
		} 
		else{
			sex='m';
			cout<<"Welcome young Lad to your Grand Adventure!\n\n"<<endl; 
		}
		 
		do{ 
		if(name=="Harold"){ 
			points=350; 
		}  
		else if(name=="Yeroshek"){ 
			points=500; 
		}  
		else if(name=="Sang"){
			points=250;
		}
		else{ 
			points=150; 
			}  
			amax=0; 
			if(name=="Olga"){
				max=50;
			}
			else{
			max=0;
			}
			pnum=0; 
			if(name=="Yeroshek"){ 
			quake=1; 
			}  
			else{ 
			quake=0; 
			}  
			num=0; 
			mcap=0; 
			cout<<"There are 3 Primary stats. They are:"<<fg_white<<endl;
			cout<<"\nLife\nAttack\nMagic\n"<<endl<<fg_cyan;
			cout<<"You may convert any extra points to ethers, and any points left over will be \nautomatically converted to potions\n\n"<<endl;
			cout<<"Now you have "<<points<<" points."<<endl; 
			cout<<fg_blue<<"How many points do you want to add to your life? "<<fg_white<<endl; 
			cin>>temp;
			cout<<fg_cyan;
				if(temp>points){ 
					cout<<fg_red<<"You don't have that many points!"<<fg_cyan<<endl; 
					cout<<fg_white<<"\n\nPress a key to start over"<<fg_cyan<<endl;
					_getch();
					cout<<clr;
					answer='n'; 
				}  
				else if(temp==points){ 
					cout<<fg_red<<"You must save some points for your attack!"<<fg_cyan<<endl; 
					cout<<fg_white<<"\n\nPress a key to start over"<<fg_cyan<<endl;
					_getch();
					cout<<clr;
					answer='n'; 
				}  
				else if(temp<=0){
					cout<<fg_red<<"You must have at least one point in your life"<<fg_cyan<<endl;
					cout<<fg_white<<"\n\nPress a key to start over"<<fg_cyan<<endl;
					_getch();
					cout<<clr;
					answer='n';
				}
				else{ 
				amax+=temp; 
				a=amax; 
				points-=temp; 
				cout<<"Now you have "<<points<<" points."<<endl; 
				cout<<fg_blue<<"How many points do you want to add to your attack? "<<fg_white<<endl; 
				cin>>temp;
				cout<<fg_cyan;
					if(temp>points){ 
					cout<<fg_red<<"You don't have that many points!"<<fg_cyan<<endl; 
					cout<<fg_white<<"\n\nPress a key to start over"<<fg_cyan<<endl;
					_getch();
					cout<<clr;
					answer='n'; 
					} 
					else if(temp<=0){
						cout<<fg_red<<"You must have at least one point in attack"<<fg_cyan<<endl;
						cout<<fg_white<<"\n\nPress a key to start over"<<fg_cyan<<endl;
						_getch();
						cout<<clr;
						answer='n';
					}
					else{ 
						max+=temp;
						points-=temp;
					    cout<<"Now you have "<<points<<" points."<<endl; 
						cout<<fg_blue<<"How many points do you want to add to your magic points? "<<fg_white<<endl; 
						cin>>temp;
						cout<<fg_cyan;
							if(temp>points){ 
							cout<<fg_red<<"You don't have that many points!"<<fg_cyan<<endl; 
							cout<<fg_white<<"\n\nPress a key to start over"<<fg_cyan<<endl;
							_getch();
							cout<<clr;
							answer='n'; 
							}  
							else if(temp<0){
								cout<<fg_red<<"You can't add negative points!"<<fg_cyan<<endl; 
								cout<<fg_white<<"\n\nPress a key to start over"<<fg_cyan<<endl;
								_getch();
								cout<<clr;	
								answer='n';
							}
							else{ 
							mcap+=temp; 
							m=mcap; 
							points-=temp; 
							cout<<"Now you have "<<points<<" points."<<endl; 
							cout<<fg_blue<<"How many points do you want to convert to ethers (2 points per ether)? "<<fg_white<<endl; 
							cin>>temp; 
							cout<<fg_cyan;
							int halfp; 
							halfp=points/2; 
								if(temp>halfp){ 
								cout<<fg_red<<"You don't have that many points!"<<fg_cyan<<endl; 
								cout<<fg_white<<"\n\nPress a key to start over"<<fg_cyan<<endl;
								_getch();
								cout<<clr;
								answer='n'; 
								}
								else if(temp<0){
								cout<<fg_red<<"You can't add negative points!"<<fg_cyan<<endl; 
								cout<<fg_white<<"\n\nPress a key to start over"<<fg_cyan<<endl;
								_getch();
								cout<<clr;
								answer='n';
								}
								else{ 
								num+=temp; 
								points-=temp*2; 
								pnum+=points; 

						cout<<fg_white<<"\nLife:    "<<amax<<endl; 
						cout<<"Attack:  "<<max<<endl; 
						cout<<"Potions: "<<pnum<<endl; 
						cout<<"Magic:   "<<mcap<<endl; 
						cout<<"Ethers:  "<<num<<endl; 
						cout<<"You have been given Level 1 quake."<<endl; 
						quake++; 
						cout<<endl; 
						cout<<fg_blue<<"Are these stats OK? "<<fg_white; 
						cin>>answer;
						cout<<fg_cyan;
						} 	 
					}  
				}  
			//	}  
		}  
		} while(answer=='n'); 
		cout<<clr; 
		FMUSIC_StopSong(Opening);
		FMUSIC_PlaySong(Quest);
//========================================================================================================================================|
//----------------------------------------------------MAIN-GAME-LOOP----------------------------------------------------------------------|
//========================================================================================================================================|		
	do{ 
	randomquest++;
	cout<<fg_cyan;
	cout<<"\n\n\n   You wake up one morning with the sun. After yawning and stretching you look\naround your two room house. Your bed is messy and your down pillow is on the\nfloor. You look in your looking glass and you aren`t to suprised to discover\nthat you look rather scruffy. You put on your buckskin pants and tunic and go\ninto the kitchen to fix breakfast. When you open the cupboard you find two\npotions.\n"<<endl; 
	pnum+=2; 
	a=amax; 
	m=mcap;
	cout<<fg_white<<"\n\nPress Any Key To Continue\n\n"<<fg_cyan<<endl;
	_getch();
	cout<<"   You consider stopping by the local store.  The old Warlock who owns it is a\nreal grouch but usually it's his daughter who's minding the store and she\nusually lets you in without the intense pain of the search spell the Warlock\nuses to search for theives.\n"<<endl; 
	cout<<fg_blue<<"So will you go? "<<fg_white; 
	cin>>gostore; 
	cout<<fg_cyan;
	if((gostore[0]=='y')||(gostore[0]=='Y')){ 
	Store(a, amax, max, gold, pnum,  sex, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
	}  
	if(randomquest==1){ 
	     quest1(name, pnum, max, totalexp, amax, a, gold, level, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
		if(a>0){ 
		x='y'; 
		}  
		else{ 
		x='n'; 
		}  
	}  
	if(randomquest==2){ 
		 quest4(name, pnum, max, totalexp, amax, a, gold, level, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
			if(a>0){ 
		x='y'; 
		}  
		else{ 
		x='n'; 
		}  
	}  
	if(randomquest==3){ 
	     quest2(name, pnum, max, totalexp, amax, a, gold, level, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
		if(a>0){ 
		x='y'; 
		}  
		else{ 
		x='n'; 
		}  
	}  
	if(randomquest==4){ 
	     quest3(name, pnum, max, totalexp, amax, a, gold, level, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
		if(a>0){ 
		x='y'; 
		}  
		else{ 
		x='n'; 
		}  
	}  
	if(randomquest==5){ 
	     quest5(name, pnum, max, totalexp, amax, a, gold, level, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash, sex); 
	if(a>0){ 
		x='y'; 
		}  
		else{ 
		x='n'; 
		}  
	}  
	if(randomquest==6){ 
	    quest6(name, pnum, max, totalexp, amax, a, gold, level, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash, sex, gostore, eveea, emax, eamax, elevel, etotalexp, egain); 
		if(a>0){ 
		x='y'; 
		}  
		else{ 
		x='n'; 
		}  
	}  
	if(randomquest==7){ 
	     quest8(name, pnum, max, totalexp, amax, a, gold, level, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash); 
		if(a>0){ 
		x='y'; 
		}  
		else{ 
		x='n'; 
		}  
	}  
	if(randomquest==8){ 
	   quest7(name, pnum, max, totalexp, amax, a, gold, level, gain, m, mcap, num, fire, ice, bolt, cure, drain, rasp, death, quake, confusion, windslash, sex); 
		if(a>0){ 
		x='n'; 
		}  
		else{ 
		x='n'; 
		}  
		
	}  
	if(randomquest==9){
	//MBattle("Monster", 100, 200, 200, 100, 600, 15, 100, 1, 0, 100, 100, 5, 100, 100, 5, 5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);  
	}
	if(randomquest==10){
	//KagosBattle();
	}
	  } while(x=='y'); 
	  cout<<fg_yellow<<"           Thank You For Playing Grand Adventure!!!"<<fg_white<<endl;
	  cout<<"\n\n\nThe End!"<<endl; 
	  _getche();
	  FSOUND_Close();
	  return(0); 
	  }
	   

