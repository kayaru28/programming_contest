


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
typedef pair<ll,P> P2;






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
vll Xs,Ys,Ps;

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
vvll masu;
double double_hosei = 1000000; //求められる精度分補正をかけておく
ll getkey(ll xi, ll yi ){
    return xi * 1000 + yi;
}
ll getxi(ll vi){
    return vi / 1000;
}
ll getyi(ll vi){
    return vi % 1000;
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;

    Xs.resize(N);
    Ys.resize(N);
    Ps.resize(N);
    rep(ni,N) cin >> Xs[ni] >> Ys[ni] >> Ps[ni];

    map<ll,ll> visit;

    //https://cpprefjp.github.io/reference/queue/priority_queue/pop.html
    //std::priority_queue<ll> que;
    //que.push(val);
    //ll getv = que.top();
    //que.pop();
    //typedef pair<ll,ll> P;  
    //priority_queue<P,vector<P>, greater<P> > que;
    //que.push(P(0,base_index));


    ll ans = llINF;
    rep(starti,N){

        //cout << "starti " << starti << endl;

        priority_queue<P,vector<P>, greater<P> > que;
        ll visit[N] = {};
        map<ll,ll> sval;
        sval[starti] = 0;
        que.push(P(1,starti));
        while(que.size()>0){
            P getv = que.top();
            que.pop();
            ll fromi = getv.second;
            //cout << "fromi " << fromi << endl;
            if(sval[fromi]==0){
                sval[fromi] = getv.first;
                rep(nexti,N){
                    if(sval[nexti]==0){
                        ll dist = abs(Xs[fromi] - Xs[nexti]) + abs(Ys[fromi] - Ys[nexti]);
                        ll buf = 0;
                        if(dist % Ps[fromi]>0) buf = 1;
                        //cout << nexti << " "<< dist << " " << buf << endl;
                        ll si = dist / Ps[fromi] + buf;
                        que.push(P(si,nexti));
                    }
                }
            }
        }
        ll tmpans = 0;
        for(auto vi : sval){
            //cout << vi.second << endl;
            tmpans = llmax(tmpans,vi.second);
        }
        ans = llmin(ans,tmpans);
    }

    cout << ans << endl;
}