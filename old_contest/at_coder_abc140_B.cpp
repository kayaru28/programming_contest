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
 
ll N;
ll NN;

int main(){

    cin >> N;
    int A[N];
    int B[N];
    int C[N];

    rep(i,N) cin >> A[i];
    rep(i,N) cin >> B[i];
    rep(i,N-1) cin >> C[i];

    int ans=0;

    ans+=B[A[0]-1];
    for( int i = 1 ; i <N ; i++ ){
        ans+=B[A[i]-1];
        if(A[i-1] +1 == A[i]){
            ans+=C[A[i-1]-1];
        }
    }
    cout << ans << endl;

}
