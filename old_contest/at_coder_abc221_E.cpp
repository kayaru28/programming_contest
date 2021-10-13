


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
vll As;
ll getMod(ll value,ll mod=MOD){
    if(value == 0) return 0;
    if(mod==0) return -1;
    value %= mod;
    if(value<0) value += mod;
    return value;
}
double double_hosei = 1000000; //求められる精度分補正をかけておく
vll dp;
ll getPower(ll value,ll shisu,ll mod=MOD){
    ll ans = 1;
    ll cnt = shisu;
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
    As.resize(N);
    rep(ni,N) cin >> As[ni];

    map<ll,vll> mapval;
    rep(ni,N){
        mapval[As[ni]].push_back(ni);
    }


    //https://cpprefjp.github.io/reference/queue/priority_queue/pop.html
    //std::priority_queue<ll> que;
    //que.push(val);
    //ll getv = que.top();
    //que.pop();
    //typedef pair<ll,ll> P;  
    //que.push(P(0,base_index));
    priority_queue<P,vector<P>, less<P> > que;
    rep(ni,N){
        que.push(P(As[ni],ni));
    }

    ll ans = 0;
    while(que.size()>0){
        P getv = que.top();
        que.pop();
        ll val = getv.first;
        ll ni = getv.second;
        ll li = 0;
        if(ni>0){
            li = getPower(2,ni)-1;
        }
        ll ri = 0;
        ll base = N-1-ni;
        if(base>0){
            ri = getPower(2,base)-1;
        }
        ans += 2 * li;
        ans = getMod(ans);
        ans -= ri;
        ans = getMod(ans);
    }
    cout << ans << endl;



}