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


int getIntSubstr(string s,int start_index,int length){
    return atoi(s.substr(start_index,length).c_str());
}
  
int main(){

    string S;
    cin >> S;

    int tmp;
    
    tmp = getIntSubstr(S,0,2);
    if(tmp>0 and tmp < 13){
        tmp = getIntSubstr(S,2,2);
        if(tmp>0 and tmp < 13){
            cout << "AMBIGUOUS";
        }else{
            cout << "MMYY";
        }
        
    }else{
        tmp = getIntSubstr(S,2,2);
        if(tmp>0 and tmp < 13){
            cout << "YYMM";
        }else{

            cout << "NA";
        }

    }

}