#include<iostream>
#include  <stdio.h>
using namespace std;


int main(){

    int N;
    int T;

    cin >> N;
    cin >> T;

    int ci[N];
    int ti[N];
    int min_c;
    int min_t;

    min_c = 1001
    for( int n = 0 ; n < N ; n++ ){

        cin >> ci[n];
        cin >> ti[n];

        if(ti[n] <= T){
            if(ci[n] < min_c){
                min_c = ci[n];
            }
        }
    }

    if(min_c == 1001){
        cout << "TLE";
    }else{
        cout << min_c;
    }




}