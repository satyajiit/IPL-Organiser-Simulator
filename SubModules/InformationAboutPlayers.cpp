#include "InformationAboutPlayers.h"
#include "../ExternVariables/global.h"
#include "../ExternVariables/global_display_object.h"
#include <dirent.h>
#include <iostream>
#include <fstream>
#include "../Modules/AccessInfoClass.h"

using namespace std;

	string players[50][2];
	int serial = 1;
	int plyrs = 0;

void InformationAboutPlayers::Start(){
	

	design.setTitle("Players Information");
	
	design.TopDesign("\t\tALL PLAYERS INFORMATION");
	
	showPlayers();	
	
	showUserSelection();
	
}
void InformationAboutPlayers::showUserSelection(){
	
	
	display.showExtraOptions();
	
	
	system("cls");
	
	if ( option > serial-1 || option < -1) {
		
		display.showInvalidOptionSelectedError();
		serial = 1;
		Start();
	}
	else if ( option == -1) display.ExitApp();
	
	else if(option == 0) {
			serial = 1;
			AccessInfoClass ob;
			ob.Start();
	
	}
					
	else {
	
	retry:
	
	string title = players[option][0];
	
	title = title.replace(title.end()-3,title.end(),3,' ');
	
	design.setTitle("Information about "+title);
	
	design.TopDesign("\t\t"+title);
	
	char location[50] = "Database/Teams/";
	
	strcat (location, players[option][1].c_str());
	
	strcat (location, "/Players/");
	
	char suffix[200];
	
	strcpy (suffix, players[option][0].c_str());
	
	int temp = option;
	
	strcat (location, suffix);
	
	cout << "\n";
	
	design.setFontColor(option);
	
	display.readFile(location);
	
	
	display.showExtraOptions();

	
	if (option == 0) {
	serial = 1;
	Start();
	}
	else if (option == -1) display.ExitApp();
	else {
	display.showInvalidOptionSelectedError();
	option = temp;
	goto retry;
	}
	
	
	
	
	
}

	
	//exit(0);
}
void InformationAboutPlayers::showPlayers(){
			
			cout << "\n\n";
			
			char ch[25] = "Database/Teams/";
			
    		fetchFolders(ch);
    		
    		design.setFontColor(15);
				
}



 void InformationAboutPlayers::fetchFolders(const char* dirLocation){
	
			
			static DIR *dir;
			
			struct dirent *ent;
			
			int count = 1;
			
			static string hope = "";
			
			if ((dir = opendir (dirLocation)) != NULL) {
  			/* print all the files and directories within directory */
  			while ((ent = readdir (dir)) != NULL) {
  				
  					if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0 ){
					  
  						
  						
  						
  						design.setFontColor(count);
  						
  						char title[50];
  						
  						strcpy (title,ent->d_name);
  						
  						
  					//	cout << "\n\tPLAYERS OF "<< title << " : \n\n";
  						
  						
  						char ch[100] = "Database/Teams/";
  						
  						  strcat (ch,ent->d_name);
  						  strcat (ch,"/Players/");
  						
  						
  						fetchFiles(ch,title);
  						
  						plyrs = 0;
  						
  						
  						
  						
					  }
    				
    				
    				count++;
    				
  				}
  			
			  closedir (dir);
			} else {
 
 						
 						cout << "Error";
 						exit(1);
 
				}
	
	
}

void InformationAboutPlayers::fetchFiles(const char* dirLocation2,string name){
	
		
			
			DIR *dir2;
			
			struct dirent *ent2;
			
			int count = 1;
			
			
			
			if ((dir2 = opendir (dirLocation2)) != NULL) {
  			/* print all the files and directories within directory */
  			while ((ent2 = readdir (dir2)) != NULL) {
  				
  							if (strcmp(ent2->d_name, ".") != 0 && strcmp(ent2->d_name, "..") != 0 ){
  						
  						if(plyrs == 0)
  						cout << "\n\tPLAYERS OF "<< name << " : \n\n";
  						
  							plyrs++;
						string s = ent2->d_name;
						players[serial][0]=s;
						players[serial][1]=name;
  						s = s.replace(s.end()-3,s.end(),3,' ');
  						cout << "\t" << serial << " : " << s << "\n";
  						
  						serial++;
  						
					  }
    				
    				count++;
    				
    				//cout << "rty2"<<"\n";
    				
  				}
  			
			  closedir (dir2);
			} else {
 
 						
 						cout << "Error";
 						exit(1);
 
				}
	

	
}





