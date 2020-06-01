#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

//#include <stack>
//#include <queue>

/*
#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

ll A[1000000];
ll B[1000000];
ll C[1000000]={};
ll N;
ll M;
ll K;

vector<int> target;
using Graph = vector<vector<int>>; //第一引数のノードは、その中のベクターにあるノードとつながりがある

bool visited[1000000];

void dfs(const Graph &G) {
    //cout << "start" << endl;
    ll tarsize= target.size();
    vector<int> next_target;
    ll next_v;
    rep(ti,tarsize){
        ll v = target[ti];
        //cout << "base " << v << endl;
        visited[v] = true; // v を訪問済にする
        // v から行ける各頂点 next_v について
        for (auto next_v : G[v]) { 
            //cout << next_v << endl;
            if (visited[next_v]) continue; // next_v が探索済だったらスルー
            C[next_v]=v;
            //cout << "in " << v << endl;
            visited[next_v]= true;
            next_target.push_back(next_v);
        }
    }
    target.clear();
    target = next_target;

    //cout << "next" << endl;
    if(target.size()>0) dfs(G); // 再帰的に探索


}
//以下を、main関数の中で使用

int main(){

    
    cin >> N;
    cin >> M;
    Graph G(N+10);
    rep(mi,M){
        cin >> A[mi];
        cin >> B[mi];
        G[A[mi]].push_back(B[mi]);
        G[B[mi]].push_back(A[mi]);
    }
    target.push_back(1);
    dfs(G);
       


    cout << "Yes" << endl;
    for( int ni = 2 ; ni <=N ; ni++ ){
        cout << C[ni] << endl;
    }

}