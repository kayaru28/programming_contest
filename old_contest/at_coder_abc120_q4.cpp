#include  <iostream>
#include  <stdio.h>
using namespace std;

#include "_data_structure_proc.h"

int main(){

    int N; // island
    int M; // bridge

    cin >> M;
    cin >> N;

    int landA[M];
    int landB[M];
    for(int i = 0 ; i < M;i++){
        cin >> landA[i];
        cin >> landB[i];
    }

    int ans[M];
    int max_ans;
    max_ans = N * ( N - 1 ) / 2;

    int parent[N];
    for(int i = 0 ; i < N;i++){
        parent[i] = 0;
    }

    for(int i = 0 ; i < N;i++){
        int index = ( N - 1 ) - i;
    }

    procBelongGragh bg();

    return 0;
}