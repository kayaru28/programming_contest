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

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

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

//vector<string> key;

/*
max 448,000,000
*/

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    char S[N];
    map<string,ll> count_map;

    rep(ni,N){
        cin >> S;
        ll count[30]={};

        rep(si,10){
            ll ind = S[si] - 'a';
            count[ind]++;
        }
        string SS = "";
        rep(ci,30) SS = SS + to_string(count[ci]);
        //key.push_back(SS);
        count_map[SS]++;
    }

    ll ans=0;
    for(auto x : count_map) {
        string key = x.first;
        ll value = x.second;
        if(value>=2){
            ans += (value * (value-1) /2);
        }
    }
    cout << ans << endl;
    

    

}