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
    int L;
    cin >> N;
    cin >> L;

    int sum=0;
    int eaten;

    eaten = L + 1 -1;
    for( int ni = 0 ; ni < N ; ni++ ){
        sum+=L+(ni+1)-1;
        if(abs(L+(ni+1)-1) < abs(eaten)) eaten = L+(ni+1)-1;
    }
    //cout << sum << endl;
    //cout << eaten << endl ;
    sum -= eaten;
    cout << sum << endl;

}