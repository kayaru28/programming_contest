


#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <bitset>

using namespace std;
#define rep(i,n) for (ll i = 0; i < (n) ; i++)
#define rep2(i,n,i2,n2) for (ll i = 0; i < (n) ; i++) for (ll i2 = 0; i2 < (n2) ; i2++)
#define incRepFT(i,s,n) for (ll i = (s); i <= (n) ; i++)
#define decRepFT(i,s,n) for (ll i = (s); i >= (n) ; i--)

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
#define vvll vector<vector<ll>>
#define vstr vector<string>
#define vvstr vector<vector<string>>
typedef pair<double,ll> P;  




// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

// for(char c : S)

//min({a1, a2, ..., an})
//max({a1, a2, ..., an})
//swap(a, b)
//S.substr(si)
// sort <--> reverse
//count(v.begin(), v.end(), x) 
// char t - 'a'
// char t - '0'

//xを2進数にした時の1の数
//__builtin_popcount(x) 
//__builtin_popcountll(x) 

ll A;
ll B;
ll C;
ll D;
ll N;
ll M;
ll K;
ll T;
ll H;
ll W;
ll X;
ll Y;
ll Z;

string S;

ll ltmp;
string stmp;
double dtmp;

ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}
P d_move[4] = {
    P(0 , 1),P(0 , -1),P(1 , 0),P(-1 , 0)//,P(1 , 1),P(1 , -1),P(-1 , 1),P(-1 , -1)
};
//for(P drc : d_move)
vector<double> AS;
vector<double> BS;

double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> K;
    cin >> N;
    cin >> M;
    AS.resize(K);
    rep(ki,K) cin >> AS[ki];
    vll sAS = AS;
    sort(sAS.begin(),sAS.end());

    //que.push(P(0,base_index));
    //cout << "start" << endl;
    if(M>=N){
        ll baisu = M/N;
        rep(ki,K){
            BS.push_back(AS[ki]*baisu);
        }
        ll bcnt = 0;
        rep(ki,K){
            BS[ki]+=AS[ki];
            bcnt += BS[ki];
        }
        ll amari = bcnt - M;
        amari = K - amari;
        
    }else{
        double baisu = M/N;
        ll bcnt = 0;
        rep(ki,K){
            ltmp = AS[ki]*baisu;
            BS.push_back(double(ltmp));
            double score;
            score = abs( BS[ki]/M - AS[ki]/N );
            que.push(P( score,ki ));
            bcnt += ltmp;
        }
        ll amari = M - bcnt;
        rep(ai,amari){
            P tar = que.top();
            que.pop();
            ll index = tar.second;
            BS[index]++;
            cout << index << endl;
            double score = abs( BS[index]/M - AS[index]/N );
            que.push(P( score,index )  );
        }
    }
    rep(ki,K) cout << BS[ki] << " ";

}