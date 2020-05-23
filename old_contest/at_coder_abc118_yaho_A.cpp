#include  <iostream>
#include  <stdio.h>
using namespace std;


int main(){

    int N;
    int K;
    int J;
    cin >> N;
    cin >> K;

    if(N % 2 == 1){
        N = N + 1;
    }

    J = N / 2;

    if(J >= K){
        cout << "YES";
    }else{
        cout << "NO";
    }
    

}