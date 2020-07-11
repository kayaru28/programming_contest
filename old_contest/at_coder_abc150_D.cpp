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

ll ltmp;
string stmp;
double dtmp;

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
vll a;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> M;
    rep(ni,N){
        cin >> ltmp;
        a.push_back(ltmp/2);
    }
    
    sort(a.begin(),a.end());
    ll kobai = a[0];
    for( ll ai = 1 ; ai <=a.size()-1 ; ai++ ){
        kobai = kobai_min(kobai,a[ai]);
    }

    bool flag=true;
    rep(ai,a.size()){
        if((kobai/a[ai])%2==0){
            flag = false;
            break;
        }
    }
    ll cnt=0;
    if(flag){
        ll comp = kobai;
        while(comp<=M){
            cnt++;
            //cout << comp << endl;
            comp += kobai*2; 
        }
    }
    cout << cnt << endl;

}