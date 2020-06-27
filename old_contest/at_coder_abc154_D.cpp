#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <iomanip>
using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
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
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

//#include <stack>
//#include <queue>

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
double p[200010];

ll ltmp;
string stmp;
double dtmp;
double sum = 0;
ll start = 1;
double sumax = 0;

double getv(double ni){
    return ni * (ni + 1) / 2 / ni;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> K;
    

    for( int ni = 1 ; ni <=K ; ni++ ){
        cin >> ltmp;
        dtmp = getv(ltmp);
        p[ni]=dtmp;
        sum+=dtmp;
    }
    sumax = sum;
    start = 1;
    for( int ni = K+1 ; ni <=N ; ni++ ){
        cin >> ltmp;
        dtmp = getv(ltmp);
        p[ni]=dtmp;
        sum-=p[ni-K];
        sum+=p[ni];
        if(sum>sumax){
            start = ni - K + 1;
            sumax = sum;
        }
    }
    cout << std::fixed << std::setprecision(10) << sumax << endl;







}