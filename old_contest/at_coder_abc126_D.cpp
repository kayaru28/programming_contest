#include  <iostream>
#include  <stdio.h>
#include <algorithm>
//#include <iomanip>
using namespace std;
#include <vector>
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
#include <string>


int getIntSubstr(string s,int start_index,int length){
    return atoi(s.substr(start_index,length).c_str());
}

//*******************************************************
//***                   belongraph                    ***
//*******************************************************

struct UnionFind {
    vector<int> par; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2
    vector<int> unti; // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UnionFind(int N) : par(N),unti(N) { //最初は全てが根であるとして初期化
        for(int i = 0; i < N; i++){
            par[i] = i;
            unti[i] = -1;
        }
    }
    int unti_root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return unti[root(x)];
    }
    int root(int x) { // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
        if (par[x] == x) return x;
        return par[x] = root(par[x]);
    }

    void unite(int x, int y) { // xとyの木を併合
        int rx = root(x); //xの根をrx
        int ry = root(y); //yの根をry
        if (rx == ry) return; //xとyの根が同じ(=同じ木にある)時はそのまま
        par[rx] = ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける
    }
    void set_unti(int x,int unti_x){
        unti[root(x)] = root(unti_x);
    }

    bool same(int x, int y) { // 2つのデータx, yが属する木が同じならtrueを返す
        int rx = root(x);
        int ry = root(y);
        return rx == ry;
    }

    void output(){
        int ans[par.size()]={};
        for( int ni = 0 ; ni < par.size() ; ni++ ){
            if(unti_root(ni)>=0){
                if(ans[unti_root(ni)] == 0){
                    ans[root(ni)] = 1;
                }
                 else{
                    ans[root(ni)] = 0;
                }
            }
            else{
                ans[root(ni)] = 0;
            }
        }
        for( int ni = 0 ; ni < par.size() ; ni++ ){
            ans[ni] = ans[root(ni)];
        }
        for( int ni = 0 ; ni < par.size() ; ni++ ){
            cout << ans[ni] << endl;
        }
    }
};



int main(){

    int N;
    cin >> N;

    int leng;


    int top1,top2;
    UnionFind uf(N);

    for( int ni = 0 ; ni < N-1 ; ni++ ){
        cin >> top1;
        cin >> top2;
        top1--;
        top2--;
        cin >> leng;
        if(leng % 2 != 0){
            uf.set_unti(top1,top2);
            uf.set_unti(top2,top1);
            if(uf.unti_root(top2)>=0){
                uf.unite(top1,uf.unti_root(top2));
            }
            if(uf.unti_root(top1)>=0){
                uf.unite(top2,uf.unti_root(top1));
            }
        }
    }
    uf.output();    
    
}