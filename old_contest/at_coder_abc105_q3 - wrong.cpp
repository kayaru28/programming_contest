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

    int N;
    cin >> N ;
    vector<int> ans;
    if(N==0){
        cout << 0;
    }else{
        int volume=0;
        int val=1;
        int flag;
        if(N>0){
            flag = 0;
        }else{
            flag = 1;
        }
        int absN = abs(N);

        int shisu=0;
        while(absN > volume){
            if(shisu % 2 == flag){
                volume += val;
                ans.push_back(1);
                //cout << volume << endl;
            }else{
                ans.push_back(0);
            }
            val = val * 2;
            shisu++;
        }


        vector<int> minus_ans;
        int bina = volume - absN;
        for (int i = 0; bina > 0 ; i++)
        {
            minus_ans.push_back(bina%2);
            bina = bina/2;
        }

        //cout << "second" << endl;
        for( int ni = 0 ; ni < minus_ans.size()  ; ni++ ){
            ans[ni] = (ans[ni] + minus_ans[ni]) % 2;
        }

    }

    for( int ni = ans.size()-1 ; ni >=0 ; ni-- ) cout << ans[ni];
}