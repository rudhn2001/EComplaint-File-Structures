#include<iostream>
#include<string.h>
#include<sstream>
using namespace std;

int main() {
    string a;
    int b=12;
    ++b;
    cout<<"b: "<<b;
    a= to_string(b);
    cout<<"A"<<a;

    return 0;
}