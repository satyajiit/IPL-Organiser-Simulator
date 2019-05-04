#include "AnalyzePlayers.h"
#include "../ExternVariables/global.h"
#include "../ExternVariables/global_display_object.h"
#include <dirent.h>
#include <iostream>
#include <fstream>
#include <sstream> 
#include "../Modules/AccessInfoClass.h"


int count2 = 1;

int max_runs = 0, min_runs = 10000, max_wckts = 0;

string max_player,min_player,wckt_player;


using namespace std;

void AnalyzePlayers::start(){

	system("cls");
	
	design.setTitle("Analyze Players");
	
	design.TopDesign("\t\tPLAYERS ANALYSIS");
	
	showTeamsAndPlayers();
	
	
}

void AnalyzePlayers::showTeamsAndPlayers(){
	
	
	cout << "\n\n";
			
			char ch[25] = "Database/Teams/";
			
    		fetchFolders(ch);
    		
    		design.setFontColor(15);
	
			display.showExtraOptions();
			
			if(option == 0)
				display.mainMenu();
			else if(option==-1)
				display.ExitApp();
			else {
				
				display.showInvalidOptionSelectedError();
				start();
				
			}
			
			
			
	
}





void AnalyzePlayers::fetchFolders(const char* dirLocation){
	
			
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
  						
  						if(max_runs!=0||min_runs!=10000||max_wckts!=0)
  						cout << "\n\t"<< title << " : \n\n";
  						
  						
  						if(max_runs!=0)
							cout << "\tBest Player -> " << max_player << "\b\bwith " << max_runs << " runs.\n";
							
						if(min_runs!=10000&&max_runs!=min_runs)	
  						cout << "\tLowest Scorer -> " << min_player << "\b\bwith " << min_runs << " runs.\n";
  						
  						if(max_wckts!=0)	
  						cout << "\tBest Bowler -> " << wckt_player << "\b\bwith " << max_wckts << " wickets.\n";
  					
					  
					  
					  min_runs = 10000;
					  max_runs = max_wckts = 0;
					  max_player = min_player = wckt_player = "";
  						
					  }
    				
    				
    				count++;
    				
  				}
  			
			  closedir (dir);
			} else {
 
 						
 						cout << "Error";
 						exit(1);
 
				}
	
	
}

void AnalyzePlayers::fetchFiles(const char* dirLocation2,string name){
	
		
			
			DIR *dir2;
			
			struct dirent *ent2;
			
			int count = 1;
			
			
			
			if ((dir2 = opendir (dirLocation2)) != NULL) {
  			/* print all the files and directories within directory */
  			while ((ent2 = readdir (dir2)) != NULL) {
  				
  					if (strcmp(ent2->d_name, ".") != 0 && strcmp(ent2->d_name, "..") != 0 ){
  						
  							
						string s = ent2->d_name;
						
						char nameLOC[100];
						
						strcpy(nameLOC,dirLocation2);
						
						strcat(nameLOC,ent2->d_name);
						
						readFile(nameLOC);
						
					//	PLAYERS[count2][0]=s;
					//	PLAYERS[count2][1]=name;
  						s = s.replace(s.end()-3,s.end(),3,' ');
  						//cout << "\t" << count2 << " : " << s << "\n";
  						
  						count2++;
  						
					  }
    				
    				count++;
    				
    				
  				}
  			
			  closedir (dir2);
			} else {
 
 						
 						cout << "Error";
 						exit(1);
 
				}
	

	
}





void AnalyzePlayers::readFile(char FILENAME[95]){
	
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
    		
    		if(temp > max_runs){
			
    		max_runs = temp;
    		max_player = FILENAME;
    		
    	max_player = max_player.substr (max_player.find_last_of("/")+1);
    	
    	max_player = max_player.replace(max_player.end()-3,max_player.end(),3,' ');
    	
    
    	}
    		
    	
		
		
		if (temp<min_runs){
			
			
			
			min_runs = temp;
    		min_player = FILENAME;
    		
    		
    		
    	min_player = min_player.substr (min_player.find_last_of("/")+1);
    	
    	min_player = min_player.replace(min_player.end()-3,min_player.end(),3,' ');
			
			
		}
		
		
			
    		
		}
		
		//Store Max Wickets
			if(line.find("Wickets") != string::npos){
    		
    		int temp;
    		stringstream str(line.substr (9,line.length())); 
    		str >> temp;
				
    		if(temp > max_wckts){
			
    		max_wckts = temp;
    		wckt_player = FILENAME;
    		
    	wckt_player = wckt_player.substr (wckt_player.find_last_of("/")+1);
    	
    	wckt_player = wckt_player.replace(wckt_player.end()-3,wckt_player.end(),3,' ');
    	
    
    	}
		
		
	}
		
      	
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
	
}












