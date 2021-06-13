

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
vll As,Bs;

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

double double_hosei = 1000000; //求められる精度分補正をかけておく

struct SegmentTree
{
    ll n_leaf;
    vector < ll > v, lazy, leafs;
    ll getDecidedVal(ll val1, ll val2){
        return val1 + val2;
    }
    void init(vector < ll > input_leaf, ll input_size){
        n_leaf = input_size;
        leafs = input_leaf;
        input_size = 4 * n_leaf + 1;
        v.resize(input_size);
        lazy.resize(input_size);
    }
    void build(ll ind_left,ll ind_right,ll ind_org=1){
        if(ind_left > ind_right) return ;
        if(ind_left == ind_right) v[ind_org] = leafs[ind_left];
        else{
            ll ind_mid = (ind_left + ind_right) / 2;
            ll ind_child_left = ind_org * 2;
            ll ind_child_right = ind_org * 2 + 1;
            build(ind_left, ind_mid,ind_child_left);
            build(ind_mid + 1, ind_right, ind_org * 2 + 1);
            v[ind_org] = getDecidedVal(v[ind_child_left]  ,  v[ind_child_right]);
        }
    }
 
    ll query(ll l, ll r, ll ind_left, ll ind_right, ll ind_org = 1) //<--This segtree is for sum of range
    {
        if(ind_left > ind_right) return 0;
        if(l > r) return 0;
        ll ind_mid = (ind_left + ind_right) / 2;
        ll ind_child_left = ind_org * 2;
         ll ind_child_right = ind_org * 2 + 1;
 
        if((l == ind_left) && (r == ind_right)) return v[ind_org];
        else
            return  getDecidedVal(query(l, min(ind_mid, r), ind_left, ind_mid, ind_child_left) , 
                        query(max(ind_mid + 1, l), r, ind_mid + 1, ind_right,ind_child_right));
    } 
    void update(ll index, ll val, ll ind_left, ll ind_right, ll ind_org = 1)
    {
        if(ind_left > ind_right) return ;
        if(ind_left == ind_right){
            if(ind_left == index){
                v[ind_org] = getDecidedVal(v[ind_org], val);
            }
        }
        else{
            ll ind_mid = (ind_left + ind_right) / 2;
            ll ind_child_left = ind_org * 2;
            ll ind_child_right = ind_org * 2 + 1;
            if(ind_mid >= index)
                update(index, val, ind_left, ind_mid, ind_child_left);
            else
                update(index, val, ind_mid + 1, ind_right, ind_child_right);
            v[ind_org] = getDecidedVal(v[ind_child_left] , v[ind_child_right]);
        }
    }
};
 /*
vll A;
segtree.build(0, N - 1); 
stree.update(ai,aval,0,N-1);
stree.query(li,ri,0,N-1);
 */

SegmentTree segtree; 

ll getans(){

    ll Asum=0;
    ll Bsum=0;
    rep(ni,N) Asum+=As[ni];    
    rep(ni,N) Bsum+=Bs[ni];    
    if(Asum!=Bsum) return -1;

    vll inds_0;
    vll inds_N;
    rep(ni,N) inds_0.push_back(ni);
    rep(ni,N) inds_N.push_back(ni);
    ll ans = 0;
    vll Acv;
    rep(ni,N) Acv.push_back(As[ni]+ni);
    map<ll,vll> Acvindex;
    rep(ni,N){
        ll Acvval = Acv[ni];
        Acvindex[Acvval].push_back(ni);
    }
    
    vll tmp;
    rep(ni,N) tmp.push_back(0);
    segtree.init(tmp, N);
    segtree.build(0, N - 1); 

    for( ll tarind = 0 ; tarind <N ; tarind++ ){
        ll Bval = Bs[tarind];
        ll Bcvval = Bval + tarind;

        if(Acvindex[Bcvval].size()==0) return -1;
        ll Aind = Acvindex[Bcvval][0];
        Acvindex[Bcvval].erase(Acvindex[Bcvval].begin());

        
        ll touchi  = segtree.query(Aind,N-1,0,N-1);
        segtree.update(Aind,1,0,N-1);
        ll hosei = touchi;
        //cout << Aind << " " <<  hosei << endl;
        ll diff = hosei; //(Aind+hosei) - tarind;
        ans += diff;
        //cout << tarind << " " << diff << " " << hosei << " " << Aind <<  endl;
    }
    return ans;


}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    As.resize(N);
    Bs.resize(N);
    rep(ni,N) cin >> As[ni];
    rep(ni,N) cin >> Bs[ni];

    cout << getans() << endl;

}