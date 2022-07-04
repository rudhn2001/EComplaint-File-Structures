#include <iostream>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
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





 int main(){}