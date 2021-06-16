


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

ll N;
ll M;
ll K;
ll T;
ll H;
ll W;
ll X;
ll R;
ll C;
vvll Aij;

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

ll ans = 0;

/*
bitset<8> xbit(131); 　　　　// 長さ 8 の bitset を定義する。整数から初期化を行う。
bitset<8> xbit('10000011'); // 長さ 8 の bitset を定義する。2 進数から初期化を行う。
xbit = (xbita & xbitb) //XOR
xbit = (xbita | xbitb) //OR
xbit = (xbita ^ xbitb) //XOR
xbit.set(x)    //x 桁目を1に
xbit.reset(x)  //x 桁目を0に
xbit[i] //i桁目にアクセス
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


#define bit_size 15 //2^30 = 10^9
double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> R;
    cin >> C;
    Aij.resize(R);
    rep(ri,R) Aij[ri].resize(C);

    rep(ri,R){
        rep(ci,C){
            cin >> Aij[ri][ci];
        }
    }

    ll keta_bit = R;
    ll bitval = pow(2,keta_bit);
    rep(bi,bitval){
        bitset<bit_size> xbit(bi);

        ///////////////////////////////////////////////////
        //// Process Start --------------------------------

        ll tmpans = 0;
        rep(ci,C){
            ll valC = 0;
            rep(ri,R){
                ll flag = xbit[ri];
                valC += ( (flag + Aij[ri][ci])%2 );
            }
            valC = llmax(valC,R-valC);
            tmpans += valC;
        }

        ans = llmax(ans,tmpans);

        //// Process End   --------------------------------
        ///////////////////////////////////////////////////

    }

    cout << ans << endl;



    

}