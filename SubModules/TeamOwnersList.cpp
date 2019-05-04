#include "TeamOwnersList.h"
#include "../ExternVariables/global.h"
#include "../ExternVariables/global_display_object.h"
#include <dirent.h>
#include <iostream>
#include <fstream>
#include "../Modules/AccessInfoClass.h"



string Owners[50][2];
int ct = 1;

void TeamOwnersList::Start(){
	
	system("cls");
	
	design.setTitle("Team Owner Informations");
	
	design.TopDesign("\t\tALL TEAM OWNERS INFORMATION");
	
	showOwners();	
	
	showUserSelection();
	
}

void TeamOwnersList::showOwners(){
			
			cout << "\n\n";
			
			char ch[25] = "Database/Teams/";
			
    		fetchFolders(ch);
    		
    		design.setFontColor(15);
				
}


void TeamOwnersList::fetchFolders(const char* dirLocation){
	
			
			static DIR *dir;
			
			struct dirent *ent;
			
			ct = 1;
			
			static string hope = "";
			
			char location[20][20];
			
			cout << "\t[ Owners AVAILABLE ] \n";
			
			if ((dir = opendir (dirLocation)) != NULL) {
  			/* print all the files and directories within directory */
  			while ((ent = readdir (dir)) != NULL) {
  				
  					if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0 ){
					  
  						
  						
  						
  						design.setFontColor(ct);
  						
  						char title[50];
  						
  						strcpy (title,ent->d_name);
  						
  						
  						cout << "\n\t" << ct << " : " << title << "\n";
  						
  						
  						char ch[20] = "Database/Teams/";
  						
  						  strcat (ch,ent->d_name);
  						  
  						  strcat (ch,"/Team owner/owners.own");
  						  
  						  Owners[ct][0] = title;
  						  Owners[ct][1] = ch;
  						  
  						  
  						
  						ct++;
  						
  						
  						
  						
  						
					  }
    				
    				
    				
    				
  				}
  			
			  closedir (dir);
			} else {
 
 						
 						cout << "Error";
 						exit(1);
 
				}
	
	
}

void TeamOwnersList::showUserSelection(){
	
	
	//	int temp = ct;
	
	display.showExtraOptions();
	
	
	system("cls");
	
	if ( option >= ct || option < -1) {
		
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
	
	
	
	string title = Owners[option][0];
	
	
	design.setTitle(title);
	
	design.TopDesign("\t\t"+title);
	
	int temp = option;
	
	cout << "\n";
	
	design.setFontColor(option);
	
	char ch[50]={};
	
	strcpy (ch, Owners[option][1].c_str());
	
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
