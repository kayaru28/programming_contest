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

ll ans=0;
int flag[20][20]={};
int p[20]={};
void getans(ll pt[20],ll index){
    if(index==N){
        bool fg=true;
        rep(mi,M){
            ll count=0;
            rep(ni,N){
                count += flag[mi][ni] * pt[ni];
            }
            if(count%2!=p[mi]){
                fg = false;
                break;
            } 
        }
        if(fg) ans++;
    }else{
        pt[index]=1;
        getans(pt,index+1);
        pt[index]=0;
        getans(pt,index+1);
    }

}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;
    ll pt[20] = {};
    rep(mi,M){
        cin >> K;
        rep(ki,K){
            int sw;
            cin >> sw;
            sw--;
            flag[mi][sw]=1;
        }
    }
    rep(mi,M){
        int pp;
        cin >> pp;
        p[mi]=pp;
    }


    getans(pt,0);
    cout << ans << endl;
}