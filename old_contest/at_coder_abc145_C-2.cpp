


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




#include <iomanip>

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
vll Xi;
vll Yi;

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



vvll partern;
void getPartern(vll left_vals, vll ans_vals){
    if(left_vals.size()==0){
        partern.push_back( ans_vals );
    }else{
        rep(li,left_vals.size()){


            vll next_left_vals = left_vals;
            vll next_ans_vals  = ans_vals;
            next_left_vals.erase( next_left_vals.begin() + li );
            next_ans_vals.push_back( left_vals[li] );

            getPartern(next_left_vals,next_ans_vals);

        }
    }
}



double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    Xi.resize(N);
    Yi.resize(N);

    rep(ni,N) cin >> Xi[ni] >> Yi[ni];

    vll vals,tmpvals;
    rep(ni,N) vals.push_back(ni);

    getPartern(vals,tmpvals);

    double ans = 0;
    for( vll xpart : partern ){
        double leng = 0;
        for( ll pi = 1 ; pi <xpart.size() ; pi++ ){
            ll ind1 = xpart[pi];
            ll ind2 = xpart[pi-1];
            leng  = ( Xi[ind1] - Xi[ind2] ) * ( Xi[ind1] - Xi[ind2] );
            leng += ( Yi[ind1] - Yi[ind2] ) * ( Yi[ind1] - Yi[ind2] );
            leng  = pow(leng,0.5);
            ans += leng;
        }
    }

    //cout << "-------------------------------------" << endl;
    //for( vll xpart : partern ){
    //    for(ll pi : xpart) cout << pi << " ";
    //    cout  << endl;
    //}
    //cout << partern.size() << endl;
    ans = ans / partern.size();
    cout << fixed << setprecision(15) << ans << endl;



}