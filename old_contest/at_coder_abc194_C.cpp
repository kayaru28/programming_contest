


#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
#include <vector>
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


//#include <stack>
//#include <queue>

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

vll A;
ll B;
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;


/*
max 448,000,000
map<string,ll> count_map;
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    A.resize(N);
    map<ll,ll> mapA;
    rep(ni,N){
        cin >> A[ni];
        mapA[A[ni]]++;
    }


    ll variationA = 0;
    vll values;
    for(auto x : mapA) {
        variationA++;
        ll val = x.first;
        values.push_back(val);
    }

    ll ans = 0;
    rep(k1,values.size()){
        for( ll k2 = k1+1 ; k2 <values.size() ; k2++ ){
            ll val1 = values[k1];
            ll val2 = values[k2];
            ltmp = val1 -val2;
            ans += (  mapA[val1] * mapA[val2] * ltmp * ltmp );
        }
    }

    cout << ans << endl;



}