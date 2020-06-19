#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define base10_4 10000      //1e4
#define base10_5 100000     //1e5
#define base10_6 1000000    //1e6
#define base10_7 10000000   //1e7
#define base10_8 100000000  //1e8
#define base10_9 1000000000 //1e9
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>
#define MOD 1000000007

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
ll getCombinationMOD(ll n,ll k,ll mod){
    if(n<0||k<0||k>n)return 0;
    return (fact[n]*invfact[n-k]%mod)*invfact[k]%mod;
}
ll getHomogeneousProductMOD(ll n,ll r,ll mod){
    return getCombinationMOD(n +r-1,r,mod);
}

ll ans=0;
int main(){

    
    cin >> N;
    cin >> K;
    setupCombination(base10_6,MOD);

    ll repeat = N;
    if(N>K) repeat = K;


    for( int ni = 0 ; ni <=repeat ; ni++ ){
        ll leftK = K-ni;
        ll leftRoom = N - ni;
        ll leftPerson = ni;
        ans = ans + getCombinationMOD(N,ni,MOD) * getHomogeneousProductMOD(leftRoom,leftPerson,MOD);
        ans = ans + MOD;
        ans = ans % MOD;
    }
    ans = ans + MOD;
    ans = ans % MOD;
    cout << ans << endl;

        
    

}