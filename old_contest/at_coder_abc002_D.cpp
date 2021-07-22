


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




// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

// for(char c : S)

//min({a1, a2, ..., an})
//max({a1, a2, ..., an})
//swap(a, b)
//S.substr(si)
// sort <--> reverse
//count(v.begin(), v.end(), x) 

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
vll X;
vll Y;
ll Z;

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

double double_hosei = 1000000; //求められる精度分補正をかけておく

/*
bitset<8> xbit(131); 　　　　// 長さ 8 の bitset を定義する。整数から初期化を行う。
bitset<8> xbit('10000011'); // 長さ 8 の bitset を定義する。2 進数から初期化を行う。
xbit = (xbita & xbitb) //XOR
xbit = (xbita | xbitb) //OR
xbit = (xbita ^ xbitb) //XOR
xbit.set(x)    //x 桁目を1に
xbit.reset(x)  //x 桁目を0に
xbit[i] //i桁目にアクセス
xbit.count() //1の数をカウント
*/


#define bit_size 20 //2^30 = 10^9
map<string,ll> mappair;

ll bit_search_ans = 1;
void execBitAllSearch(int keta_bit){
    ll bitval = pow(2,keta_bit);
    
    rep(bi,bitval){
        bitset<bit_size> xbit(bi);
        ///////////////////////////////////////////////////
        //// Process Start --------------------------------

        ll cnt = 0;

        vll member;
        rep(ni,N){
            if(xbit[ni]==1){
                cnt++;
                member.push_back(ni);
            }
        }

        ll flag = 1;
        for( ll mi1 : member){
            for( ll mi2 : member){

                if(mi1 >= mi2) continue;

                bitset<bit_size> xbitX(0);
                bitset<bit_size> xbitY(0);
                xbitX.set(mi1);
                xbitY.set(mi2);
                
                bitset<bit_size> xbitXY = ( xbitX | xbitY );

                stmp = xbitXY.to_string();
                if(mappair[ stmp ]==0){
                    mi2=M;
                    mi1=M;
                    flag  = 0;
                }

            }
        }

        bit_search_ans = llmax(bit_search_ans , cnt*flag  ) ;

        //// Process End   --------------------------------
        ///////////////////////////////////////////////////
    }

    cout << bit_search_ans << endl;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;
    X.resize(M);
    Y.resize(M);

    rep(mi,M) cin >> X[mi]  >> Y[mi];
    rep(mi,M) X[mi]--;
    rep(mi,M) Y[mi]--;


    rep(mi,M){
        bitset<bit_size> xbitX(0);
        xbitX.set(X[mi]);
        bitset<bit_size> xbitY(0);
        xbitY.set(Y[mi]);

        bitset<bit_size> xbitXY = ( xbitX | xbitY );

        stmp = xbitXY.to_string();
        //cout << stmp << endl;
        mappair[stmp]++;
    }
    
    execBitAllSearch(N);

}