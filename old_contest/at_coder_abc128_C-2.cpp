


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

ll A;
ll B;
ll C;
ll D;
ll N;
ll M;
ll T;
ll H;
ll W;
ll X;
ll Y;
ll Z;

vll K,P;
vvll sw;


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
*/



#define bit_size 30 //2^30 = 10^9


ll bit_search_ans = 0;
void execBitAllSearch(int keta_bit){

    ll bitval = pow(2,keta_bit);
    rep(bi,bitval){
        bitset<bit_size> xbit(bi);

        ///////////////////////////////////////////////////
        //// Process Start --------------------------------

        bool flag = true;
        rep(mi,M){
            ll val=0;
            rep(ki,K[mi]) val += xbit[ sw[mi][ki] ];
            if(val % 2 != P[mi]){
                flag = false;
                break;
            }
        }
        if(flag) bit_search_ans++;

        //// Process End   --------------------------------
        ///////////////////////////////////////////////////

    }

    cout << bit_search_ans << endl;

}



double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;

    K.resize(M);
    P.resize(M);
    sw.resize(M);

    rep(mi,M){
        cin >> K[mi];
        sw[mi].resize( K[mi] );
        rep(ki,K[mi]){
            cin >> sw[mi][ki];
            sw[mi][ki]--;
        }
    }
    rep(mi,M) cin >> P[mi];

    execBitAllSearch(N);



    

}