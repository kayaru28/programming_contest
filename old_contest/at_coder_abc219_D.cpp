


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

double double_hosei = 1000000; //求められる精度分補正をかけておく
vll As, Bs;
ll dp[301][301][301] = {};
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> X >> Y;
    As.resize(N);
    Bs.resize(N);
    rep(ni,N) cin >> As[ni] >> Bs[ni];


    for( ll ni = 0 ; ni <N ; ni++ ){
        for( ll xi = 0 ; xi <=X ; xi++ ){
            for( ll yi = 0 ; yi <=Y ; yi++ ){
                dp[xi][yi][ni] = llINF;
            }
        }
    }

    for( ll ni = 0 ; ni <N ; ni++ ){
        dp[0][0][ni] = 0;
    }
    for( ll xi = 1 ; xi <=X ; xi++ ){
        for( ll yi = 1 ; yi <=Y ; yi++ ){
            if(As[0] >= xi) dp[xi][0][0] = 1;
            if(Bs[0] >= yi) dp[0][yi][0] = 1;
            if(As[0] >= xi && Bs[0] >=yi) dp[xi][yi][0] = 1;
        }
    }
    /*
    for( ll xi = 1 ; xi <=X ; xi++ ){
        ll maxi=0;    
        for( ll ni = 1 ; ni <N ; ni++ ){
            maxi = llmax(maxi,As[ni]);
            if(maxi >= xi) dp[xi][0][ni] = 1;
        }
    }
    for( ll yi = 1 ; yi <=Y ; yi++ ){
        ll maxi=0;    
        for( ll ni = 1 ; ni <N ; ni++ ){
            maxi = llmax(maxi,Bs[ni]);
            if(maxi >= yi) dp[0][yi][ni] = 1;
        }
    }
    */


    for( ll ni = 1 ; ni <N ; ni++ ){
        for( ll xi = 0 ; xi <=X ; xi++ ){
            for( ll yi = 0 ; yi <=Y ; yi++ ){
                ll ai = llmax(0, xi - As[ni]);
                ll bi = llmax(0, yi - Bs[ni]);
                dp[xi][yi][ni] = llmin(dp[xi][yi][ni-1],dp[ai][bi][ni-1]+1);
            }
        }
    }
    if(dp[X][Y][N-1]==llINF) dp[X][Y][N-1]=-1;
    cout << dp[X][Y][N-1] << endl;

}