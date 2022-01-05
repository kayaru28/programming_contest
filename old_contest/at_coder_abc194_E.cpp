


#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <set>

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
multiset<int> ms;
ms.insert(7);
ms.insert(5);
ms.insert(2);
ms.insert(7);
ms.count(5);
if (ms.find(5) == ms.end()){}else{}
ms.erase(5);
*/
ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}
multiset<int> msval;
map<ll,ll> map_stock;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;
    A.resize(N+1);
    rep(ni,N) cin >> A[ni+1];

    ll Amax = 1.5 * base10_6;

    for( ll ai = 0 ; ai <=Amax ; ai++ ){
        msval.insert(ai);
    }

    
    ll ans = llINF;

    for( ll ai = 1 ; ai <=M-1 ; ai++ ){
        ll val = A[ai];
        map_stock[val]++;
        if (msval.find(val) != msval.end()) msval.erase(val);
    }

    ll outind = 1;
    ll inind  = M ;
    for( ll ii = 0 ; ii <=N-M ; ii++ ){
        ll val;
        val = A[inind];
        map_stock[val]++;
        if (msval.find(val) != msval.end()) msval.erase(val);
        
        decltype(msval)::iterator it = msval.begin();
        ans = llmin(ans,*it);

        val = A[outind];
        map_stock[val]--;
        if(map_stock[val]==0) msval.insert(val);

        outind++;
        inind++;
    }

    cout << ans << endl;

    

}