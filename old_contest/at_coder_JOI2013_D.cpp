


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
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> D;
    cin >> N;

    vll Ts;
    Ts.resize(D);
    rep(di,D) cin >> Ts[di];

    vll As,Bs,Cs;
    As.resize(N);
    Bs.resize(N);
    Cs.resize(N);
    rep(ni,N){
        cin >> As[ni] >> Bs[ni] >> Cs[ni];
        //cout << ni << endl;
    }
    
    vvll kouho;
    kouho.resize(D);
    rep(di,D){
        ll temprature = Ts[di];
        rep(ni,N){
            if( As[ni] <= temprature && temprature <= Bs[ni] ){
                kouho[di].push_back(Cs[ni]);
            }
        }
    }

    rep(di,D){
        if( kouho[di].size()==1 ){
            ll ind;
            ind = di - 1;
            if(ind >= 0){
                rep(ki,kouho[ind].size()){
                    if(kouho[ind][ki]==kouho[di][0]) kouho[ind].erase(kouho[ind].begin()+ki);
                }
            }
            ind = di + 1;
            if(ind < D){
                rep(ki,kouho[ind].size()){
                    if(kouho[ind][ki]==kouho[di][0]) kouho[ind].erase(kouho[ind].begin()+ki);
                }
            }
        }
    }
    rep(di,D){
        sort(kouho[di].begin(),kouho[di].end());
    }

    ll dp[D][2] = {};
    dp[0][0] = 0;
    dp[0][1] = 0;
    for( ll di = 1 ; di <D ; di++ ){
        ll kouho_max = kouho[di][kouho[di].size()-1];
        ll kouho_min = kouho[di][0];
        ll kouho_max_1 = kouho[di-1][kouho[di-1].size()-1];
        ll kouho_min_1 = kouho[di-1][0];
        dp[di][0] = llmax( abs(kouho_max - kouho_max_1)+ dp[di-1][0]  , abs(kouho_max - kouho_min_1) + dp[di-1][1]  );
        dp[di][1] = llmax( abs(kouho_min - kouho_max_1)+ dp[di-1][0]  , abs(kouho_min - kouho_min_1) + dp[di-1][1]  );
    }

    cout << llmax( dp[D-1][0], dp[D-1][1]  ) << endl;
    //rep(di,D){
    //    cout << dp[di][0] << " " << dp[di][1] << endl;
    //}


}