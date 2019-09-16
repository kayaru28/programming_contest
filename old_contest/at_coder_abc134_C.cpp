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
 

int main(){

    int N;
    cin >> N;
    int A[N];
    
    rep(ni,N) cin >> A[ni];

    int n1=0;
    int n2=1;
    if(A[n1]<A[n2]){
        n1 = 1;
        n2 = 0;
    }
    for( int ni = 2 ; ni <N ; ni++ ){
        if(A[ni]>A[n1]){
            n2 = n1;
            n1 = ni;
        }else if(A[ni] > A[n2]){
            n2 = ni;
        }
    }
    rep(ni,N){
        if(ni==n1) cout << A[n2] << endl;
        else cout << A[n1] << endl;
    }


}