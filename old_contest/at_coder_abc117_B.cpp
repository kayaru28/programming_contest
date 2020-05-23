#include<iostream>
#include  <stdio.h>
#include  <cmath>

using namespace std;


int main(){

    int N;
    int L;
    int max;
    int sum;
    cin >> N;

    max = 0;
    sum = 0;
    for( int n = 0 ; n < N ; n++ ){

        cin >> L;

        sum = sum + L;

        if(max < L){
            max     = L;
        }

    }
    if(sum - max > max  ){
        cout << "Yes";
    }
    else{
        cout << "No";
    }





}