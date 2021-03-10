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

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;
ll D;

ll ltmp;
string stmp;
double dtmp;

ll isInRange(ll X1, ll Y1, ll X2, ll Y2 ){
    if(X1+Y1==X2+Y2) return 1;
    else if(X1-Y1==X2-Y2) return 1;
    else if( abs(X1-X2) + abs(Y1-Y2) <= 3  ) return 1;
    else return 0;
}
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

    cin >> A;
    cin >> B;
    cin >> C;
    cin >> D;

    ll ans = 0;

    if(A==C && B == D) ans = 0;
    else if(isInRange(A,B,C,D)==1) ans = 1;
    else{
        ll dX = C - A;
        ll dY = D - B;

        if((dX+dY) %2 == 0) ans = 2;
        else if( abs(A-C) + abs(B-D) <= 6 ) ans = 2;
        else{
            A += dX;
            B += ( dX * ( dY / abs(dY))  );
            if(isInRange(A,B,C,D)==1) ans = 2;
            else ans = 3;

        }
    }

    cout << ans << endl;


}