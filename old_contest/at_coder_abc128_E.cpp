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


int N_construction;
int N_passerby;

int main(){

    cin >> N_construction;
    cin >> N_passerby;

    int const_X[N_construction];
    int const_S[N_construction];
    int const_T[N_construction];

    for( int ni = 0 ; ni < N_construction ; ni++ ){
        cin >> const_S[ni];
        cin >> const_T[ni];
        cin >> const_X[ni];
    }

    int progress[1000000000];


}