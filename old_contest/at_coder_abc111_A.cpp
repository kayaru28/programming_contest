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
    for( int ni = 1 ; ni < 10 ; ni++ ){
        int kai;
        kai = ni * 111;
        if(N <= kai){
            cout << kai;
            break;
        }
    }
    

}