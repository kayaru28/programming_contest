#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;

/*
#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 
int main(){

    int N;
    cin >> N;

    long long A[N];
    int minus_count=0;
    long long min=100000000000;
    long long sum=0;
    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> A[ni];
        if(A[ni]<0)   minus_count++;
        A[ni] = abs(A[ni]);
        if(A[ni]<min) min = A[ni];
        sum += A[ni];
    }

    if(minus_count % 2 == 1) sum = sum - min * 2;

    cout << sum;    

}