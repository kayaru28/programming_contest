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

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;

vector<pair<ll,ll>> factors;
#include <queue>
void getPrimeFactorize(ll n_max) {
    for (long long a = 2; a * a <= n_max; ++a) {
        if (n_max % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (n_max % a == 0) {
            ++ex;
            n_max /= a;
        }

        // その結果を push
        factors.push_back({a, ex});
    }

    // 最後に残った数について
    if (n_max != 1) factors.push_back({n_max, 1});
}
void checkval(ll fi){
    cout << factors[fi].first << " " << factors[fi].second;
    cout << endl;

}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    getPrimeFactorize(N);

    ll ans = 0;

    rep(fi,factors.size()){
        ll base = 1;
        while(factors[fi].second>=base){
            //checkval(fi);
            ans++;
            factors[fi].second-=base;
            base++;
        }
    }
    cout << ans << endl;

    

}