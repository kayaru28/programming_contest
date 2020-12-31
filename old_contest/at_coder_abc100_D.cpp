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

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;

vll xi,yi,zi;
ll xf,yf,zf;

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
#include <queue>
//https://cpprefjp.github.io/reference/queue/priority_queue/pop.html
//std::priority_queue<ll> que;
//que.push(val);
//ll getv = que.top();
//que.pop();
//que.push(P(0,base_index));
typedef pair<ll,ll> P;  

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;

    rep(ni,N){
        cin >> ltmp;
        xi.push_back(ltmp);
        cin >> ltmp;
        yi.push_back(ltmp);
        cin >> ltmp;
        zi.push_back(ltmp);
    }

    ll ans = 0;
    for (ll xf = -1 ; xf <=1 ; xf=xf+2 ){
        for (ll yf = -1 ; yf <=1 ; yf=yf+2 ){
            for (ll zf = -1 ; zf <=1 ; zf=zf+2 ){
                priority_queue<P> que;

                rep(ni,N){
                    ll flag=0;
                    flag = xf * xi[ni] + yf * yi[ni] + zf * zi[ni];
                    que.push(P(flag,ni));
                }


                ll xsum=0;
                ll ysum=0;
                ll zsum=0;
                ll mi = 0;

                while(M > mi){
                    P getv = que.top();
                    que.pop();

                    ll ni = getv.second;
                    xsum += xi[ni];
                    ysum += yi[ni];
                    zsum += zi[ni];
                    mi++;
                }

                ltmp = abs(xsum) + abs(ysum) + abs(zsum);
                ans = llmax(ans, ltmp);
                //cout << ltmp << " = " << xsum << " + " << ysum << " + "<< zsum << endl;

            }
        }
    }
    cout << ans  << endl;

    

}