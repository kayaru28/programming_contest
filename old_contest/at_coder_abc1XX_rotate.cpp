


#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <vector>

using namespace std;
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

// for(char c : S)


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
point rotateXY_radian(point p0, double radian, point center){
    double xi = p0.first;
    double yi = p0.second;
    double xc = center.first;
    double yc = center.second;

    double xi_c = xi - xc;
    double yi_c = yi - yc; 
    double xn = xi_c * cos(radian) - yi_c * sin(radian) + xc;
    double yn = xi_c * sin(radian) + yi_c * cos(radian) + yc;
    return point(xn,yn);
}
point rotateXY_kakudo(point p0, double kakudo, point center){
    double radian = changeKakudoToRadian(kakudo);
    point pn = rotateXY_radian(p0, radian, center);
    return pn;
}

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
ll T;
ll X;
ll Y;
ll Z;

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

double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    point p0 = point(1,2);
    double rad = 90;//changeKakudoToRadian(90);
    point pn;
    pn = rotateXY_kakudo(p0, rad, point(0,0));
    cout << pn.first << " " << pn.second << endl;
    pn = rotateXY_kakudo(pn, rad, point(0,0));
    cout << pn.first << " " << pn.second << endl;
    pn = rotateXY_kakudo(pn, rad, point(0,0));
    cout << pn.first << " " << pn.second << endl;
    pn = rotateXY_kakudo(pn, rad, point(0,0));
    cout << pn.first << " " << pn.second << endl;





    

}