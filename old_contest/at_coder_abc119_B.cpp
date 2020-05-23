#include  <iostream>
#include  <stdio.h>
using namespace std;


int main(){

    int N;
    cin >> N;

    double x;
    string u;
    double otoshi;
    otoshi = 0;
    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> x;
        cin >> u;
        if(u == "JPY"){
            otoshi = otoshi + x;
        }else{
            otoshi = otoshi + x * 380000;
        }
    }
    cout << otoshi ;

}