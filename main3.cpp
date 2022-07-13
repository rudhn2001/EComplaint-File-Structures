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

using namespace std;

class complaint {  
    string name,email,subj,desc,location,city,phoneNo, buffer,frrn,stats;

    public:
    void pack(); //done
    void write_to_file(); //done
    void unpack(); //done
    void create_rrn(); //done
    void view_complaint();
    void update_complaint();
    void print_complaint(); //done
    void delete_complaint(); // not needed i believe
    void add_complaint(); //done
    int search(string key);
    int rrn,count;
    int rrn_list[100];
    int rrn_count();
    int list_rrn();

    complaint() {
        stats='pending';
    }



};

/* --------------------------------------FUNCTION TO PACK ALL DATA IN ONE RECORD TO STORE IN FILE-----------------------*/
void complaint::pack() {
    buffer.erase();
    buffer=name+'|'+email+'|'+phoneNo+'|'+city+'|'+subj+'|'+desc+'|'+stats+'$'+'\n';
}

/* --------------------------------------FUNCTION TO UNPACK ALL DATA FROM RECORD TO SHOW IN OUTPUT-----------------------*/
void complaint::unpack() {
    int ch=1,i=0;
    name.erase();
    i++;
    while(buffer[i]!='|')
        name+=buffer[i++];
    email.erase();
    i++;
    while(buffer[i]!='|')
        email+=buffer[i++];
    phoneNo.erase();
    i++;
    while(buffer[i]!='|')
        phoneNo+=buffer[i++];
    city.erase();
    i++;
    while(buffer[i]!='|')
        city+=buffer[i++];
        phoneNo.erase();
    i++;
    while(buffer[i]!='|')
        phoneNo+=buffer[i++];
    subj.erase();
    i++;
    while(buffer[i]!='|')
        subj+=buffer[i++];
    desc.erase();
    i++;
    while(buffer[i]!='|')
        desc+=buffer[i++];
    stats.erase();
    i++;
    while(buffer[i]!='$')
        stats+=buffer[i++];
}

/* --------------------------------------FUNCTION TO write these into file-----------------------*/

void complaint:: write_to_file() {
    
    fstream file;
    file.open("complaint.txt",ios::out|ios::app);
    file<<buffer;
    file.close();

}

/* --------------------------------------FUNCTION TO create a complaint-----------------------*/

void complaint::add_complaint() {
    system("cls");
	cout<<"\n";
    	cout<<"\t\t ================================================\n";
	cout<<"\t\t|   Complaint Registration system |\n";
	cout<<"\t\t ================================================\n\n\n";
	cout <<"\nAdd Complaint Details of Customer\n";
	cout <<"_____________________________________ \n\n";
	cout<< "Enter Customer Name: ";
	cin.ignore();
	getline(cin, name);
	cout<<"Enter your Email : ";
	cin>>email;
    cout<<"Enter your Phone Number : ";
    cin>>phoneNo;
    cout<<"Enter your City : ";
    cin>>city;
    cout<<"Please enter the subject of the complaint(in about 10-20 words) : ";
    cin.ignore();
    getline(cin, subj);
	cout << "Complaint Description:";
	cout<<"( 1000 words maximum ) \n";
	cin.ignore();
	getline(cin, desc);
    create_rrn();
    pack();
    write_to_file();

	cout<<"==========================================================================="<<endl;
    	cout << "Complaint added Successfully"<<endl;
    	cout<<"==========================================================================="<<endl;
}

/* --------------------------------------function to generate rrn for records-----------------------*/

void complaint::create_rrn() {
    ifstream file;
    int pos;
    count=-1;
    file.open("complaint.txt",ios::in);
    while(!file.eof())
        {
            pos=file.tellg();
            buffer.erase();
            getline(file,buffer);
            rrn_list[++count]=pos;
        }
    file.close();
}

/* --------------------------------------function to count rrn-----------------------*/
int complaint::rrn_count() {
        
}

/* --------------------------------------function to Print the complaint-----------------------*/

