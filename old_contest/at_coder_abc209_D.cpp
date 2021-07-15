


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
ll Q;
vll As,Bs,Cs,Ds;

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
#include <queue>    
struct edge{ll next_index, cost;};    
typedef pair<ll,ll> P;    
struct graph{    
    ll graph_size;    
    vector<vector <edge> > G; 
    vector<ll> node_costs;    
    graph(ll n){    
        init(n);    
    }    
    void init(ll n){    
        graph_size = n;    
        G.resize(graph_size);    
        node_costs.resize(graph_size);    
        rep(i,graph_size){    
            node_costs[i] = INF;    
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
                    que.push(P(node_costs[e.next_index],e.next_index));    
                }    
            }    
        }    
    }    
};
double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q;
    As.resize(N-1);
    Bs.resize(N-1);
    Cs.resize(Q);
    Ds.resize(Q);
    rep(ni,N-1) cin >> As[ni] >> Bs[ni];
    rep(qi,Q) cin >> Cs[qi] >> Ds[qi];

    graph g(N+1);
    rep(ni,N-1){
        g.add_edge(As[ni],Bs[ni],1);
        g.add_edge(Bs[ni],As[ni],1);
    }
    g.dijkstra(1);
    rep(qi,Q){
        ll distC = g.node_costs[Cs[qi]];
        ll distD = g.node_costs[Ds[qi]];

        ll diff = abs(distC - distD);
        if(diff % 2 == 0) cout << "Town" << endl;
        else cout << "Road" << endl;

    }



}