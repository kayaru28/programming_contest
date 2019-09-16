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
#include <string>

int main(){


    int N;
    cin >> N;
    int K;
    cin >> K;
    string S;
    cin >> S;
    string ans = "";
    for( int ni = 0 ; ni < N ; ni++ ){
        if(ni == K -1){
            string target = S.substr(ni,1);
            if(target=="A"){
                ans = ans + "a";
            }else if(target=="B"){
                ans = ans + "b";
            }else{
                ans = ans + "c";
            }
        }else{
            ans = ans + S.substr(ni,1);
        }
    }    
    cout << ans;

}