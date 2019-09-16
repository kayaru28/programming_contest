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
    
    cin >> S;

    string tmp;
    int ans = 0;
    for( int si = 0 ; si < S.length() ; si++ ){
        tmp = S.substr(si,1);
        if(tmp == "+") ans++;
        else ans--;
    }
    cout << ans;

    

}