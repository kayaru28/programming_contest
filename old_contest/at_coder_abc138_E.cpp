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
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

//#include <stack>
//#include <queue>

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

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
/*
max 448,000,000
map<string,ll> count_map;
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/
ll ltmp;
string stmp;
double dtmp;
map<string,ll> countS,countT;
string S,T;
ll solve(){
    rep(si,S.size()){
        countS[S.substr(si,1)]++;
    }
    rep(ti,T.size()){
        countT[T.substr(ti,1)]++;
    }

    for(auto x : countT) {
        if(x.second > 0 && countS[x.first]==0) return -1;
    }

    ll maxti = T.size();
    ll ti = 0;
    string base = S;
    ll ans = 0;
    while(ti<maxti){
        ll tar = T[ti];
        if(base.find(tar)== std::string::npos){
            ans += base.size();
            base = S;
        }

        ll index = base.find(tar);
        ll leng = index + 1;

        base = base.substr(index+1, base.size() - leng);
        ans += leng;
        ti++;
    }

    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

   
    cin >> S >> T;
    cout << solve() << endl; 


    

}