


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
vll As,Bs;


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

double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;
    As.resize(M);
    Bs.resize(M);
    rep(mi,M) cin >> As[mi] >> Bs[mi];

    graph g(N+10);
    rep(mi,M){
        g.add_edge(As[mi],Bs[mi],1);
    }
    ll ans = 0;
    for( ll ni = 1 ; ni <=N ; ni++ ){
        g.dijkstra(ni);
        for( ll ni2 = 1 ; ni2 <=N ; ni2++ ){
            if(g.node_costs[ni2]!=llINF){
                //cout << ni << " " << ni2 << endl;
                ans++;
            }
        }
    }
    cout << ans << endl;


}