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

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

ll A;
ll B;
ll C;
ll D;
ll M;
ll K;
ll CD;

long long koyaku_max(long long a,long long b){
    long long r;
    r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}
long long kobai_min(long long a,long long b){
    long long tmp;
    tmp =  a / koyaku_max(a,b);
    return tmp * b;
}

ll ltmp;
string stmp;
double dtmp;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> A;
    cin >> B;
    cin >> C;
    cin >> D;

    ll C_A,C_B,D_A,D_B;
    ll CD_A,CD_B;

    A--;
    C_A = A/C;
    C_B = B/C;
    D_A = A/D;
    D_B = B/D;

    CD = kobai_min(C,D);
    CD_A = A/CD;
    CD_B = B/CD;

    ll N_C  = C_B  - C_A;
    ll N_D  = D_B  - D_A;
    ll N_CD = CD_B - CD_A;

    cout <<  B-A - (N_C+N_D-N_CD) << endl;

    

    

}