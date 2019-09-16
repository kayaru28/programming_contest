#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
typedef long long ll;
//#include <stack>
//#include <queue>
#define MOD 1000000007

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 

int main(){

    int N,M;
    cin >> N >> M;

    bool kaidan[100000];
    rep(ni,N+100) kaidan[ni]=true;
    int tmp;
    int dp[100000]={};
    rep(mi,M) { cin >> tmp; kaidan[tmp] = false;   }

    dp[0]=1;
    rep(ni,N){
        //cout << ":" << kaidan[ni+1] << endl;
        if(kaidan[ni+1])  {dp[ni+1]+=dp[ni]; dp[ni+1]%=MOD;}
        if(kaidan[ni+2])  {dp[ni+2]+=dp[ni]; dp[ni+2]%=MOD;}
    }
    //rep(ni,N+1) cout << dp[ni] << endl;
    cout << dp[N] << endl;
}