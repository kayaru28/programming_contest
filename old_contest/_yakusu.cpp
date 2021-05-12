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


ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}

vll yakusu;
void getYakusu(ll N){
    for( ll ni = 1 ; ni*ni <=N ; ni++ ){
        if(N%ni==0){
            yakusu.push_back(ni);
            if(N/ni!=ni) yakusu.push_back(N/ni);
        }
    }
    sort(yakusu.begin(),yakusu.end());
}



int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> K;
    ll sumA=0;
    rep(ni,N){
        cin >> ltmp;
        A.push_back(ltmp);
        sumA+=ltmp;
    }

    ll ans = 0;
    getYakusu(sumA);
    rep(yi,yakusu.size()){
        ll tmpans = yakusu[yakusu.size()-1-yi];
        vll mods;
        rep(ni,N)  mods.push_back(A[ni]%tmpans);
        sort(mods.begin(),mods.end());
        ll left = 0;
        ll right = N-1;
        ll sum_l = 0;
        ll sum_r = 0;
        while(left<=right){
            if(sum_l<=sum_r){
                sum_l+=mods[left];
                left++;
            }else{
                sum_r += tmpans-mods[right];
                right--;
            }
        }
        if(sum_l==sum_r && sum_r <= K){
            ans = tmpans;
            break;
        }
    }
    cout << ans << endl;

}