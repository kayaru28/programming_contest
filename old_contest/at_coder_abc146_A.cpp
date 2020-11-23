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
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;
/*
max 448,000,000
map<string,ll> count_map;
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    string S;
    
    cin >> S;

    map<string,ll> s_map;
    s_map["SUN"]=7;
    s_map["MON"]=6;
    s_map["TUE"]=5;
    s_map["WED"]=4;
    s_map["THU"]=3;
    s_map["FRI"]=2;
    s_map["SAT"]=1;
    cout << s_map[S] << endl; 

}