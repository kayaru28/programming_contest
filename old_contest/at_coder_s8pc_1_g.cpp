


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

vll Ss,ts,ds,times;
double double_hosei = 1000000; //求められる精度分補正をかけておく
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
#define bit_size 30 //2^30 = 10^9
vvll dp_cnt;
vvll dp_val;
ll getIndexVal(ll nodei){
    return pow(2,nodei-1);
}


map<ll,ll> map_time;
map<ll,ll> map_limit;
void searchNode(){

    int keta_bit = N;
    ll bitval = pow(2,keta_bit);
    for( ll index_sets = 0 ; index_sets <bitval ; index_sets++ ){

        bitset<bit_size> xbit(index_sets);
        if( xbit[1-1]==0 ) continue;
        for( ll f_val = 1 ; f_val <=N ; f_val++ ){
            if(xbit[f_val-1]==0) continue;
            for( ll t_val = 2 ; t_val <=N ; t_val++ ){
                if(xbit[t_val-1]==0) continue;
                ll f_index = getIndexVal(f_val);
                ll t_index = getIndexVal(t_val);
                ll ft_index = f_index + t_index;           

                if( map_time[ft_index]==0 ) continue;

                ll f_index_sets = index_sets - t_index;
                ll arrive_time = dp_val[f_index_sets][f_val] + map_time[ ft_index ];
                if( arrive_time > map_limit[ft_index]) continue;

                if( arrive_time < dp_val[index_sets][t_val] ){
                    dp_cnt[index_sets][t_val] = dp_cnt[f_index_sets][f_val];
                    dp_val[index_sets][t_val] = arrive_time;
                }else if(arrive_time == dp_val[index_sets][t_val] ){
                    dp_cnt[index_sets][t_val] += dp_cnt[f_index_sets][f_val];
                }                                
            }
        }
    }
    
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> N;
    cin >> M;
    Ss.resize(M);
    ts.resize(M);
    ds.resize(M);
    times.resize(M);
    rep(mi,M) cin >> Ss[mi] >> ts[mi] >> ds[mi] >> times[mi];
    
    int keta_bit = N+2;
    ll bitval = pow(2,keta_bit);
    dp_cnt.resize(bitval);
    dp_val.resize(bitval);
    rep2(bi,bitval,bi2,N+2){
        dp_val[bi].push_back(llINF);
        dp_cnt[bi].push_back(0);
    }
    rep(mi,M){
        ll si = getIndexVal(Ss[mi]);
        ll ti = getIndexVal(ts[mi]);
        map_time[ti+si] = ds[mi];
        map_limit[ti+si] = times[mi];
    }

    ll index = getIndexVal(1);
    dp_cnt[index][1] = 1;
    dp_val[index][1] = 0;
    //searchNode(index,1);
    searchNode();
    
    ll last_indexset = 0;
    incRepFT(vi,1,N){
        last_indexset += getIndexVal(vi);
    }

    ll ans_min = llINF;
    ll ans_cnt = 0;
    incRepFT(vi,2,N){
        ll f_val = vi;
        ll t_val = 1;
        ll f_index = getIndexVal(f_val);        
        ll t_index = getIndexVal(t_val);        
        ll ft_index = f_index + t_index;
        ll costtime = map_time[ft_index];
        //cout << last_indexset << " " << f_val << " " <<  dp_val[last_indexset][f_val] << endl;
        if(costtime==0) continue;
        if(dp_val[last_indexset][f_val]==llINF) continue;

        ll arrive_time = dp_val[last_indexset][f_val] + map_time[ ft_index ];
        if( arrive_time > map_limit[ft_index]) continue;

        if( arrive_time < ans_min ){
            ans_cnt = dp_cnt[last_indexset][f_val];
            ans_min = arrive_time;
        }else if(arrive_time = ans_min ){
            ans_cnt += dp_cnt[last_indexset][f_val];
        }
    }
    if(ans_min==llINF) cout << "IMPOSSIBLE" << endl;
    else cout << ans_min << " " <<  ans_cnt   << endl;








}