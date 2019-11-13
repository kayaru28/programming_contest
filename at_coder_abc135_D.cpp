#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

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
 
ll index[1000000][15]={};

int main(){



    string S;
    cin >> S;
    string Sn;
    index[0][0]=1;
    int cnt=1;
    for( int si = 0 ; si < S.length() ;si++ ){
        Sn = S.substr(si,1);

        int target;
        //cout << Sn << endl;
        if(Sn=="?"){
            rep(ii,10){
                rep(jj,13){
                    index[cnt][ (jj * 10 + ii)%13  ] += index[cnt-1][jj]; 
                }
            }
        }else{
            target =  atoi(Sn.c_str());
            rep(jj,13){
                index[cnt][ (jj * 10 + target) % 13  ] += index[cnt-1][jj]; 
            }
        }
        rep(jj,13){
            index[cnt][jj] %= MOD;
        }
        cnt++;
    }
    cout << index[cnt-1][5] << endl;



}