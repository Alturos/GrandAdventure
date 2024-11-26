#include "Mastermind.hpp"
#include "Globals.h"
#include "Combat.h"
//using namespace JadedHoboConsole;
using std::cout;
using std::cin;
using std::endl;
using std::string;
using namespace Globals;




bool Mastermind::Start()
{
     
int guess=1; 
string answer; 
Combat fgt;
fgt.Randomize();
	int g1,g2,g3,cc=0,pc=0; 
	int p1,p2,p3;p1=1+fgt.Randoms(5),p2=1+fgt.Randoms(5),p3=1+fgt.Randoms(5); 
	cout<<fg_yellow<<"                       WELCOME TO MASTERMIND!"<<fg_blue<<endl; 
	cout<<endl; 
	cout<<"Would you like instructions? "<<fg_white;
	cin>>answer;
	cout<<fg_cyan<<"\n\n\n";
	if((answer[0]=='y')||(answer[0]=='Y'))
	{
		cout<<"There are five numbers and three pegs. The object of the game is to guess which\nnumber is on which peg.";
		cout<<fg_white<<"\n\n  Press Any Key To Continue...\n\n\n"<<fg_cyan;
		fflush(stdin);
		getchar();
	}
	cout<<endl; 

	do{ 
	
    	p1=1+fgt.Randoms(5),p2=1+fgt.Randoms(5),p3=1+fgt.Randoms(5); 
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
	    return false; 
        } 	 
	if((guess>=5)&&(guess<=9)){ 
		cout<<"'Damn that was hard!' you say. "<<endl; 
	    return true; 
		}  
	if(guess<=4){ 
		cout<<"'I Got it!' you declare."<<endl; 
	    return true; 
		}
	return false;
    } 	 
    	

