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

int N,K;

vector<vector<long long>> combination(int n, int r, int mod=0) {
    vector<vector<long long>> v(n + 1,vector<long long>(n + 1, 0));
    for (int i = 0; i < v.size(); i++) {
        v[i][0] = 1;
        v[i][i] = 1;
    }
    for (int j = 1; j < v.size(); j++) {
        for (int k = 1; k < j; k++) {
            v[j][k] = (v[j - 1][k - 1] + v[j - 1][k]);
            if(mod>0) v[j][k] %= mod;
        }
    }
    return v;
}
vector<vector<long long>> combi;

int main(){

    cin >> N >> K;

    ll ans;
    combi = combination(2010,2010,MOD);
    for( int sousa = 1 ; sousa <= K  ; sousa++ ){
        ans = 1;
        ans *= combi[N-K+1][sousa];
        ans *= combi[K-1][sousa-1];
        cout << ans % MOD << endl;
    }





}