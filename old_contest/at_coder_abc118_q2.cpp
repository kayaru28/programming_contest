#include  <iostream>
#include  <stdio.h>
using namespace std;


int main(){

    int N;
    int M;

    cin >> N;
    cin >> M;
    int ans[M];

    for(int i = 0;i < M;i++){
        ans[i]=0;
    }

    int K;
    int index;
    for(int i = 0;i < N;i++){
        cin >> K;
        for(int ki = 0 ; ki < K; ki++){
            cin >> index;
            index      = index - 1;
            ans[index] = ans [index] + 1;
        }

    }

    int count;
    count = 0;
    for(int i = 0; i < M ; i++){
        if(ans[i]==N){
            count = count + 1;
        }
    }
    cout << count;

}