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
ll getCombinationH(ll n, ll k , ll mod){
    return getCombination(n+k-1,k,mod);
}
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
    cin >> K;

    setupCombination(2010,MOD);
    
    for( ll ki = 1 ; ki <=K ; ki++ ){
        int betB = ki - 1;
        ll ans = getCombination(K-1,betB,MOD);

        int l = betB+2;
        int r = (N-K)-betB;

        ans *= getCombinationH(l,r,MOD);

        cout << getMod(ans,MOD) << endl;
    }

}