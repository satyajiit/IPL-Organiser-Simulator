#include "InformationAboutTeams.h"
#include "../ExternVariables/global.h"
#include "../ExternVariables/global_display_object.h"
#include <dirent.h>
#include <iostream>
#include <fstream>
#include "../Modules/AccessInfoClass.h"

string Teams[50][2];
int count = 1;

void InformationAboutTeams::Start(){
	
	system("cls");
	
	design.setTitle("Players Information");
	
	design.TopDesign("\t\tALL TEAMS INFORMATION");
	
	showTeams();	
	
	showUserSelection();
	
}

void InformationAboutTeams::showTeams(){
			
			cout << "\n\n";
			
			char ch[25] = "Database/Teams/";
			
    		fetchFolders(ch);
    		
    		design.setFontColor(15);
				
}


void InformationAboutTeams::fetchFolders(const char* dirLocation){
	
			
			static DIR *dir;
			
			struct dirent *ent;
			
			count = 1;
			
			static string hope = "";
			
			char location[20][20];
			
			cout << "\t[ TEAMS AVAILABLE ] \n";
			
			if ((dir = opendir (dirLocation)) != NULL) {
  			/* print all the files and directories within directory */
  			while ((ent = readdir (dir)) != NULL) {
  				
  					if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0 ){
					  
  						
  						
  						
  						design.setFontColor(count);
  						
  						char title[50];
  						
  						strcpy (title,ent->d_name);
  						
  						
  						cout << "\n\t" << count << " : " << title << "\n";
  						
  						
  						char ch[20] = "Database/Teams/";
  						
  						  strcat (ch,ent->d_name);
  						  strcat (ch,"/info.team");
  						  
  						  Teams[count][0] = title;
  						  Teams[count][1] = ch;
  						  
  						  
  						
  						count++;
  						
  						
  						
  						
  						
					  }
    				
    				
    				
    				
  				}
  			
			  closedir (dir);
			} else {
 
 						
 						cout << "Error";
 						exit(1);
 
				}
	
	
}

void InformationAboutTeams::showUserSelection(){
	
	

	
	display.showExtraOptions();
	
	
	system("cls");
	
	if ( option >= count || option < -1) {
		
		display.showInvalidOptionSelectedError();
		
		Start();
	}
	else if ( option == -1) display.ExitApp();
	
	else if(option == 0) {
		//	serial = 1;
			AccessInfoClass ob;
			ob.Start();
	
	}
					
	else {
	
	retry:
	
	
	
	string title = Teams[option][0];
	
	
	design.setTitle(title);
	
	design.TopDesign("\t\t"+title);
	
	int temp = option;
	
	cout << "\n";
	
	design.setFontColor(option);
	
	char ch[50];
	
	strcpy (ch, Teams[option][1].c_str());
	
	display.readFile(ch);
	
	
	display.showExtraOptions();

	
	if (option == 0) {
	Start();
	}
	else if (option == -1) display.ExitApp();
	else {
	display.showInvalidOptionSelectedError();
	option = temp;
	goto retry;
	}
	
	
	
	
	
}


}
