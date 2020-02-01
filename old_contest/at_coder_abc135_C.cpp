#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

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
 
ll A[10000000];
ll B[10000000];
ll cnt=0;

int main(){

    int N;
    
    cin >> N;

    for( int ni = 0 ; ni <N+1 ; ni++ ){
        cin >> A[ni];
    }
    for( int ni = 0 ; ni <N ; ni++ ){
        cin >> B[ni];
    }

    int beated;
    int index;
    index=0;

    beated = min(B[index],A[index]);
    cnt+=beated;
    B[index] -= beated;
    A[index] -= beated;
    
    for( index = 1 ; index <N ; index++ ){

        beated = min(B[index-1],A[index]);
        cnt+=beated;
        B[index-1] -= beated;
        A[index] -= beated;

        beated = min(B[index],A[index]);
        cnt+=beated;
        B[index] -= beated;
        A[index] -= beated;
        
    }
    index = N;
    beated = min(B[index-1],A[index]);
    cnt+=beated;
    B[index-1] -= beated;
    A[index] -= beated;

    cout << cnt << endl;

}