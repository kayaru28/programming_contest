


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
#define rep2(i,n,i2,n2) for (ll i = 0; i < (n) ; i++) for (ll i2 = 0; i2 < (n2) ; i2++)
#define incRepFT(i,s,n) for (ll i = (s); i <= (n) ; i++)
#define decRepFT(i,s,n) for (ll i = (s); i >= (n) ; i--)

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
typedef pair<ll,ll> P;  




// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

// for(char c : S)

//min({a1, a2, ..., an})
//max({a1, a2, ..., an})
//swap(a, b)
//S.substr(si)
// sort <--> reverse
//count(v.begin(), v.end(), x) 
// char t - 'a'
// char t - '0'

//xを2進数にした時の1の数
//__builtin_popcount(x) 
//__builtin_popcountll(x) 

ll A;
ll B;
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

string S;

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
P d_move[4] = {
    P(0 , 1),P(0 , -1),P(1 , 0),P(-1 , 0)//,P(1 , 1),P(1 , -1),P(-1 , 1),P(-1 , -1)
};
//for(P drc : d_move)
vstr masu;
vector<vector<ll>> dp;

double double_hosei = 1000000; //求められる精度分補正をかけておく
map<char,ll> score;


ll getdp(ll hi , ll wi, ll flag){
    //cout << hi << " " << wi << " " << flag << endl;
    if(dp[hi][wi]==llINF){
        ll dp1 = -1 * llINF * flag;
        ll dp2 = -1 * llINF * flag;
        if(hi+1<=H) dp1 = getdp(hi+1,wi,flag*-1) + score[masu[hi+1-1][wi-1]] * flag;
        if(wi+1<=W) dp2 = getdp(hi,wi+1,flag*-1) + score[masu[hi-1][wi+1-1]] * flag;
        
        //cout << "insert " <<  hi << " " << wi << " " << flag << endl;
        if(flag==1) dp[hi][wi] = llmax(dp1,dp2);
        else dp[hi][wi] = llmin(dp1,dp2);
    }
    //cout << "return " <<dp[hi][wi] << endl;
    return dp[hi][wi];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    dp.resize(2010);
    rep(ni,2010){
        rep(ni2,2010){
            dp[ni].push_back(llINF);
        }
    }
    score['+']=1;
    score['-']=-1;


    cin >> H;
    cin >> W;
    dp[H][W]=0;
    masu.resize(H);
    rep(hi,H) cin >> masu[hi];
    ll sousa = H -1 + W - 1;
    ll ansscore = getdp(1 , 1, 1);
    /*
    rep(hi,H){
        rep(wi,W){
            cout << dp[hi+1][wi+1] << " ";
        }
        cout  << endl;
    }
    cout << ansscore << endl;
    */
   
    if(ansscore>0){
        cout << "Takahashi" << endl;
    }else if(ansscore==0){
        cout << "Draw" << endl;
    }else{
        cout << "Aoki" << endl;
    }





}