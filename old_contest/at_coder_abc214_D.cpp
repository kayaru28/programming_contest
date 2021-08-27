


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

vll Us,Ws,Vs;

double double_hosei = 1000000; //求められる精度分補正をかけておく
vll node_kakutei;
vll node_nokori;

//https://cpprefjp.github.io/reference/queue/priority_queue/pop.html
//std::priority_queue<ll> que;
//que.push(val);
//ll getv = que.top();
//que.pop();
//typedef pair<ll,ll> P;  
//priority_queue<P,vector<P>, greater<P> > que;
//que.push(P(0,base_index));
ll ans = 0;
class UnionFind {
public:
    vector<ll> parent; // parent[i]:iの親の番号　(例) parent[3] = 2 : 3の親が2
    vector<ll> parentsize; // parent[i]:iの親の番号　(例) parent[3] = 2 : 3の親が2
    UnionFind(ll N){ //最初は全てが根であるとして初期化
        for(ll node_i = 0; node_i < N; node_i++){
            ll parent_i = node_i;
            parent.push_back(parent_i);
            parentsize.push_back(1);
        }
    }
    ll getRoot(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (parent[x] == x) return x;
        return parent[x] = getRoot(parent[x]);
    }
    ll getSize(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        ll pi = getRoot(x);
        return parentsize[pi];
    }
    void unite(ll x, ll y) { // xとyの木を併合
        ll rx = getRoot(x); //xの根をrx
        ll ry = getRoot(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        parent[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        parentsize[ry] += parentsize[rx]; 
    }
    bool isSameRoot(ll x, ll y) { // 2つのデータx, yが属する木が同じならtrueを返す
        ll rx = getRoot(x);
        ll ry = getRoot(y);
        return rx == ry;
    }
};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    node_kakutei.resize(N);
    node_nokori.resize(N);
    rep(ni,N) node_kakutei[ni]=0;
    rep(ni,N) node_nokori[ni]=0;
    
    Us.resize(N-1);
    Vs.resize(N-1);
    Ws.resize(N-1);
    rep(ni,N-1){
        cin >> Us[ni] >> Vs[ni] >> Ws[ni];
    }

    UnionFind uf(N);
    priority_queue<P,vector<P>, greater<P> > que;
    rep(ni,N-1){
        que.push(P(Ws[ni] ,ni));
    }

    while(que.size()>0){
        P get = que.top();
        que.pop();
        ll weight = get.first;
        ll index = get.second;
        ll li = Us[index];
        ll ri = Vs[index];
        ll lcnt = uf.getSize(li);
        ll rcnt = uf.getSize(ri);
        ll totalcnt = lcnt * rcnt;
        ans += weight * totalcnt;
        uf.unite(ri,li);
    }
    cout << ans << endl;



}