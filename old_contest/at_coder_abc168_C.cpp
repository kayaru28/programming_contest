#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

//#include <stack>
//#include <queue>

#include <math.h>
/*
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
#include <cmath>
ll A;
ll B;
ll C;
ll H;
ll M;
ll K;
#include <iomanip>
int main(){

    
    cin >> A;
    cin >> B;
    cin >> H;
    cin >> M;

    double radA;
    double radB;
    double base;

    base = H * 60 + M;

    radA = base / (12.0*60) * 360;
    radB = (M / 60.0) * 360;
    
    if(radA==radB){
        cout << max(A,B)-min(A,B) << endl;
    
    }
    else{
        double base2;
        base2 = abs(radA-radB);
        if(base2>180) base2=360-base2;
        double value;
        value = A * A + B * B - 2 * A * B * cos(base2/180*M_PI);
        //cout << radA << endl;
        //cout << radB << endl;
        //cout << base2 << endl;
        //cout << base2/180 << endl;
        //cout << cos(base2/180*M_PI) << endl;
        //cout << value << endl;
        //cout << sqrt(value) << endl;
        cout << fixed << setprecision(20) << pow(value,0.5) << endl;
    }

}