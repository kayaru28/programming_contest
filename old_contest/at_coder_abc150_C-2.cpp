


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
vll Pi;
vll Qi;

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

vvll parttern;
void getparttern(vll left_vals, vll ans_vals){
    if(left_vals.size()==0){
        parttern.push_back( ans_vals );
    }else{
        rep(li,left_vals.size()){
            vll next_left_vals = left_vals;
            vll next_ans_vals  = ans_vals;
            next_left_vals.erase( next_left_vals.begin() + li );
            next_ans_vals.push_back( left_vals[li] );
            getparttern(next_left_vals,next_ans_vals);
        }
    }
}

double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    Pi.resize(N);
    Qi.resize(N);
    rep(ni,N) cin >> Pi[ni];
    rep(ni,N) cin >> Qi[ni];

    ll Pval = 0;
    ll Qval = 0;
    //rep(ni,N) Pval = Pval * 10 + Pi[ (N-1)-ni  ];
    //rep(ni,N) Qval = Qval * 10 + Qi[ (N-1)-ni  ];
    rep(ni,N) Pval = Pval * 10 + Pi[ ni  ];
    rep(ni,N) Qval = Qval * 10 + Qi[ ni  ];
    //cout << Pval << endl;
    //cout << Qval << endl;

    vll vals;
    vll vals2;
    rep(ni,N) vals.push_back(ni+1);
    getparttern(vals,vals2);
    
    vll vallists;
    for( vll xpart : parttern ){
        ltmp = 0;
        rep(ni,N) ltmp = ltmp * 10 + xpart[ ni ];
        //cout << ltmp << endl;
        vallists.push_back(ltmp);
    }

    sort(vallists.begin(),vallists.end());

    map<ll,ll> map_ans;
    rep(vi,vallists.size()){
        //cout << vallists[vi] << endl;
        map_ans[vallists[vi]] = vi + 1;
    }

    cout << abs( map_ans[Pval] - map_ans[Qval]   ) << endl;

    

}