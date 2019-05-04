#include "AccessInfoClass.h"
#include "../ExternVariables/global.h"
#include "../ExternVariables/global_display_object.h"
#include "../SubModules/InformationAboutPlayers.h"
#include "../SubModules/InformationAboutTeams.h"
#include "../SubModules/ShowUmpires.h"
#include "../SubModules/CoachingStaffInformation.h"
#include "../SubModules/TeamOwnersList.h"
#include "../SubModules/IPLStadiums.h"
#include <iostream>

using namespace std;



void AccessInfoClass::Start(){

	
	design.TopDesign("IPL CRICKET TOURNAMENT ORGANIZER - INFO MENU");
	
	display.showOptionsForAccess();
	

	display.showExtraOptions();
	
	takeInputAndVerify();
	
	
}


void AccessInfoClass::takeInputAndVerify(){
	
	switch(option){
			
			case -1:
				display.ExitApp();
				break;
			case 1:
				system("cls");
				InformationAboutPlayers ob;
				ob.Start();
				break;
			case 2:
				system("cls");
				InformationAboutTeams ob2;
				ob2.Start();
				break;	
			case 3:
				system("cls");
				ShowUmpires ob3;
				ob3.Start();
				break;	
			case 4:
				system("cls");
				CoachingStaffInformation ob4;
				ob4.Start();
				break;	
			
			case 5:
				system("cls");
				TeamOwnersList ob5;
				ob5.Start();
				break;	
			case 6:
				system("cls");
				IPLStadiums ob6;
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


