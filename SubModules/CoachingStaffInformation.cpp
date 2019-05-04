#include "CoachingStaffInformation.h"
#include "../ExternVariables/global.h"
#include "../ExternVariables/global_display_object.h"
#include <dirent.h>
#include <iostream>
#include <fstream>
#include "../Modules/AccessInfoClass.h"



using namespace std;

	string staff[50][2];
	int counter = 1;
	int stf = 0;


void CoachingStaffInformation::Start(){
	
	system("cls");

	design.setTitle("Staff Information");
	
	design.TopDesign("\t\tALL STAFF INFORMATION");
	
	showStaff();	
	
	showUserSelection();
	
}
void CoachingStaffInformation::showUserSelection(){
	
	
	display.showExtraOptions();
	
	
	system("cls");
	
	if ( option > counter-1 || option < -1) {
		
		display.showInvalidOptionSelectedError();
		counter = 1;
		Start();
	}
	else if ( option == -1) display.ExitApp();
	
	else if(option == 0) {
			counter = 1;
			AccessInfoClass ob;
			ob.Start();
	
	}
					
	else {
	
	retry:
	
	string title = staff[option][0];
	
	title = title.replace(title.end()-6,title.end(),6,' ');
	
	design.setTitle("Information about "+title);
	
	design.TopDesign("\t\t"+title);
	
	char location[50] = "Database/Teams/";
	
	strcat (location, staff[option][1].c_str());
	
	strcat (location, "/Coaching staff/");
	
	char suffix[200];
	
	strcpy (suffix, staff[option][0].c_str());
	
	int temp = option;
	
	strcat (location, suffix);
	
	cout << "\n";
	
	design.setFontColor(option);
	
	display.readFile(location);
	
	
	display.showExtraOptions();

	
	if (option == 0) {
	counter = 1;
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
void CoachingStaffInformation::showStaff(){
			
			cout << "\n\n";
			
			char ch[25] = "Database/Teams/";
			
    		fetchFolders(ch);
    		
    		design.setFontColor(15);
				
}



 void CoachingStaffInformation::fetchFolders(const char* dirLocation){
	
			
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
  						  strcat (ch,"/Coaching staff/");
  						
  						
  						fetchFiles(ch,title);
  						
  						stf  = 0;
  						
  						
					  }
    				
    				count++;
    				
    				
  				}
  			
			  closedir (dir);
			} else {
 
 						
 						cout << "Error";
 						exit(1);
 
				}
	
	
}

void CoachingStaffInformation::fetchFiles(const char* dirLocation2,string name){
	
		
			
			DIR *dir2;
			
			struct dirent *ent2;
			
			int count = 1;
			
			
			
			if ((dir2 = opendir (dirLocation2)) != NULL) {
  			/* print all the files and directories within directory */
  			while ((ent2 = readdir (dir2)) != NULL) {
  				
  							if (strcmp(ent2->d_name, ".") != 0 && strcmp(ent2->d_name, "..") != 0 ){
  						
  						if (stf == 0) cout << "\n\tSTAFF OF "<< name << " : \n\n";
						  
						  stf++;
						  	
						string s = ent2->d_name;
						staff[counter][0]=s;
						staff[counter][1]=name;
  						s = s.replace(s.end()-6,s.end(),6,' ');
  						cout << "\t" << counter << " : " << s << "\n";
  						
  						counter++;
  						
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





