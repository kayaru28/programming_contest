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
#define base10_4 10000      //1e4
#define base10_5 100000     //1e5
#define base10_6 1000000    //1e6
#define base10_7 10000000   //1e7
#define base10_8 100000000  //1e8
#define base10_9 1000000000 //1e9

#include <map>


/*
    map<string,ll> count_map;
    count_map["0"]=0;  
    for(auto x : count_map) {
        string key = x.first;
        ll value = x.second;
    }
*/
int main(){
    ll M = base10_9;
    ll N = M/1000;
    map<ll,ll> count_map;
    rep(mi,M){
        if(mi%N==0) cout << mi << endl;
        count_map[mi]=mi;
    }
}