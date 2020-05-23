#include  <iostream>
#include  <stdio.h>
using namespace std;

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
    string black = "0";
    string white = "1";

    int ans[2]={};
    int index;

    for( int si = 0 ; si < S.length() ; si++ ){
        index = si % 2;
        if(S.substr(si,1) == black){
            ans[index] = ans[index] + 1;
        }else{
            index = ( si + 1 ) % 2;
            ans[index] = ans[index] + 1;
        }
    }

    if(ans[0] > ans[1]){
        cout << ans[1];
    }else{
        cout << ans[0];
    }
    

}