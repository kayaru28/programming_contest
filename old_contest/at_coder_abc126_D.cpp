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

#include <queue>
//https://cpprefjp.github.io/reference/queue/priority_queue/pop.html
priority_queue<ll> que;
//que.push(val);
//ll getv = que.top();
//que.pop();
//typedef pair<ll,ll> P;  
//priority_queue<P,vector<P>, greater<P> > que;
//que.push(P(0,base_index));

ll N;
vll G[base10_6];
vll leng[base10_6];

ll visited[base10_6]={};
ll node_belong[base10_6];

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    for( ll ni = 1 ; ni <=N-1 ; ni++ ){
        ll u,v,w;
        cin >> u;
        cin >> v;
        cin >> w;

        G[u].push_back(v);
        leng[u].push_back(w);

        G[v].push_back(u);
        leng[v].push_back(w);
    }
    ll index = 1;
    visited[index]=1;
    node_belong[index]=0;
    que.push(index);

    while(que.size()>0){
        ll base_index = que.top();
        que.pop();

        rep(gi,G[base_index].size()){
            ll ni = G[base_index][gi];
            ll li = leng[base_index][gi];

            if(visited[ni]==0){
                que.push(ni);
                ll bi = (node_belong[base_index] + li % 2 ) % 2;
                //cout << "ni " << ni << endl;
                //cout << "bi " << bi << endl;
                node_belong[ni]=bi;
                visited[ni]=1;
            }

        }
    }    


    for( ll ni = 1 ; ni <=N ; ni++ ){
        cout << node_belong[ni] << endl;
    }    





}