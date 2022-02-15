


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
    Bs.resize(N);
    rep(ni,N) cin >> Bs[ni];

    vll BBs = Bs;
    sort(BBs.rbegin(),BBs.rend());
    map<ll,ll> Bmap;
    
    rep(bi,BBs.size()){
        Bmap[BBs[bi]] = bi;
    }

    binary_indexed_tree btr(N);

    //https://cpprefjp.github.io/reference/queue/priority_queue/pop.html
    //std::priority_queue<ll> que;
    //que.push(val);
    //ll getv = que.top();
    //que.pop();
    //typedef pair<ll,ll> P;  
    //que.push(P(0,base_index));

    priority_queue<P,vector<P>, greater<P> > que;
    rep(ni,N){
        que.push(P( As[ni], Bmap[Bs[ni]] ));
    }
    ll ans = 0;

    P befV = P(-1,-1);
    map<string,ll> Bcnt;
    while(que.size()>0){
        P getv = que.top();
        que.pop();

        ll ai = getv.first;
        ll bi = getv.second;
        stmp = to_string(ai) + "-" + to_string(bi);
        btr.add(bi,1);

        ll dans = btr.sum(bi);
        //cout << ai << " " << bi << " " << dans << endl;
        dans+= Bcnt[stmp];
        ans += dans;
        Bcnt[stmp]++;
    }
    cout << ans << endl;




    

}