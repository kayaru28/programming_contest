


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
ll baseV;
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
vvll masu;
double double_hosei = 1000000; //求められる精度分補正をかけておく

map<ll,ll> memov;

ll getans(ll tarval, ll index){
    if(memov.find(tarval)!=memov.end()) return memov[tarval];
    if(index==N-1) return tarval/As[N-1];
    if(tarval==0) return 0;

    ll crrval = As[index];
    ll nextval = As[index+1];
    ll dans = tarval % nextval / crrval;
    ll tmpans1 = getans( tarval/nextval*nextval,index+1) + dans; 
    ll dval=0;
    if(tarval % nextval>0) dval=1;
    ll tmpans2 = getans( (tarval/nextval + dval )*nextval,index+1) + (nextval/crrval - dans); 

    ll tmpans = llmin(tmpans1,tmpans2);
    memov[tarval] = tmpans;
    return tmpans;

}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> X;

    As.resize(N);
    rep(ni,N) cin >> As[ni];

    cout << getans(X,0) << endl;

    

}