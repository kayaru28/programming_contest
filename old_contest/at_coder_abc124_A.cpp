#include  <iostream>
#include  <stdio.h>
using namespace std;

/*
#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 

int main(){

    int A_int;
    int B_int;
    int C_int;

    cin >> A_int;
    cin >> B_int;
    

    C_int = 0;
    if(A_int > B_int){
        C_int = C_int + A_int;
        A_int = A_int - 1;
    }else{
        C_int = C_int + B_int;
        B_int = B_int - 1;
    }

    if(A_int > B_int){
        C_int = C_int + A_int;
        A_int = A_int - 1;
    }else{
        C_int = C_int + B_int;
        B_int = B_int - 1;
    }

    cout << C_int;
    

}