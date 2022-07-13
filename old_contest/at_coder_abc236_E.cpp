


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




#include <iomanip>

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
vll As,Bs;

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

vvll masu;
double double_hosei = 1000000; //求められる精度分補正をかけておく

double getAvg(){
    ll v_Over = base10_9+1;
    v_Over *= 1000;
    ll v_Inc = 0;

    while(v_Inc+1 < v_Over){
        ll v_avgtarget = (v_Inc + v_Over)/2;
        //cout << "abd" << v_avgtarget << endl;
        vll tmpAs;

        for(ll ai : As){
            tmpAs.push_back(ai * 1000 - v_avgtarget);
        }


        ll dp[N+1];
        dp[0] = 0;
        dp[1] = tmpAs[0];
        for( ll ni = 2 ; ni <=N ; ni++ ){
            ll ai = ni -1;
            dp[ni] = tmpAs[ai] + llmax(dp[ni-1],dp[ni-2]);
            //cout << ni << " " << dp[N] << endl;
        }

        ll base = llmax(dp[N],dp[N-1]);

        //cout << "N " << dp[N] << endl;
        if(base>=0) v_Inc = v_avgtarget;
        else v_Over = v_avgtarget;
    }

    dtmp = v_Inc;
    return dtmp/1000;
    


}

ll getMod(){
    ll v_Over = base10_9+1;
    ll v_Inc = 0;

    ll base;
    if(N%2==0){
        base = 2;
    }else{
        base  =1;
    }

    while(v_Inc+1 < v_Over){
        ll v_mod = (v_Inc + v_Over)/2;
        //cout << "abd" << v_avgtarget << endl;
        vll tmpAs;
        for(ll ai : As){
            ll tmpval;
            if(ai >= v_mod) tmpval = 1;
            else tmpval = -1;
            tmpAs.push_back(tmpval);
        }


        ll dp[N+1];
        dp[0] = 0;
        dp[1] = tmpAs[0];
        for( ll ni = 2 ; ni <=N ; ni++ ){
            ll ai = ni -1;
            dp[ni] = tmpAs[ai] + llmax(dp[ni-1],dp[ni-2]);
            //cout << ni << " " << dp[N] << endl;
        }

        ll basev = llmax(dp[N],dp[N-1]);
        if(basev>=base) v_Inc = v_mod;
        else v_Over = v_mod;

    }
    return v_Inc;
    


}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    As.resize(N);
    rep(ni,N) cin >> As[ni];

     cout << fixed << setprecision(15) << getAvg() << endl;
    cout << getMod() << endl;




    

}