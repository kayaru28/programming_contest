


#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <bitset>

using namespace std;
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
#define vvll vector<vector<ll>>
#define vstr vector<string>
#define vvstr vector<vector<string>>




// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

// for(char c : S)

//min({a1, a2, ..., an})
//max({a1, a2, ..., an})
//swap(a, b)
//S.substr(si)
// sort <--> reverse
//count(v.begin(), v.end(), x) 

//xを2進数にした時の1の数
//__builtin_popcount(x) 
//__builtin_popcountll(x) 

vll A;
vll B;
ll C;
ll D;
ll N;
ll M;
ll K;
ll T;
ll H;
ll W;
ll X;
ll Y;
ll Z;

ll ltmp;
string stmp;
double dtmp;

ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}

double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    A.resize(N);
    B.resize(N);

    rep(ni,N) cin >> A[ni] >> B[ni];

    ll sum_A = 0;
    ll sum_B = 0;
    rep(ni,N) sum_A += A[ni];
    rep(ni,N) sum_B += B[ni];

    ll sum_mid = 0;
    rep(ni,N) sum_mid += abs(A[ni] - B[ni]);

    sort(A.begin(),A.end());
    sort(B.begin(),B.end());

    ll base = N/2;
    ll sum_sta = llINF;
    for( ll ind = base-1 ; ind <=base+1 ; ind++ ){
        ltmp = 0;
        rep(ni,N) ltmp += abs(A[ni] - A[ind]);
        sum_sta = llmin(sum_sta,ltmp);
    }

    ll sum_end = llINF;
    for( ll ind = base-1 ; ind <=base+1 ; ind++ ){
        ltmp = 0;
        rep(ni,N) ltmp += abs(B[ni] - B[ind]);
        sum_end = llmin(sum_end,ltmp);
    }
    cout << sum_sta + sum_mid + sum_end << endl;
    

}