#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <iomanip> 
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
vll Y;

ll ltmp;
string stmp;
double dtmp;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> N;
    rep(ni,N){
        cin >> ltmp;
        X.push_back(ltmp);
        cin >> ltmp;
        Y.push_back(ltmp);
    }    

    double sum = 0;
    double cnt = 0;
    double NN;
    NN = 1;
    ltmp = N;
    while(ltmp>0){
        NN = NN * N ;
        ltmp--;
    }

    ll basecnt = NN / (N-1);
    rep(ni,N){
        rep(nii,N){
            if(ni!=nii){
                double d = pow(X[ni]-X[nii],2.0)+pow(Y[ni]-Y[nii],2.0);
                d = pow(d,0.5);
                sum += d;
                cnt += 1;
            }
        }
    }
    cout << std::fixed << std::setprecision(15) << sum/cnt*(N-1) << endl;

}