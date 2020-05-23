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


    int N;
    cin >> N;

    int v1[100010]={};
    int v2[100010]={};


    if(N==2){
        int val1;
        int val2;
        cin >> val1;
        cin >> val2;
        if(val1==val2){
            cout << 1;
        }else{
            cout << 0;
        }

    }else{
        int val;
        for( int ni = 0 ; ni < N/2 ; ni++ ){
            cin >> val;
            v1[val]++;
            cin >> val;
            v2[val]++;
        }

        int r11=0,r12=0,r21=0,r22=0;
        int v11=0,v12=0,v21=0,v22=0;
        for( int ni = 1 ; ni <= 100000 ; ni++ ){
            if(v1[ni]>v11){
                v12 = v11;
                r12 = r11;

                v11 = v1[ni];
                r11 = ni;
            }else if(v1[ni]>v12){
                r12 = ni;
                v12 = v1[ni];
            }

            if(v2[ni]>v21){
                v22 = v21;
                r22 = r21;

                v21 = v2[ni];
                r21 = ni;
            }else if(v2[ni]>v22){
                r22 = ni;
                v22 = v2[ni];
            }
        }
        if(r11!=r21){
            cout << N - v11 - v21;
        }else{
            cout << min(N-v12-v21,N-v11-v22);
        }

    }





}