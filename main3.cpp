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
    string name,email,subj,desc,location,city,phoneNo, buffer,frrn;

    public:
    void pack(); //done
    void write_to_file(); //done
    void unpack();
    void create_rrn(); //done
    void view_complaint();
    void update_complaint();
    void print_complaint();
    void delete_complaint();
    void add_complaint(); //done
    int search(string key);
    int rrn;




};

/* --------------------------------------FUNCTION TO PACK ALL DATA IN ONE RECORD TO STORE IN FILE-----------------------*/
void complaint::pack() {
    buffer.erase();
    buffer=frrn+'|'+name+'|'+email+'|'+phoneNo+'|'+city+'|'+subj+'|'+desc+'$'+'\n';
}

/* --------------------------------------FUNCTION TO UNPACK ALL DATA FROM RECORD TO SHOW IN OUTPUT-----------------------*/
void complaint::unpack() {
    int ch=1,i=0;
    frrn.erase();
    while(buffer[i]!='|')
        frrn+=buffer[i++];
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
    while(buffer[i]!='$')
        desc+=buffer[i++];
}

/* --------------------------------------FUNCTION TO write these into file-----------------------*/

void complaint:: write_to_file() {
    
    fstream file;
    file.open("3.txt",ios::out|ios::app);
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

void complaint::create_rrn() {
    int rrn=0;
    rrn=rrn+1;
    frrn=to_string(rrn);
}

/* --------------------------------------MAIN MENU OF THE PROGRAM-----------------------*/

int main_menu() {
    int choice;
    system("cls");
    gotoxy(16,4);
    printf("*****  E-Complaint Registration System ***** ");
    gotoxy(12,6);
    cout<<"Press  1. ----> ADMIN.";
    gotoxy(12,8);
    cout<<"Press  2. ----> Customer.";
    gotoxy(12,18);
    cout<<"Press  3. ----> Quit Program.";
    gotoxy(16,22);
    cout<<"Input number associated with your user type (or 3 to exit) :  ====> ";
    cin>>choice;
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
            gotoxy(16,22);
            sleep(3000);
            exit(0);
        default:
            cout<<"++++++++++++++++++++++++++++INVALID INPUT!!!!! TRY AGAIN++++++++++++++";
            gotoxy(16,22);
        }
    }

    return 0;
    
    
}