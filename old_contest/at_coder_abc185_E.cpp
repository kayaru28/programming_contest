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
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define vsort(v) sort(v.begin(),v.end())
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

vll A;
vll B;
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;

ll calcMatch(ll ai, ll bi){
    ll tai = ai;
    ll tbi = bi;
    ll ans = 0;
    while(tai<N && tbi < M){
        if(A[tai]!=B[tbi]) ans++;
        tai++;
        tbi++;
    }
    return ans;
}

vector <vector<int>> dp;
int getval(int ai, int bi){
    int tmp = INF;
    if(ai==1){
        tmp = bi-1;
    } else if(bi==1){
        tmp = ai-1;
    }else{
        for( int tai = 1 ; tai <=ai-1 ; tai++ ) tmp = min(tmp, dp[tai][bi-1] + (ai-1-tai) );
        for( int tbi = 1 ; tbi <=bi-1 ; tbi++ ) tmp = min(tmp, dp[ai-1][tbi] + (bi-1-tbi));
    }
    if(A[ai]!=B[bi]) tmp++;
    return tmp;
}
int getans(){

    dp.resize(1001);
    rep(di,1001) rep(ni,1001) dp[di].push_back(0);
    for( ll ai = 1 ; ai <=N ; ai++ ){
        for( ll bi = 1 ; bi <=M ; bi++ ){
            dp[ai][bi] = getval(ai,bi);
        }
    }
    for( ll ai = 1 ; ai <=N ; ai++ ){
        for( ll bi = 1 ; bi <=M ; bi++ ){
            dp[ai][bi] += (N-ai);
            dp[ai][bi] += (M-bi);
        }
    }

    int ans = INF;
    for( ll ai = 1 ; ai <=N ; ai++ ){
        for( ll bi = 1 ; bi <=M ; bi++ ){
            //cout << "ai " << ai <<  " bi " << bi << " = " << dp[ai][bi] << endl;
            ans = min(ans,dp[ai][bi]);
        }
    }
    

    return ans;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;
    A.resize(N+1);
    B.resize(M+1);
    rep(ni,N) cin >> A[ni+1];
    rep(mi,M) cin >> B[mi+1];

    ll minA = 0;
    ll minB = 0;
    
    cout << getans() << endl;


}