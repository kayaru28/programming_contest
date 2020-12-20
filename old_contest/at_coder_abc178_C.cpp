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
ll B;
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;

vector<ll> inv,fact,invfact;

ll getMod(ll value,ll mod){
    if(value == 0) return 0;
    if(mod==0) return -1;
    value %= mod;
    if(value<0) value += mod;
    return value;
}
ll getAns(){

    if(N==1) return 0;


    ll all10 = 1;
    rep(ni,N){
        all10 *= 10;
        all10 = getMod(all10,MOD);
    }

    
    ll all8 = 1;
    rep(ni,N){
        all8 *= 8;
        all8 = getMod(all8,MOD);
    }
    ll all9 = 1;
    rep(ni,N){
        all9 *= 9;
        all9 = getMod(all9,MOD);
    }

    ll ans = all10 - all9*2 + all8;
    ans = getMod(ans,MOD);


    return ans;    






}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    
    cout << getAns() << endl;
    

}