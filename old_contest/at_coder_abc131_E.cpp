#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
//#include <stack>
//#include <queue>

/*
#include <math.h>
long long standerd = long long(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 


int n_pair;
int N;
int K;


int main(){

    cin >> N;
    cin >> K;

    if( K > (N-1) * (N-2) / 2 ){
        cout << -1 << endl;
    }else{
        int M;
        int diff;
        diff = (N-1) * (N-2) / 2 - K;
        M = (N - 1) + diff;
        cout << M << endl;
        for( int ni = 2 ; ni <= N ; ni++ ){
            cout << "1 " << ni  << endl;
        }
        int count = 0;
        for( int n1 = 2 ; n1 <= N-1 ; n1++ ){
            for( int n2 = n1 + 1 ; n2 <= N  ; n2++ ){
                if(diff > count) cout << n1 << " " << n2 << endl;
                count++;
            }
        }


        
    }


    
}