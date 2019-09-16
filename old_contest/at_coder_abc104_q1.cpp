#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
//#include <vector>
//#include <stack>
//#include <queue>

/*
#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 

int main(){

    int A;
    cin >> A;

    if(A<1200){
        cout << "ABC";
    }else if(A<2800){
        cout << "ARC";
    }else{
        cout << "AGC";
    }
   

}