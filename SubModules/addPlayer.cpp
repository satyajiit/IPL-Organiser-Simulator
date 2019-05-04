#include "addPlayer.h"
#include "../ExternVariables/global.h"
#include "../ExternVariables/global_display_object.h"
#include <dirent.h>
#include <iostream>
#include <fstream>
#include "../Modules/ManageClass.h"

string teamsLink[50][2];

int countt = 1;

using namespace std;

void addPlayer::start(){
	
	system("cls");
	
	design.setTitle("Add Players");
	
	design.TopDesign("\t\tTEAM SELECTION");
	
	showTeams();	
	
	showUserSelection();
	
}

void addPlayer::showTeams(){
			
			cout << "\n\n";
			
			char ch[25] = "Database/Teams/";
			
    		fetchFolders(ch);
    		
    		design.setFontColor(15);
				
}


void addPlayer::fetchFolders(const char* dirLocation){
	
			
			static DIR *dir;
			
			struct dirent *ent;
			
			countt = 1;
			
			static string hope = "";
			
			char location[20][20];
			
			cout << "\t[ TEAMS AVAILABLE ] \n";
			
			if ((dir = opendir (dirLocation)) != NULL) {
  			/* print all the files and directories within directory */
  			while ((ent = readdir (dir)) != NULL) {
  				
  					if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0 ){
					  
  						
  						
  						
  						design.setFontColor(countt);
  						
  						char title[50];
  						
  						strcpy (title,ent->d_name);
  						
  						
  						cout << "\n\t" << countt << " : " << title << "\n";
  						
  						
  						char ch[50] = "Database/Teams/";
  						
  						  strcat (ch,ent->d_name);
  						  strcat (ch,"/Players/");
  						  
  						 
  						  teamsLink[countt][1] = ch;
  						  teamsLink[countt][0] = title;
  						  
  						  
  						
  						countt++;
  						
  						
  						
  						
  						
					  }
    				
    				
    				
    				
  				}
  			
			  closedir (dir);
			} else {
 
 						
 						cout << "Error";
 						exit(1);
 
				}
	
	
}





void addPlayer::showUserSelection(){
	
	

	
	display.showExtraOptions();
	
	
	system("cls");
	
	if ( option >= countt || option < -1) {
		
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
	
	
	
	string title = teamsLink[option][0];
	
	
	design.setTitle("ADD PLAYER TO "+title);
	
	design.TopDesign("\t\t"+title);
	
	int temp = option;
	
	cout << "\n";
	
	design.setFontColor(15);
	
	
	
	char str[450];
	
	strcpy(str, teamsLink[option][1].c_str());
	
	char name[430];
	
	int temper = option;
	
	cout << "\n\tEnter Name : ";
	
	cin.ignore();
	scanf ("%[^\n]%*c", name);
	
	strcat(str, name);
	
	strcat(str, ".pl");
	
	fstream file; 
	
	 file.open(str,ios::out); 
  
   if(!file) 
   { 
   
   		
   		cout << "ERROR";
      
      
   } 
  else {
  	
  	file << name <<"\n";
   		
		   retryy:
   			
   		cout << "\tEnter Age (Years): ";
   		
   		
   		
   		char tempo[435];
   		
   		scanf ("%[^\n]%*c", tempo);
   		
   		file << "Age: " << tempo << "\n";
   		
   		for (int i = 0; i<strlen(tempo); i++)
   				if(!isdigit(tempo[i])){
   					
   					cout << "\tError it Should be a numeric value!!";
   					goto retryy;
   					break;
   					
				   }
   		
   		
   		cout << "\tEnter Playing role : ";
   		scanf ("%[^\n]%*c", tempo);
   		file << "Playing role: " << tempo << "\n";
   		
   		
   		cout << "\tEnter Batting Hand : ";
   		scanf ("%[^\n]%*c", tempo);
   		file << "Batting: " << tempo << "\n";
   		
   		
   		cout << "\tEnter Bowling Hand : ";
   		scanf ("%[^\n]%*c", tempo);
   		file << "Bowling: " << tempo << "\n";
   		
   		cout << "\tWickets taken : ";
   		scanf ("%[^\n]%*c", tempo);
   		file << "Wickets: " << tempo << "\n";
   		
   		
   		cout << "\tRuns scored : ";
   		scanf ("%[^\n]%*c", tempo);
   		file << "Runs: " << tempo << "\n";
   		
   		cout<<"\n\tPlayer Add Success!!";
   		
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



