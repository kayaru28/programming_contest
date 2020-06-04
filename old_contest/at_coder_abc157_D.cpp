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

#include <math.h>
/*
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 
ll N;
ll M;
ll K;
class UnionFind {
public:
    vector<int> parent; // parent[i]:iの親の番号　(例) parent[3] = 2 : 3の親が2
    vector<int> cnt;
    UnionFind(int N){ //最初は全てが根であるとして初期化
        for(int node_i = 0; node_i < N; node_i++){
            int parent_i = node_i;
            parent.push_back(parent_i);
            cnt.push_back(1);
        }
    }
    int getRoot(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (parent[x] == x) return x;
        return parent[x] = getRoot(parent[x]);
    }
    int getCnt(int x){
        return cnt[getRoot(x)];
    }
    void unite(int x, int y) { // xとyの木を併合
        int rx = getRoot(x); //xの根をrx
        int ry = getRoot(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        parent[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
        cnt[ry]+=cnt[rx];
    }
    bool isSameRoot(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = getRoot(x);
        int ry = getRoot(y);
        return rx == ry;
    }
};

int main(){
    cin >> N >> M >> K;
    UnionFind union_find(N);
    vint chain[N];

    int A,B;
    rep(ni,N){
        chain[ni].push_back(ni);
    }


    rep(mi,M){
        cin >> A;
        cin >> B;
        A--;
        B--;
        union_find.unite(A,B);
        chain[A].push_back(B);
        chain[B].push_back(A);
    }

    rep(ki,K){
        cin >> A;
        cin >> B;
        A--;
        B--;
        if(union_find.isSameRoot(A,B)){
            chain[A].push_back(B);
            chain[B].push_back(A);
        }
    }
    rep(ni,N){
        cout << ( union_find.getCnt(ni)-chain[ni].size() );
        cout << " ";
    }

}