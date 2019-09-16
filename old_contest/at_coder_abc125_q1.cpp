#include  <iostream>
#include  <stdio.h>
#include <algorithm>
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

    int A;
    int B;
    double Z;
    
    cin >> A;
    cin >> B;
    cin >> Z;

    int count = 0;
    int number = 1;
    while(A * number <= Z + 0.5){
        count = count + B;
        number++;
    }


    cout << count;
    

}