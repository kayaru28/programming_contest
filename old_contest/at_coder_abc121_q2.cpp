#include  <iostream>
#include  <stdio.h>
using namespace std;


int main(){

    int N;
    int M;
    int C;
    
    cin >> N;
    cin >> M;
    cin >> C;

    int value;
    int B[M];

    for( int index = 0 ; index < M ; index++ ){
        cin >> B[index];
    }

    int A;
    int count = 0;
    for( int ai = 0 ; ai < N ; ai++ ){
        value = C;
        for( int ii = 0 ; ii < M ; ii++ ){
            cin >> A;
            value = value + B[ii] * A;
        }
        if(value > 0)    count = count + 1;
    }
    cout << count;    
}