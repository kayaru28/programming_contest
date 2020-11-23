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
ll K;

ll ltmp;
string stmp;
double dtmp;
string S;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> K;
    
    cin >> S;
    string base = S.substr(0,1);
    string opt;
    opt = "L";
    if(base == "L") opt = "R";

    string li = base + opt;
    string ri = opt + base;

    ll cntK = 0;
    ll get = 0;
    ll index = 0;
    while(index+1 < N){
        stmp = S.substr(index,2);
        if(stmp==li){
            get++;
            index++;
            while(index+1 < N){
                stmp = S.substr(index,2);
                if(stmp==ri){
                    get++;
                    break;
                }
                index++;
            }
            cntK++;
        }
        if(cntK == K ) break;
        index++;
    }

    ll ans = 0;
    rep(ni,N-1){
        if(S.substr(ni,1) == S.substr(ni+1,1)) ans++;
    }

    ans += get;
    cout << ans << endl;
    

}