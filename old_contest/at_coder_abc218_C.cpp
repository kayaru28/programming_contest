


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

typedef pair<double,double> point;
const double PI=3.14159265358979323846;
double changeKakudoToRadian(ll kakudo,ll kakudohosei = 1000000){
    double radian;
    radian = kakudohosei;
    radian *=  kakudo;
    radian = radian * PI/180;
    radian /= kakudohosei;
    return radian;
}
P rotateXY_radian(P p0, double radian, P center){
    double xi = p0.first;
    double yi = p0.second;
    double xc = center.first;
    double yc = center.second;
    double xi_c = xi - xc;
    double yi_c = yi - yc; 
    double xn = xi_c * cos(radian) - yi_c * sin(radian) + xc;
    double yn = xi_c * sin(radian) + yi_c * cos(radian) + yc;
    return P(xn,yn);
}
P rotateXY_kakudo(P p0, double kakudo, P center){
    double radian = changeKakudoToRadian(kakudo);
    P pn = rotateXY_radian(p0, radian, center);
    return pn;
}


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

double double_hosei = 1000000; //求められる精度分補正をかけておく
priority_queue<P,vector<P>, greater<P> > queS;
priority_queue<P,vector<P>, greater<P> > queT;
priority_queue<P,vector<P>, greater<P> > queT1;
priority_queue<P,vector<P>, greater<P> > queT2;
priority_queue<P,vector<P>, greater<P> > queT3;
priority_queue<P,vector<P>, greater<P> > tmpT;
priority_queue<P,vector<P>, greater<P> > tmpS;

string getans(){
    bool flag;

    flag = true;
    tmpT = queT;
    tmpS = queS;
    P ptmpT = tmpT.top();
    P ptmpS = tmpS.top();
    ll baseX = ptmpT.first - ptmpS.first;
    ll baseY = ptmpT.second - ptmpS.second;
    while(tmpT.size()>0){
        P ptmpT = tmpT.top();
        P ptmpS = tmpS.top();
        tmpT.pop();
        tmpS.pop();
        ll vx = ptmpT.first - ptmpS.first;
        ll vy = ptmpT.second - ptmpS.second;
        if(vx!=baseX || vy!=baseY){
            flag = false;
            break;
        }

    }
    if(flag) return "Yes";


    flag = true;
    tmpT = queT1;
    tmpS = queS;
    ptmpT = tmpT.top();
    ptmpS = tmpS.top();
    baseX = ptmpT.first - ptmpS.first;
    baseY = ptmpT.second - ptmpS.second;
        while(tmpT.size()>0){
        P ptmpT = tmpT.top();
        P ptmpS = tmpS.top();
        tmpT.pop();
        tmpS.pop();
        ll vx = ptmpT.first - ptmpS.first;
        ll vy = ptmpT.second - ptmpS.second;
        if(vx!=baseX || vy!=baseY){
            flag = false;
            break;
        }
    }
    if(flag) return "Yes";

    flag = true;
    tmpT = queT2;
    tmpS = queS;
    ptmpT = tmpT.top();
    ptmpS = tmpS.top();
    baseX = ptmpT.first - ptmpS.first;
    baseY = ptmpT.second - ptmpS.second;
    while(tmpT.size()>0){
        P ptmpT = tmpT.top();
        P ptmpS = tmpS.top();
        tmpT.pop();
        tmpS.pop();
        ll vx = ptmpT.first - ptmpS.first;
        ll vy = ptmpT.second - ptmpS.second;
        if(vx!=baseX || vy!=baseY){
            flag = false;
            break;
        }
    }
    if(flag) return "Yes";


    flag = true;
    tmpT = queT3;
    tmpS = queS;
    ptmpT = tmpT.top();
    ptmpS = tmpS.top();
    baseX = ptmpT.first - ptmpS.first;
    baseY = ptmpT.second - ptmpS.second;
    while(tmpT.size()>0){
        P ptmpT = tmpT.top();
        P ptmpS = tmpS.top();
        tmpT.pop();
        tmpS.pop();
        ll vx = ptmpT.first - ptmpS.first;
        ll vy = ptmpT.second - ptmpS.second;
        if(vx!=baseX || vy!=baseY){
            flag = false;
            break;
        }
    }
    if(flag) return "Yes";






    return "No";
}
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    //https://cpprefjp.github.io/reference/queue/priority_queue/pop.html
    //std::priority_queue<ll> que;
    //que.push(val);
    //ll getv = que.top();
    //que.pop();
    //typedef pair<ll,ll> P;  
    //priority_queue<P,vector<P>, greater<P> > que;
    //que.push(P(0,base_index));
    cin >> N;
    rep(ni,N){
        cin >> S;
        ll cnt = 0;
        for(char ctmp : S){
            if(ctmp=='#'){
                queS.push(P(ni,cnt));
            }
            cnt++;
        }
    }
    rep(ni,N){
        cin >> S;
        ll cnt = 0;
        for(char ctmp : S){
            if(ctmp=='#'){
                queT.push(P(ni,cnt));
            }
            cnt++;
        }
    }


    tmpT = queT;
    while(tmpT.size()>0){
        P ptmp = tmpT.top();
        tmpT.pop();
        ll vx = ptmp.first;
        ll vy = ptmp.second;

        queT1.push(P(vx,-1 * vy));
        queT2.push(P(-1 * vx,vy));
        queT3.push(P(-1 * vx,-1 * vy));
    }

    cout << getans() << endl;


    
       



}