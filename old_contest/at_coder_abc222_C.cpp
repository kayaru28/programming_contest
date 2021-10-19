


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
typedef pair<ll,ll> P;  




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

vstr As,Bs;

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

double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;

    ll N2 = 2*N;
    As.resize(N2);
    rep(ni,N2) cin >> As[ni];

    //https://cpprefjp.github.io/reference/queue/priority_queue/pop.html
    //std::priority_queue<ll> que;
    //que.push(val);
    //ll getv = que.top();
    //que.pop();
    //typedef pair<ll,ll> P;  
    //que.push(P(0,base_index));
    priority_queue<P,vector<P>, less<P> > que;
    rep(ni,N2){
        que.push(P(0,N2-ni));
    }

    rep(mi,M){
        priority_queue<P,vector<P>, less<P> > tmp_que;

        rep(ni,N){
            P p1 = que.top();
            que.pop(); 
            P p2 = que.top();
            que.pop();

            ll ind1 = N2 - p1.second;
            ll ind2 = N2 - p2.second;
            //cout << "check " << ind1 << endl;
            //cout << "check " << ind2 << endl;
            char te1 = As[ind1][mi];
            char te2 = As[ind2][mi];
            if(te1==te2){
                tmp_que.push(P(p1.first,p1.second));
                tmp_que.push(P(p2.first,p2.second));
            }else if(te1=='G' && te2== 'C'){
                tmp_que.push(P(p1.first+1,p1.second));
                tmp_que.push(P(p2.first,p2.second));
            }else if(te1=='C' && te2== 'P'){
                tmp_que.push(P(p1.first+1,p1.second));
                tmp_que.push(P(p2.first,p2.second));
            }else if(te1=='P' && te2== 'G'){
                tmp_que.push(P(p1.first+1,p1.second));
                tmp_que.push(P(p2.first,p2.second));
            }else if(te1=='C' && te2== 'G'){
                tmp_que.push(P(p1.first,p1.second));
                tmp_que.push(P(p2.first+1,p2.second));
            }else if(te1=='P' && te2== 'C'){
                tmp_que.push(P(p1.first,p1.second));
                tmp_que.push(P(p2.first+1,p2.second));
            }else if(te1=='G' && te2== 'P'){
                tmp_que.push(P(p1.first,p1.second));
                tmp_que.push(P(p2.first+1,p2.second));
            }
        }
        //cout << mi << endl;
        que = tmp_que;
    }

    rep(ni,N2){
        P p1 = que.top();
        que.pop(); 
        cout << N2-p1.second+1 << endl;

    }


}