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
    
    string S;
    cin >> S;

    string tmp;
    tmp = S.substr(0,1);
    if(tmp!="A"){
        cout << "WA";
    }else{
        int count = 0;
        for( int si = 2 ; si < S.length()-1 ; si++ ){
            tmp = S.substr(si,1);
            if(tmp=="C") count++;
        }
        int count2 = 0;
        for( int si = 0 ; si < S.length() ; si++ ){
            if(isupper(S[si])) count2++;
        }
        if(count2 > 2) cout << "WA";
        else if(count==1) cout << "AC";
        else cout << "WA";
    }

}