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

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;
vector<string> dic;

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
    ll cntmax=1;
    map<string,ll> count_map;


    cin >> N;
    rep(ni,N){
        cin >> stmp;
        if(count_map.count(stmp)==0){
            count_map[stmp]=1;
        }else{
            count_map[stmp]++;
            if(count_map[stmp]>cntmax){
                cntmax = count_map[stmp];
            }
        }
    }

    for(auto cmi : count_map) {
        string key = cmi.first;
        ll value = cmi.second;
        if(value == cntmax){
            cout << key << endl;
        }
    }



    

}