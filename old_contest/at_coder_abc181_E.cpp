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

ll N;
ll M;
vll H;
vll W;
vll SUMH;

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
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;

    rep(ni,N){
        cin >> ltmp;
        H.push_back(ltmp);
    }
    rep(mi,M){
        cin >> ltmp;
        W.push_back(ltmp);
    }

    sort(H.begin(),H.end());
    sort(W.begin(),W.end());

    SUMH.push_back(0);
    for( ll ni = 1 ; ni <N ; ni=ni+2 ){
        SUMH[0]+=(H[ni]-H[ni-1]);
    }
    SUMH.push_back(0);
    for( ll ni = 2 ; ni <N ; ni=ni+2 ){
        SUMH[1]+=(H[ni]-H[ni-1]);
    }
    for( ll ni = 2 ; ni <N ; ni++ ){
        SUMH.push_back(SUMH[ni-2] - (H[ni-1]-H[ni-2]));
    }
    SUMH.push_back(0);
    SUMH.push_back(0);
    SUMH.push_back(0);

    ll ni = 0;
    ll wi = 0;
    ll ans = 0;
    ans = abs(H[0]-W[wi]) + SUMH[1];
    while(wi < M && W[wi] <= H[0]){
        ans = H[0]-W[wi] + SUMH[1];
        wi++;
    }
    while(ni<N && wi < M){
        if(W[wi]<=H[ni]){
            ll tmpans;
            if(ni%2==0){
                tmpans = SUMH[0] - SUMH[ni];
                tmpans += H[ni]-W[wi];
                tmpans += SUMH[ni+1];
            }else{
                tmpans = SUMH[0] - SUMH[ni-1];
                tmpans += W[wi] - H[ni-1];
                tmpans += SUMH[ni];
            }
            ans = llmin(ans,tmpans);
            wi++;
        }else{
            ni++;
        }
    }

    while(wi < M){
        ll tmpans;
        tmpans = SUMH[0] + ( W[wi] - H[N-1]  );
        ans = llmin(ans,tmpans);
        wi++;
    }
    cout << ans << endl;   

}