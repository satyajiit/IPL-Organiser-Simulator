#include "addStadium.h"
#include "../ExternVariables/global.h"
#include "../ExternVariables/global_display_object.h"
#include <dirent.h>
#include <iostream>
#include <fstream>
#include "../Modules/ManageClass.h"


void addStadium::start(){
	
	system("cls");
	
	design.setTitle("Add Stadium");
	
	design.TopDesign("\t\tADD STADIUM");
	
	char stream[400];
	cout << "\n\n\tEnter Stadium Name : ";
	
	
	cin >> stream;
	
	fstream file; 
	
	cin.ignore();
	
	 file.open("Database/Stadiums/data.std",ios::app); 
	 
	  if(!file) 
   { 
   
   		
   		cout << "ERROR";
      
      
   } 
  else {
  	
  	file << "\n" << stream;
  	
  	cout << "\n\tSuccess!!";
  	
  	file.close();
   		
   		check:
   		
   		design.setFontColor(6);
   		cout << "\n\n\t 1 -> ADD MORE";
   		display.showExtraOptions();
   		
   		
   		if(option==-1) display.ExitApp();
   		
   		else if(option==0){
   			
   			ManageClass ob;
			ob.Start();
   		}
   		
   		else if(option==1){
   			start();
   			
		   }
   		
   		else {
   			
   			display.showInvalidOptionSelectedError();
   			goto check;
   			
		   }
   		
  	
  }
	
}

