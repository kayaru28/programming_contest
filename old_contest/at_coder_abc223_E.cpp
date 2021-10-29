


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
vll As,Bs;

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
vvll Ainsu;

vll yakusu;
void getYakusu(ll N){
    yakusu.clear();
    for( ll ni = 1 ; ni*ni <=N ; ni++ ){
        if(N%ni==0){
            yakusu.push_back(ni);
            if(N/ni!=ni) yakusu.push_back(N/ni);
        }
    }
    sort(yakusu.begin(),yakusu.end());
}
double double_hosei = 1000000; //求められる精度分補正をかけておく

ll getXY(ll varid, ll vmin){
    ll li = 0;
    ll ri = Ainsu[varid].size()-1;
    if(Ainsu[varid][li] == vmin) return Ainsu[varid][li];
    if(Ainsu[varid][li] > vmin) return Ainsu[varid][li];
    if(Ainsu[varid][ri] == vmin) return Ainsu[varid][ri];
    if(Ainsu[varid][ri] < vmin) return llINF;
    while(li+1 < ri){
        ll mid = (li+ri)/2;
        if(Ainsu[varid][mid] == vmin) return vmin;
        else if(Ainsu[varid][mid]<vmin) li = mid;
        else ri = mid;
    }
    return Ainsu[varid][ri];
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> X >> Y >> A >> B >> C;
    As.resize(3);
    As[0] = A;
    As[1] = B;
    As[2] = C;
    N =3;

    Ainsu.resize(3);
    rep(ni,N){
        getYakusu(As[ni]);
        Ainsu[ni] = yakusu;
    }
    sort(As.begin(),As.end());

    string ans = "No";

    ll leftX;
    ll leftY;
    
    leftX = X;
    rep(ni,N){
        ll getX = As[ni]/Y;
        if(As[ni]%Y!=0) getX++;
        getX = getXY(ni,getX);
        leftX -= getX;
    }
    if(leftX>0) ans = "Yes";

    leftY = Y;
    rep(ni,N){
        ll getY = As[ni]/X;

        if(As[ni]%X!=0) getY++;
        getY = getXY(ni,getY);
        leftY -= getY;
    }
    if(leftY>0) ans = "Yes";

    rep(ni,N){
        leftX = X;
        leftY = Y;
        ll getX = As[ni]/Y;
        if(As[ni]%Y!=0) getX++;
        getX = getXY(ni,getX);
        leftX -= getX;
        if(leftX>0){
            for( ll di = 1 ; di <=2 ; di++ ){

                ll index = (ni+di) % 3;
                ll getY = As[index]/leftX;
                if(As[index]%leftX!=0) getY++;
                getY = getXY(index,getY);
                leftY -= getY;
            }
            if(leftY > 0 ) ans = "Yes";
        }

        leftX = X;
        leftY = Y;
        ll getY = As[ni]/X;
        if(As[ni]%X!=0) getY++;
        getY = getXY(ni,getY);
        leftY -= getY;
        if(leftY>0){
            for( ll di = 1 ; di <=2 ; di++ ){
                ll index = (ni+di) % 3;
                getX = As[index]/leftY;
                if(As[index]%leftY!=0) getX++;
                getX = getXY(index,getX);
                leftX -= getX;
            }
            if(leftX > 0 ) ans = "Yes";

        }


    }


    cout << ans << endl;
}