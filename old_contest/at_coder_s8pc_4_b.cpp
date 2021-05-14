


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
ll K;
ll T;
ll H;
ll W;
ll X;
ll Y;
ll Z;
vll Ai;
vll befMaxAi;

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
ll bit_search_ans = 0;
#define bit_size 30 //2^30 = 10^9
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

ll bit_search_ans = 0;
ll ans = llINF;
#define bit_size 30 //2^30 = 10^9

double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> K;

    Ai.resize(N);
    befMaxAi.resize(N);
    rep(ni,N) cin >> Ai[ni];
    ll Amax = 0;
    rep(ni,N){
        befMaxAi[ni] = Amax;
        Amax = llmax(Ai[ni],Amax);
    }


    
    int keta_bit = N;
    ll bitval = pow(2,keta_bit);
    rep(bi,bitval){
        bitset<bit_size> xbit(bi);

        ///////////////////////////////////////////////////
        //// Process Start --------------------------------

        if(xbit[0]!=1) continue;
        if(xbit.count()!=K) continue;

        vll buildings;
        vll buildingsBeforeMax;
        rep(ki,keta_bit){
            if( xbit[ki]==1 ){
                buildings.push_back( Ai[ki] );
                buildingsBeforeMax.push_back( befMaxAi[ki] );
            }
        }

        ll tmpans = 0;
        ll target = 0;
        for( ll bi = 0 ; bi <buildings.size() ; bi++ ){

            target = llmax(target, buildingsBeforeMax[bi]+1 ); 

            //cout << bi << "----------------------------" << endl;
            if(target > buildings[bi]){
                ll cost = target - buildings[bi];
                tmpans += cost;
                //cout << target << " " << buildings[bi] << endl;
                //buildings[bi]=target;
                target = target + 1;
            }else{
                target = buildings[bi]+1;
            }
        }

        //cout << tmpans << " :";
        //rep(ni,K) cout << " " << buildings[ni];
        //cout << endl;

        ans = llmin(ans,tmpans);

        //// Process End   --------------------------------
        ///////////////////////////////////////////////////
    }

    cout << ans << endl;

    

}