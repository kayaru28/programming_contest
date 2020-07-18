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

ll getPower(ll value,ll shisu,ll mod){
    ll ans = 1;
    ll cnt = shisu;
    while(cnt>0){
        if(cnt%2==1){
            ans = ans * value % mod;
        }
        value = value * value % mod;
        cnt = cnt/2;
    }
    return ans;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    rep(ni,N){
        cin >> ltmp;
        A.push_back(ltmp);
    }
    int base=1;
    ll ans = 0;

    sort(A.begin(),A.end());
    ll maxi = A.size()-1;
    while( A[maxi] > 0 ){
        ll cnt[2]={};
        rep(ai,A.size()){
            ll flag = A[ai]%2;
            cnt[flag]++;
            A[ai]=A[ai]/2;
        }
        ans = ans + (cnt[0] * cnt[1] % MOD) * base;
        ans = (ans+MOD) % MOD;
        base = (base * 2) % MOD;
    }

    //ll ans = A^B;
    cout << ans << endl;

}