


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


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> K;

    As.resize(N);
    rep(ni,N){
        cin >> As[ni];
    }

    map<ll,ll> AMap;
    priority_queue<ll,vector<ll>, less<ll>> que;

    que.push(0);
    rep(ni,N){
        que.push(As[ni]);
        AMap[As[ni]]++;
    }
    ll li = 0;
    ll ri = 2 * base10_9 + 1 ;//que.top();
    ll cnt = 0;
    while(li+1<ri){
        ll midi = (ri + li)/2;  

        cnt = 0;
        rep(ni,N){
            cnt += llmax(0,As[ni] - midi + 1);
        }

        if(cnt > K){
            li = midi;
        }else{
            ri = midi;
        }
    }

    cnt = 0;
    ll ans = 0;
    ll tyosei = li * (li+1) /2;
    rep(ni,N){
        if(li < As[ni]){
            ll dans = -1 * tyosei;
            dans += As[ni] * (As[ni] + 1) / 2;
            ans += dans;
            cnt += As[ni] - li;
        }
    }

    ans += li * (K-cnt);

    cout << ans << endl;



}