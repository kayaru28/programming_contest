#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

/*
#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 
int main(){

    int s;
    cin >> s;
    vector<int> alist;
    int count = 1;
    int ax;
    ax = s;
    while(binary_search(alist.begin(),alist.end(),ax)!=true){
        alist.push_back(ax);
        sort(alist.begin(),alist.end());
        count++;
        if(ax%2==0){
            ax = ax / 2;
        }else{
            ax = 3 * ax + 1;
        }
    }
    cout << count;
        

}