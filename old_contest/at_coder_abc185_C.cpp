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
vector<ll> inv,fact,invfact;

ll wari[20] = {};
int main(){

    cin >> N;
    ll N_cutposition = N-1;

    ll ans = 1;
    rep(ni,11){
        ll kake = N_cutposition - ni;
        ans = ans * kake;
        for( ll wi = 2 ; wi <=11 ; wi++ ){
            if(wari[wi]==0){
                if(ans % wi==0){
                    ans = ans / wi;
                    wari[wi]= 1;
                }
            }
        }
    }
    cout << ans << endl;
 
}