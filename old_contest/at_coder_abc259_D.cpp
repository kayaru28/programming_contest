


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
#define llINF numeric_limits<long long>::max()
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
ll Q;
ll T;
ll H;
ll W;
ll X;
ll Y;
ll Z;
vll Xs,Ys,Rs;

string S;

ll ltmp;
string stmp;
double dtmp;

vvll graphi;

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
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
double double_hosei = 1000000; //求められる精度分補正をかけておく
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
                if(node_costs[e.next_index] > node_costs[index]+e.cost){    
                    node_costs[e.next_index] = node_costs[index]+e.cost;    
                    que.push(P(node_costs[e.next_index],e.next_index));    
                }    
            }    
        }    
    }    
};
ll getdist(ll x1, ll x2, ll y1 , ll y2){
    return ( x1 - x2) * ( x1 - x2) + (y1 - y2) * (y1 - y2);

}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    

    Xs.resize(N);
    Ys.resize(N);
    Rs.resize(N);
    rep(ni,N) cin >> Xs[ni] >> Ys[ni] >> Rs[ni];

    graph graphi(N);

    for( ll n1 = 0 ; n1 <N ; n1++ ){
        for( ll n2 = n1+1 ; n2 <N ; n2++ ){
            ll dist = getdist(Xs[n1],Xs[n2],Ys[n1],Ys[n2]);
            ll rmax = Rs[n1] + Rs[n2];
            ll rmin = Rs[n1] - Rs[n2];
            rmax = rmax * rmax;
            rmin = rmin * rmin;
            if( rmin <= dist && dist <= rmax){
                graphi.add_edge(n1,n2,1);
                graphi.add_edge(n2,n1,1);
            }
        }
    }

    ll si, ti;
    rep(ni,N){
        ll dist;
        dist = getdist(sx, Xs[ni],sy,Ys[ni]);
        if(Rs[ni] * Rs[ni] == dist ) si = ni;

        dist = getdist(tx, Xs[ni],ty,Ys[ni]);
        if(Rs[ni] * Rs[ni] == dist ) ti = ni;
    }

    graphi.dijkstra(si);
    if(graphi.node_costs[ti] < llINF){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }




}