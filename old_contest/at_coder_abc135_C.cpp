#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
#include <vector>
#define rep(i,n) for (ll i = 0; i < (n) ; i++)
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
#define ld long double
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

//#include <stack>
//#include <queue>

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

vll A;
vll B;
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;
ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll sum0=0;

    cin >> N;
    rep(ni,N+1){
        cin >> ltmp;
        A.push_back(ltmp);
        sum0+=ltmp;
    }
    rep(ni,N){
        cin >> ltmp;
        B.push_back(ltmp);
    }

    rep(ni,N){
        if(A[ni]>=B[ni]){
            A[ni]-=B[ni];
            B[ni]-=B[ni];
        }else{
            B[ni]-=A[ni];
            A[ni]-=A[ni];
        }

        if(A[ni+1]>=B[ni]){
            A[ni+1]-=B[ni];
            B[ni]-=B[ni];
        }else{
            B[ni]-=A[ni+1];
            A[ni+1]-=A[ni+1];
        }


    }

    ll sum1=0;

    rep(ni,N+1){
        sum1+=A[ni];
    }

    cout << sum0 - sum1 << endl;
    

}