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
 

int main(){

    int H;
    int W;
    
    cin >> H;
    cin >> W;
    
    char a[H][W];
    int flagshowH[H]={};
    int flagshowW[W]={};

    for( int wi = 0 ; wi < W ; wi++ ){
        for( int hi = 0 ; hi < H ; hi++ ){
            cin >> a[hi][wi];
            if(a[hi][wi]=="#") flagshowW[wi]=1;
        }
    }

    for( int hi = 0 ; hi < H ; hi++ ){
        for( int wi = 0 ; wi < W ; wi++ ){
            if(a[hi][wi]=="#") flagshowH[hi]=1;
        }
    }

    for( int wi = 0 ; wi < W ; wi++ ){
        if(flagshowW[wi]==1){
            for( int hi = 0 ; hi < H ; hi++ ){
                if(flagshowH[hi]) cout << a[hi][wi];
            }
            cout << endl;
        }
    }


}