#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define MOD 998244353
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

//#include <stack>
//#include <queue>

/*
#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

ll cnt[2000000]={};
ll B;
ll C;
ll N;
ll M;
ll K;

vector<ll> inv,fact,invfact;
void Mod_build(ll n,ll mod){
	fact.resize(n+1);
	inv.resize(n+1);
	invfact.resize(n+1);
	fact[0]=inv[0]=invfact[0]=1;
	inv[1]=1;
	for(ll i=0;i<n;i++){
		fact[i+1]=fact[i]*(i+1)%mod;
		if(i>0)inv[i+1]=mod-inv[mod%(i+1)]*(mod/(i+1))%mod;
		invfact[i+1]=invfact[i]*inv[i+1]%mod;
	}
}

ll comb(ll n,ll k,ll mod){
	if(n<0||k<0||k>n)return 0;
	return (fact[n]*invfact[n-k]%mod)*invfact[k]%mod;
}
ll getPower(ll value,ll shisu){
    ll ans = 1;
    ll cnt = shisu;
    while(cnt>0){
        if(cnt%2==1){
            ans = ans * value % MOD;
        }
        value = value * value % MOD;
        cnt = cnt/2;
    }
    return ans;
}
int main(){
    cin >> N;
    cin >> M;
    cin >> K;
    Mod_build(201010,MOD);


    ll nCk;
    ll ans = 0;
    for( int ki = 0 ; ki <=K ; ki++ ){
        nCk = comb(N-1,ki,MOD);
        ans += ((nCk * M) % MOD) * getPower(M-1,N-ki-1);
        ans = ans % MOD;
    }
    if(ans<0) ans+=MOD;
    cout << ans << endl;

}