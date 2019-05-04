#include "ScheduleGenerator.h"
#include "../ExternVariables/global.h"
#include "../ExternVariables/global_display_object.h"
#include <dirent.h>
#include <iostream>
#include <fstream>
#include <string>

string teamsArray[50];

void ScheduleGenerator::Start(){
	
	system("cls");

	design.setTitle("Schedule Generation");
	
	design.TopDesign("\t\tSCHEDULE");
	
	int row  = 2 , column = 3;
	
	int TeamsCount = countTeams();
	
	if (TeamsCount%2!=0){
		
		cout << "Not possible";
		exit(0);
		
	}
	
	
	column = TeamsCount/2;
	
	string Teams[row][column];
	
	string Teams2[row][column];

	int c_start = column-1, c_end = 0;
	
	string end_b, end_c;
	
	//First Initialise
	
	int index = 0; 
	int index2 = TeamsCount-1;
	
	int flag = 0;
	int color_code = 0;
	
	for (int r = 0; r < row; r++){
		
		
		
		
		if (r != 0) {
			
			for (int c = column-1; c >= 0; c--){
			Teams[r][c] = teamsArray[index]; 
			Teams2[r][c] = teamsArray[index2]; 
			
			index++;
			index2--;
			}	 //end of loop
			
		}
		
		
		else {
			
			c_start = 0; 
			c_end = column;
			
			
			for (int c = c_start; c < c_end; c++){
				
				Teams[r][c] = teamsArray[index];
				Teams2[r][c] = teamsArray[index2]; 
				index++;
				index2--;
				
			
				
			}	//end of loop
													
			
			
		}
		
		
		
		
		
		
		
	
		
	}
	
	
	flag++;
	
	cout << "\n\n\t\t\t\t\t\tROUND " << flag << "\n\n";
	
	
		for (int r = 0; r < TeamsCount/2; r++){
		
		
		
			cout <<  "\t\t\t\t" << Teams[0][r] << " vs " << Teams[1][r];
			
			cout << "\n";	
		
	}

	
	
	
	
	
	
	
	//The Logic
	
	repeatLogic:
	
	end_b = Teams[0][column-1];
	end_c = Teams[1][0];
		

	
	for (int r = 0; r < row; r++){
		
		
		
		
		if (r != 0) {
			
			c_start = 0; 
			c_end = column-1;
			
			
			for (int c = c_start; c < c_end; c++)	
													Teams[r][c] = Teams[r][c+1];
			
			
		}
		
		
		else {
			
			for (int c = column-1; c >= 1; c--)	
													Teams[r][c] = Teams[r][c-1];
			
		}
		
		
		
		
	
		
	}
	
	
		Teams[0][1] = end_c;
		
	
		
		Teams[1][column-1] = end_b;
		
	
	flag++;
	color_code++;
	
	if(color_code>15) color_code = 1;
	
	design.setFontColor(color_code);
	cout << "\n\n\t\t\t\t\t\tROUND " << flag << "\n\n";
	
		
	for (int r = 0; r < TeamsCount/2; r++){
		
		
		
			cout <<  "\t\t\t\t" << Teams[0][r] << " vs " << Teams[1][r];
			
			cout << "\n";	
		
	}
	
	
	if ((TeamsCount-2)!=flag)
			goto repeatLogic;
				
	
	
	
	flag++;
	color_code++;
	if(color_code>15) color_code = 1;
	design.setFontColor(color_code);
	
	cout << "\n\n\t\t\t\t\t\tROUND " << flag << "\n\n";
	
	
		for (int r = 0; r < TeamsCount/2; r++){
		
		
		
			cout <<  "\t\t\t\t" << Teams2[0][r] << " vs " << Teams2[1][r];
			
			cout << "\n";	
		
	}
	
	
	
	repeatLogic2:
	
	end_b = Teams2[0][column-1];
	end_c = Teams2[1][0];
		
	//cout << end_b;
	
	for (int r = 0; r < row; r++){
		
		
		
		
		if (r != 0) {
			
			c_start = 0; 
			c_end = column-1;
			
			
			for (int c = c_start; c < c_end; c++)	
													Teams2[r][c] = Teams2[r][c+1];
			
			
		}
		
		
		else {
			
				for (int c = column-1; c >= 1; c--)	
													Teams2[r][c] = Teams2[r][c-1];
			
		}
		
		
		
		
	
		
	}
	
	
		Teams2[0][1] = end_c;
		
	Teams2[1][column-1] = end_b;
		
		
		// string temp = Teams2[0][column-1];
		//Teams2[0][column-1] = Teams2[1][column-1];
	//	Teams2[1][column-1] = temp;
	
	flag++;
	color_code++;
	
	if(color_code>15) color_code = 1;
	
	design.setFontColor(color_code);
	cout << "\n\n\t\t\t\t\t\tROUND " << flag << "\n\n";
	
		
	for (int r = 0; r < TeamsCount/2; r++){
		
		
		
			cout << "\t\t\t\t" << Teams2[0][r] << " vs " << Teams2[1][r];
			
			cout << "\n";	
		
	}
	
	
	if (((TeamsCount*2)-2)!=flag)
			goto repeatLogic2;
	
	
	
	
	display.showExtraOptions();
	
	if( option == 0)
			display.mainMenu();
	
	else if(option == -1) display.ExitApp();
	
	else {
		
		display.showInvalidOptionSelectedError();
		Start();
		
	}
	
	
	
}



int ScheduleGenerator::countTeams(){
	
		const char* dirLocation = "Database/Teams/";
			
			static DIR *dir;
			
			struct dirent *ent;
			
			int count = 0;
			
			
			if ((dir = opendir (dirLocation)) != NULL) {
  			/* print all the files and directories within directory */
  			while ((ent = readdir (dir)) != NULL) {
  				
  					if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0 )
					  {
					  
  						
  						char title[50];
  						strcpy (title,ent->d_name);
  						teamsArray[count] = title;
  						count++;
  						
  					
    			}
    				
    				
    				
  				}
  			
			  closedir (dir);
			} else {
 
 						
 						cout << "Error";
 						exit(1);
 
				}
	
	return count;
}
