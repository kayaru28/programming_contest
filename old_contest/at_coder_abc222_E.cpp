


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
ll Z,R;
vll Us,Vs;
vll As;
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

ll map_cnt[1010] = {};

#include <queue>    
struct edge{ll next_index, cost;};    
typedef pair<ll,ll> P;    
struct graph{    
    ll graph_size;    
    vector<vector <edge> > G; 
    vector<ll> node_costs;    
    vector<ll> node_from;    
    graph(ll n){    
        init(n);    
    }    
    void init(ll n){    
        graph_size = n;    
        G.resize(graph_size);    
        node_costs.resize(graph_size);    
        node_from.resize(graph_size);    
        rep(i,graph_size){    
            node_costs[i] = INF;    
            node_from[i] = 0;
        }    
    }    
    void add_edge(ll start_index, ll next_index, ll cost){    
        edge e;    
        e.next_index = next_index;    
        e.cost = cost;    
        G[start_index].push_back(e);    
    }    
    void dijkstra(ll base_index){    
        rep(i,graph_size){    
            node_costs[i] = INF;    
            node_from[i] = 0;
        }    
        node_costs[base_index] = 0;    
        priority_queue<P,vector<P>, greater<P> > que;    
        que.push(P(0,base_index));    
        while(!que.empty()){    
            P p = que.top();    
            que.pop();    
            ll index = p.second;    
            ll updated_cost = p.first;    
            if(node_costs[index] < updated_cost) continue;    
            for(auto e : G[index]){    
                if(node_costs[e.next_index] > node_costs[index]+e.cost){    
                    node_costs[e.next_index] = node_costs[index]+e.cost;
                    node_from[e.next_index] = index;
                    que.push(P(node_costs[e.next_index],e.next_index));    
                }    
            }    
        }    
    }    
};    
vvll dp;
ll ans = 0;
void getAns(){
    dp.resize(N);
    rep(ni,N){
        rep(ri,R+1) dp[ni].push_back(0);
    }

    dp[0][0] = 1;
    for (int i = 0; i < N-1; ++i) {
        for (int j = 0; j <= R; ++j) {
            (dp[i+1][j] += dp[i][j]) %= MOD;
            if (j >= map_cnt[i]) (dp[i+1][j] += dp[i][j-map_cnt[i]]) %= MOD;
        }
    }
    ans = dp[N-1][R];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M >> K;

    As.resize(M);
    rep(mi,M) cin >> As[mi];


    Us.resize(N-1);
    Vs.resize(N-1);
    rep(ni,N-1) cin >> Us[ni] >> Vs[ni];

    graph g(N+1);
    map<ll,ll> map_conv;
    ll maphosei= 10000;
    rep(ni,N-1){
        g.add_edge(Us[ni],Vs[ni],1);
        g.add_edge(Vs[ni],Us[ni],1);
        map_conv[Us[ni]*maphosei + Vs[ni]]=ni;
        map_conv[Vs[ni]*maphosei + Us[ni]]=ni;
    }


    rep(mi,M-1){
        ll fromi = As[mi];
        ll toi = As[mi+1];

        g.dijkstra(fromi);

        ll nodei = toi;
        while(nodei!=fromi){
            ll mapindex = nodei * maphosei +  g.node_from[nodei];
            ll index = map_conv[mapindex];
            map_cnt[index]++;
            nodei = g.node_from[nodei];
        }
    }

    ll sum_cnt = 0;
    rep(ni,N-1){
        sum_cnt += map_cnt[ni];
    }

    R = sum_cnt;
    B = 0;

    for(R = 0 ; R <=sum_cnt ; R++ ){
        B = sum_cnt - R;
        if(R-B==K){
            getAns();
            break;
        }
    }

    cout << ans << endl;    




}