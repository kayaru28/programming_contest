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
ll K;

ll ltmp;
string stmp;
double dtmp;

vector<ll> G[2*base10_5+10];
ll root_point[2*base10_5+10]={};
ll value[2*base10_5+10]={};
ll visited[2*base10_5+10]={};


void calcValue(ll target,ll parent_point){
    value[target] += parent_point;
    visited[target]=1;

    rep(gi,G[target].size()){
        ll next = G[target][gi];
        if(visited[next]==0) calcValue(next,value[target]);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;

    ll from,to;
    rep(ni,N-1){
        cin >> from;
        cin >> to;
        G[from].push_back(to);
        G[to].push_back(from);
    }
    ll target,point;
    rep(mi,M){
        cin >> target;
        cin >> point;
        root_point[target]+=point;
    }
    for( ll ni = 1 ; ni <=N ; ni++ ){
        value[ni] = root_point[ni];
    }
    calcValue(1,0);

    for( ll ni = 1 ; ni <=N ; ni++ ){
        cout << value[ni] << " ";
    }
   

}