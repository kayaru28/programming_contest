


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

double double_hosei = 1000000; //求められる精度分補正をかけておく
#define bit_size 16 //2^30 = 10^9

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

    ll Amap[4][4];
    ll ans = 0;
    rep(ni,4){
        rep(ni2,4){
            cin >> Amap[ni][ni2];
        }
    }

    ll bitval = pow(2,16);
    rep(bi,bitval){
        bitset<bit_size> xbit(bi);
        ///////////////////////////////////////////////////
        //// Process Start --------------------------------
        ll Xmap[4][4]={};
        ll baseindex;
        rep(ni,16){
            ll hi = ni / 4;
            ll wi = ni % 4;
            Xmap[hi][wi] = xbit[ni];
            if(xbit[ni]==1) baseindex = ni;
        }


        ll tmpans = 1;
        rep(hi,4){
            rep(wi,4){
                if(Amap[hi][wi]>Xmap[hi][wi]) tmpans = 0;
            }
        }

        vvll graphMap;
        graphMap.resize(16);
        ll visit[16]={};
        rep(hi,3){
            rep(wi,3){
                
                if(Xmap[hi][wi]==0) continue;
                
                ll index1 = hi * 4 + wi; 

                ll nhi,nwi;
                nhi = hi+1;
                nwi = wi;
                if(Xmap[nhi][nwi]==1){
                    ll index2 = nhi * 4 + nwi;
                    graphMap[index1].push_back(index2);
                    graphMap[index2].push_back(index1);
                }
                nhi = hi;
                nwi = wi+1;
                if(Xmap[nhi][nwi]==1){
                    ll index2 = nhi * 4 + nwi;
                    graphMap[index1].push_back(index2);
                    graphMap[index2].push_back(index1);
                }
            }
        }

        queue<ll> nextnode;
        nextnode.push(baseindex);
        visit[baseindex]=1;
        while(nextnode.size()>0){
            ll node = nextnode.front();
            nextnode.pop();

            for(ll nexti : graphMap[node]){
                if(visit[nexti]==0){
                    visit[nexti]=1;
                    nextnode.push(nexti);
                }
            }
        }

        ll sumvisit=0;
        rep(ni,16) sumvisit+=visit[ni];
        if(sumvisit!=xbit.count()) tmpans=0;

        ans += tmpans;


        //// Process End   --------------------------------
        ///////////////////////////////////////////////////
    }

    /*
    bitset<8> xbit(131); 　　　　// 長さ 8 の bitset を定義する。整数から初期化を行う。
    bitset<8> xbit('10000011'); // 長さ 8 の bitset を定義する。2 進数から初期化を行う。
    xbit = (xbita & xbitb) //XOR
    xbit = (xbita | xbitb) //OR
    xbit = (xbita ^ xbitb) //XOR
    xbit.set(x)    //x 桁目を1に
    xbit.reset(x)  //x 桁目を0に
    xbit[i] //i桁目(0～)にアクセス
    xbit.count() //1の数をカウント
    ll bit_search_ans = 0;
    */
   cout << ans << endl;
}