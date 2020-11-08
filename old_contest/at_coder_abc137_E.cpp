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
    #define vvint vector<vector<int>>
    #define vll vector<ll>
     
    //#include <stack>
    #include <queue>
     
    // #include <iomanip>
    //  cout << fixed << setprecision(15) << y << endl;
     
    string ans_Yes = "Yes"; 
    string ans_No = "No"; 
    string ans_yes = "yes"; 
    string ans_no = "no"; 
     
    vll A;
    vll B;
    vll C;
    vll Cp;
    ll N;
    ll M;
    ll Pt;
     
    ll ltmp;
    string stmp;
    double dtmp;
     
    struct bell_edge
    {
    	int from, to;
    	long long cost;
    };
    vector<bell_edge> edges;
    const ll bell_INF = llINF;
    vector<ll> bell_dist;
    vector<bool> bell_is_negative;
    bool bellman_ford(ll node_n, ll start_i){
        bell_dist = vector<ll>(node_n,bell_INF);
        bell_is_negative = vector<bool>(node_n,false);
        bell_dist[start_i] = 0;
        for(int rep_c=0;rep_c<node_n;rep_c++){
            bool update = false;
            for (bell_edge e : edges) {
                if(bell_dist[e.from] >= bell_INF) continue;
                if(bell_dist[e.to] > bell_dist[e.from] + e.cost){
                    bell_dist[e.to] = bell_dist[e.from] + e.cost;
                    update = true;
                }
            }
            if (!update) return true;
        }
        for(int rep_c=0;rep_c<node_n;rep_c++){
            for (bell_edge e : edges) {
                if(bell_dist[e.from] >= bell_INF) continue;
                if(bell_dist[e.to] > bell_dist[e.from] + e.cost){
                    bell_dist[e.to] = bell_dist[e.from] + e.cost;
                    bell_is_negative[e.to] = true;
                }
                if (bell_is_negative[e.from]) bell_is_negative[e.to] = true;
            }
        }
        return false;
    }
    ll llmin(ll a,ll b){
        if(a>=b) return b;
        return a;
    }
    ll llmax(ll a,ll b){
        if(a<=b) return b;
        return a;
    }
     
    int main(){
     
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
     
        cin >> N;
        cin >> M;
        cin >> Pt;
     
        
        rep(mi,M){
            cin >> ltmp;
            ltmp--;
            A.push_back(ltmp);
            cin >> ltmp;
            ltmp--;
            B.push_back(ltmp);
            cin >> ltmp;
            C.push_back(ltmp);
        }
     
        rep(mi,M) Cp.push_back(Pt-C[mi]);
        rep(mi,M){
            int from, to, cost;
            from = A[mi];
            to = B[mi];
            cost = Cp[mi];
            edges.push_back((bell_edge){from,to,cost});
        }
     
        bool resultbell = bellman_ford(N,0) ;
        if(bell_is_negative[N-1]==false) cout << llmax(-1*bell_dist[N-1],0) << endl;
        else cout << -1 << endl;
    }