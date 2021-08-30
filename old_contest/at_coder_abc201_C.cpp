

#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <bitset>

using namespace std;
#define rep(i,n) for (ll i = 0; i < (n) ; i++)
#define rep2(i,n,i2,n2) for (ll i = 0; i < (n) ; i++) for (ll i2 = 0; i2 < (n2) ; i2++)
#define incRepFT(i,s,n) for (ll i = (s); i <= (n) ; i++)
#define decRepFT(i,s,n) for (ll i = (s); i >= (n) ; i--)

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
#define vvll vector<vector<ll>>
#define vstr vector<string>
#define vvstr vector<vector<string>>
typedef pair<ll,ll> P;  




// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

// for(char c : S)

//min({a1, a2, ..., an})
//max({a1, a2, ..., an})
//swap(a, b)
//S.substr(si)
// sort <--> reverse
//count(v.begin(), v.end(), x) 
// char t - 'a'
// char t - '0'

//xを2進数にした時の1の数
//__builtin_popcount(x) 
//__builtin_popcountll(x) 

ll A;
ll B;
ll C;
ll D;
ll N;
ll M;
ll K;
ll T;
ll H;
ll W;
ll X;
ll Y;
ll Z;

string S;

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
P d_move[4] = {
    P(0 , 1),P(0 , -1),P(1 , 0),P(-1 , 0)//,P(1 , 1),P(1 , -1),P(-1 , 1),P(-1 , -1)
};
//for(P drc : d_move)

vector<ll> inv,fact,invfact;
void setupCombination(ll n_max,ll mod=MOD){
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
ll getCombination(ll n,ll k,ll mod=MOD){
    if(n<0||k<0||k>n)return 0;
    return (fact[n]*invfact[n-k]%mod)*invfact[k]%mod;
}
ll getCombinationH(ll n, ll k , ll mod){
    return getCombination(n+k-1,k,mod);
}

double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> S;

    ll inkaku=0;
    ll nokaku=0;
    ll hatena=0;
    setupCombination(10000);
    for( char si : S){
        if(si == 'o'){
            inkaku++;
        }else if(si == 'x'){
            nokaku++;
        }else{
            hatena++;
        }
    }

    ll ans = 0;
    // 4
    if(inkaku==1){
        ans++;
    }else if(inkaku==0){
        ans+=hatena;
    }
    // 3 1
    ll tmpans = 0;
    if(inkaku==0){
        tmpans = getCombination(hatena,2) * 2 * 4;
    }else if(inkaku==1){
        tmpans = 1 * hatena * 2 * 4;
    }else if(inkaku==2){
        tmpans = 1 * 1 * 2 * 4;
    }
    ans += tmpans;

    // 2 2 
    tmpans = 0;
    if(inkaku==0){
        tmpans = getCombination(hatena,2) * 1 * 6;
    }else if(inkaku==1){
        tmpans = 1 * hatena * 1 * 6;
    }else if(inkaku==2){
        tmpans = 1 * 1 * 1 * 6;
    }
    ans += tmpans;

    // 2 1 1
    tmpans = 0;
    if(inkaku==0){
        tmpans = getCombination(hatena,3) * 3 * 12;
    }else if(inkaku==1){
        tmpans = 1 * getCombination(hatena,2) * 3 * 12;
    }else if(inkaku==2){
        tmpans = 1 * 1 * hatena * 3 * 12;
    }else if(inkaku==3){
        tmpans = 1 * 1 * 1 * 3 * 12;
    }
    ans += tmpans;

    // 1 1 1 1 
    if(inkaku==0){
        tmpans = getCombination(hatena,4) * 1 * 24;
    }else if(inkaku==1){
        tmpans = 1 * getCombination(hatena,3) * 1 * 24;
    }else if(inkaku==2){
        tmpans = 1 * 1 * getCombination(hatena,2) * 1 * 24;
    }else if(inkaku==3){
        tmpans = 1 * 1 * 1  * hatena *  1 * 24;
    }else if(inkaku==4){
        tmpans = 1 * 1 * 1 * 1 * 24;
    }
    ans += tmpans;
    cout << ans << endl;

}