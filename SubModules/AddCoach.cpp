#include "AddCoach.h"

#include "../ExternVariables/global.h"
#include "../ExternVariables/global_display_object.h"
#include <dirent.h>
#include <iostream>
#include <fstream>
#include "../Modules/ManageClass.h"

string teamLink[50][2];

int flagged = 1;

using namespace std;

void AddCoach::start(){
	
	system("cls");
	
	design.setTitle("Add Coaching staff");
	
	design.TopDesign("\t\tTEAM SELECTION");
	
	showTeams();	
	
	showUserSelection();
	
}

void AddCoach::showTeams(){
			
			cout << "\n\n";
			
			char ch[25] = "Database/Teams/";
			
    		fetchFolders(ch);
    		
    		design.setFontColor(15);
				
}


void AddCoach::fetchFolders(const char* dirLocation){
	
			
			static DIR *dir;
			
			struct dirent *ent;
			
			flagged = 1;
			
			static string hope = "";
			
			char location[20][20];
			
			cout << "\t[ TEAMS AVAILABLE ] \n";
			
			if ((dir = opendir (dirLocation)) != NULL) {
  			/* print all the files and directories within directory */
  			while ((ent = readdir (dir)) != NULL) {
  				
  					if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0 ){
					  
  						
  						
  						
  						design.setFontColor(flagged);
  						
  						char title[50];
  						
  						strcpy (title,ent->d_name);
  						
  						
  						cout << "\n\t" << flagged << " : " << title << "\n";
  						
  						
  						char ch[50] = "Database/Teams/";
  						
  						  strcat (ch,ent->d_name);
  						  strcat (ch,"/Coaching staff/");
  						  
  						 
  						  teamLink[flagged][1] = ch;
  						  teamLink[flagged][0] = title;
  						  
  						  
  						
  						flagged++;
  						
  						
  						
  						
  						
					  }
    				
    				
    				
    				
  				}
  			
			  closedir (dir);
			} else {
 
 						
 						cout << "Error";
 						exit(1);
 
				}
	
	
}





void AddCoach::showUserSelection(){
	
	

	
	display.showExtraOptions();
	
	
	system("cls");
	
	if ( option >= flagged || option < -1) {
		
		display.showInvalidOptionSelectedError();
		
		start();
	}
	else if ( option == -1) display.ExitApp();
	
	else if(option == 0) {
		//	serial = 1;
			ManageClass ob;
			ob.Start();
	
	}
					
	else {
	
	retry:
	
	
	
	string title = teamLink[option][0];
	
	
	design.setTitle("ADD COACHING STAFF TO "+title);
	
	design.TopDesign("\t\t"+title);
	
	int temp = option;
	
	cout << "\n";
	
	design.setFontColor(15);
	
	
	char str[200];
	
	strcpy(str, teamLink[option][1].c_str());
	
	int temper = option;
	
	char name[200];
	
	
	
	cout << "\n\tEnter Coaching staff Name : ";
	cin.ignore();
	scanf ("%[^\n]%*c", name);
	
	strcat(str, name);
	
	strcat(str, ".staff");
	
	
	fstream file; 
	
	 file.open(str,ios::out); 
  
   if(!file) 
   { 
   
   		
   		cout << "ERROR";
      
      
   } 
  else {
  	
  	
   		
   		cout << "\tEnter about : ";
   		
   		cin.ignore();
   		
   		char tempo[105];
   		
   		scanf ("%[^\n]%*c", tempo);
   		
   		file << tempo;
   		
   		
   		
   		cout<<"\n\tStaff Add Success!!";
   		
   		file.close();
   		
   		check:
   		
   		design.setFontColor(6);
   		cout << "\n\n\t 1 -> ADD MORE";
   		display.showExtraOptions();
   		
   		
   		if(option==-1) display.ExitApp();
   		
   		else if(option==0){
   			
   			start();
   		}
   		
   		else if(option==1){
   			system("cls");
   			option = temper;
   			goto retry;
   			
		   }
   		
   		else {
   			
   			display.showInvalidOptionSelectedError();
   			goto check;
   			
		   }
   		
   		
   		
  	
  	
  }
   
	
	
	
	
	
}


}



