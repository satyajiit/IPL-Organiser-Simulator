#include "ShowUmpires.h"
#include "../ExternVariables/global.h"
#include "../ExternVariables/global_display_object.h"
#include <iostream>
#include <fstream>
#include <dirent.h>
#include "../Modules/AccessInfoClass.h"


string Umpires[50][2];

int flag = 1;

void ShowUmpires::Start(){
	
	system("cls");
	
	design.setTitle("Umpires Information");
	
	design.TopDesign("\t\tALL UMPIRES INFORMATION");
	
	showUmpires();	
	
	showUserSelection();
	
}

void ShowUmpires::showUmpires(){
			
			cout << "\n\n";
			
			char ch[25] = "Database/Umpires/";
			
    		fetchFolders(ch);
    		
    		design.setFontColor(15);
				
}


void ShowUmpires::fetchFolders(const char* dirLocation){
	
			
			static DIR *dir;
			
			struct dirent *ent;
			
			 flag = 1;
			
			static string hope = "";
			
			char location[20][20];
			
			cout << "\t[ Umpires AVAILABLE ] \n";
			
			if ((dir = opendir (dirLocation)) != NULL) {
  			/* print all the files and directories within directory */
  			while ((ent = readdir (dir)) != NULL) {
  				
  					if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0 ){
					  
  						
  						
  						
  						design.setFontColor(flag);
  						
  						char title[50];
  						
  						strcpy (title,ent->d_name);
  						
  						char ch[20] = "Database/Umpires/";
  						
  						 char temp[20];
  						 
						   strcpy(temp,ent->d_name);
  						
  						string s = title;
  						
  						
  						
  						s = s.replace(s.end()-4,s.end(),4,' ');
  						
  						cout << "\n\t" << flag << " : " << s << "\n";
  						
  						strcat (ch,temp);
  						  
  						  
  						Umpires[flag][0] = s;
  						Umpires[flag][1] = ch;
  						  
  						  
  						  
  						  
  						
  						flag++;
  						
  						
  						
  						
  						
					  }
    				
    				
    				
    				
  				}
  			
			  closedir (dir);
			} else {
 
 						
 						cout << "Error";
 						exit(1);
 
				}
	
	
}

void ShowUmpires::showUserSelection(){
	
	
	
	display.showExtraOptions();
	
	
	system("cls");
	
	if ( option >= flag || option < -1) {
		
		display.showInvalidOptionSelectedError();
		
		flag = 1;
		
		Start();
	}
	else if ( option == -1) display.ExitApp();
	
	else if(option == 0) {
		
			flag = 1;
			AccessInfoClass ob;
			ob.Start();
	
	}
					
	else {
	
	retry:
	
	
	string title = Umpires[option][0];
	
	
	design.setTitle(title);
	
	design.TopDesign("\t\t"+title);
	
	int temp = option;
	
	cout << "\n";
	
	design.setFontColor(option);
	
	char ch[50];
	
	strcpy (ch, Umpires[option][1].c_str());
	
	display.readFile(ch);
	
	
	display.showExtraOptions();

	
	if (option == 0) {
		flag = 1;
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
