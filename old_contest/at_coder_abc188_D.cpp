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
vll ai,bi,ci;
map<ll,ll> valmap;
ll ltmp;
string stmp;
double dtmp;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> C;
    rep(ni,N) ai.push_back(N);
    rep(ni,N) bi.push_back(N);
    rep(ni,N) ci.push_back(N);
    rep(ni,N) cin >> ai[ni] >> bi[ni] >> ci[ni];

    rep(ni,N){
        valmap[ai[ni]]   += ci[ni];
        valmap[bi[ni]+1] -= ci[ni];
    }

    vll valdate;
    for(auto x : valmap) {
        ll key = x.first;
        ll value = x.second;
        valdate.push_back(key);
    }

    sort(valdate.begin(),valdate.end());

    ll costflow=0;
    ll ans=0;
    ll vi = 0;
    for( ll di = 1 ; di <=base10_9+10 ; di++ ){
        if(valdate[vi]==di){
            vi++;
            costflow += valmap[di];
        }

        if(costflow>C) ans+=C;
        else ans+=costflow;
//        cout << di << " " << ans << endl;
    }

    cout << ans << endl;
}