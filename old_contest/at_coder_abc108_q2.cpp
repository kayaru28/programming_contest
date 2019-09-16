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
    int point[4][2];
    for( int ni = 0 ; ni < 2 ; ni++ ){
        for( int ti = 0 ; ti < 2 ; ti++ ){
            cin >> point[ni][ti];
        }
    }
    int hen = 0;
    int x=0;
    int y=1;

    for( int id  = 2 ;id < 4 ; id++ ){
        point[id][x] = point[id-1][x] + (point[id-2][y] - point[id-1][y]);
        point[id][y] = point[id-1][y] + (point[id-1][x] - point[id-2][x]);
    }
    for( int ni = 2 ; ni < 4 ; ni++ ){
        for( int ti = 0 ; ti < 2 ; ti++ ){
            cout << point[ni][ti];
            cout << " ";
        }
    }
    



}