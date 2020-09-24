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

ll ans[base10_6]={};
ll pointR=0;
ll pointL=0;
ll countR=0;
ll countL=0;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string S;
    cin >> S;

    string bef = "L";
    ll si = 0;
    for( ll si = 0 ; si <= (S.size()-1)-1 ; si++ ){
        stmp = S.substr(si,2);
        if(stmp=="RL"){
            pointR = si;
            pointL = si+1;
            countR++;
        }else if(stmp=="RR"){
            countR++;
        }else if(stmp=="LL"){
            countL++;
        }

        if(stmp=="LR" || si == (S.size()-1)-1){
            countL++;
            ans[pointR] = ((countR+1) / 2) + (countL / 2);
            ans[pointL] = ((countL+1) / 2) + (countR / 2);
            countL=0;
            countR=0;
        }
    }

    rep(si,S.size()) cout << ans[si] << " ";

}