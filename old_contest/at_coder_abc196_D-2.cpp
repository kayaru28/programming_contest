


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

ll ans = 0;
void getsolve(ll hi, ll wi,ll A,ll B,vvll mat,ll cnt){
    vvll tmpmat;
    tmpmat.resize(H);
    rep2(hi,H,wi,W) tmpmat[hi].push_back( mat[hi][wi] );
    //tmpmat = mat;
    if(hi>=H) return;
    if(wi>=W){
        getsolve(hi+1,0,A,B,tmpmat,cnt);
        return;
    } 
    if(hi == H-1 && wi == W-1){
        /*
        cout << "------------------------" << endl;
        rep(hi,H){
            rep(wi,W) cout << tmpmat[hi][wi];
            cout << endl;
        }
        cout << "------------------------" << endl;
        */
        ans++;
        return;
    }
    if(tmpmat[hi][wi]>0){
        getsolve(hi,wi+1,A,B,tmpmat,cnt);
        return;
    }
    if(B>0){
        tmpmat[hi][wi] = 1;
        getsolve(hi,wi+1,A,B-1,tmpmat,cnt);
        tmpmat[hi][wi] = 0;
    }
    if(A>0){
        cnt++;
        if(wi+1<W){
            //cout << cnt << " " <<hi << " "<< wi << " " << tmpmat[hi][wi+1] << endl;
            if(tmpmat[hi][wi+1]==0){
                tmpmat[hi][wi] = cnt;
                tmpmat[hi][wi+1] = cnt;
                getsolve(hi,wi+1,A-1,B,tmpmat,cnt);
                tmpmat[hi][wi] = 0;
                tmpmat[hi][wi+1] = 0;
            }
        }
        if(hi+1<H){
            if(tmpmat[hi+1][wi]==0){
                tmpmat[hi][wi] = cnt;
                tmpmat[hi+1][wi] = cnt;
                getsolve(hi,wi+1,A-1,B,tmpmat,cnt);
                tmpmat[hi][wi] = 0;
                tmpmat[hi+1][wi] = 0;
            }
        }
    }
}



double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H >> W >> A >> B;
    vvll mat;
    mat.resize(H);
    rep(hi,H){
        rep(wi,W) mat[hi].push_back(0);
    }
    getsolve(0,0,A,B,mat,1);
    cout << ans << endl;
}