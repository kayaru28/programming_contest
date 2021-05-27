


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

vll As;
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

map<ll,ll> summap;
map<ll,ll> sum_map_gu;
map<ll,ll> sum_map_ki;
map<ll,ll> sum_map_gu_tmp;
map<ll,ll> sum_map_ki_tmp;
vll sumvals1;
vll sumvals2;
void show1(){
    incRepFT(ni,0,N){
        cout << sumvals1[ni] << " ";
    }
    cout << endl;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    As.resize(N);
    rep(ni,N) cin >> As[ni];

    sumvals1.push_back(0);
    sumvals1.push_back(As[0]);
    sum_map_gu[0]++;
    sum_map_gu[0]++;
    sum_map_ki[0]++;
    sum_map_ki[As[0]]++;
    //sumvals2.push_back(0);
    //sumvals2.push_back(As[0]*-1);
    for( ll ni = 1 ; ni <N ; ni++ ){
        sumvals1.push_back( sumvals1[ni] * -1 + As[ni]  );   
        //sumvals2.push_back( sumvals2[ni-1] * -1 - As[ni]  );

        if( (ni+1) % 2 == 0 ) sum_map_gu[sumvals1[ni+1]]++;
        else                  sum_map_ki[sumvals1[ni+1]]++;
    }

    ll ans = 0;
    sum_map_gu_tmp[0]++;
    sum_map_gu_tmp[0]++;
    sum_map_ki_tmp[0]++;
    sum_map_ki_tmp[As[0]]++;
    for( ll ni = 1 ; ni <=N ; ni++ ){
        ll basegu = sumvals1[ni-1];
        ll baseki = sumvals1[ni-1];
        if(ni%2==0) basegu *= -1;
        else baseki *= -1;
        ans += (sum_map_gu[basegu]-sum_map_gu_tmp[basegu]);
        ans += (sum_map_ki[baseki]-sum_map_ki_tmp[baseki]);

        if( (ni+1) % 2 == 0 ) sum_map_gu_tmp[sumvals1[ni+1]]++;
        else                  sum_map_ki_tmp[sumvals1[ni+1]]++;
    }

    //show1();

    cout << ans << endl;

}