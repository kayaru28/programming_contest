#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>

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

//#include <stack>
//#include <queue>

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

/*
sort(ord.begin(),ord.end(),[&](int x, int y){
    return p[x]>p[y];
});
*/

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;
ll ans = 0;
string S;
map<string,ll> mapmin;
map<string,ll> mapmax;
map<string,ll> mapval;
ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}
vll tmpans;
void zAlgorithm(string S) {
    ll ci = 0;
    vll ansi;
    ansi.resize(S.size());
    for (ll i = 1; i < S.size(); i++){
        if (i+ansi[i-ci] < ci+ansi[ci]) {
            ansi[i] = ansi[i-ci];
        } else {
            ll j = ci+ansi[ci]-i;
            if(j<0) j = 0;
            while (i+j < S.size() && S[j] == S[i+j]) ++j;
            ansi[i] = j;
        }
    }
    ansi[0] = S.size();

    rep(si,S.size()) tmpans.push_back(llmin(si,ansi[si]));
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> S;

    /*N = 5000;
    string S;
    S = "";
    rep(ni,N) S = S + "a"; 
    cout << S << endl;
    */
    rep(si,S.size()) zAlgorithm(S.substr(si,S.size()-si));

    
    sort(tmpans.rbegin(),tmpans.rend());
    cout << tmpans[0] << endl;
    

}