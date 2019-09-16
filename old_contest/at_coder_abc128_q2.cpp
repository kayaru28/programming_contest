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

    int N;

    cin >> N;
    string S[N];
    string S2[N];
    int P[N];
    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> S[ni];
        S2[ni]=S[ni];
        cin >> P[ni];
    }
    sort(S2,S2+N);

    int maxv;
    int nmax;
    for( int ni = 0 ; ni <N ; ni++ ){
        maxv = -1;
        nmax = 0; 
        for( int n1 = 0 ; n1 < N ; n1++ ){
            if(S[n1]==S2[ni]){
                if(maxv < P[n1]){
                    maxv = P[n1];
                    nmax = n1;
                }
            }
        }
        cout << nmax+1 << endl;
        P[nmax]=-1;
    }
    
    


}