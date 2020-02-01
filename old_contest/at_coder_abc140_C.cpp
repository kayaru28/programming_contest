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
    int K;
    cin >> K;

    string S;
    cin >> S;

    int Flag[N];
    int cnt=0;
    rep(i,N){
        if(S.substr(i,1)=="L")  Flag[i] = 0;
        else Flag[i] = 1;
        cnt += Flag[i];
    }
    if(cnt==0 || cnt == N) cout << N-1 << endl;
    else{

    }
}
