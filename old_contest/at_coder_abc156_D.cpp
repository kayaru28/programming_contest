#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define base10_4 10000      //1e4
#define base10_5 100000     //1e5
#define base10_6 1000000    //1e6
#define base10_7 10000000   //1e7
#define base10_8 100000000  //1e8
#define base10_9 1000000000 //1e9
#define MOD      1000000007
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

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;

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
    return (ans+MOD)%MOD;
}
ll modDivision(ll warukazu,ll mod=MOD){
    //mod is prime number
    //warukazu can not separate
    return getPower(warukazu,MOD-2,MOD);
}


ll a,b;
ll c;
int main(){

    
    cin >> N;
    cin >> a;
    cin >> b;

    if(N==2){
        cout << 0 << endl;
    }else{
        ll nca,ncb;

        nca = 1;
        c = 1;
        for( int ni = 1 ; ni <=a ; ni++ ){
            //nca = nca * (N-(ni-1)) * modDivision(ni,MOD);
            //nca = nca + MOD;
            //nca = nca % MOD;
            nca = nca * (N-(ni-1)) % MOD;
            c = c * ni % MOD;
        }
        ncb = nca;
        nca = nca * modDivision(c,MOD) % MOD;

        for( int ni = a+1 ; ni <=b ; ni++ ){
            //ncb = ncb * (N-(ni-1)) * modDivision(ni,MOD);
            //ncb = ncb + MOD;
            //ncb = ncb % MOD;
            ncb = ncb * (N-(ni-1)) % MOD;
            c = c * ni % MOD;
        }
        ncb = ncb * modDivision(c,MOD) % MOD;

        //nca = (nca + MOD) % MOD;
        //ncb = (ncb + MOD) % MOD;

        ll ans=0;
        ans = -1;
        ans = ans + getPower(2,N,MOD);
        //cout << ans << endl;
        //cout << nca << endl;
        //cout << ncb << endl;
        ans = ans - nca;
        ans = ans + MOD;
        ans = ans % MOD;
        ans = ans - ncb;
        ans = ans + MOD;
        ans = ans % MOD;
        cout << ans << endl;
    }
}