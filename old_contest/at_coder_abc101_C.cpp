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
    int K;
    cin >> K;

    int A[N];

    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> A[ni];
    }

    if(N==K){
        cout << 1;
    }else{
        if( (N-1) % (K-1) == 0 ){
            cout << (N-1) / (K-1) ;
        }else{
            cout << (N-1) / (K-1) + 1;
        }

    }



}