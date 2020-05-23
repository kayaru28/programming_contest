#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
//#include <stack>
//#include <queue>

/*
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 

#include <math.h>


int main(){

    long long N;
    cin >> N ;
    string ans="";
    if(N==0){
        cout << 0;
    }else{

        long long  volume=0;

        long long  calc;
        if(N%2==0){
            ans = "0";
        }else{
            ans = "1";
            volume = 1;
        }
        calc = -2;
        while(volume != N){
            if((N - volume) % (calc * 2)==0){
                ans = "0" + ans;
            }else{
                volume += calc;
                ans = "1" + ans;
            }
            calc = calc * -2;
            //cout << "ans:" << ans << "calc:" << calc << " volume:" << volume << endl;
        }
        cout << ans;
    }

}