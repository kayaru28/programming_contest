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

    int D;
    int N;
    
    cin >> D;
    cin >> N;

    int bet = 1;
    for( int di = 0 ; di < D ; di++ ){
        bet = bet * 100;
    }

    if(N<100)    cout << bet * N << endl;
    else    cout << bet * (N + 1) << endl;
    

}