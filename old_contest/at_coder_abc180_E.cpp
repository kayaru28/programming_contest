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

//#include <stack>
//#include <queue>

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

ll A;
ll B;
ll C;
ll N;
ll M;
vll X,Y,Z;
ll ans = llINF;
ll ltmp;
string stmp;
double dtmp;
ll dest[20][20];
ll mindest[20][20];
ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}
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
void calcdest(){
    rep(ni,N){
        rep(nii,N){
            if(ni==nii) continue;
            dest[ni][nii] = abs(X[nii]-X[ni]) + abs(Y[nii]-Y[ni]) + llmax(0,Z[nii]-Z[ni]);
        }
    }
}
#include <queue>
//priority_queue<P,vector<P>, greater<P> > que;
//que.push(P(0,base_index));
typedef pair<ll,ll> P;

void goNext(ll from,ll tmpans,vll visit, vll froms){
    visit[from]=1;
    froms.push_back(from);
    priority_queue<P> que;
    rep(ni,N){
        if(visit[ni]==0) que.push(P(mindest[from][ni],ni));
    }

    if(que.size()==0){
        tmpans += mindest[from][0];
        ans = llmin(ans,tmpans);
        //rep(ni,N) cout << froms[ni] << " > ";
        //cout << tmpans << endl;
    }else{
        while(que.size()>0){
            P getv = que.top();
            if(tmpans + getv.first < ans ){
                goNext(getv.second , tmpans + getv.first, visit ,froms);
            }
            que.pop();
        }

    }




}
ll getans(){
    graph g(N);
    rep(ni,N){
        rep(nii,N){
            if(ni==nii) continue;
            g.add_edge(ni,nii,dest[ni][nii]);
        }
    }
    rep(ni,N){
        g.dijkstra(ni);
        rep(nii,N){
            if(ni==nii) continue;
            mindest[ni][nii]=g.node_costs[nii];
        }
    }
    vll froms;
    vll visit;
    rep(ni,N) visit.push_back(0);
    visit[0]=1;
    goNext(0,0,visit,froms);

    return ans;

}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    rep(ni,N){
        X.push_back(0);
        Y.push_back(0);
        Z.push_back(0);
    }    
    rep(ni,N){
        cin >> X[ni];
        cin >> Y[ni];
        cin >> Z[ni];
    }
    calcdest();

    cout << getans() << endl;

}