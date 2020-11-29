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
#include <queue>

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
vector<int> R;
vector<int> W;

ll ltmp;
string stmp;
double dtmp;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    string S;
    cin >> S;

    R.push_back(0);
    rep(ni,N){
        
        if(S.substr(ni,1)=="R"){
            R.push_back(ni+1);
        }else{
            W.push_back(ni+1);
        }
    }
    W.push_back(N+1);
    sort(R.rbegin(),R.rend());
    sort(W.begin(),W.end());

    ll ind_r = 0;
    ll ind_w = 0;

    ll cnt = 0;
    while(R[ind_r]>W[ind_w]){
        cnt++;
        ind_r++;
        ind_w++;
    }
    cout << cnt << endl;


    

}