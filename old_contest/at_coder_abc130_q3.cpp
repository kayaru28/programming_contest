#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
//#include <stack>
//#include <queue>
#include <iomanip>

/*
#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 

class SegmentTree {
private:
    int n;
    vector<long long> node;

    int segmentValue(int left_node,int right_node){
        return left_node + right_node;
    }

public:
    int getLeftChildNode(int now_index){
        return node[getLeftChildIndex(now_index)];
    }
    int getRightChildNode(int now_index){
        return node[getRightChildIndex(now_index)];
    }
    int getLeftChildIndex(int now_index){
        return now_index * 2 + 1;
    }
    int getRightChildIndex(int now_index){
        return now_index * 2 + 2;
    }
    int getParentIndex(int now_index){
        int index = (n - 1) / 2;
        return index;
    }
    // 元配列 v をセグメント木で表現する
    reBottomUpCalculate(){
        for(int i=n-2; i>=0; i--) node[i] =segmentValue(node[2*i+1], node[2*i+2]);
    }
    bool isLeafIndex(int now_index){
        if(now_index >= node.size()) return false;
        else if (now_index <= n-2 ) return false;
        else return true;        
    }

    SegmentTree(vector<int> v) {
        // 最下段のノード数は元配列のサイズ以上になる最小の 2 冪 -> これを n とおく
        // セグメント木全体で必要なノード数は 2n-1 個である
        int sz = v.size();
        n = 1; while(n < sz) n *= 2;
        node.resize(2*n-1, 0);

        // 最下段に値を入れたあとに、下の段から順番に値を入れる
        // 値を入れるには、自分の子の 2 値を参照すれば良い
        for(int i=0; i<sz; i++) node[i+n-1] = v[i];
        for(int i=n-2; i>=0; i--) node[i] =segmentValue(node[2*i+1], node[2*i+2]);
    }
    int breadthFirstSearch(int value){
        for( int ni = 0 ; ni < node.size() ; ni++ ){
            if(node[ni]==value) return ni;
        }
        return node.size();
    }
    int breadthFirstSearchGE(int value){
        for( int ni = 0 ; ni < node.size() ; ni++ ){
            if(node[ni]>=value) return ni;
        }
        return node.size();
    }
    int getNodeSize(){
        return node.size();
    }
    inputValueToChild(int now_index,int value){
        if(isLeafIndex(now_index)) node[now_index] = value;
        else{
            inputValueToChild(getLeftChildIndex(now_index),value);
            inputValueToChild(getRightChildIndex(now_index),value);
        }
    }
    calculateValueToChild(int now_index,int value){
        if(isLeafIndex(now_index)) node[now_index] = node[now_index] - value;
        else{
            calculateValueToChild(getLeftChildIndex(now_index),value);
            calculateValueToChild(getRightChildIndex(now_index),value);
        }
    }
    bool calculate(){
        int right_max_index = 0;
        int count = 0;
        int stage = 0;
        int index = 0;
        while(right_max_index < node.size()){
            index = breadthFirstSearchGE(1);
            cout << "index "<<   index << endl;
            while(index <= right_max_index){
                int index2 = index + 1;
                int min_value = node[index];
                while(node[index2] > 0 && index2 <= right_max_index){
                    min_value = min(min_value,node[index2]);
                    index2++;
                }
                while(node[index] > 0 && index <= right_max_index){
                    calculateValueToChild(index,min_value);
                    index++;
                }
                count = count + min_value;
                reBottomUpCalculate();
                index = breadthFirstSearchGE(1);
                cout << "count " << count << endl;
                showAllNodes();
            }
            stage++;
            right_max_index = (pow(2,stage+1) - 1) - 1;
        }
        cout << count;
    }

    showAllNodes(){
        for( int ni = 0 ; ni < node.size() ; ni++ ){
            cout << " " << ni << ":" << node[ni] << endl;
        }
    }

};

int main(){

    int N;
    int K;
    cin >> N;
    cin >> K;

    int tmp;
    vector<int> va;
    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> tmp;
        va.push_back(tmp;
    }

    SegmentTree sega(va);
    




}