#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>





//https://nexusuica.hatenablog.jp/entry/2018/08/14/114524
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
/*
graph g(n);
//と書けばn頂点のグラフが作成され、
g.add_edge(a,b,cost);
//とすれば頂点aから頂点bへのコストcostの辺が張られます。そして
g.dijkstra(s);
//とすれば頂点sから各頂点への最短経路をダイクストラ法で探索できます。探索結果は
int dist = g.d[i]:
*/


int main(){
    ll N=10;
    graph g(N);
    rep(ni,N-1){
        g.add_edge(ni,ni+1,1);
        g.add_edge(ni+1,ni,1);
    }
    cout << "start" << endl;
    g.dijkstra(2);
    rep(ni,N) cout << ni << "\t: " << g.node_costs[ni] << endl;

}



