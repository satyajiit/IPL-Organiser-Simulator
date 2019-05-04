#include "IplStats.h"
#include "../ExternVariables/global.h"
#include "../ExternVariables/global_display_object.h"
#include <dirent.h>
#include <iostream>
#include <fstream>
#include <sstream> 



int max_runs2 = 0, min_runs2 = 10000, max_wckts2 = 0;

string max_player2,min_player2,wckt_player2;

string team_with_max_runs,team_with_max_wickets;



int team_max_runs=0, team_max_runs2 = 0,team_max_wickets=0, team_max_wickets2 = 0;

void IplStats::start(){
	
	system("cls");
	
	design.setTitle("IPL STATS");
	
	design.TopDesign("\t\tIPL ANALYSIS");
	
	showStats();
						
}


void IplStats::showStats(){
	
	
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

void IplStats::fetchFolders(const char* dirLocation){
	
			
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
  						
  						if (team_max_runs2 > team_max_runs){
  							
  							team_max_runs = team_max_runs2;
  							team_with_max_runs = title;
  							
						  }
						  
						 if (team_max_wickets2 > team_max_wickets){
  							
  							team_max_wickets = team_max_wickets2;
  							team_with_max_wickets = title;
  							
						  } 
						  
						  team_max_runs2 = 0;
					  		team_max_wickets2= 0;
  						
					  }
    				
    				
    				count++;
    				
  				}
  			
			  closedir (dir);
			} else {
 
 						
 						cout << "Error";
 						exit(1);
 
				}
	
	
  						if(max_runs2!=0)
						{
							cout << "\tBest Player -> " ;
							design.setFontColor(15); 
							cout << max_player2; design.setFontColor(10);  cout << "\b\bwith ";
							design.setFontColor(15); 
							cout << max_runs2; 
							design.setFontColor(10); 
							cout << " runs.\n";
						}
						
						
						if(min_runs2!=10000&&max_runs2!=min_runs2){
							
							
							cout << "\tLowest Scorer -> " ;
							design.setFontColor(15); 
							cout << min_player2; design.setFontColor(10);  cout << "\b\bwith ";
							design.setFontColor(15); 
							cout << min_runs2; 
							design.setFontColor(10); 
							cout << " runs.\n";
							
							
						}	
  						
  						
  						if(max_wckts2!=0){
  							
  								
  							cout << "\tBest Bowler -> " ;
							design.setFontColor(15); 
							cout << wckt_player2; 
							design.setFontColor(10);  
							cout << "\b\bwith ";
							design.setFontColor(15); 
							cout << max_wckts2; 
							design.setFontColor(10); 
							cout << " wickets.\n";
  							
						  }	
  						
  						if(team_max_runs!=0){
  						
						  	cout << "\tTeam with Highest Score -> " ;
							design.setFontColor(15); 
							cout << team_with_max_runs; 
							design.setFontColor(10);  
							cout << " with ";
							design.setFontColor(15); 
							cout << team_max_runs; 
							design.setFontColor(10); 
							cout << " runs.\n";
  					
						  }
							
  						if(team_max_wickets!=0){
  							cout << "\tTeam with Highest Wickets Taken -> " ;
							design.setFontColor(15); 
							cout << team_with_max_wickets; 
							design.setFontColor(10);  
							cout << " with ";
							design.setFontColor(15); 
							cout << team_max_wickets; 
							design.setFontColor(10); 
							cout << " wickets.\n";
						  }
							

}

void IplStats::fetchFiles(const char* dirLocation2,string name){
	
		
			
			DIR *dir2;
			
			struct dirent *ent2;
			
		//	int count = 1;
			
			
			
			if ((dir2 = opendir (dirLocation2)) != NULL) {
  			/* print all the files and directories within directory */
  			while ((ent2 = readdir (dir2)) != NULL) {
  				
  					if (strcmp(ent2->d_name, ".") != 0 && strcmp(ent2->d_name, "..") != 0 ){
  						
  							
						string s = ent2->d_name;
						
						char nameLOC[100];
						
						strcpy(nameLOC,dirLocation2);
						
						strcat(nameLOC,ent2->d_name);
						
						readFile(nameLOC);
						
						//PLAYERS[count2][0]=s;
						//PLAYERS[count2][1]=name;
  						//s = s.replace(s.end()-3,s.end(),3,' ');
  						//cout << "\t" << count2 << " : " << s << "\n";
  						
  						//count2++;
  						
					  }
    				
    			//	count++;
    				
    				
  				}
  			
			  closedir (dir2);
			} else {
 
 						
 						cout << "Error";
 						exit(1);
 
				}
	

	
}





void IplStats::readFile(char FILENAME[95]){
	
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
    		
    		team_max_runs2 = team_max_runs2 + temp;
    		
    		if(temp > max_runs2){
			
    		max_runs2 = temp;
    		max_player2 = FILENAME;
    		
    	max_player2 = max_player2.substr (max_player2.find_last_of("/")+1);
    	
    	max_player2 = max_player2.replace(max_player2.end()-3,max_player2.end(),3,' ');
    	
    
    	}
    		
    	
		
		
		if (temp<min_runs2){
			
			
			
			min_runs2 = temp;
    		min_player2 = FILENAME;
    		
    		
    		
    	min_player2 = min_player2.substr (min_player2.find_last_of("/")+1);
    	
    	min_player2 = min_player2.replace(min_player2.end()-3,min_player2.end(),3,' ');
			
			
		}
		
		
			
    		
		}
		
		//Store Max Wickets
			if(line.find("Wickets") != string::npos){
    		
    		int temp;
    		stringstream str(line.substr (9,line.length())); 
    		str >> temp;
			
			team_max_wickets2 = team_max_wickets2 + temp;
				
    		if(temp > max_wckts2){
			
    		max_wckts2 = temp;
    		wckt_player2 = FILENAME;
    		
    	wckt_player2 = wckt_player2.substr (wckt_player2.find_last_of("/")+1);
    	
    	wckt_player2 = wckt_player2.replace(wckt_player2.end()-3,wckt_player2.end(),3,' ');
    	
    
    	}
		
		
	}
		
      	
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
	
}

















