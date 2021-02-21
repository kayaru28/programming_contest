


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

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K;

    ll cnt_1=0;
    ll cnt_2=0;
    ll cnt_3=0;

    ll val;


    for( ll v1 = 1 ; v1 <=200000 ; v1++ ){
        val = v1 * v1 * v1;
        if(val>K){
            cnt_1 = v1 -1;
            break;
        } 
    }

    for( ll v1 = 1 ; v1 <=200000 ; v1++ ){
        ll tmpK = K / v1 / v1;
        if(tmpK == 0) break;
        cnt_2 += tmpK;
    }
    cnt_2 -= cnt_1;

    for( ll v1 = 1 ; v1 <=200000 ; v1++ ){
        ll tmpK = K / v1;
        for( ll v2 = v1+1 ; v2 <=tmpK ; v2++ ){
            ll tmpKK = tmpK/v2;
            if(tmpKK > v2) cnt_3+=(tmpKK - v2);
            else break;
        }
    }
    //cout << cnt_1 << endl;
    //cout << cnt_2 << endl;
    //cout << cnt_3 << endl;

    ll ans = cnt_1;
    ans += cnt_2 * 3;
    ans += cnt_3 * 6;

    cout << ans << endl;

    

}