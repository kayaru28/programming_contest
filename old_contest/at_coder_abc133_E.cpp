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

vll G[base10_5+10];
vll B;
ll C;
ll N;
ll M;
ll K;

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
ll getMod(ll value,ll mod){
    if(value == 0) return 0;
    if(mod==0) return -1;
    value %= mod;
    if(value<0) value += mod;
    return value;
}
#include <queue>
//https://cpprefjp.github.io/reference/queue/priority_queue/pop.html
//std::priority_queue<ll> que;
//que.push(val);
//ll getv = que.top();
//que.pop();
//typedef pair<ll,ll> P;  
//priority_queue<P,vector<P>, greater<P> > que;
//que.push(P(0,base_index));
ll visited[base10_6]={};
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> K;

    rep(ni,N-1){
        ll mi,mj;
        cin >> mi >> mj;
        G[mi].push_back(mj);
        G[mj].push_back(mi);
    }
    ll max2=0;
    for( ll ni = 1 ; ni <=N ; ni++ ){
        max2 = llmax( max2, G[ni].size() );
    }    
    
    ll ans = 1;
    ans *= K;
    ans = getMod(ans,MOD);
    visited[1]=1;

    priority_queue<ll> nexti;
    ll ki = K-1;
    rep(mi,G[1].size()){
        ll ni = G[1][mi];
        if(visited[ni]==0){
            ans *= ki;
            ki--;
            ans = getMod(ans,MOD);
            nexti.push(ni);
            visited[ni]=1;
        }
    }
    //cout << ans << endl;
    while(nexti.size()>0){
        ll index = nexti.top();
        nexti.pop();
        ki = K-2;
        rep(mi,G[index].size()){
            ll ni = G[index][mi];
            if(visited[ni]==0){
                //cout << ni  << " " << ki << endl;
                ans *= ki;
                ki--;
                ans = getMod(ans,MOD);
                nexti.push(ni);
                visited[ni]=1;
            }
        }
        //cout << index << endl;
    }

    cout << ans << endl;

}