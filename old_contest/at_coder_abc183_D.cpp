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

ll A;
ll B;
ll C;
ll N;
ll M;
ll W;
vll S,T,P;

ll ltmp;
string stmp;
double dtmp;

ll gainloss[base10_6]={};

ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> W;

    ll tmax = 0;
    rep(ni,N){
        cin >> ltmp;
        S.push_back(ltmp);
        cin >> ltmp;
        tmax = llmax(tmax,ltmp);
        T.push_back(ltmp);
        cin >> ltmp;
        P.push_back(ltmp);
    }

    rep(ni,N){
        gainloss[S[ni]] += P[ni];
        gainloss[T[ni]] -= P[ni];
    }
    ll need=0;
    string ans = "Yes";
    rep(ti,tmax+1000){
        need += gainloss[ti];
        // cout << ti << " ; " << need << endl;
        if(need > W){
            ans = "No";
            break;
        }


    }
    cout << ans << endl;



    

}