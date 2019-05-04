#include "deletePlayer.h"

#include "../ExternVariables/global.h"
#include "../ExternVariables/global_display_object.h"
#include <dirent.h>
#include <iostream>
#include <fstream>
#include "../Modules/ManageClass.h"

using namespace std;

	string player[50][2];
	int increment = 1;
	int plr = 0;

void deletePlayer::Start(){
	
	system("cls");

	design.setTitle("Select to Delete");
	
	design.TopDesign("\t\tSELECT PLAYER TO DELETE");
	
	showPlayers();	
	
	showUserSelection();
	
}
void deletePlayer::showUserSelection(){
	
	
	display.showExtraOptions();
	
	
	system("cls");
	
	if ( option > increment-1 || option < -1) {
		
		display.showInvalidOptionSelectedError();
		increment = 1;
		Start();
	}
	else if ( option == -1) display.ExitApp();
	
	else if(option == 0) {
			increment = 1;
			ManageClass ob;
			ob.Start();
	
	}
					
	else {
	
	retry:
	
	string title = player[option][0];
	
	title = title.replace(title.end()-3,title.end(),3,' ');
	
	design.setTitle("Player Deletion "+title);
	
	design.TopDesign("\t\tDELETE");
	
	char location[50] = "Database/Teams/";
	
	strcat (location, player[option][1].c_str());
	
	strcat (location, "/Players/");
	
	char suffix[200];
	
	strcpy (suffix, player[option][0].c_str());
	
	int temp = option;
	
	strcat (location, suffix);
	
	cout << "\n\n";
	
	design.setFontColor(option);
	
	cout << "\n\tWait a sec";
	design.showDots(3);
	
	design.setFontColor(10);
	
	if( remove( location ) != 0 )
    perror( "Failed to Delete Player" );
  else
    puts( "\n\n\tDelete Success!!" );
	
	
	
	display.showExtraOptions();

	
	if (option == 0) {
	increment = 1;
	Start();
	}
	else if (option == -1) display.ExitApp();
	else {
	display.showInvalidOptionSelectedError();
	Start();
	}
	
	
	
	
	
}

	
	//exit(0);
}
void deletePlayer::showPlayers(){
			
			cout << "\n\n";
			
			char ch[25] = "Database/Teams/";
			
    		fetchFolders(ch);
    		
    		design.setFontColor(15);
				
}



 void deletePlayer::fetchFolders(const char* dirLocation){
	
			
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
  						
  						
  					
  						
  						
  						char ch[100] = "Database/Teams/";
  						
  						  strcat (ch,ent->d_name);
  						  strcat (ch,"/Players/");
  						
  						
  						fetchFiles(ch,title);
  						
  						plr = 0;
  						
  						
					  }
    				
    				
    				count++;
    				
  				}
  			
			  closedir (dir);
			} else {
 
 						
 						cout << "Error";
 						exit(1);
 
				}
	
	
}

void deletePlayer::fetchFiles(const char* dirLocation2,string name){
	
		
			
			DIR *dir2;
			
			struct dirent *ent2;
			
			int count = 1;
			
			
			
			if ((dir2 = opendir (dirLocation2)) != NULL) {
  			/* print all the files and directories within directory */
  			while ((ent2 = readdir (dir2)) != NULL) {
  				
  							if (strcmp(ent2->d_name, ".") != 0 && strcmp(ent2->d_name, "..") != 0 ){
  						
  							if (plr == 0 ) 	cout << "\n\tPlayers OF "<< name << " : \n\n";
  							
							  plr++;
  							
						string s = ent2->d_name;
						player[increment][0]=s;
						player[increment][1]=name;
  						s = s.replace(s.end()-3,s.end(),3,' ');
  						cout << "\t" << increment << " : " << s << "\n";
  						
  						increment++;
  						
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





