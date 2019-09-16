#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;


#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

int main(){

    int N;
    cin >> N;
    vector<int> flower;
    int value;
    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> value;
        flower.push_back(value);
    }

    int left=0;
    int right=0;
    int min_val;
    int count = 0;
    while( left < N){
        right = left;
        while(right+1<N && flower[right+1]>0){
            right++;
        }
        min_val = flower[left];

        for( int index = left + 1 ; index <= right ; index++ ){
            if(min_val > flower[index]) min_val = flower[index];
        }
        count = count + min_val;

        //cout << "count " << count << endl;
        //cout << "l:" << left << "  r:" << right << endl;
        for( int index = left ; index <= right ; index++ ){
            flower[index] = flower[index] - min_val;
        }
        /*
        for( int index = 0 ; index < N ; index++ ){
            cout << flower[index] << " ";
        }
        cout << endl;
        */
        while(left<N && flower[left]==0){
            left++;
        }
        

    }
    cout << count;


}