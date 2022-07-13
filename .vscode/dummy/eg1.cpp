#include<iostream>
#include<sstream>
#include<fstream>
using namespace std;

int main() {
    int rrn_list[100];
    fstream file;
    string buffer;
    int pos,temp=0;
    int count=-1,i=0;
    file.open("text1.txt",ios::in);
    while(!file.eof())
        {
            pos=file.tellg();
            buffer.erase();
            getline(file,buffer);
            rrn_list[++count]=pos;
        }
    file.close();


        if(rrn_list[temp]=='\n') {
    	cout << "\tThere is no Complaint to show\n\t\t\tSo The List is Empty\n\n\n";
    }
    else {
            file.open("text1.txt",ios::in);
            // while(temp!=pos) {
            //     buffer.erase();
            //     file.open("text1.txt");
            //     temp=rrn_list[i];
            //     i++;
            //     file.seekg(temp,ios::beg);
                // getline(file,buffer);
                // cout <<"\t\t\t"<<temp<<buffer<<"\n"; 

                // }

                while(!file.eof())
        {
            pos=file.tellg();
            buffer.erase();
            getline(file,buffer);
            rrn_list[++count]=pos;
            cout <<"\t\t\t"<<pos<<buffer<<"\n";
        }
            file.close();
        }
    }