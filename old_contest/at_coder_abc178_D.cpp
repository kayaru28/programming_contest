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

ll ltmp;
string stmp;
double dtmp;

ll cnt = 1;
ll getMod(ll value,ll mod){
    if(value == 0) return 0;
    if(mod==0) return -1;
    value %= mod;
    if(value<0) value += mod;
    return value;
}

ll cntPat[2010][1010]={};


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    ll cut = 1;
    for( ll ci = 3 ; ci <=N ; ci++ ){
        cntPat[ci][cut] = 1;
    }

    cut++;
    while(3 * cut  <= N){
        ll start = 3 * cut;
        ll dsum = 0;
        for( ll val = start ; val <=N ; val++ ){

            dsum += cntPat[val-3][cut-1];
            dsum = getMod(dsum,MOD);

            cntPat[val][cut] += dsum;
            cntPat[val][cut]=getMod(cntPat[val][cut],MOD);
        }
        cut++;
    }

    //cout << "calc" << endl;
    ll ans = 0;
    for( ll ci = 1 ; ci <=1000 ; ci++ ){
        ans += cntPat[N][ci];
        ans = getMod(ans,MOD);
    }

    cout << ans << endl;

}