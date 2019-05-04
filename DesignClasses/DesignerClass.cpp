#include "DesignerClass.h"
#include <windows.h>
#include <string>

//Implementaion of Designer Class




void DesignerClass::showText(string msg){



    cout<<"\n\n\t\t\t\t";

		cout << msg;
	
    //cout<<msg;

    cout<<"\n";


}
void DesignerClass::setTitle(string text){
	
	char cmd[50] = "title ";
	
	 strcat(cmd, text.c_str()); 
		
	system(cmd);
	
}

void DesignerClass::showTextCenter(string msg){

    //Shows text in the center of console

    cout<<"\n\t\t\t\t";

    cout<<msg;


}


void DesignerClass::setBorders(int n,char c){

    //Set Borders

    cout<<"\n";

    for (int i = 1; i <= 120; i++ ){

        if (i%n)
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4); //Red Color if i is divisible by 4

        else SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2); //Green Color if i is !divisible by 4

        cout << c;
    }

}


void DesignerClass::setFontColor(int colorID){

    //A member of Windows.h Header
    //GetStdHandle uses Output Handler alternative could be system("color 1e") , which sets console color in DOS/CMD
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);

}


void DesignerClass::showDots(int count){

    //Generate Dots with 1sec interval


    for (int i = 1; i <= count; i++){

        cout << ".";
        system("timeout 1 > Nul");


    }


}

void DesignerClass::TopDesign(string text){
	
	setBorders();  //Sets the border
	
	setFontColor(15);  //Set font Color
	
	showText(text);  //Show message
	
	setBorders(); //Sets the border
	
	setFontColor(11);
	
}





