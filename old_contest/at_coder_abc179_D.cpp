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

#define MOD 998244353
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

ll N;
ll K;
ll A,B;

ll ltmp;
string stmp;
double dtmp;
vll steps[10];
ll SUMstep[10]={};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> K;

    //N = 2 * base10_5;
    //K = 1;

    ll d[N+10]={};
    d[1]=1;
    rep(ni,K){
        cin >> A;
        cin >> B;

        //A = 1;
        //B = N;

        steps[ni].push_back(A);
        steps[ni].push_back(B);

    }

    for( ll ni = 2 ; ni <=N ; ni++ ){
        rep(ki,K){
            ll n0 = ni - steps[ki][1]-1;
            ll n1 = ni - steps[ki][0];
            if(n0>=1) SUMstep[ki]-=d[n0];
            if(n1>=1) SUMstep[ki]+=d[n1];

            d[ni] +=  SUMstep[ki];
            d[ni] = (d[ni] + MOD)% MOD;
        }
    }
    cout << d[N] << endl;

}