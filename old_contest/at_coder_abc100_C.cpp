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
    cin >> N;

    int count=0;
    int val;

    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> val;
        while(val % 2==0){
            val = val/2;
            count++;
        }
    }

    cout << count << endl;
    

}