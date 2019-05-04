#include "GetterSetterClass.h"
#include "../ExternVariables/global.h"
#include <iostream>
#include <fstream>
#include <string.h>
#include <dirent.h>
#include <bits.h>
#include <limits>
#include "../Modules/ManageClass.h"
#include "../Modules/AccessInfoClass.h"
#include "../Modules/ScheduleGenerator.h"
#include "../Modules/AnalyzePlayers.h"
#include "../Modules/IplStats.h"
#include "../Modules/TeamRecords.h"


using namespace std;

void GetterSetterClass::showOptions(){
			
			cout << "\n\n";
			cout << "\t1 - Access Information of IPL"<<endl;	
			cout << "\t2 - Manage Data IPL 19"<<endl;	
			cout << "\t3 - Generate IPL 19 Schedule"<<endl;	
			cout << "\t4 - Analyze Player Performance"<<endl;
			cout << "\t5 - Check Tournament Stats"<<endl;
			cout << "\t6 - Check Team Records"<<endl;
			
				
}

void GetterSetterClass::showOptionsForAccess(){
			
			cout << "\n\n";
			
			cout << "\tWhat do you want to know or access about?"<<endl;
			cout << "\n\t1 - Player"<<endl;	
			cout << "\t2 - Team"<<endl;	
			cout << "\t3 - Umpires"<<endl;	
			cout << "\t4 - Coaching Staff"<<endl;
			cout << "\t5 - Team Owners"<<endl;
			cout << "\t6 - Stadiums"<<endl;
				
}


void GetterSetterClass::showInvalidOptionSelectedError(){
	
				system("cls");
				design.setTitle("Invalid Input");
				design.setFontColor(12);
				design.showText("Invalid Option Entered..Please Try again!!");
				design.setFontColor(15);
				design.showTextCenter("Starting again , Please Wait");
				design.showDots(4);
				system("cls");
	
}

void GetterSetterClass::ExitApp(){
	
				system("cls");
				design.setFontColor(14);
				design.showText("Thanks for Using the Simulator!! Good Bye..");
				design.setFontColor(15);
				design.showTextCenter("Exiting");
				design.showDots(3);
				cout << "\n\n\n\n\n";
				exit(0);
	
}

void GetterSetterClass::mainMenu(){
	
	system("cls");
	
	design.setTitle("IPL CRICKET TOURNAMENT ORGANIZER MAIN MENU");
	
	design.TopDesign("IPL CRICKET TOURNAMENT ORGANIZER MAIN MENU");
	
	
	showOptions(); //Show options menu
	
	
	
	
	cout << "\t0 - Exit"<<endl;
	
	start:
	cout << "\n\tEnter Option : ";
	
	design.setFontColor(15); //Set White as font Color
	
	cin >> option;
	
	
		if(!cin) // or if(cin.fail())
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	design.setFontColor(12);
    cout << "\n\tError Please enter a numeric value!!\n";
    goto start;
    
}

	
	
	VerifyOption();
	
	
}



void GetterSetterClass::VerifyOption(){
	if (option<0||option>6){
			
				showInvalidOptionSelectedError();
				mainMenu();
				
				
		}
		else initMainMenuUI();
}


void GetterSetterClass::initMainMenuUI(){
	
	switch(option){
			case 0:
				ExitApp();
			case 1:
				system("cls");
				AccessInfoClass ob;
				ob.Start();
				break;
			case 2:
				
				ManageClass ob2;
				ob2.Start();
				break;
			case 3:
				ScheduleGenerator ob3;
				ob3.Start();
				break;
			case 4:
				
				AnalyzePlayers ob4;
				ob4.start();
				break;	
			case 5:
				IplStats ob5;
				ob5.start();
				break;	
			case 6:
			TeamRecords ob6;
			ob6.start();
			break;	
		}
	
}

void GetterSetterClass::showExtraOptions(){
	
	
	start:
	design.setFontColor(15);
	cout << "\n\t-1 -> EXIT\n";
	cout << "\t 0 -> BACK\n";
	cout << "\n\tEnter Selection : ";
	
	
	
	cin >> option;
	
	
	if(!cin) // or if(cin.fail())
{
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	
	design.setFontColor(12);
    cout << "\n\tError Please enter a numeric value!!\n";
    goto start;
    
}
	
	
}

void GetterSetterClass::readFile(char FILENAME[25]){
	
	string line;
	
	ifstream myfile (FILENAME);
	
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
      	cout << "\n\t" << line << "\n";
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
	
}

