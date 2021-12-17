


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
#define ld long double
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vstr vector<string>
#define vvstr vector<vector<string>>


//#include <stack>
//#include <queue>

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

vll A;
vll B;
vll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;

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
            node_costs[i] = llINF;    
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
ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}

map<ll,ll> gbase;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;
    A.resize(M);
    B.resize(M);
    C.resize(M);
    rep(mi,M){
        cin>>A[mi];
        cin>>B[mi];
        cin>>C[mi];
    }

    rep(mi,M){
        ll index = A[mi]*10000 + B[mi];
        if(gbase[index]==0) gbase[index] = C[mi];
        else gbase[index] = llmin(gbase[index],C[mi]);
    }
    graph g(N+1);
    vll backNode[N+10];
    vll backCost[N+10];

    for(auto x : gbase) {
        ll key = x.first;
        ll Ai = key / 10000;
        ll Bi = key % 10000;
        ll Ci = x.second;

        g.add_edge(Ai,Bi,Ci);
        backNode[Bi].push_back(Ai);
        backCost[Bi].push_back(Ci);
    }
    rep(ni,N){
        ll nodei= ni+1;
        g.dijkstra(nodei);
        ll ans = llINF;
        rep(bi,backNode[nodei].size()){
            ll tmpans = g.node_costs[backNode[nodei][bi]] + backCost[nodei][bi];
            ans = llmin(ans,tmpans);
        }
        if(ans>=llINF) cout << -1 << endl;
        else cout << ans << endl;

    }


}