void complaint::print_complaint() {
    int position=0,choice;
    system("cls");
    string fname;
    fstream outputFile,file1;

    outputFile.open("complaint.txt");





    cout<<"\n";
 	cout<<"\t\t ================================================\n";
 	cout<<"\t\t|   Complaint Management System - TRAVEL AGENCY |\n";
 	cout<<"\t\t ================================================\n\n\n";
 	outputFile<<"\n";
 	outputFile<<"\t\t ================================================\n";
 	outputFile<<"\t\t|   Complaint Management System - TRAVEL AGENCY |\n";
 	outputFile<<"\t\t ================================================\n\n\n";
    cout<<"\n";
	cout<<"---------------------------------------------------------------------------"<<endl;
	cout <<"\t\tHere is the Complaint list\n"; 
	cout<<"---------------------------------------------------------------------------"<<endl;


    if(rrn_list[position]==NULL) {
    	cout << "\tThere is no Complaint to show\n\t\t\tSo The List is Empty\n\n\n";
    }
    else {
            while(!outputFile.eof())
            {
                position=outputFile.tellg();
                buffer.erase();
                unpack();
                getline(outputFile,buffer);
                rrn_list[++count]=position;
                cout <<"\t\t\t"<<position<<"."<<"\t"<<subj<<"\n";
            }
        	cout<<"---------------------------------------------------------------------------"<<endl;
	        cout <<"\t\tEnter the Complaint number associated with the subject : "; 
	        cout<<"---------------------------------------------------------------------------"<<endl;
            cin>>choice;
            buffer.erase();
            position=rrn_list[choice];
            outputFile.seekg(position,ios::beg);
            getline(outputFile,buffer);
            unpack();

            frrn=to_string(position);
            fname=frrn+name+"complaint";
            file1.open(fname);
		        cout <<"Complaint Number : "<<position;
				file1 << "Complaint Number : "<<position << endl;
				cout <<"\n";
				cout<<"Customer Name: "<<name<<endl;
				file1 << "Customer Name: "<<name<<endl;
				cout<<"Email : "<<email<<endl;
				file1 << "Email : "<<email<<endl;
            	cout<<"Contact Number : "<<phoneNo<<endl;
				file1 << "Contact Number : "<<phoneNo<<endl;
            	cout<<"City : "<<city<<endl;
				file1 << "City : "<<city<<endl;
				cout<<"____________________________________________________________________________"<<endl;
				file1 << "____________________________________________________________________________"<<endl;
				cout<<"Complaint Subject: "<<endl;
				file1 << "Complaint Subject: "<<endl;
				cout<<"----------------------"<<endl;
				file1<<"------------------------------------------------------------------------------"<<endl;
				cout<< subj;
				file1 << subj<<endl; 
				cout <<"\n";
				cout<<"____________________________________________________________________________"<<endl;
				file1 << "____________________________________________________________________________"<<endl;
                				cout<<"____________________________________________________________________________"<<endl;
				file1 << "____________________________________________________________________________"<<endl;
				cout<<"Complaint Description: "<<endl;
				file1 << "Complaint Description: "<<endl;
				cout<<"----------------------"<<endl;
				file1<<"------------------------------------------------------------------------------"<<endl;
				cout<< desc;
				file1 << desc<<endl; 
				cout <<"\n";
				cout<<"____________________________________________________________________________"<<endl;
				file1 << "____________________________________________________________________________"<<endl;
            	cout<<"----------------------"<<endl;
            	cout<<"Status: "<<stats;
				file1 << "Status: "<<stats<<endl;

				file1<<"------------------------------------------------------------------------------"<<endl;
            outputFile.close();
            file1.close();
    }
}

/* --------------------------------------MAIN MENU OF THE PROGRAM-----------------------*/

int main_menu() {
    int choice;
    system("cls");
	cout<<"\n";
    	cout<<"\t\t ================================================\n";
	cout<<"\t\t|   Complaint Management System - TRAVEL AGENCY |\n";
	cout<<"\t\t ================================================\n\n\n";

	cout<<"\t\t-------------------------------------------------\n";
	cout<<"\t\t|\t1. Customer \t\t\t\t|\n";
	cout<<"\t\t-------------------------------------------------\n";
	cout<<"\t\t-------------------------------------------------\n";
	cout<<"\t\t|\t2. Administrator \t\t\t|\n";
	cout<<"\t\t-------------------------------------------------\n";
	cout<<"\t\t-------------------------------------------------\n";
	cout<<"\t\t|\t3. EXIT \t\t\t\t|\n";
	cout<<"\t\t-------------------------------------------------\n\n";
    cout<<"\t\tInput number associated with your user type (or 3 to exit) :  ====> ";
    choice=getch();
    return choice;
}

/* --------------------------------------ADMIN MENU OF THE PROGRAM-----------------------*/

