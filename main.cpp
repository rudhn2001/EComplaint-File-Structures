<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <string>
#include<sstream>
#include <stdlib.h>
#include <conio.h>
#include<stdio.h>
#include<windows.h>
#include<unistd.h>
#include <bits/stdc++.h>
#include <rrn.h>
#include<hash.h>

using namespace std;

class complaint {
	string name,email,subject,desc,location,city,phoneNo, buffer;
	void readData();
    void pack();
	void write_to_file();
};
/*=============================Read the input from the user==========================*/
void complaint::readData() {         // to read all the input from the user
    
    cout<<"==== Enter your Name : ";
    cin>>name;
    cout<<"==== Enter your Phone Number : ";
    cin>>phoneNo;
    cout<<"==== Enter yor Email : ";
    cin>>email;
        cout<<"==== Enter the location : ";
    cin>>location;
    cout<<"==== Enter the city : ";
    cin>>city;
    cout<<"==== Enter the subject of the complaint : ";
    cin>>subject;
    cout<<"====== Enter the complaint description in less than 100 words ====== \n";
    getline(cin,desc);
    
}
/*============================all the input pack it into one string========================*/
void complaint:: pack() {
    buffer.erase();
    buffer=name+'|'+phoneNo+'|'+email+'|'+location+'|'+city+'|'+subject+'|'+desc+'$'+'\n';
}

/*=============================write that input into yhe file=============*/

void complaint:: write_to_file(){
    fstream file;
    file.open("complaint.txt",ios::out|ios::app);
}





 int main(){}



=======
#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <graphics.h>
#include <bits/stdc++.h>
using namespace std;

class file {
	string name,email,subject,desc,location,city, buffer;
	long int phoneNo;
	void readData();
    void pack();
	
};

void file::readData() {         // to read all the input from the user
    
    cout<<"==== Enter your Name : ";
    cin>>name;
    cout<<"==== Enter your Phone Number : ";
    cin>>phoneNo;
    cout<<"==== Enter yor Email : ";
    cin>>email;
        cout<<"==== Enter the location : ";
    cin>>location;
    cout<<"==== Enter the city : ";
    cin>>city;
    cout<<"==== Enter the subject of the complaint : ";
    cin>>subject;
    cout<<"====== Enter the complaint description in less than 100 words ====== \n";
    getline(cin,desc);
    
}

void file:: pack() {
    buffer.erase();
    buffer+=name+"|"+phoneNo+"|"+email+"|"+location+"|"+city+"|"+subject+"|"+desc+"$";
}





 int main(){
 
     int ch, i, j;

     return 0;
 }


 void user() {
     int choice;
     while (1) {
         cout << "==============Are you a=============\n";
         cout << "1.Customer?\n";
         cout << "2.Admin?\n";
         cin >> choice;
         switch (choice) {
         case 1: customer();
             break;
         case 2: admin();
             break;
         default: cout << "not a valid option, try again.......";
             break;
         }
     }
 }



 void password(string pass) {

 }
>>>>>>> 9235790cba052d6c653b209543ca217a436707ab
