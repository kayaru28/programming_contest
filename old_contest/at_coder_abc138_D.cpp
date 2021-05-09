


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




// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

// for(char c : S)

//min({a1, a2, ..., an})
//max({a1, a2, ..., an})
//swap(a, b)
//S.substr(si)
// sort <--> reverse
//count(v.begin(), v.end(), x) 

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
ll Q;
vll As,Bs,Ps,Xs;

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

vll points;
vvll graph;

double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> Q;
    As.resize(N);
    Bs.resize(N);
    Ps.resize(Q);
    Xs.resize(Q);

    rep(ni,N-1) cin >> As[ni] >> Bs[ni];
    rep(qi,Q) cin >> Ps[qi] >> Xs[qi];

    points.resize(N+1);
    rep(ni,N+1) points[ni]=0;
    rep(qi,Q){
        points[Ps[qi]]+=Xs[qi];
    }


    graph.resize(N+1);
    rep(ni,N-1){
        graph[As[ni]].push_back(Bs[ni]);
        graph[Bs[ni]].push_back(As[ni]);
    }

    stack<ll> next_node;
    vll parent_node;
    parent_node.resize(N+1);

    next_node.push(1);
    while(next_node.size()>0){
        ll target_node = next_node.top();
        next_node.pop();
        points[target_node] += points[ parent_node[target_node] ];

        for(ll xnode : graph[target_node] ){
            if(xnode == parent_node[target_node]) continue;
            next_node.push(xnode);
            parent_node[xnode] = target_node;
        }
    }

    ll ans = 0;
    for( ll ni = 1 ; ni <=N ; ni++ ){
        cout << points[ni] << " ";
    }



    

}