


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
#define vvll vector<vector<ll>>
#define vstr vector<string>
#define vvstr vector<vector<string>>


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
vll C;
vll D;
ll N;
ll M;
ll K;

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
ll getans(ll cnt,vll cs){
    if(cnt==K){
        map<ll,ll> cntmap;
        rep(ki,K){
            if(cs[ki]==0) cntmap[C[ki]]++;
            else cntmap[D[ki]]++;
        }
        ll tmpans = 0;
        rep(mi,M){
            if(cntmap[A[mi]]>0 && cntmap[B[mi]]>0) tmpans++;

        }
        return tmpans;
    }else{
        cs[cnt]=0;
        ll ans1 = getans(cnt+1,cs);
        cs[cnt]=1;
        ll ans2 = getans(cnt+1,cs);
        return llmax(ans1,ans2);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;
    A.resize(M);
    B.resize(M);
    rep(mi,M){
        cin >> A[mi];
        cin >> B[mi];
    }

    cin >> K;
    C.resize(K);
    D.resize(K);
    rep(ki,K){
        cin >> C[ki];
        cin >> D[ki];
    }

    vll cs;
    cs.resize(K);
    cout << getans(0,cs) << endl;

}