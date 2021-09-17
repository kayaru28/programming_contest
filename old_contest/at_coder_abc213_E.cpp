


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

ll getkey(ll hi, ll wi){
    return hi * 1000 + wi;
}
#define size_data 500501
char HW[size_data]={};
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
bool checkInternal(ll hi, ll wi){
    if(hi < 0 || hi >= H) return false;
    if(wi < 0 || wi >= W) return false;
    return true;

}
graph g(size_data);

void addGraghnode(ll hi,ll wi, ll dhi, ll dwi, ll cost){
    ll fromkey = getkey(hi,wi);
    ll n_hi = hi+dhi;
    ll n_wi = wi+dwi;
    if( checkInternal(n_hi,n_wi)){
        ll tokey = getkey(n_hi,n_wi);
        g.add_edge(fromkey,tokey,cost);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W;
    rep(hi,H){
        cin >> stmp;
        rep(wi,W){
            HW[getkey(hi,wi)] = stmp[wi];
        }
    }

    rep(hi,H){
        rep(wi,W){
            ll fromkey = getkey(hi,wi);
            for(P dxy : d_move){
                ll n_hi = hi+dxy.first;
                ll n_wi = wi+dxy.second;
                if( checkInternal(n_hi,n_wi)){
                    ll tokey = getkey(n_hi,n_wi);
                    if(HW[tokey]=='.') g.add_edge(fromkey,tokey,0);
                }
            }
            addGraghnode(hi,wi,-2,-1,1);
            addGraghnode(hi,wi,-2, 0,1);
            addGraghnode(hi,wi,-2, 1,1);
            addGraghnode(hi,wi,-1,-2,1);
            addGraghnode(hi,wi,-1,-1,1);
            addGraghnode(hi,wi,-1, 0,1);
            addGraghnode(hi,wi,-1, 1,1);
            addGraghnode(hi,wi,-1, 2,1);
            addGraghnode(hi,wi, 0,-2,1);
            addGraghnode(hi,wi, 0,-1,1);
            addGraghnode(hi,wi, 0, 1,1);
            addGraghnode(hi,wi, 0, 2,1);
            addGraghnode(hi,wi, 1,-2,1);
            addGraghnode(hi,wi, 1,-1,1);
            addGraghnode(hi,wi, 1, 0,1);
            addGraghnode(hi,wi, 1, 1,1);
            addGraghnode(hi,wi, 1, 2,1);
            addGraghnode(hi,wi, 2,-1,1);
            addGraghnode(hi,wi, 2, 0,1);
            addGraghnode(hi,wi, 2, 1,1);
        }
    }
    ll key = getkey(0,0);
    g.dijkstra(key);
    ll gkey = getkey(H-1,W-1);
    cout << g.node_costs[gkey] << endl;


}