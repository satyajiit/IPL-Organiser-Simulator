#include "ManageClass.h"
#include "../ExternVariables/global.h"
#include "../ExternVariables/global_display_object.h"
#include "../SubModules/addPlayer.h"
#include "../SubModules/addTeam.h"
#include "../SubModules/addUmpires.h"
#include "../SubModules/AddCoach.h"
#include "../SubModules/addStadium.h"
#include "../SubModules/deletePlayer.h"

void ManageClass::Start(){

	system("cls");

	design.setTitle("MANAGE MENU");
	
	design.TopDesign("IPL CRICKET TOURNAMENT ORGANIZER - MANAGE MENU");
	
	
			
			cout << "\n\n";
			
			cout << "\tWhat to do?"<<endl;
			cout << "\n\t1 - Add Player"<<endl;	
			cout << "\t2 - Add Team"<<endl;	
			cout << "\t3 - Add Umpires"<<endl;	
			cout << "\t4 - Add Coaching Staff"<<endl;
			cout << "\t5 - Add Stadiums"<<endl;
			cout << "\t6 - Delete Player"<<endl;


	display.showExtraOptions();
	
	takeInputAndVerify();
	
	
}


void ManageClass::takeInputAndVerify(){
	
	switch(option){
			
			case -1:
				display.ExitApp();
				break;
			case 1:
				system("cls");
				addPlayer ob;
				ob.start();
				break;
			case 2:
				system("cls");
				addTeam ob2;
				ob2.start();
				break;
				
			case 3:
				system("cls");
				addUmpires ob3;
				ob3.start();
				break;
				break;	
			case 4:
				system("cls");
				AddCoach ob4;
				ob4.start();
				break;	
			
			case 5:
				addStadium ob5;
				ob5.start();
				break;	
			case 6:
				deletePlayer ob6;
				ob6.Start();
				break;		
					
			case 0:
				display.mainMenu();
				break;
			default:
				display.showInvalidOptionSelectedError();
				Start();
				
				
				
		}
	
}


