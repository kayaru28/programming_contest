#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>

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


/*
max 448,000,000
map<string,ll> count_map;
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
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
vll P;

ll ltmp;
string stmp;
double dtmp;

ll ans = 0;

vector<vector<ll>> topval; 
vector<vector<ll>> secval; 
ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}

void solve(){
    ll Pimax = N-1;
    for( ll rank = 2 ; rank <=N ; rank++ ){
        for( ll pi = rank-1 ; pi <=Pimax ; pi++ ){
            ll p1i = pi;
            ll p2i = pi- ( rank-1 );
            ll v1i = topval[1][p1i];
            ll v2i = topval[rank-1][p2i];
            ll vtop = llmax(v1i,v2i);
            ans += (v1i + v2i - vtop);
            cout << ans << " " << vtop << endl;
            topval[rank].push_back(vtop);
        }
    }
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    topval.resize(base10_5+10);    

    cin >> N;
    rep(ni,N) topval[1].push_back(0);
    rep(ni,N) cin >> topval[1][ni];
    solve();
    cout << ans << endl;
}