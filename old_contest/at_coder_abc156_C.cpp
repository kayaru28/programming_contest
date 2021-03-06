#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define base10_4 10000      //1e4
#define base10_5 100000     //1e5
#define base10_6 1000000    //1e6
#define base10_7 10000000   //1e7
#define base10_8 100000000  //1e8
#define base10_9 1000000000 //1e9

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

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;
vll X;



int main(){

    
    cin >> N;
    rep(ni,N){
        ll ltmp;
        cin >> ltmp;
        X.push_back(ltmp);
    }
    sort(X.begin(),X.end());

    ll minX = X[0];
    ll sumX=0;
    rep(ni,N) sumX += (X[ni] - minX);

    ll center1 = sumX/N + minX;
    ll center2 = sumX/N + minX + 1;

    ll ans1 = 0;
    ll ans2 = 0;

    rep(ni,N){
        ans1+=pow( (X[ni]-center1)  ,2.0);
        ans2+=pow( (X[ni]-center2)  ,2.0);
    }

    if(ans1<ans2) cout << ans1 << endl;
    else cout << ans2 << endl;

}