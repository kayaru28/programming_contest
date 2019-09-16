#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
//#include <stack>
//#include <queue>
#include <iomanip>

/*
#include <math.h>
*/
int standerd = 1000000007;
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 
int main(){

    int N;
    int M;
    cin >> N;
    cin >> M;

    vector<int> S;
    vector<int> T;
    int tmp;    
    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> tmp;
        S.push_back(tmp);
    }
    for( int ni = 0 ; ni < M ; ni++ ){
        cin >> tmp;
        T.push_back(tmp);
    }

    long long dp[N][M]={};
    for( int ni = N-1 ; ni >= 0 ; ni-- ){
        for( int mi = M-1 ; mi >= 0 ; mi-- ){

            if(ni < N-1 && mi < M-1){
                dp[ni][mi]+= dp[ni][mi+1] + dp[ni+1][mi] - dp[ni+1][mi+1];

                if( S[ni]==T[mi] ){
                    dp[ni][mi]+= 1 + dp[ni+1][mi+1];
                }


            }else if(ni==N-1 && mi==M-1){
                if(S[ni]==T[mi]) dp[ni][mi]+= 1;

            }else if(ni==N-1){
                if(S[ni]==T[mi]){
                    dp[ni][mi]+= 1 + dp[ni][mi+1];
                }else{
                    dp[ni][mi]+= dp[ni][mi+1];
                }
            }else if(mi==M-1){
                if(S[ni]==T[mi]){
                    dp[ni][mi]+= 1 + dp[ni+1][mi];
                }else{
                    dp[ni][mi]+= dp[ni+1][mi];
                }
            }

            dp[ni][mi] = dp[ni][mi] % standerd;
            //cout << "ni:" << ni << "\tmi:" << mi   << "\t= " << dp[ni][mi] << endl;
        }
    }

    cout << (dp[0][0] + 1) % standerd;

}