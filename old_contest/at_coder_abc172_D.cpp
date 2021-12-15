#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <set>

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
#include <queue>

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

/*
max 448,000,000
map<string,ll> count_map;
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/

vll is_visit;
vector<map<ll,ll>> fk_base;
vector<ll> fk;

vector<ll> factors;
#include <queue>
void getPrimeFactorize(ll n_max) {
    factors.clear();
    for (long long a = 2; a * a <= n_max; ++a) {
        if (n_max % a != 0) continue;
        long long ex = 0; // 指数

        // 割れる限り割り続ける
        while (n_max % a == 0) {
            ++ex;
            n_max /= a;
        }

        // その結果を push
        factors.push_back(ex);
    }

    // 最後に残った数について
    if (n_max != 1) factors.push_back(1);
}

vector<ll> prime_numbers;
void getPrimeNumbers(ll n_max){
    vll is_prime;
    for( ll ni = 0 ; ni <=n_max ; ni++ ){
        is_prime.push_back(true);
    }
   is_prime[0]=is_prime[1]=false;
    for( ll number = 2 ; number <=n_max ; number++ ){
        if(is_prime[number]){
            prime_numbers.push_back(number);
            for( ll ni = number*2 ; ni <=n_max ; ni+=number ){
                is_prime[ni]=false;
            }
        }
    }
}
multiset<ll> ms;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    // for 1;
    ll ans = N * (N+1)/2;

    for( ll ni = 2 ; ni <=N ; ni++ ){
        ll v_baisu = 1;
        ll tar_val = ni*v_baisu;
        while(tar_val <=N){
            ans+=tar_val;
            v_baisu++;
            tar_val = ni * v_baisu;
        }
    }
    cout << ans << endl;

    

}