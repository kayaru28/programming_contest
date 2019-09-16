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

    int N_candle;
    int K_candle;
    cin >> N_candle;
    cin >> K_candle;

    int tmpx;
    vector<int> x_left;
    vector<int> x_right;

    for( int xi = 0 ; xi < N_candle ; xi++ ){
        cin >> tmpx;
        if(tmpx<0){
            tmpx = tmpx * -1;
            x_left.insert(x_left.begin(),tmpx);
        }
        else{
            x_right.push_back(tmpx);
        }
    }
    x_left.insert(x_left.begin(),0);
    x_right.insert(x_right.begin(),0);
    int mix = 500000000;
    int right_len = x_right.size();
    int value;
    for( int ri = 0 ; ri <= min(K_candle,right_len-1) ; ri++ ){
        if( K_candle <= ri + x_left.size() - 1 ){
            value = x_right[ri] + x_left[K_candle-ri] + min(x_right[ri],x_left[K_candle-ri]);
            if(mix > value){
                mix = value;
            }
//            cout << ri << " : " << value << endl;

        }
    }

    cout << mix;


}