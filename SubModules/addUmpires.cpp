#include "addUmpires.h"


#include "../ExternVariables/global.h"
#include "../ExternVariables/global_display_object.h"
#include <dirent.h>
#include <iostream>
#include <fstream>
#include "../Modules/ManageClass.h"





using namespace std;

void addUmpires::start(){
	
	system("cls");
	
	design.setTitle("ADD UMPIRE");
	
	design.TopDesign("\t\tUMPIRE ADD");
	
	cout << "\n\n\tEnter Umpire name : ";
	
	char temp[50] = "Database/Umpires/";
	char name[50];
	
	cin.ignore();
	
	scanf ("%[^\n]%*c", name);
	
	
		strcat(temp,name);
		
		strcat(temp,".ump");
		
	
		fstream file; 
	
		char stream[100];
	
		file.open(temp,ios::out); 
		
		
		cout << "\tEnter About Umpire : ";
		scanf ("%[^\n]%*c", stream);
		
		file << stream;
		
		file.close();
		
		
		
		design.setFontColor(6);
		cout << "\n\n\tAdded";
		design.showDots(3);
		system("cls");
   		ManageClass ob;
   		ob.Start();
		
		
	}
	
	
	








