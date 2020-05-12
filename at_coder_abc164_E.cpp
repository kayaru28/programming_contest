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
#include <queue>
#include <queue>

//#include <stack>
//#include <queue>

/*
#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 
ll N;
ll M;
ll S;
vll candidate;
ll cost[55]={};
ll silver[55]={};
vll neighber[110];
ll C[55];
ll D[55];
ll confirm[55]={};

struct edge{ll to, cost,silv;};
typedef pair<ll,ll> P;
ll buySilver(edge e,ll base_index,ll base_silv);
struct graph{
    ll V;
    vector<vector <edge> > G;
    vector<ll> d;
    vector<ll> silv;
    
    graph(ll n){
        init(n);
    }
    void init(ll n){
        V = n;
        G.resize(V);
        d.resize(V);
        silv.resize(V);
        rep(i,V){
            d[i] = INF;
            silv[i] = 0;
        }
    }

    void add_edge(ll s, ll t, ll cost,ll silv){
        edge e;
        e.to = t, e.cost = cost;
        e.silv = silv;
        G[s].push_back(e);
    }
    void dijkstra(ll s){
        rep(i,V){
            d[i] = INF;
        }
        d[s] = 0;
        silv[s] = silver[s];
        ll unit_C = C[s];
        ll unit_D = D[s];
        priority_queue<P,vector<P>, greater<P> > que;
        que.push(P(0,s));
        while(!que.empty()){
            P p = que.top(); que.pop();
            ll v = p.second;
            if(d[v]<p.first) continue;
            for(auto e : G[v]){
                ll buy = buySilver(e,s,silv[v]);
                ll cost_i = d[v]+e.cost+buy*unit_D;
                if(d[e.to]>cost_i){
                    d[e.to] = cost_i;
                    silv[e.to] = silv[v]+buy*unit_C-e.silv;
                    que.push(P(d[e.to],e.to));
                }
            }
        }
    }
};
/*
graph g(n);
//と書けばn頂点のグラフが作成され、
g.add_edge(a,b,cost);
c//とすれば頂点aから頂点bへのコストcostの辺が張られます。そして
g.dijkstra(s);
//とすれば頂点sから各頂点への最短経路をダイクストラ法で探索できます。探索結果は
int dist = g.d[i]:
*/

void doneConfirm(int index){
    confirm[index]=1;
    int Vsize = neighber[index].size();
    rep(ni,Vsize){
        int next_index = neighber[index][ni];
        if(confirm[next_index]!=1){
            candidate.push_back(neighber[index][ni]);
         }
    }
    sort(candidate.begin(), candidate.end());
    decltype(candidate)::iterator result = std::unique(candidate.begin(), candidate.end());
    candidate.erase(result, candidate.end());
}
ll buySilver(edge e,ll base_index,ll base_silv){
    ll buy;
    ll need;
    need = e.silv-base_silv;
    if(need>0){
        if(need % C[base_index] ==0){
            buy = need / C[base_index];
        }else{
            buy = need / C[base_index] + 1;
        }
    }else{
        buy = 0;
    }
    return buy;
}
void update(graph g,ll base_index){
    rep(ni,N){
        
    }

}
int main(){

    cin >> N >> M >> S;

    graph g(N);

    ll U,V,A,B;
    rep(mi,M){
        cin >> U;
        cin >> V;
        cin >> A;
        cin >> B;
        U--;
        V--;
        neighber[U].push_back(V);
        neighber[V].push_back(U);
        g.add_edge(U,V,B,A);
        g.add_edge(V,U,B,A);
    }
    rep(ni,N){
        cin >> C[ni];
        cin >> D[ni];
        cost[ni]=llINF;
    }
    int index = 0;
    cost[index]=0;

    g.dijkstra(index);
    doneConfirm(index);
    update(g,0);
    while(candidate.size()!=0){
        ll index_i;
        ll cand_i;
        cand_i = 0;
        index = candidate[cand_i];
        int Vsize = candidate.size();
        rep(ci,Vsize){
            index_i= candidate[ci];
            if(cost[index]>cost[index_i]){
                cand_i = ci;
                index = index_i;
            }
        }
        candidate.erase(candidate.begin()+cand_i);
        //cout << "target " << index << endl;
        //rep(ni,N) cout << "cost " << ni << " : " << cost[ni] << endl;
        //rep(ci,candidate.size()) cout << "candi : " << candidate[ci] << endl;
        doneConfirm(index);
        S = silver[index];
        g.dijkstra(index);
        update(g,index);
    }
    for( int ni = 1 ; ni <N ; ni++ ){
        cout << cost[ni] << endl;
    }
}