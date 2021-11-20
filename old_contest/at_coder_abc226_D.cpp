


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
vvll masu;
double double_hosei = 1000000; //求められる精度分補正をかけておく
long long koyaku_max(long long a,long long b){
    long long r;
    r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
long long kobai_min(long long a,long long b){
    long long tmp;
    tmp =  a / koyaku_max(a,b);
    return tmp * b;
}
string getkey(ll x , ll y ){
    return to_string(x) + " " + to_string(y);
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    Xs.resize(N);
    Ys.resize(N);
    rep(ni,N) cin >> Xs[ni] >> Ys[ni];

    //vector<P> kouho;
    map<string,ll> mapKouho;
    for( ll n1 = 0 ; n1 <N ; n1++ ){
        for( ll n2 = 0 ; n2 <N ; n2++ ){
            if(n1==n2) continue;
            ll dx = Xs[n1] - Xs[n2];
            ll dy = Ys[n1] - Ys[n2];

            if(dx * dy != 0){
                ll dxi = abs(dx);
                ll dyi = abs(dy);
                ll dkouyaku = koyaku_max(dxi,dyi);

                dx /= dkouyaku;
                dy /= dkouyaku;
            }else{
                if(dx == 0 ) dy = 1;
                else dx = 1;
            }
            mapKouho[getkey(dx,dy)]++;
            //kouho.push_back(P(dx,dy));
            dx *= -1;
            dy *= -1;
            mapKouho[getkey(dx,dy)]++;
            //kouho.push_back(P(dx,dy));

        }
    }

    ll ans = 0;
    for(auto x : mapKouho){
        //cout << x.first << endl;
        ans++;
    }
    cout << ans << endl;

    

}