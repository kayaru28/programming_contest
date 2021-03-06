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

vll A;
vll B;
ll C;
ll N;
ll M;
ll K;



ll ltmp;
ll ltmpA;
ll ltmpB;
string stmp;
double dtmp;

#include <queue>
//https://cpprefjp.github.io/reference/queue/priority_queue/pop.html
//std::priority_queue<ll> que;
//que.push(val);
//ll getv = que.top();
//que.pop();
//que.push(P(0,base_index));

typedef pair<ll,ll> P;  
priority_queue<P,vector<P>, greater<P> > que;

int solve(){
    rep(ni,N){
        que.push(P(B[ni],A[ni]));
    }
    ll T=0;
    rep(ni,N){
        P getv = que.top();
        T+= getv.second;
        if(getv.first < T){
            cout << "No" << endl;
            return 0;
        }
        que.pop();
    }

    cout << "Yes" << endl;
    return 0;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    rep(ni,N){
        cin >> ltmpA >> ltmpB;
        A.push_back(ltmpA);
        B.push_back(ltmpB);
    }

    solve();
}