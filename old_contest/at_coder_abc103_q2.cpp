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

    string S;
    string T;
    cin >> S;
    cin >> T;

    string ans;
    ans = ans_No;

    string roteS;
    roteS = S;
    for( int si = 0 ; si < S.length() ; si++ ){
        roteS = roteS.substr(roteS.length()-1,1) + roteS.substr(0,roteS.length()-1);
        if(roteS == T) ans = ans_Yes;
    }

    cout << ans;

}