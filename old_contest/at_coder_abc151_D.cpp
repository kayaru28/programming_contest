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
#define vint vector<int>
#define vll vector<ll>

//#include <stack>
//#include <queue>

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;

ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}


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
    ll getMaxCost(){
        ll ans = 0;
        rep(ii,node_costs.size()){
            if(node_costs[ii] < INF) ans = llmax(node_costs[ii],ans);
        }
        return ans;
    }
};    

int getNodeId(int H, int W){
    return H*20 + W;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll H,W;
    cin >> H;
    cin >> W;
    int S[20][20];

    graph g(500);
    rep(hi,H){
        cin >> stmp;
        rep(ii,stmp.size()){
            int wi = ii;
            if(stmp.substr(ii,1)=="#") S[hi][wi]=1;
            else S[hi][wi]=0;
        }
    }
    for( ll wi = 0 ; wi <= W-1-1 ; wi++ ){
        rep(hi,H){
            if(S[hi][wi]+S[hi][wi+1]==0){
                int index1 = getNodeId(hi,wi);
                int index2 = getNodeId(hi,wi+1);
                g.add_edge(index1,index2,1);
                g.add_edge(index2,index1,1);
            }
        }
    }
    for( ll hi = 0 ; hi <= H-1-1 ; hi++ ){
        rep(wi,W){
            if(S[hi][wi]+S[hi+1][wi]==0){
                int index1 = getNodeId(hi,wi);
                int index2 = getNodeId(hi+1,wi);
                g.add_edge(index1,index2,1);
                g.add_edge(index2,index1,1);
            }
        }
    }
    ll maxans=0;
    rep(hi,H){
        rep(wi,W){
            ll index = getNodeId(hi,wi);
            g.dijkstra(index);
            ltmp = g.getMaxCost();
            maxans = llmax(maxans,ltmp);

        }
    }
    cout << maxans << endl;


}




