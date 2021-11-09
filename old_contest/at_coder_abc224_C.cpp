


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
vll Xs,Ys;

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

//typedef pair<ll,ll> P; 
bool triangleCheck(P p1, P p2, P p3) {

    if(p1==p2) return false;
    if(p1==p3) return false;
    if(p2==p3) return false;

    ll h1X = (p1.first  -p2.first);
    ll h1Y = (p1.second -p2.second);
    ll h2X = (p1.first  -p3.first);
    ll h2Y = (p1.second -p3.second);
    if(h1Y * h2X!= h2Y * h1X) return true;
    else return false;
}


double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    Xs.resize(N);
    Ys.resize(N);
    rep(ni,N) cin >> Xs[ni] >> Ys[ni];
    ll ans = 0;
    for( ll i1 = 0 ; i1 <N ; i1++ ){
        for( ll i2 = i1+1 ; i2 <N ; i2++ ){
            for( ll i3 = i2+1 ; i3 <N ; i3++ ){
                if(triangleCheck(P(Xs[i1],Ys[i1]),P(Xs[i2],Ys[i2]),P(Xs[i3],Ys[i3]))) ans++;
            }
        }
    }
    cout << ans << endl;

}