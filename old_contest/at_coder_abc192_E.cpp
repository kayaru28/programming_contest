


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
vll T,K;
ll N;
ll M;
ll X,Y;

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
            node_costs[i] = llINF;    
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
                ll add_cost = 0;
                add_cost = T[e.cost];
                if(updated_cost % K[e.cost] > 0  ) add_cost = add_cost + K[e.cost] - updated_cost % K[e.cost];

                if(node_costs[e.next_index] > node_costs[index]+add_cost){    
                    node_costs[e.next_index] = node_costs[index]+add_cost;    
                    que.push(P(node_costs[e.next_index],e.next_index));    
                }    
            }    
        }    
    }    
};    
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;
    cin >> X;
    cin >> Y;

    A.resize(M);
    B.resize(M);
    T.resize(M);
    K.resize(M);
    rep(mi,M){
        cin >> A[mi];
        cin >> B[mi];
        cin >> T[mi];
        cin >> K[mi];
    }

    graph g(N+10);
    rep(mi,M){
        g.add_edge(A[mi],B[mi],mi);
        g.add_edge(B[mi],A[mi],mi);
    }
    g.dijkstra(X);
    if(g.node_costs[Y] == llINF) g.node_costs[Y]=-1;
    cout << g.node_costs[Y] << endl;

}