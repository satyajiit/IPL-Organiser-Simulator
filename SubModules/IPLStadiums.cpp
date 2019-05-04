#include "IPLStadiums.h"
#include "../ExternVariables/global.h"
#include "../ExternVariables/global_display_object.h"
#include "../Modules/AccessInfoClass.h"
#include <fstream>

void IPLStadiums::Start(){
	
	system("cls");
	
	design.setTitle("Stadiums");
	
	design.TopDesign("\t\tALL AVAILABLE STADIUMS");
	
	showStadiums();	
	
	showUserSelection();
}

void IPLStadiums::showUserSelection(){
	
	
	display.showExtraOptions();
	
	
	system("cls");
	
	 if ( option == -1) display.ExitApp();
	
	else if(option == 0) {
		
			AccessInfoClass ob;
			ob.Start();
	
	}
					
	else {
	
		display.showInvalidOptionSelectedError();
		
		Start();
	
	}



}

void IPLStadiums::showStadiums(){
	
	
	char ch[30] = "Database/Stadiums/data.std";
	cout << "\n";
	readFile(ch);
	
	
}


void IPLStadiums::readFile(char FILENAME[45]){
	
	string line;
	int count = 2;
	ifstream myfile (FILENAME);
	
  if (myfile.is_open())
  {
    while ( getline (myfile,line) )
    {
    	design.setFontColor(count);
      	cout << "\n\t- > " << line << "\n";
      	count++;
    }
    myfile.close();
  }

  else cout << "Unable to open file"; 
	
}

