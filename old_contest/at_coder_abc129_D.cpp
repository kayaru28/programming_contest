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

ll H;
ll W;
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;
vll MASU[base10_5];
ll CNT[2000][2000]={};
ll CNTH[2000][2000]={};
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

    cin >> H;
    cin >> W;
    rep(hi,H){
        string S;
        cin >> S;
        rep(wi,W){
            //cout << wi << endl;
            if(S.substr(wi,1)=="#")   MASU[hi].push_back(1);
            else             MASU[hi].push_back(0);
        }
    }

    ll ans = 0;

    rep(hi,H){
        ll bef = 1;

            rep(wi,W){
            if(MASU[hi][wi]==0){
                if(bef==0) CNT[hi][wi] = CNT[hi][wi-1];
                else{
                    ltmp = 1;
                    while(1){
                        if(wi+ltmp>=W) break;
                        if(MASU[hi][wi+ltmp]==1) break;
                        ltmp++;
                    }
                    CNT[hi][wi]+=ltmp;
                }
            }
            bef = MASU[hi][wi];
        }
    }
    rep(wi,W){
        ll bef = 1;
        rep(hi,H){
            if(MASU[hi][wi]==0){
                if(bef==0) CNTH[hi][wi] = CNTH[hi-1][wi];
                else{
                    ltmp = 1;
                    while(1){
                        if(hi+ltmp>=H) break;
                        if(MASU[hi+ltmp][wi]==1) break;

                        ltmp++;
                    }
                    CNTH[hi][wi]+=ltmp;
                }
            }
            bef = MASU[hi][wi];
        }
    }


    rep(hi,H){
        rep(wi,W){
            ans = llmax(ans,CNT[hi][wi]+CNTH[hi][wi]-1);
        }
    }
    cout << ans << endl;
    

}