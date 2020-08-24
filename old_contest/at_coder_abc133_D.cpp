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

vll A;
vll B;
vll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;
ll A_min=base10_9+100;
ll ind_min = 0;
ll B_min=base10_9+100;

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

    cin >> N;
    rep(ni,N){
        cin >> ltmp;
        A.push_back(ltmp);
    }

    ll ans0=0;

    rep(ni,N){
        if(ni%2==0) ans0+=A[ni];
        else ans0-=A[ni];
    }

    cout << ans0 << " ";

    ll bef = ans0;
    for( ll ni = 0 ; ni <N-1 ; ni++ ){
        ll ans = (A[ni] - bef/2)*2;
        cout << ans << " ";
        bef = ans;
    }



    

}