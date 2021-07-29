


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
#define repRangeInc(i,s,n) for (ll i = (s); i <= (n) ; i++)
#define repRangeDec(i,s,n) for (ll i = (s); i >= (n) ; i--)
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
ll R;
ll sr,sc;
ll gr,gc;

ll ltmp;
string stmp;
double dtmp;
ll steps[52][52]={};

ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}
P shihou[4] = {
    P(  0 ,  1),
    P(  0 , -1),
    P(  1 ,  0),
    P( -1 ,  0)
};

double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> R;
    cin >> C;
    cin >> sr >> sc;
    cin >> gr >> gc;

    P shihou[4] = {
        P(  0 ,  1),
        P(  0 , -1),
        P(  1 ,  0),
        P( -1 ,  0)
    };

    vector<char> mapchar[R+2];
    rep(ci,C) mapchar[0].push_back('#');
    rep(ci,C) mapchar[R+1].push_back('#');
    repRangeInc(ri,1,R){
        string S;
        cin >> S;
        mapchar[ri].push_back('#');
        for(char c : S) mapchar[ri].push_back(c);
        rep(ci,C) mapchar[0].push_back('#');
    }

    queue<P> next_points;
    next_points.push( P (sr,sc)  );
    steps[sr][sc]=1;
    while(next_points.size()>0){
        //cout << next_points.size() << endl;
        P point = next_points.front();
        next_points.pop();
        //cout << "->" <<  next_points.size() << endl;
        ll now_step =steps[point.first ][point.second];

        for(P drc : shihou){
            ll next_r = point.first  + drc.first;
            ll next_c = point.second + drc.second;
            if(mapchar[next_r][next_c]=='#') continue;
            
            if( steps[next_r][next_c]==0 ){
                steps[next_r][next_c]= now_step + 1;
                next_points.push( P( next_r,next_c ) );
            }
        }
    }

    cout << steps[gr][gc]-1 << endl;
    

}