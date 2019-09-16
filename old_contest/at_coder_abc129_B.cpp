#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
typedef long long ll;
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
    int sum=0;
    
    cin >> N;

    int W[N];
    for( int ni = 0 ; ni < N ; ni++ ){
        cin >> W[ni];
        sum+=W[ni];
    }

    int ans=sum;
    int sum1=0;
    rep(ni,N){
        sum1+=W[ni];
        if(ni+1<N){
            if(sum1 + W[ni+1] > sum/2) ans = min(ans,abs(sum1 - (sum - sum1)));
        }

    }

    cout << ans  << endl;

}