


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
vll As,Bs;

string S;

ll ltmp;
string stmp;
double dtmp;
double get2[base10_6];
ll getMod(ll value,ll mod=MOD){
    if(value == 0) return 0;
    if(mod==0) return -1;
    value %= mod;
    if(value<0) value += mod;
    return value;
}
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


template <typename T>
struct BIT {
    // !!!!!!!!!!!! Indexの最小値は１！！
    int n;          // 配列の要素数(数列の要素数+1)
    vector<T> bit;  // データの格納先
    BIT(int tree_size) : n(tree_size + 1), bit(n, 0) {}
    
    void add(int index, T val) {
        for (int idx = index; idx < n; idx += (idx & -idx)) {
            bit[idx] += val;
        }
    }

    T sum(int index) {
        T s(0);
        for (int idx = index; idx > 0; idx -= (idx & -idx)) {
            s += bit[idx];
        }
        return s;
    }
};
ll modDivision(ll warareru, ll warukazu,ll mod=MOD){
    //mod is prime number
    //warukazu can not separate
    ll div = getPower(warareru,mod-2);
    return getPower(div,warukazu);
}
double double_hosei = 1000000; //求められる精度分補正をかけておく
int comp(vector<ll> &A){
    std::map<int,int> mem;
    for(auto p: A) mem[p] = 0;
    int sz = 0;
    for(auto &p: mem) p.second = sz++;
    for(auto &p: A) p = mem[p];
    return sz;
}
struct binary_indexed_tree{
    int N;
    ll mod = MOD;
    vector<ll> bit;
    binary_indexed_tree(int n):N(n){
        bit.resize(N+1,0);
    }
    ll addition(ll x, ll y){
        return (x+y)%mod;
    }
    void add(int x,ll a){
        x++;
        for(x; x<=N; x+=(x&-x)) bit[x] = addition(bit[x],a);
    }
    ll sum(int x){
        x++;
        ll ret=0;
        for(x; x>0; x-=(x&-x)) ret = addition(ret,bit[x]);
        return ret;
    }
};
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    As.resize(N);
    rep(ni,N) cin >> As[ni];
    int nv = comp(As);
    //BIT<ll> bittree(nv);
    binary_indexed_tree bittree(nv);
    ltmp = 1;

    ll ans = 0;
    map<ll,ll> mapA;
    rep(ni,N) mapA[As[ni]]=0;
    ll cnt = 1;
    for(auto x : mapA){
        mapA[ x.first] = cnt;
        cnt++;
    }
    rep(ni,N){
        ll dans;
        ll index = ni+1;
        dans = getPower(2,index-1);
        //cout << As[index-1] << endl;
        dans *= bittree.sum(As[index-1]);
        //cout << index << " " << dans << endl;
        ans += dans;
        ans = getMod(ans);
        //cout << index << " " << modDivision(2,index) << endl;
        bittree.add(As[index-1],modDivision(2,index));
    }
    cout << ans << endl;




}