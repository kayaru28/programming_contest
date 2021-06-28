

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
vll kinds;

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


map<ll,ll> map_kinds_cnt;
vll rc_kinds_cnt[20];       

ll getBitVal(ll val){
    return pow(2,val);
}
#define bit_size 30 //2^30 = 10^9

/*

bitset<8> xbit(131); 　　　　// 長さ 8 の bitset を定義する。整数から初期化を行う。
bitset<8> xbit('10000011'); // 長さ 8 の bitset を定義する。2 進数から初期化を行う。
xbit = (xbita & xbitb) //XOR
xbit = (xbita | xbitb) //OR
xbit = (xbita ^ xbitb) //XOR
xbit.set(x)    //x 桁目を1に
xbit.reset(x)  //x 桁目を0に
xbit[i] //i桁目(0～)にアクセス
xbit.count() //1の数をカウント
ll bit_search_ans = 0;
void execBitAllSearch(int keta_bit){
    ll bitval = pow(2,keta_bit);
    rep(bi,bitval){
        bitset<bit_size> xbit(bi);
        ///////////////////////////////////////////////////
        //// Process Start --------------------------------


        //// Process End   --------------------------------
        ///////////////////////////////////////////////////
    }
}
*/
#define bit_size 30 //2^30 = 10^9
vll dp;
ll solution(){

    ll bit_search_ans = 0;
    int keta_bit = M ;
    ll bitval = pow(2,keta_bit);
    dp.resize(bitval);
    dp[0] = 0;
    incRepFT(bi,1,bitval-1){
        bitset<bit_size> xbit(bi);
        ///////////////////////////////////////////////////
        //// Process Start --------------------------------

        ll tmpans = llINF;
        rep(tari,M){
            if(xbit[tari]==0) continue;

            ll bef_bitval = bi - pow(2,tari);
            bitset<bit_size> bef_xbit(bef_bitval);
            ll starti = 0;
            rep(mi,M){
                if(bef_xbit[mi]==1) starti += map_kinds_cnt[mi];
            }
            ll endi = starti + map_kinds_cnt[tari] - 1;
            ll cnt_tar;
            if(starti==0){
                cnt_tar = rc_kinds_cnt[tari][endi];
            }else{
                cnt_tar = rc_kinds_cnt[tari][endi] - rc_kinds_cnt[tari][starti-1];
            }
            ll cnt_total = endi - starti + 1;

            //cout << tari << " " << bi <<" : " << starti << " -> " << endi  <<" " << cnt_total << " " << cnt_tar << endl;
            tmpans = llmin(tmpans, dp[bef_bitval] + cnt_total - cnt_tar );
        }
        dp[bi] = tmpans;
        //cout << bi << endl;
        //cout << dp[bi]  << endl;
        //// Process End   --------------------------------
        ///////////////////////////////////////////////////
    }
    return dp[bitval-1];

}

double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;
    kinds.resize(N);
    
    rep(ni,N) cin >> kinds[ni];
    rep(ni,N) kinds[ni]--;
    rep(ni,N) map_kinds_cnt[ kinds[ni] ]++;

    rep(mi,M) rc_kinds_cnt[mi].resize(N);
    rep(mi,M){
        rc_kinds_cnt[mi][0] = 0;
    }

    rc_kinds_cnt[ kinds[0] ][0] = 1;
    incRepFT(ni,1,N-1){
        rep(mi,M){
            rc_kinds_cnt[mi][ni] = rc_kinds_cnt[mi][ni-1];
        }
        rc_kinds_cnt[ kinds[ni] ][ni]++;
    }

    
    cout << solution() << endl;

    




    




}