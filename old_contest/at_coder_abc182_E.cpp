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
vll B;
vll C;
vll D;
ll H;
ll W;
ll N;
ll M;

ll f_den = 1;
ll f_blk = -1;
ll ind_l = 0;
ll ind_r = 1;
ll ind_u = 2;
ll ind_d = 3;

ll ltmp;
string stmp;
double dtmp;

ll masu_val[1510][1510][4]={};
ll masu_res[1510][1510]={};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H;
    cin >> W;
    cin >> N;
    cin >> M;

    rep(ni,N){
        cin >> ltmp;
        ltmp--;
        A.push_back(ltmp);
        cin >> ltmp;
        ltmp--;
        B.push_back(ltmp);
    }
    rep(mi,M){
        cin >> ltmp;
        ltmp--;
        C.push_back(ltmp);
        cin >> ltmp;
        ltmp--;
        D.push_back(ltmp);
    }

    rep(ni,N){
        masu_res[A[ni]][B[ni]] = f_den;
        rep(hi,4) masu_val[A[ni]][B[ni]][hi] = f_den;
    }
    rep(mi,M){
        masu_res[C[mi]][D[mi]] = f_blk;
        rep(hi,4) masu_val[C[mi]][D[mi]][hi] = 0;
    }

    for( ll hi = 0 ; hi <H ; hi++ ){
        for( ll wi = 1 ; wi <= W-1 ; wi++ ){
            if(masu_res[hi][wi]==0) masu_val[hi][wi][ind_l] = masu_val[hi][wi-1][ind_l];
        }
        for( ll wi = W-1-1 ; wi >=0 ; wi-- ){
            if(masu_res[hi][wi]==0) masu_val[hi][wi][ind_r] = masu_val[hi][wi+1][ind_r];
        }
    }
    for( ll wi = 0 ; wi <= W-1 ; wi++ ){
        for( ll hi = 1 ; hi <= H-1 ; hi++ ){
            if(masu_res[hi][wi]==0) masu_val[hi][wi][ind_u] = masu_val[hi-1][wi][ind_u];
        }
        for( ll hi = H-1-1 ; hi >= 0 ; hi-- ){
            if(masu_res[hi][wi]==0) masu_val[hi][wi][ind_d] = masu_val[hi+1][wi][ind_d];
        }
    }

    ll ans = 0;
    rep(hi,H){
        rep(wi,W){
            ltmp = 0;
            rep(houi,4){
                ltmp += masu_val[hi][wi][houi];
            }
            if(ltmp>0) ans++ ;
        }
    }
    cout << ans << endl;

}