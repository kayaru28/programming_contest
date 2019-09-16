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

    int h[N];
    int x[N];
    int y[N];

    int index_base;

    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> x[ni];
        cin >> y[ni];
        cin >> h[ni];
        if(h[ni]>0) index_base = ni;
    }

    int Cx;
    int Cy;
    int H;
    int flag;
    for( Cx = 0 ; Cx <= 100 ; Cx++ ){
        for( Cy = 0 ; Cy <= 100 ; Cy++ ){
            flag = 1;
            H = h[index_base] + abs(x[index_base]-Cx) + abs(y[index_base]-Cy);
            //cout << "Cx Cy" << Cx << " " << Cy << endl;
            //cout << "H " << H << endl;
            for( int ni = 0 ; ni < N ; ni++ ){
                if(h[ni]==0){
                    if(H - abs(x[ni]-Cx) - abs(y[ni]-Cy) > 0){
                        flag = 0;
                        break;
                    } 
                }else{
                    if(H != h[ni] + abs(x[ni]-Cx) + abs(y[ni]-Cy)){
                        flag = 0;
                        break;
                    } 
                }
            }
            if(flag==1) break;
        }
        if(flag==1) break;
    }
    cout << Cx;
    cout << " ";
    cout << Cy;
    cout << " ";
    cout << H;


}