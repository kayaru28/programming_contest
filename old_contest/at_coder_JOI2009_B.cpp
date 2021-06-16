


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
vll Ds;
vll Ks;

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
//探索したいkeyより大きい
ll getIndexUpperBoundLong(vll x_vector,ll key){
    decltype(x_vector)::iterator it = upper_bound(x_vector.begin(), x_vector.end(), key);
    ll index = distance(x_vector.begin(), it);
    return index;
}
//探索したいkeyより大きい
ll getIndexUpperBoundString(vector<string> x_vector,string key){
    decltype(x_vector)::iterator it = upper_bound(x_vector.begin(), x_vector.end(), key);
    ll index = distance(x_vector.begin(), it);
    return index;
}
//探索したいkey以上
ll getIndexLowerBoundLong(vll x_vector,ll key){
    decltype(x_vector)::iterator it = lower_bound(x_vector.begin(), x_vector.end(), key);
    ll index = distance(x_vector.begin(), it);
    return index;
}
//探索したいkey以上
ll getIndexLowerBoundString(vector<string> x_vector,string key){
    decltype(x_vector)::iterator it = lower_bound(x_vector.begin(), x_vector.end(), key);
    ll index = distance(x_vector.begin(), it);
    return index;
}


double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> D;
    cin >> N;
    cin >> M;

    Ds.resize(N);
    Ks.resize(M);

    Ds[0] = 0;
    for( ll ni = 1 ; ni <N ; ni++ ){
        cin >> Ds[ni];
    }

    rep(mi,M){
        cin >> Ks[mi];
    }

    sort(Ds.begin(),Ds.end());
    Ds.push_back(D);

    ll ans = 0;
    rep(mi,M){
        ll tar_d = Ks[mi];
        ll ind1 = getIndexUpperBoundLong( Ds , tar_d );

        ll d1 = abs( Ds[ind1] - tar_d );
        ind1--;
        if(ind1 == -1) ind1 = N-1;
        ll d2 = abs( Ds[ind1] - tar_d );

        ans += llmin(d1,d2);

    }
    cout << ans << endl;






    

}