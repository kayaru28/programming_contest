#include  <iostream>
#include  <stdio.h>
using namespace std;


int main(){

    string b;
    cin >> b;
    if(b == "A"){
        cout << "T";
    }else if(b=="T"){
        cout << "A";
    }else if(b=="C"){
        cout << "G";
    }else{
        cout << "C";
    }

    return 0;
}