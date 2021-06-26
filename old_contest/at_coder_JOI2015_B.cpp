


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
vll As;

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



vll dp[2010];
ll convTurn(ll leftcnt){
    if( (N % 2) == (leftcnt % 2 ) ) return 1;
    else return 0;
}
ll getindex(ll index){
    if(index>N) return index - N;
    else if(index <= 0) return index +N;
    else return index;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    As.resize(N+2);

    incRepFT(ni,1,N) cin >> As[ni];
    As[0]   = As[N];
    As[N+1] = As[1];
 

    rep(ni,2010) dp[ni].resize(2010);

    ltmp = convTurn(1);
    incRepFT(ni,1,N) dp[ni][ni] = ltmp * As[ni] ;
    //incRepFT(ni,1,N) cout << dp[ni][ni] << " ";
    //cout << " aaa" << endl;
    for( ll leng = 2 ; leng <=N ; leng++ ){
        ll turni = convTurn(leng);
        for( ll starti = 1 ; starti <=N ; starti++ ){
            ll endi     = getindex( starti + leng - 1 );
            ll starti_1 = getindex( starti + 1 );
            ll endi_1   = getindex( endi - 1 );
            if(turni==1){
                dp[starti][endi] = llmax( dp[starti][endi_1] + As[endi] , dp[starti_1][endi] + As[starti]  );
            }else{
                if(As[starti] > As[endi]) dp[starti][endi] = dp[starti_1][endi];
                else dp[starti][endi] = dp[starti][endi_1];
            }
        }
    }
    
    /*
    for( ll leng = 1 ; leng <=N ; leng++ ){
        for( ll starti = 1 ; starti <=N ; starti++ ){
            ll endi     = getindex( starti + leng - 1 );
            cout << dp[starti][endi] << "\t";
        }
        cout << " " << endl;

    }*/
    

    ll ans = 0;
    for( ll leng = N ; leng <=N ; leng++ ){
        for( ll starti = 1 ; starti <=N ; starti++ ){
            ll endi     = getindex( starti + leng - 1 );
            ans = llmax(ans,dp[starti][endi]);
        }
    }


    cout << ans << endl; 




}