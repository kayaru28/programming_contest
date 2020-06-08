#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>

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


ll getPower(ll value,ll shisu){
    ll ans = 1;
    ll cnt = shisu;
    while(cnt>0){
        if(cnt%2==1){
            ans = ans * value;
        }
        value = value * value;
        cnt = cnt/2;
    }
    return ans;
}
string getPowerFlag(ll value,ll shisu){
    ll ans = 1;
    ll cnt = shisu;
    while(cnt>0){
        if(cnt%2==1){
            ans = ans * value;
        }
        value = value * value;
        cnt = cnt/2;

        if(ans>base10_9) return "large";
    }
    return "OK";
}

double A;
double B;
double C;
ll N;
ll M;
ll K;

int main(){

    
    cin >> A;
    cin >> B;
    cin >> C;
    /*
    string flag = getPowerFlag(B,C-1);
    if(flag=="OK"){
        ll value = getPower(B,C-1) * A; 
        if(value>base10_9) cout << "large" << endl;
        else cout << value << endl;
    }else{
        cout << flag << endl;
    }
    */

    double flag;
    flag = log10(A) + (C-1)*log10(B);
    if(flag > 9) cout << "large" << endl;
    else{
        ll ans = getPower(B,C-1) * A;
        cout << ans << endl;
    }
    

}