


#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include<bits/stdc++.h>
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
vll Vs;


double double_hosei = 1000000; //求められる精度分補正をかけておく
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

#define all_val_sum 100001
bitset<all_val_sum> xbit;
void calc_part_sum_dp(){
    xbit[0]=1;
    for(ll vi : Vs){
        for( ll ki = all_val_sum-vi ; ki >=0 ; ki-- ){
            xbit[ki+vi] = xbit[ki+vi] | xbit[ki];
        }
        //cout << xbit.to_string() << endl;
    }    
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    ll Vsum=0;
    Vs.resize(N);
    rep(ni,N) cin >> Vs[ni];
    rep(ni,N) Vsum += Vs[ni];
    sort(Vs.begin(),Vs.end());


    calc_part_sum_dp();
    ll ans = llINF;
    for( ll vsumi = 0 ; vsumi <=Vsum ; vsumi++ ){
        //cout << vsumi << " " << xbit[vsumi] << endl;
        if(xbit[vsumi]==0) continue;
        ll tmpans = llmax(vsumi,Vsum-vsumi);
        ans = llmin(ans,tmpans);
    }
    cout << ans << endl;


}