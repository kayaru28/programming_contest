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

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;

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

ll tmpcount(ll li,ll ri){
    ll cntans=0;

    if(li==ri){
        if(li<=N) cntans++;
    }

    if(li*10+ri<=N) cntans++;

    for( ll base = 100 ; base <=base10_6 ; base=base*10 ){
        if(N >= base*li){
            for( ll bi = 0 ; bi <base/10 ; bi++ ){
                ll val = li * base + bi * 10 + ri;
                if(val<=N) cntans++;
                else break;
            }
        }
    }
    return cntans;

}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    ll cntans = 0;

    for( ll ni = 1 ; ni <=9 ; ni++ ){
        ll tmpcnt = tmpcount(ni,ni);
        cntans += tmpcnt * tmpcnt;
    }
    for( ll li = 1 ; li <=8 ; li++ ){
        for( ll ri = li+1 ; ri <=9 ; ri++ ){
            ll tmpcntl = tmpcount(li,ri);
            ll tmpcntr = tmpcount(ri,li);
            cntans += (tmpcntl * tmpcntr * 2);
        }
    }

    cout << cntans << endl;

}