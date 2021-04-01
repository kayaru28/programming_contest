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

vll A;
ll B;
ll C;
ll N;
ll M;
ll K;
vll X;
vll Y;

ll ltmp;
string stmp;
double dtmp;

#include <queue>    
struct edge{ll next_index, cost;};    
typedef pair<ll,ll> P;    

vector<vector <ll> > G; 
vll cost;
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
 
    rep(ni,N+10) A.push_back(0);
    rep(ni,N+10) cost.push_back(llINF);
    rep(ni,N) cin >> A[ni+1];


    rep(mi,M) X.push_back(0);
    rep(mi,M) Y.push_back(0);
    rep(mi,M) cin >> X[mi] >> Y[mi];

    G.resize(N+1);

    rep(mi,M){
        ll from = X[mi];
        ll to = Y[mi];
        G[from].push_back(to);
    }

    for( ll ni = 1 ; ni <=N ; ni++ ){
        ll costi = llmin(A[ni],cost[ni]);
        for( ll gi = 0 ; gi <G[ni].size() ; gi++ ){
            ll to = G[ni][gi];
            if(cost[to] > costi) cost[to] = costi;
        }
    }

    ll profit = -1 * llINF;
    //for( ll ni = 1 ; ni <=N ; ni++ ) cout << "a " << A[ni] << endl;
    //for( ll ni = 1 ; ni <=N ; ni++ ) cout << "c " << cost[ni] << endl;
    for( ll ni = 1 ; ni <=N ; ni++ ){
        profit = llmax(profit, A[ni] - cost[ni]);
    }
    cout << profit << endl;



}