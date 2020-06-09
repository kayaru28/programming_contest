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

/*
max 448,000,000
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/

int main(){
    map<string,ll> n_map;

    n_map[".###.#.#.#.#.#.#.###"]=0;
    n_map["..#..##...#...#..###"]=1;
    n_map[".###...#.###.#...###"]=2;
    n_map[".###...#.###...#.###"]=3;
    n_map[".#.#.#.#.###...#...#"]=4;
    n_map[".###.#...###...#.###"]=5;
    n_map[".###.#...###.#.#.###"]=6;
    n_map[".###...#...#...#...#"]=7;
    n_map[".###.#.#.###.#.#.###"]=8;
    n_map[".###.#.#.###...#.###"]=9;

    cin >> N;

    string S;
    string KEY[N];
    rep(ni,N) KEY[ni]="";
    
    rep(si,5){
        cin >> S;
        rep(ni,N){
            KEY[ni]=KEY[ni]+S.substr(4*ni,4);
        }
    }
    
    rep(ni,N){
        cout <<  n_map[KEY[ni]];
    }

    

}