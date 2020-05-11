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

#include <math.h>
//#include <stack>
//#include <queue>

/*
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

#define MAXV 1000000

ll VALM[MAXV]={};
ll VALP[MAXV]={};
ll C;
ll N;
ll M;
ll K;

int main(){

    cin >> N;
    ll H[N+1];
    for( int ni = 1 ; ni <=N ; ni++ ){
        ll tmp;
        cin >> tmp;
        H[ni]=tmp;
    }

    ll cnt=0;
    for( int ni = N ; ni >=1 ; ni-- ){
        ll hi = H[ni];
        if(hi<MAXV){
            if(ni+hi<MAXV){
                VALP[ni+hi]++;
                cnt+=VALM[ni+hi];
            }
            if(ni-hi>=0){
                VALM[ni-hi]++;
            }
        }
    }

    cout << cnt << endl;
    

}