#include "TeamRecords.h"
#include "../ExternVariables/global.h"
#include "../ExternVariables/global_display_object.h"
#include <dirent.h>
#include <iostream>
#include <fstream>
#include <sstream> 

int team_max_runs3 = 0, team_max_wickets3 = 0, no_players=0, avg_age = 0, left_handed_batsman=0, coach_count = 0;

void TeamRecords::start(){
	
	system("cls");
	
	design.setTitle("TEAM RECORDS");
	
	design.TopDesign("\t\tTEAM RECORDS");
	
	showStats();
	
	cout << "\n";
	
	
	display.showExtraOptions();
	
	
		if (option==-1) display.ExitApp();
		else if(option==0) display.mainMenu();
		else {
			
			display.showInvalidOptionSelectedError();
			start();
			
		}
	
						
}


void TeamRecords::showStats(){
			
			cout << "\n";
			
			char ch[25] = "Database/Teams/";
			
    		fetchFolders(ch);
    		
    		design.setFontColor(15);
				
}



 void TeamRecords::fetchFolders(const char* dirLocation){
	
			
			static DIR *dir;
			
			struct dirent *ent;
			
			int count = 1;
			
			static string hope = "";
			
			if ((dir = opendir (dirLocation)) != NULL) {
  			/* print all the files and directories within directory */
  			while ((ent = readdir (dir)) != NULL) {
  				
  					if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0 ){
					  
  						
  						
  						
  						
  						
  						char title[50];
  						
  						strcpy (title,ent->d_name);
  						
  						design.setFontColor(15);
  						cout << "\n\n\t"<< title << " RECORDS\n";
  						
  						design.setFontColor(count);
  						
  						char ch[100] = "Database/Teams/";
  						char ch2[100] = "Database/Teams/";
  						
  						  strcat (ch,ent->d_name);
  						  strcat (ch,"/Players/");
  						
  							strcat (ch2,ent->d_name);
  						  strcat (ch2,"/Coaching staff/");
  						
  						fetchFiles(ch);
  						fetchCoach(ch2);
  						
  						
  						cout << "\tTotal Players : " << no_players;
  						cout << "\n\tTotal Runs Scored : " << team_max_runs3;
  						cout << "\n\tTotal Wickets Taken : " << team_max_wickets3;
  						if(no_players!=0)
  						cout << "\n\tAverage Age of Player : " << avg_age/no_players;
  						cout << "\n\tLeft Handed : " << left_handed_batsman;
  						cout << "\n\tCoach in Database : " << coach_count;
  						
  						//RESET
  						team_max_runs3 = 0;
  						team_max_wickets3 = 0;
  						no_players = 0;
  						avg_age = 0;
  						coach_count = 0;
  						
					  }
    				
    				
    				count++;
    				
  				}
  			
			  closedir (dir);
			} else {
 
 						
 						cout << "Error";
 						exit(1);
 
				}
	
	
}

void TeamRecords::fetchFiles(const char* dirLocation2){
	
		
			
			DIR *dir2;
			
			struct dirent *ent2;
			
		
			
			
			
			if ((dir2 = opendir (dirLocation2)) != NULL) {
  			/* print all the files and directories within directory */
  			while ((ent2 = readdir (dir2)) != NULL) {
  				
  							if (strcmp(ent2->d_name, ".") != 0 && strcmp(ent2->d_name, "..") != 0 ){
  						
  							no_players++;
						string s = ent2->d_name;
						
						char nameLOC[100];
						
						strcpy(nameLOC,dirLocation2);
						
						strcat(nameLOC,ent2->d_name);
						
						readFile(nameLOC);
  						
					  }
    				
    				
    				
    				//cout << "rty2"<<"\n";
    				
  				}
  			
			  closedir (dir2);
			} else {
 
 						
 						cout << "Error";
 						exit(1);
 
				}
	

	
}




void TeamRecords::readFile(char FILENAME[95]){
	
	string line;
	
	ifstream myfile (FILENAME);
	
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
    	if(line.find("Runs") != string::npos){
    		
    		
    		
    		
    		int temp;
    		stringstream str(line.substr (6,line.length())); 
    		str >> temp;
    		
    		team_max_runs3 = team_max_runs3 + temp;
    	
		
		
	
		
			
    		
		}
		
		//Store Max Wickets
			if(line.find("Wickets") != string::npos){
    		
    		int temp;
    		stringstream str(line.substr (9,line.length())); 
    		str >> temp;
			
			team_max_wickets3 = team_max_wickets3 + temp;
				
    		
		
		
	}
		
		
		
			//Store Age
			if(line.find("Age") != string::npos){
    		
    		int temp;
    		stringstream str(line.substr (5,line.length())); 
    		str >> temp;
			
			avg_age = avg_age + temp;
				
    		
		
		
		
	}
		
		
		
		
			//Store Left Handed Batsman
			if(line.find("Left") != string::npos)
    		left_handed_batsman++;
		
		
      	
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
	
}





void TeamRecords::fetchCoach(const char* dirLocation2){
	
		
			
			DIR *dir2;
			
			struct dirent *ent2;
			
		
			
			
			
			if ((dir2 = opendir (dirLocation2)) != NULL) {
  			/* print all the files and directories within directory */
  			while ((ent2 = readdir (dir2)) != NULL) {
  				
  							if (strcmp(ent2->d_name, ".") != 0 && strcmp(ent2->d_name, "..") != 0 ){
  						
  						coach_count++;
  						
  						
					  }
    				
    				
    				
    				//cout << "rty2"<<"\n";
    				
  				}
  			
			  closedir (dir2);
			} else {
 
 						
 						cout << "Error";
 						exit(1);
 
				}
	

	
}








