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

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;
vector<string> S,T;

ll ltmp;
string stmp;
double dtmp;

map<string,ll> cT,cS;

map<string,ll> countT,countS;
ll d[base10_4][base10_4]={};
ll dSUM[base10_4][base10_4]={};
ll getMod(ll value,ll mod){
    if(value == 0) return 0;
    if(mod==0) return -1;
    value %= mod;
    if(value<0) value += mod;
    return value;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;
    S.push_back("t");
    T.push_back("s");
    rep(ni,N){
        cin >> stmp;
        S.push_back(stmp);
    }
    rep(mi,M){
        cin >> stmp;
        T.push_back(stmp);
    }

    for( ll ni = 1 ; ni <=N ; ni++ ){
        for( ll mi = 1 ; mi <=M ; mi++ ){
            if(S[ni]==T[mi]){
                d[ni][mi] = dSUM[ni-1][mi-1]+1;
                d[ni][mi] = getMod(d[ni][mi],MOD);
            }
            dSUM[ni][mi] = dSUM[ni][mi-1] + dSUM[ni-1][mi] - dSUM[ni-1][mi-1] + d[ni][mi];
            dSUM[ni][mi] = getMod(dSUM[ni][mi],MOD);
            //cout << ni << " : " << mi << " -> " << dSUM[ni][mi] << endl;
        }
    }
    ll ans = 1; 
    for( ll ni = 1 ; ni <=N ; ni++ ){
        for( ll mi = 1 ; mi <=M ; mi++ ){
            ans += d[ni][mi];
            ans = getMod(ans,MOD);
        }
    }
    cout << getMod(ans,MOD) << endl;



}