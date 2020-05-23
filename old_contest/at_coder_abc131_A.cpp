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

    string B;
    cin >> B;
    string tmp;
    tmp = B.substr(0,1);
    string tmp2;
    
    string ans = "Good";
    for( int bi = 1 ; bi < B.length() ; bi++ ){
        tmp2 = B.substr(bi,1);
        if(tmp == tmp2) ans = "Bad";
        tmp = B.substr(bi,1);
    }
    cout << ans << endl;

}