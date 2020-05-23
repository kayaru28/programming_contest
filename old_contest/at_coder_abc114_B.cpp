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
 
int getIntSubstr(string s,int start_index,int length){
    return atoi(s.substr(start_index,length).c_str());
}

int main(){

    string S;
    cin >> S;

    int min;
    min=5000;
    int tmp;
    for( int ni = 0 ; ni < S.length() - 2 ; ni++ ){
        tmp = getIntSubstr(S,ni,3);
        if(min > abs(753-tmp)){
            min = abs(753-tmp);
        }
    }
    cout << min;
}