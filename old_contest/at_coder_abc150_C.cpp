#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
#include <vector>
#define rep(i,n) for (ll i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define base10_4 10000      //1e4
#define base10_5 100000     //1e5
#define base10_6 1000000    //1e6
#define base10_7 10000000   //1e7
#define base10_8 100000000  //1e8
#define base10_9 1000000000 //1e9

#define MOD 1000000007
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

//#include <stack>
//#include <queue>

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

vll A;
vll B;
ll C;
ll N;
ll M;
ll K;

ll cntA[10]={};
ll cntB[10]={};

ll ltmp;
string stmp;
double dtmp;

vector<ll> inv,fact,invfact;
void setupCombination(ll n_max,ll mod){
    fact.resize(n_max+1);
    inv.resize(n_max+1);
    invfact.resize(n_max+1);
    fact[0]=inv[0]=invfact[0]=1;
    inv[1]=1;
    for(ll i=0;i<n_max;i++){
        fact[i+1]=fact[i]*(i+1)%mod;
        if(i>0)inv[i+1]=mod-inv[mod%(i+1)]*(mod/(i+1))%mod;
        invfact[i+1]=invfact[i]*inv[i+1]%mod;
    }
}
ll getCombination(ll n,ll k,ll mod){
    if(n<0||k<0||k>n)return 0;
    return (fact[n]*invfact[n-k]%mod)*invfact[k]%mod;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    setupCombination(10,MOD);

    cin >> N;
    rep(ni,N){
        cin >> ltmp;
        A.push_back(ltmp);
    }
    rep(ni,N){
        cin >> ltmp;
        B.push_back(ltmp);
    }

    ll orderA=1,orderB=1;

    for( ll ni = 0 ; ni <=N-2 ; ni++ ){
        for( ll mi = ni+1 ; mi <=N-1 ; mi++ ){
            if(A[ni]>A[mi]) cntA[ni]++;
            if(B[ni]>B[mi]) cntB[ni]++;
        }
    }
    for( ll ni = 0 ; ni <=N-2 ; ni++ ){
        ll value;
        value = cntA[ni];
        orderA += value * fact[(N-1)-ni];
        value = cntB[ni];
        orderB += value * fact[(N-1)-ni];


    }

    //cout << orderA << endl;
    //cout << orderB << endl;
    cout << abs(orderA-orderB) << endl;




    

}