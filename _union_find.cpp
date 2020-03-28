#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n) ; i++)


//*******************************************************
//***                   belongraph                    ***
//*******************************************************

class UnionFind {
public:
    vector<int> parent; // parent[i]:iの親の番号　(例) parent[3] = 2 : 3の親が2

    UnionFind(int N){ //最初は全てが根であるとして初期化
        for(int node_i = 0; node_i < N; node_i++){
            int parent_i = node_i;
            parent.push_back(parent_i);
        }
    }

    int getRoot(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (parent[x] == x) return x;
        return parent[x] = getRoot(parent[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = getRoot(x); //xの根をrx
        int ry = getRoot(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        parent[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }

    bool isSameRoot(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = getRoot(x);
        int ry = getRoot(y);
        return rx == ry;
    }
};

bool test1(){
    int N = 10;
    string test_name = "test1";
    UnionFind union_find(N);

    union_find.unite(1,4);
    union_find.unite(5,8);
    union_find.unite(5,7);
    union_find.unite(3,2);
    union_find.unite(3,1);


    cout << test_name << endl;
    rep(ni,N){
        cout << "fact " << ni << " parent " << union_find.getRoot(ni) << endl;
    }
    return true;

}


int main(){
    cout << test1() << endl;
    
}