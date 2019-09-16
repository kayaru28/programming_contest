#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
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


string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 


int main(){
    int N;
    cin >> N;
    ll A[N];

    ll Amin=10000000000;
    int i_Amin;
    ll sum = 0;
    rep(ni,N){
        cin >> A[ni];
        if(ni % 2 == 0 ) sum+=A[ni] * 2;
        else sum -= A[ni] * 2;
    }

    ll ans[N];
    ans[0] = sum/2;
    for( int ni = 1 ; ni < N ; ni++ ){
        ans[ni] = ( A[ni-1] - ans[ni-1]/2 ) * 2;
    }

    rep(ni,N){
        cout << ans[ni];
        cout << " ";
    }
}