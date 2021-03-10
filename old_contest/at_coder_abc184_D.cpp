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

 #include <iomanip>

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

ll A;
ll B;
ll C;

ll ltmp;
string stmp;
double dtmp;
double ans=0;

double memo[101][101][101]={};

double getans(ll A ,ll B, ll C){
    if(A==100) return 0;
    if(B==100) return 0;
    if(C==100) return 0;

    if(memo[A][B][C]>0) return memo[A][B][C];

    double total = A+B+C;
    //dtmp = (getans(A+1,B,C)+1) * A / total;
    //dtmp += (getans(A,B+1,C)+1) * B / total;
    //dtmp += (getans(A,B,C+1)+1) * C / total;
    dtmp = ( (getans(A+1,B,C)+1) * A +(getans(A,B+1,C)+1) * B + (getans(A,B,C+1)+1) * C) / total;
    memo[A][B][C] = dtmp;
	return memo[A][B][C];
}   
const double EPS = 1e-7;
 
int check(double a, double b){
	if(a>b)return (a-b) > EPS;
	return (b-a) > EPS;
}
 
double dp(int x, int y, int z){
	if(x == 100 || y == 100 || z == 100)return 0;
	if(check(memo[x][y][z],0))return memo[x][y][z];
	double sum = x + y + z;
	memo[x][y][z] = ((dp(x+1,y,z)+1) * x + (dp(x,y+1,z)+1)*y +(dp(x,y,z+1)+1)*z) / sum;
	return memo[x][y][z];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A;
    cin >> B;
    cin >> C;

    cout << fixed << setprecision(15) << getans(A,B,C) << endl;
    //cout << fixed << setprecision(15) << dp(A,B,C) << endl;


}