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

ll N;
ll K;
ll MAX=110000;
ll sum=0;


ll getPower(ll value,ll shisu){
    ll ans = 1;
    ll cnt = shisu;
    while(cnt>0){
        if(cnt%2==1){
            ans = ans * value % MOD;
        }
        value = value * value % MOD;
        cnt = cnt/2;
    }
    return ans;
}

int main(){


    ll cnt[MAX]={};
    ll ans[MAX]={};
    cin >> N;
    cin >> K;

    ll baisu;
    for( ll index = K ; index >1 ; index-- ){
        baisu = K / index;
        ans[index] = getPower(baisu,N);
        for( int aft_index = 2 ; aft_index <=baisu ; aft_index++ ){
            ans[index]-=ans[index*aft_index];
        }
    }

    sum = getPower(K,N) % MOD;
    for( ll index = 2 ; index <= K ; index++ ){
        sum += (index - 1 ) * ans[index];
        sum %= MOD;
    }
    cout << sum << endl;
}