


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
vvll hw;
map<ll,P> map_number;

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
P shihou[4] = {
    P(  0 ,  1),
    P(  0 , -1),
    P(  1 ,  0),
    P( -1 ,  0)
};
//for(P drc : shihou)





double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string S;

    cin >> H;
    cin >> W;
    cin >> N;

    hw.resize(H);
    rep(hi,H){
        cin >> S;
        for(char c : S){
            hw[hi].push_back(c);
        }
    }

    rep2(hi,H,wi,W){
        char tar = hw[hi][wi];
        if(tar=='X') continue;
        if(tar=='.') continue;
        if(tar=='S') map_number[0] = P(hi,wi);
        map_number[tar - '0'] = P(hi,wi);
    }

    ll ans = 0;
    incRepFT(start_number,0,N-1){
        ll end_number = start_number + 1;

        ll steps[H][W]={};
        P point = map_number[start_number];
        steps[ point.first ][ point.second ] = 1;
        queue<P> next_points;
        next_points.push(point);

        while(next_points.size()>0){
            P p0 = next_points.front();
            next_points.pop();
            ll stepi = steps[p0.first][p0.second];
            for(P drc : shihou){
                ll hi = p0.first  + drc.first;
                ll wi = p0.second + drc.second;
                if(hi < 0 ) continue;
                if(wi < 0 ) continue;
                if(hi >= H) continue;
                if(wi >= W) continue;
                if(hw[hi][wi]=='X') continue;

                if(steps[hi][wi]==0){
                    steps[hi][wi] = stepi+1;
                    next_points.push( P(hi,wi) );
                }
            }
        }
        point = map_number[end_number];
        ans += steps[ point.first ][ point.second ];
        ans--;
        //cout << start_number << " " << end_number << " " << ans << endl;
    }
    cout << ans << endl;



    

}