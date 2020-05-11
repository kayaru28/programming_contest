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

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;

int main(){

    
    cin >> N;
    cin >> K;

    ll d;
    ll MEM[N+1]={};

    rep(ki,K){
        cin >> d;
        rep(di,d){
            int tmp;
            cin >> tmp;
            MEM[tmp]=1;
        }
    }
    ll cnt=0;
    for( int ni = 1 ; ni <=N ; ni++ ){
        if(MEM[ni]==0) cnt++;
    }
    cout << cnt << endl;
}