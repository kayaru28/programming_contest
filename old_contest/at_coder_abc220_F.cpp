

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
vll Us,Vs;
double double_hosei = 1000000; //求められる精度分補正をかけておく
vvll gN;

ll ansval[base10_6]={};
ll after_cnt[base10_6]={};
ll getMod(ll value,ll mod=MOD){
    if(value == 0) return 0;
    if(mod==0) return -1;
    value %= mod;
    if(value<0) value += mod;
    return value;
}

ll ans1 = 0;
void getAfter(ll index, ll layer,ll parent){

    ans1 += layer;
    ans1 = getMod(ans1);

    after_cnt[index] = 1;
    for(ll gi : gN[index]){
        if(gi!=parent){
            getAfter(gi,layer+1,index);
            after_cnt[index] += after_cnt[gi];
        }
    }
}
void getSearch(ll index,ll parent){
    ll tmpans = 0;

    if(index==0){
        tmpans = ans1;
    }else{
        ll pindex = parent;
        tmpans = ansval[pindex];
        tmpans -= after_cnt[index];
        tmpans += (N-after_cnt[index]);
    }

    tmpans = getMod(tmpans);
    ansval[index] = tmpans;

    for(ll gi : gN[index]){
        if(gi!=parent){
            getSearch(gi,index);
        }
    }
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;


    gN.resize(N);
    Us.resize(N);
    Vs.resize(N);
    rep(ni,N-1){
        cin >> Us[ni];
        cin >> Vs[ni];
    }
    rep(ni,N-1){
        Us[ni]--;
        Vs[ni]--;
    }
    rep(ni,N-1){
        gN[Us[ni]].push_back(Vs[ni]);
        gN[Vs[ni]].push_back(Us[ni]);
    }


    getAfter(0,0,-1);

    getSearch(0,-1);


    /*
    cout << "-------------" << endl;
    rep(ni,N){
        cout << after_cnt[ni] << endl;
    }
    cout << "-------------" << endl;
    rep(ni,N){
        cout << after_sum[ni] << endl;
    }
    cout << "-------------" << endl;
    */

    rep(ni,N){
        cout << ansval[ni] << endl;
    }



}