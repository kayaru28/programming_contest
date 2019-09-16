#include  <iostream>
#include  <stdio.h>
using namespace std;


int main(){

    string S;
    string yyyymmdd;
    int yyyymmdd_int;

    cin >> S;
    yyyymmdd = S.substr(0,4);
    yyyymmdd = yyyymmdd + S.substr(5,2);
    yyyymmdd = yyyymmdd + S.substr(8,2);

    yyyymmdd_int = atoi(yyyymmdd.c_str());
    
    if(yyyymmdd_int<=20190430){
        cout << "Heisei";
    }else{
        cout << "TBD";
    }

}