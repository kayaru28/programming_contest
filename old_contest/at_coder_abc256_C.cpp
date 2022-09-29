


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
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll Hs[10];
    ll Ws[10];

    rep(hi,3) cin >> Hs[hi];
    rep(wi,3) cin >> Ws[wi];
    ll ans = 0;
    for( ll m00 = 1 ; m00 <30 ; m00++ ){
        ll h0 = Hs[0] - m00;
        ll w0 = Ws[0] - m00;
        for( ll m01 = 1 ; m01 <h0 ; m01++ ){
            for( ll m10 = 1 ; m10 <w0 ; m10++ ){
                ll m02 = h0 - m01;
                ll m20 = w0 - m10;
                ll h1 = Hs[1] - m10;
                ll h2 = Hs[2] - m20;
                for( ll m11 = 1 ; m11 <h1 ; m11++ ){
                    for( ll m21 = 1 ; m21 <h2; m21++ ){
                        ll m12 = h1 - m11;
                        ll m22 = h2 - m21;
                        if(Ws[1]== m01 + m11 + m21){
                            if(Ws[2]== m02 + m12 + m22){
                                /*
                                cout << "------------------" << endl;
                                cout << m00 << " " << m01 << " " << m02 << endl;
                                cout << m10 << " " << m11 << " " << m12 << endl;
                                cout << m20 << " " << m21 << " " << m22 << endl;
                                */
                                ans++;
                            }

                        }
                        
                    }



                }
                
            }        


        }        
        
    }
    cout << ans << endl;
    

}