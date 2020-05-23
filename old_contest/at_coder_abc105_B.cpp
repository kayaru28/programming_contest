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
    cin >> N ;
    int flag = 0;
    for( int ni = 0 ; ni <= N/4 ; ni++ ){
        if((N-4*ni) % 7 == 0) flag = 1;
    }
    if(flag==1) cout << ans_Yes;
    else cout << ans_No;

}