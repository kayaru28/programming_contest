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

    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> h[ni];
    }
    sort(h,h+N);
    cout << h[N-1]-h[N-1-(K-1)];
}