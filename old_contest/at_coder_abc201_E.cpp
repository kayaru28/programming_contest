


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
vll Us,Vs,Ws;
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


vvll gtree;
map<string,ll> mapW;
vll cnt;
vll parent;
vll cost;
string getkey(ll fi,ll ti){
    return to_string(fi) + " " + to_string(ti);
}

double double_hosei = 1000000; //求められる精度分補正をかけておく
ll getCnt(ll tari){
    if(gtree[tari].size()==1 && gtree[tari][0] == parent[tari]){
        cnt[tari]=1;
    }else{
        ll tmpcnt = 0;
        for(ll ni : gtree[tari]){
            if(ni==parent[tari]) continue;
            parent[ni] = tari;
            tmpcnt += getCnt(ni);
        }
        cnt[tari]=tmpcnt;
    }
    return cnt[tari];

}
#define bit_size 70 //2^30 = 10^9

ll getMod(ll value,ll mod){
    if(value == 0) return 0;
    if(mod==0) return -1;
    value %= mod;
    if(value<0) value += mod;
    return value;
}
ll getPower(ll value,ll shisu,ll mod){
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
    Us.resize(N);
    Vs.resize(N);
    Ws.resize(N);
    rep(ni,N-1) cin >> Us[ni] >> Vs[ni] >> Ws[ni];

    gtree.resize(N+10);
    cnt.resize(N+10);
    parent.resize(N+10);
    cost.resize(N+10);
    rep(ni,N){
        gtree[Us[ni]].push_back(Vs[ni]);
        gtree[Vs[ni]].push_back(Us[ni]);
        mapW[ getkey(Us[ni],Vs[ni]) ] = Ws[ni];
        mapW[ getkey(Vs[ni],Us[ni]) ] = Ws[ni];
    }

    ll basei = 1;
    queue<ll> nnode;
    nnode.push(basei);
    parent[basei]=0;
    cost[basei] = 0;
    while(nnode.size()>0){
        ll tari = nnode.front();
        nnode.pop();

        for(ll ni : gtree[tari]){
            if( parent[tari] == ni ) continue;
            nnode.push(ni);
            parent[ni] = tari;
            cost[ni] = cost[tari] ^ mapW[ getkey(tari,ni) ];
        }
    }

    ll ans = 0;
    for( ll keta = 0 ; keta <=65 ; keta++ ){
        ll cnt0=0;
        ll cnt1=0;
        for( ll ni = 1 ; ni <=N ; ni++ ){
            bitset<bit_size> tmpxbit(cost[ni]);
            if(tmpxbit[keta]==0) cnt0++;
            else cnt1++;
        }
        ans += getPower(2,keta,MOD) * cnt0 * cnt1;
        ans = getMod(ans,MOD);
    }    
    cout << ans << endl;







}