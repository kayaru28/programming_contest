#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
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
    int X;
    
    cin >> N;
    cin >> X;

    int L=0;
    int tmp;
    int cnt=1;
    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> tmp;
        L+=tmp;
        if(L<=X) cnt++;

    }    
    cout << cnt << endl;

}