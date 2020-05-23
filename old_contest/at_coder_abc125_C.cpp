#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;

/*
#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 
int get_val(int a,int b){
    int tmp;
    
    if(a<b){
        tmp = a;
        a = b;
        b = tmp;
    }
 
    /* ユークリッドの互除法 */
    int r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}


int main(){

    int N;
    cin >> N;

    int A[N];
    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> A[ni];
    }

    sort(A,A+N);

    int value_bef[N];
    int value_aft[N];

    value_bef[0]=A[0];
    for( int ni = 1 ; ni < N ; ni++ ){
        if(value_bef[ni-1]==1){
            value_bef[ni] = 1;
        }else{
            value_bef[ni] = get_val(value_bef[ni - 1],A[ni]) ;
        }
    }

    int ni_max = N-1 ;
    value_aft[ni_max]=A[ni_max];
    for( int ni = ni_max-1 ; ni >=0 ; ni-- ){
        if(value_aft[ni+1]==1){
            value_aft[ni] = 1;
        }else{
            value_aft[ni] = get_val(value_aft[ni + 1],A[ni]) ;
        }
    }

    int max = value_aft[1];
    if(max<value_bef[ni_max-1]) max = value_bef[ni_max-1];

    int tmp;
    for( int ni = 1 ; ni < ni_max ; ni++ ){
        tmp = get_val(value_bef[ni-1],value_aft[ni+1]);
        if(max < tmp) max = tmp;
    }

    cout << max;    

}