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

    ll N;
    cin >> N;

    ll A[N];
    ll C[N]={};
    ll FullD=0;

    ll tmp;
    rep(ni,N){
        cin >> tmp;
        tmp--;
        A[ni]=tmp;
        C[tmp]=C[tmp]+1;
    }
    rep(ni,N){
        FullD+=C[ni]*(C[ni]-1) / 2;
    }
    rep(ni,N){
        cout << FullD - (C[A[ni]]-1) << endl;
    }
}