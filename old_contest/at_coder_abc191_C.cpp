


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

ll H,W;

ll ltmp;
string stmp;
double dtmp;

vstr S;

ll getFlag(ll hi, ll wi){
    ll dh[] = {0,1,0,1};
    ll dw[] = {0,0,1,1};
    ll cnt = 0;

    rep(di,4){
        if(S[hi+dh[di]][wi+dw[di]]=='#') cnt++;
    }

    if(cnt==1) return 1;
    else if(cnt==3) return 1;
    return 0;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H;
    cin >> W;
    
    S.resize(H);
    rep(hi,H) cin >> S[hi];


    ll ans = 0;
    for( ll hi = 0 ; hi <=H-1-1 ; hi++ ){
        for( ll wi = 0 ; wi <=W-1-1 ; wi++ ){
            ans += getFlag(hi,wi);            
        }
    }
    cout << ans << endl;




    


}