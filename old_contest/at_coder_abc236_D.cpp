


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
vvll As,Bs;

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
    ll bitval = pow(2,keta_bit);d
    rep(bi,bitval){
        bitset<bit_size> xbit(bi);
        ///////////////////////////////////////////////////
        //// Process Start --------------------------------


        //// Process End   --------------------------------
        ///////////////////////////////////////////////////
    }
}
*/
vvll masu;
double double_hosei = 1000000; //求められる精度分補正をかけておく
ll ans = 0;


void getans(ll ri, ll tmpans, bitset<bit_size> xbit){

    if(ri==2*N-1){
        if(xbit[ri]==0){
            ll ci = ri + 1;
            if(xbit[ci]==0){
                tmpans = tmpans ^ As[ri][ci];                
            }
        }
        ans = llmax(ans,tmpans);
    }else{
        if(xbit[ri]==0){
            xbit[ri] = 1;
            for(ll ci = ri+1 ; ci <= 2*N; ci++){
                if(xbit[ci]==0){
                    xbit[ci]=1;
                    getans(ri+1,tmpans^As[ri][ci],xbit);
                    xbit[ci]=0;
                }
            }  
        }else{
            getans(ri+1,tmpans,xbit);
       
        }

    }

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    As.resize(2*N);
    bitset<bit_size> xbit(0);

    for( ll ri = 1 ; ri <=2*N-1 ; ri++ ){
        As[ri].resize(2*N);
        for( ll ci = ri+1 ; ci <=2*N ; ci++ ){
            cin >> As[ri][ci];
        }
    }

    if(N==1){
        cout << As[1][2] << endl;
    }else{
        ll ri = 1;
        for( ll ci = ri+1 ; ci <=2*N ; ci++ ){
            xbit[ci]=1;
            getans(ri+1,As[ri][ci],xbit);
            xbit[ci]=0;
        }

        cout << ans << endl;


    }
    


}