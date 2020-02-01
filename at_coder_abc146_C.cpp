#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <string>
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

#include <math.h>
/*
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 

int main(){


    ll A;
    ll B;
    ll X;
    cin >> A;
    cin >> B;
    cin >> X;

    int keta;
    int K=1;
    for( int keta = 10 ; keta >0 ; keta-- ){
        if( X >= A * pow(10.0,(double)keta-1) + B * keta){
            K = keta;
            break;
        } 
    }

    K = max(1,K);

    X = X - B * K;
    //cout << K << endl;
    //cout << X << endl;
    if(X/A >1000000000 ) cout << 1000000000 << endl;
    else if (X/A < 0) cout << 0 << endl;
    else cout << X / A << endl;


}