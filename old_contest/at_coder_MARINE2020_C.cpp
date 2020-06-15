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

ll dvalue[base10_6];
vll dindex;
vll dindextmp;
ll base = 0;
ll N;
ll K;
ll x_[base10_6]={};
ll _x[base10_6]={};
ll ltmp;
string stmp;
double dtmp;

ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> K;

    rep(ni,N){
        cin >> ltmp;
        dvalue[ni]=ltmp;
    }
    rep(ki,K){
        ll cntN = 0;
        rep(ni,N) x_[ni]=0;
        rep(ni,N) _x[ni]=0;
        rep(ni,N){
            ll pos = ni;
            ll rumen = dvalue[ni];
            ll left = llmax(0,pos-rumen);
            ll right = llmin(N-1,pos+rumen);
            _x[left]++;
            x_[right]++;
        }

        ll sta = 0;
        ll fin = 0;
        
        rep(ni,N){
            sta = sta + _x[ni];
            dvalue[ni] = sta-fin;
            if(dvalue[ni]==N) cntN++;
            fin = fin + x_[ni];
        }
        if(cntN==N) break;
    }
    rep(ni,N){
        cout << dvalue[ni];
        cout << " ";
    }


}