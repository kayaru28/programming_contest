#include<iostream>
#include  <stdio.h>
using namespace std;

int main(){

    int A;
    int B;
    int C;
    int ans;
    int V1,V2,V3;

    cin >> A;
    cin >> B;
    cin >> C;

    V1 = A;
    if ( V1 < B){
        V2 = V1;
        V1 = B;
    }
    else V2 = B ;

    if (V1 < C ){
        V3 = V2;
        V2 = V1;
        V1 = C;
    }else if ( V2 < C ){
        V3 = V2;
        V2 = C;
    }else{
        V3 = C;
    }

    ans = V1 * 10 + V2 + V3;
    cout << ans;



    return 0;
}