#include<iostream>
#include  <stdio.h>
#include  <cmath>

using namespace std;

int main(){

    int N;
    int T;
    int A;

    cin >> N;
    cin >> T;
    cin >> A;

    int H[N];
    double Tx;
    double Tbet_min;
    double Tbet;
    int ans;

    Tbet_min = 500.0;
    ans = 0;

    for( int n = 0 ; n < N ; n++ ){

        cin >> H[n];
        Tx   = T - H[n] * 0.006;
        Tbet = abs( Tx - A );

        if(Tbet < Tbet_min){
            ans      = n;
            Tbet_min = Tbet;
        }







































































































































































    }
    cout << ans + 1;





}