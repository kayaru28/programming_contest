#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
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

    int N;
    cin >> N;

    if(N==1) cout << ans_Yes;
    else{
        int base = 1;
        int Sn = 0;
        while(base <= N){
            base = base * 10;
            Sn +=  ( N % base ) / (base / 10);
        }

        if(N%Sn==0)    cout << ans_Yes;
        else cout << ans_No;
    }
}