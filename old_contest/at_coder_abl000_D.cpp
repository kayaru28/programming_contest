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
#define ld long double
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

//#include <stack>
//#include <queue>

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

vll A;
ll B;
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;
map<ll,vll> leng_map;
/*
max 448,000,000
map<string,ll> count_map;
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> K;

    rep(ni,N){
        cin >> ltmp;
        A.push_back(ltmp);
    }
    leng_map[1].push_back(A[N-1]);
    ll leng_max = 1;

    for( ll ni = N-2 ; ni >=0 ; ni-- ){
        ll flag = 0;
        ll leng = 1;
        for( ll li = leng_max ; li >=1 ; li-- ){
            vll values = leng_map[li];
            rep(vi,values.size()){
                ll val = values[vi];
                if(abs(A[ni]-val)<=K){
                    leng = li+1;
                    li = 0;
                    break;
                }
            }
        }
        leng_map[leng].push_back(A[ni]);
        if(leng>leng_max) leng_max = leng;
    }
    cout << leng_max << endl;

}