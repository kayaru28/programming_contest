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
vll Ai;
ll B;
ll C;
ll N;
ll M;
ll K;

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

ll getval(ll val){
    ll sum = 0;
    rep(ni,N) sum+= abs(Ai[ni]-val);

    return sum;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> N;

    rep(ni,N) A.push_back(0);
    rep(ni,N) cin >> A[ni];

    rep(ni,N) Ai.push_back(A[ni]-(ni+1));

    sort(Ai.begin(),Ai.end());

    vll sumi;
    sumi.push_back(0);
    for( ll ni = 0 ; ni <N ; ni++ ){
        sumi.push_back(sumi[ni]+Ai[ni]);
    }

    ll ans = llINF;
    for( ll ni = 1 ; ni <=N ; ni++ ){
        ll base = Ai[ni-1];
        ll li = abs(sumi[ni-1] - base * (ni-1));
        ll ri = abs((sumi[N]-sumi[ni]) - base * (N-ni));
        ll tmpans = li + ri;
        //cout << ni <<" "<< li << " "<< ri << endl;
        ans = llmin(ans,tmpans);
    }
    cout << ans << endl;

}