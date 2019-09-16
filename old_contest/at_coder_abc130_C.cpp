#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
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
 

int main(){

    ll L;
    ll R;
    
    cin >> L;
    cin >> R;

    ll Ll = L % 2019;
    ll Rr = R % 2019;

    if( R - L >= 2019  ) cout << 0 << endl;
    else{

        if(Rr < Ll) Rr += Rr + 2019;

        ll ans = 2019 * 2019;
        ll tmp;
        //cout << Ll << endl;
        //cout << Rr << endl;
        for( int n1 = Ll ; n1 <= Rr-1 ; n1++ ){
            for( int n2 = n1 + 1 ; n2 <= Rr ; n2++ ){
                tmp = (n1 * n2) % 2019;        
                if(tmp < ans ) ans = tmp;
            }
            
        }
        cout << ans << endl;

    }
}