#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
//#include <vector>
//#include <stack>
//#include <queue>

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
    int K;
    cin >> K;
    int h[N];

    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> h[ni];
    }
    sort(h,h+N);
    int min;
    min = h[K-1] - h[0];
    for( int ni = 1 ; ni < N - (K-1); ni++ ){
        if(min > h[K-1+ni]-h[ni]) min = h[K-1+ni]-h[ni];
    }

    cout << min;
}