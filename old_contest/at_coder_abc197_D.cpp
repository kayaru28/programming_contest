

//#include <bits/stdc++.h>
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

#include <iomanip>

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

ll A;
ll B;
ll C;
double N;
ll M;
ll K;



ll ltmp;
string stmp;
double dtmp;
double x_0;
double y_0;
double x2n;
double y2n;
const ll hosei = 100000000;

typedef pair<double,double> point;  
point rotateXY(point pi_0, double radian, point center,ll zahyouhosei = 1000000){
    double xi = pi_0.first;
    double yi = pi_0.second;
    double xc = center.first;
    double yc = center.second;
    xi *= zahyouhosei;
    yi *= zahyouhosei;
    xc *= zahyouhosei;
    yc *= zahyouhosei;
    
    double xi_c = xi - xc;
    double yi_c = yi - yc; 
    double xn = xi_c * cos(radian) - yi_c * sin(radian) + xc;
    double yn = xi_c * sin(radian) + yi_c * cos(radian) + yc;
    xn /= zahyouhosei;
    yn /= zahyouhosei;

    return point(xn,yn);
}
const double PI=3.14159265358979323846;
double changeKakudoToRadian(ll kakudo,ll kakudohosei = 1000000){
    double radian;
    radian = kakudohosei;
    radian *=  kakudo;
    radian = radian * PI/180;
    radian /= kakudohosei;
    return radian;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> x_0 >> y_0 >> x2n >> y2n;
    
    /*
    x_0 *= hosei;
    y_0 *= hosei;
    x2n *= hosei;
    y2n *= hosei;
    */

    double xc,yc;
    xc = (x_0 + x2n) /2;
    yc = (y_0 + y2n) /2;

    double kakudo = 360.0 / N;
    kakudo = hosei * 360.0 / N;
    double radian = changeKakudoToRadian(kakudo,hosei);
    radian /= hosei;
    
    point pi_0 = point(x_0,y_0);
    point center = point(xc,yc);
    point ans = rotateXY(pi_0,radian,center,hosei); 
    
    cout << fixed << setprecision(15) << ans.first << " " << ans.second << endl;





}