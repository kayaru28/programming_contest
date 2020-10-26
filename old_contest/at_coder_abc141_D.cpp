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

vector<double> A;
ll B;
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;
    rep(ni,N){
        cin >> dtmp;
        A.push_back(dtmp);
    }
    sort(A.rbegin(),A.rend());

    ll cnt = 0;
    double base = A[0]/2;
    ll index = 0;


    while( cnt < M ){
        if(A[index]>=base){
            A[index] = A[index]/2.0;
            index++;
            cnt++;
        }else{
            sort(A.rbegin(),A.rend());
            if(A[0]<1) break;
            base = A[0]/2;
            index = 0;
        }
    }

    ll total =0;
    rep(ai,A.size()){
        ltmp = A[ai];
        total += ltmp;
    }
    cout << total << endl;
}