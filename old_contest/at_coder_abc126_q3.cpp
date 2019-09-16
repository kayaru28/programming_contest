#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <iomanip>
using namespace std;
//#include <vector>
//#include <stack>
//#include <queue>

#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
#include <string>


int getIntSubstr(string s,int start_index,int length){
    return atoi(s.substr(start_index,length).c_str());
}
  
int main(){

    int N;
    int K;
    cin >> N;
    cin >> K;

    int tmp_kaisu=0;
    int kaisu[N+1];

    double tmpK;
    tmpK=K;
    for( int ni = N ; ni > 0 ; ni-- ){
        while(ni < tmpK){
            tmp_kaisu++;
            tmpK = tmpK/2;
        }
        kaisu[ni]=tmp_kaisu;
    }
    double ans = 0.0;
    for( int ni = N ; ni > 0 ; ni-- ){
        double added = 1.0 / N;
        for( int ki = 0 ; ki < kaisu[ni] ; ki++ ){
            added = added * 0.5;
        }
        ans = ans + added;
    }
    //1000000000
    cout << setprecision(12) << ans;


}