#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
using namespace std;
#include <vector>
typedef long long ll;
//#include <stack>
//#include <queue>
/*
#include <math.h>
long long standerd = long long(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 


const int base = 100005;
bool visited[ base*2 ];
vector<int> bi_graph[base*2];

void dfs(ll cnt[],int ni){
    if(visited[ni]) return;
    visited[ni] = true;
    cnt[ni/base]++;
    for(int to: bi_graph[ni]){
        dfs(cnt,to);
    }
}


int main(){

    int N;    
    cin >> N;

    
    rep(ni,N){
        int x,y;
        cin >> x;
        cin >> y;
        y+=base;
        bi_graph[x].push_back(y);
        bi_graph[y].push_back(x);
    }

    ll ans=0;
    rep(ni,2*base){
        if(visited[ni]) continue;
        ll cnt[2]={};    
        dfs(cnt,ni);
        ans += (ll)cnt[0] * cnt[1];
    }
    cout << ans - N << endl;

    
}