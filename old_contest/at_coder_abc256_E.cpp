


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
vll Xs,Cs;

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
class UnionFind {
public:
    vector<ll> parent; // parent[i]:iの親の番号　(例) parent[3] = 2 : 3の親が2
    UnionFind(ll N){ //最初は全てが根であるとして初期化
        for(ll node_i = 0; node_i < N; node_i++){
            ll parent_i = node_i;
            parent.push_back(parent_i);
        }
    }
    ll getRoot(ll x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (parent[x] == x) return x;
        return parent[x] = getRoot(parent[x]);
    }
    void unite(ll x, ll y) { // xとyの木を併合
        ll rx = getRoot(x); //xの根をrx
        ll ry = getRoot(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        parent[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
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

    Xs.resize(N);
    Cs.resize(N);
    rep(ni,N) cin >> Xs[ni];
    rep(ni,N) Xs[ni]--;
    rep(ni,N) cin >> Cs[ni];

    UnionFind uf(N);
    //https://cpprefjp.github.io/reference/queue/priority_queue/pop.html
    //std::priority_queue<ll> que;
    //que.push(val);
    //ll getv = que.top();
    //que.pop();
    //typedef pair<ll,ll> P;  
    //priority_queue<P,vector<P>, greater<P> > que;
    //que.push(P(0,base_index));

    priority_queue<P,vector<P>, less<P> > que;

    rep(ni,N) que.push(P(Cs[ni],ni));

    ll ans = 0;
    while(que.size()>0){
        P getv = que.top();
        que.pop();
        ll ni = getv.second;
        ll ci = getv.first;
        ll index1 = ni;
        ll index2 = Xs[ni];
        if(uf.isSameRoot(index1,index2)){
            ans += ci;
        }else{
            uf.unite(index1,index2);
        }
    }
    cout << ans << endl;


    

}