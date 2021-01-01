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

//#include <stack>
//#include <queue>

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

ll H;
ll W;
string S[2100][2100];
ll getMod(ll value,ll mod=MOD){
    if(value == 0) return 0;
    if(mod==0) return -1;
    value %= mod;
    if(value<0) value += mod;
    return value;
}
ll ltmp;
string stmp;
double dtmp;
ll d[2100][2100] = {};
ll dsumh[2100][2100] = {};
ll dsumw[2100][2100] = {};
ll dsumhw[2100][2100] = {};

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H;
    cin >> W;

    rep(hi,H){
        cin >> stmp;
        rep(wi,W){
            S[hi][wi] = stmp.substr(wi,1);
        }
    }
    ll gH = H - 1;
    ll gW = W - 1;


    /*
    for( ll hi = 1 ; hi <H ; hi++ ){
        if(S[hi-1][0]=="."){
            d[hi][0] = getMod(d[hi-1][0]+1);
        }
    }
    for( ll wi = 1 ; wi <W ; wi++ ){
        if(S[0][wi-1]==".") d[0][wi] = getMod(d[0][wi-1]+1);
    }*/

    d[0][0] = 1;

    for( ll hi = 0 ; hi <H ; hi++ ){
        for( ll wi = 0 ; wi <W ; wi++ ){
            ll twi = wi-1;
            ll thi = hi-1;
            if(S[hi][wi]=="#") continue;

            if(wi>0) dsumw[hi][wi] = getMod(dsumw[hi][wi-1] + d[hi][wi-1]); 
            if(hi>0)  dsumh[hi][wi] = getMod(dsumh[hi-1][wi] + d[hi-1][wi]); 
            if(wi>0&&hi>0)  dsumhw[hi][wi] = getMod(dsumhw[hi-1][wi-1] + d[hi-1][wi-1]); 

            d[hi][wi] += dsumh[hi][wi] ;
            d[hi][wi] += dsumw[hi][wi] ;
            d[hi][wi] += dsumhw[hi][wi] ;
            d[hi][wi] = getMod(d[hi][wi]);
        }
    }

    /*
    rep(wi,W){
        rep(hi,H){
            cout << hi << " : " << wi << " = " << d[hi][wi] << endl;
        }
    }*/
    
    cout << d[gH][gW] << endl;
    

}