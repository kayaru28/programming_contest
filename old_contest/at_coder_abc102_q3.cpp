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

    vector<int> A;
    for( int ni = 0 ; ni < N ; ni++ ){
        int tmp;
        cin >> tmp;
        A.push_back(tmp - (ni + 1) );
    }
    sort(A.begin(),A.end());

    int index;
    int b;
    long long score;
    long long ans;
    if(N==1){
        ans = 0;
    }else{
        if(N%2==0){
            index = N /2 - 1;
            b = A[index];
            score=0;
            for( int ni = 0 ; ni < N ; ni++ ){
                score += abs(A[ni]-b);
            }
            ans = score;

            index = N /2 - 1 + 1;
            b = A[index];
            score=0;
            for( int ni = 0 ; ni < N ; ni++ ){
                score += abs(A[ni]-b);
            }
            ans = min(ans,score);

        }else{
            index = (N + 1) /2 - 1;
            b = A[index];
            score=0;
            for( int ni = 0 ; ni < N ; ni++ ){
                score += abs(A[ni]-b);
            }
            ans = score;
        }
    }
    cout << ans << endl;

}