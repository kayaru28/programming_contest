


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

#define MOD 998244353
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

ll getMod(ll value,ll mod=MOD){
    if(value == 0) return 0;
    if(mod==0) return -1;
    value %= mod;
    if(value<0) value += mod;
    return value;
}


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
vll As,Bs;

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
vvll masu;
double double_hosei = 1000000; //求められる精度分補正をかけておく
ll getPowerSimple(ll value,ll shisu){
    ll ans = 1;
    ll cnt = shisu;
    while(cnt>0){
        if(cnt%2==1){
            ans = ans * value;
        }
        value = value * value;
        cnt = cnt/2;
    }
    return ans;
}
ll getPower(ll value,ll shisu,ll mod=MOD){
    ll ans = 1;
    ll cnt = shisu;
    value %= mod;
    cout << value << endl;
    while(cnt>0){
        if(cnt%2==1){
            ans = ans * value % mod;
        }
        value = value * value % mod;
        cnt = cnt/2;
    }
    return ans;
}
ll getPowerPrimaryShisu(ll value,ll shisu,ll mod=MOD){
    //phelmar
    ll ans = 1;
    ll cnt = shisu;
    mod -= 1;
    value = value % mod;
    while(cnt>0){
        if(cnt%2==1){
            ans = ans * value % mod;
        }
        value = value * value % mod;
        cnt = cnt/2;
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> K >> M;

    ll ans;
    if(M % MOD == 0){
        ans = 0;
    }else{


        ll shisu = getPowerPrimaryShisu(K,N);
        ans = getPower(M,shisu);

    }
    
    cout << ans << endl;

}