


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

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;
double X,Y,R;

ll ltmp;
string stmp;
double dtmp;

double base = 100000; //求められる精度分補正をかけておく



ll getbetval(double a, double b){
    ll la = a;
    ll lb = b;
    ll hosei = 0;
    ll val;
    if(a == 0 || b == 0){
        val= (la - lb) + 1;

    }else if(a>0 && b < 0){
        val= (la - lb) + 1;

    }else if(a>0 && b>0 ){
        dtmp = lb * base - b * base;
        if(dtmp == 0) hosei = 1;
        val= (la - lb) + hosei;
    }else{
        dtmp = la * base - a * base;
        if(dtmp == 0) hosei = 1;
        val= (la - lb) + hosei;
    }
    return val;
}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> X >> Y >> R;

    double top, bottom, left, right;
    top = Y + R;
    bottom = Y - R;
    left = X - R;
    right = X + R;
    
    ll ti;
    double dli,dri;
    ll ans=0;
    ti = base10_6;
    while(ti>top){
        ti -= 1;
    }
    while(ti>=bottom){
        double tate_leng = ti - Y;
        double nana_leng = R;

        tate_leng *= base;
        nana_leng *= base;
        double yoko_leng = pow( nana_leng * nana_leng - tate_leng * tate_leng , 0.5);
        yoko_leng /= base;

        dli = X - yoko_leng;
        dri = X + yoko_leng;
        ans += getbetval(dri,dli);
        ti -= 1;
    }

    cout << ans << endl;



}