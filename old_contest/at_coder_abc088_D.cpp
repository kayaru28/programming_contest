


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
map<ll,P> map_number;
string S;
vll HW[50];

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
//for(P dhw : d_move)
ll dfsForHW(ll sh, ll sw , ll eh , ll ew, char key_stop=' '){
    // 行き止まりのある、H行W列のマップに対する幅優先探索
    // 移動の仕方は　d_move 依存

    queue<P> next_points;
    ll steps[H][W]={};

    next_points.push( P (sh,sw)  );
    steps[sh][sw]=1;

    while(next_points.size()>0){
        // get value
        P point = next_points.front();
        ll now_step =steps[point.first ][point.second];
        next_points.pop();

        // update queue
        for(P dhw : d_move){
            ll nh = point.first  + dhw.first;
            ll nw = point.second + dhw.second;
            if(nh < 0) continue;
            if(nw < 0) continue;
            if(nh >= H) continue;
            if(nw >= W) continue;
            if(HW[nh][nw]==key_stop) continue;
           
            if( steps[nh][nw]==0 ){
                steps[nh][nw]= now_step + 1;
                next_points.push( P( nh,nw ) );
            }
        }
    }

    return steps[eh][ew];
}

double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> H;
    cin >> W;


    ll cnt_w = 0;

    rep(hi,H){
        cin >> S;
        ll ci = 0;
        for(char c : S){
            HW[hi].push_back(c);
            if(c=='.') cnt_w++;
        }
    }

    ll sh = 0;
    ll sw = 0;
    ll eh = H-1;
    ll ew = W-1;
    char key_stop = '#';

    ll ans = dfsForHW(sh,sw,eh,ew,key_stop);
    if(ans == 0) cout << -1 << endl;
    else cout << cnt_w - ans << endl;



}