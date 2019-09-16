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

    int N;
    cin >> N;

    int V[N],C[N];

    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> V[ni];
    }
    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> C[ni];
    }

    int ans=0;
    for( int ni = 0 ; ni < N ; ni++ ){
        if(V[ni]-C[ni]>0){
            ans = ans + V[ni]-C[ni];
        }
    }


    cout << ans;    

}