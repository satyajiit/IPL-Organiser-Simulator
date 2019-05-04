#include "addTeam.h"

#include "../ExternVariables/global.h"
#include "../ExternVariables/global_display_object.h"
#include <dirent.h>
#include <iostream>
#include <fstream>
#include "../Modules/ManageClass.h"





using namespace std;

void addTeam::start(){
	
	system("cls");
	
	design.setTitle("ADD TEAM");
	
	design.TopDesign("\t\tTEAM ADD");
	
	cout << "\n\n\tEnter Team name : ";
	
	char temp[50] = "Database/Teams/";
	char name[50];
	
	cin.ignore();
	
	scanf ("%[^\n]%*c", name);
	
	
	strcat(temp,name);
	
	for (int i=0; i < strlen(temp); i++)
{
   temp[i] = toupper(temp[i]);
}
	
	
	int status = mkdir(temp);
	
	if (status==0){
		
		//Success
		
		char link[50];
		strcpy(link,temp);
		strcat(link,"/Coaching staff");
		mkdir(link);
		
		strcpy(link,temp);
		strcat(link,"/Players");
		mkdir(link);
		
		strcpy(link,temp);
		strcat(link,"/Team owner");
		mkdir(link);
		
		
		strcpy(link,temp);
	
		strcat(link, "/info.team");
	
		fstream file; 
	
		char stream[100];
	
		file.open(link,ios::out); 
		
		
		cout << "\tEnter About Team : ";
		scanf ("%[^\n]%*c", stream);
		
		file << stream;
		
		file.close();
		
		strcpy(link,temp);
	
		strcat(link, "/Team owner/owners.own");
		
		file.open(link,ios::out); 
		
		
		cout << "\tEnter Team Owner : ";
		
		cin >> stream;
		
		file << stream;
		
		design.setFontColor(6);
		cout << "\n\n\tAdded";
		design.showDots(3);
		system("cls");
   		ManageClass ob;
   		ob.Start();
		
		
	}
	
	else cout << "Something Went Wrong!!";
	
	
}







