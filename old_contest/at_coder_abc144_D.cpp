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
#include <iomanip>
//#include <stack>
//#include <queue>

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

double A;
double B;
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;

double getAngle(double teihen,double takasa){
    return atan(takasa/teihen)*180/M_PI;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A;
    cin >> B;
    cin >> N;

    ll V_full = A*A*B;
    ll V_half = V_full/2;
    ll V_enp  = V_full - N;

    double ans;
    if(V_half==N){
        ans = getAngle(B,A);
    }else if(V_half<N){
        double teihen = V_enp / A / A * 2;
        ans = getAngle(teihen,A);
    }else{
        double takasa = N / B / A * 2;
        ans = getAngle(B,takasa);
    }
 
    ans = 90 -ans;
    cout << fixed << setprecision(15) << ans << endl;

}