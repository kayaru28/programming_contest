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
ll c[10][10]={};

ll ltmp;
string stmp;
double dtmp;
ll H,W;
ll countans = 0;

ll getsum(vll masu){

    vll wsousa,hsousa;
    rep(wi,W){
        wsousa.push_back(masu[wi]);
    }
    rep(hi,H){
        hsousa.push_back(masu[hi+W]);
    }

    ll sum0 = 0;
    rep(hi,H){
        rep(wi,W){
            if(hsousa[hi]==0&&wsousa[wi]==0){
                sum0+=c[hi][wi];
            }
        }
    }
    return sum0;
}

void counting(vll masu,ll index){
    if(index==H+W){
        ll total = getsum(masu);
        if(total == K) countans++;

    }else{
        masu.push_back(0);
        counting(masu,index+1);
        masu[index] = 1;
        counting(masu,index+1);
    }

}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H;
    cin >> W;
    cin >> K;

    
    string S;
    rep(hi,H){
        cin >> S;
        rep(wi,S.size()){
            stmp = S.substr(wi,1);
            if(stmp == "#") c[hi][wi] = 1;
        }
    }

    vll masu;
    counting(masu,0);

    cout << countans << endl;


    



}