int admin_menu() {
    complaint admin;
    int menu;
    string userName, userPassword;
	system("cls");
	cout<<"\n";
    	cout<<"\t\t ===================================================\n";
	cout<<"\t\t|   Complaint Registration - Admin Menu     |\n";
	cout<<"\t\t ===================================================\n\n\n";
    	cout<<"\t\t----------------------------------------------------\n";
    	cout<<"\t\t\t  Administrator / Staff Login      \n";
    	cout<<"\t\t----------------------------------------------------\n\n";
    	cout << "\n\n\t\tPlease enter your user name: ";
    	cin >> userName;
    	cout << "\n\n\t\tPlease enter your user password: ";
    	cin >> userPassword;

    	if ((userName == "rudh" && userPassword == "80000") || (userName == "shankar" && userPassword == "shoes") )
    	{  
            while(1)
            {
                system("cls");
                    cout<<"\n";
                    cout<<"\t\t ===================================================\n";
                cout<<"\t\t|   Complaint Registration - Admin Menu    |\n";
                cout<<"\t\t ===================================================\n\n\n";
                cout<<"\t\t--------------------------------------------------\n";
                cout<<"\t\t||\t1. View Complaint\t\t\t ||\n";
                cout<<"\t\t||\t2. Update Complaint Status \t\t ||\n";
                cout<<"\t\t||\t3. Print the complaint \t\t\t ||\n";
                cout<<"\t\t||\t4. Delete a Complaint \t\t\t ||\n";
                cout<<"\t\t||\t5. Logout\t\t\t\t ||\n";
                cout<<"\t\t--------------------------------------------------\n";
                cout<<"Enter choice: ";
                cin>>menu;
                switch (menu)
                {
                case 1 :admin.view_complaint();
                        break;
                case 2 :admin.update_complaint();
                        break;
                case 3 :admin.print_complaint();
                        break;
                case 4 :admin.delete_complaint();
                        break;
                case 5 :
                		cout<<"You are Logged Out...!\n\n\n\n";
				        system ("PAUSE");
				        return 0;
				        break;
              default:
                    cout << "\n\n\t\tInvalid input. Please try again.\n" << '\n';
                    system("PAUSE");
                    system ("cls");
                    admin_menu();
                    break;
                }
            }
        }
        	else
	        {
                    cout << "\n\n\t\tInvalid login attempt. Please try again.\n" << '\n';
                system("PAUSE");
                system ("cls");
                admin_menu();
            }
            
}

/* --------------------------------------CUSTOMER MENU OF THE PROGRAM-----------------------*/

int customer_menu() {
    complaint customer;
    int menu;

	system("cls");
	cout<<"\n";
    	cout<<"\t\t ===================================================\n";
	cout<<"\t\t|   Complaint Registration - Customer Menu     |\n";
	cout<<"\t\t ===================================================\n\n\n";
    	cout<<"\t\t----------------------------------------------------\n";  
            while(1)
            {
                system("cls");
                    cout<<"\n";
                    cout<<"\t\t ===================================================\n";
                cout<<"\t\t|   Complaint Registration - Customer Menu    |\n";
                cout<<"\t\t ===================================================\n\n\n";
                cout<<"\t\t--------------------------------------------------\n";
                cout<<"\t\t||\t1. Add a Complaint\t\t\t ||\n";
                cout<<"\t\t||\t2. Print a complaint \t\t\t ||\n";
                cout<<"\t\t||\t3. View all Complaints \t\t\t ||\n";
                cout<<"\t\t||\t4. Logout\t\t\t\t ||\n";
                cout<<"\t\t--------------------------------------------------\n";
                cout<<"Enter choice: ";
                cin>>menu;
                switch (menu)
                {
                case 1 :customer.add_complaint();
                        break;
                case 2 :customer.print_complaint();
                        break;
                case 3 :customer.view_complaint();
                        break;
                case 4 :
                        cout<<"-------------------THANK YOU, HAVE A GOOD DAY----------------";
				        system ("PAUSE");
				        return 0;
				        break;
              default:
                        cout << "\n\n\t\tInvalid input. Please try again.\n" << '\n';
                system("PAUSE");
                system ("cls");
                customer_menu();
                    break;
                }
            }
}


/* --------------------------------------MAIN FUNCTION OF THE PROGRAM-----------------------*/

int main() {

    system("color 02");
    complaint comp;
    int ch;

    while (1)
    {
        comp.create_rrn();
        ch=main_menu();
        switch (ch)
        {
        case 1:
            admin_menu();
            break;
        case 2:
            customer_menu();
            break;
        case 3:
            cout<<"-------------------THANK YOU, HAVE A GOOD DAY----------------";
            sleep(3000);
            exit(0);
        default:
            cout<<"++++++++++++++++++++++++++++INVALID INPUT!!!!! TRY AGAIN++++++++++++++";
        }
    }

    return 0;
    
    
}