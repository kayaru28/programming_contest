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
#define ull unsigned long long
#define vll vector<ll>
#define vll vector<ll>

//#include <stack>
//#include <queue>

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

vll X;
vll Y;
vll Z;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;

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
    cin >> M;
    X.resize(M);
    Y.resize(M);
    Z.resize(M);

    rep(mi,M){
        cin >> X[mi];
        cin >> Y[mi];
        cin >> Z[mi];
    }
    rep(mi,M){
        X[mi]--;
        Y[mi]--;
    }
    
    UnionFind uf(N);

    rep(mi,M){
        uf.unite(X[mi],Y[mi]);
    }

    map<ll,ll> count_map;
    rep(ni,N){
        ll root_no = uf.getRoot(ni);
        count_map[root_no]++;
    }

    ll ans = 0;
    for(auto x : count_map) {
        ans++;
    }
    cout << ans << endl;
    

}