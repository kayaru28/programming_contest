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

ll N;
vll leftv;
vll rightv;
vll aaa;

ll ltmp;
string stmp;
double dtmp;


vector<ll> G[base10_5+10];
map<string,ll> color_map;
ll top_color[base10_5+10]={};
string getMapId(ll from, ll to){
    return to_string(from) + "-" + to_string(to);
}





/*
max 448,000,000
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/
vll ans;
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);



    //木構造であることを利用すれば一気に解ける
    //子要素はまず、親要素との間の色を使う、そしてそれ以外の色を子要素に対して使う
    //一回木構造を組んで親ー子のセットでマップを組んで色を決めて、それを入力順に出力する。


    cin >> N;
    rep(ni,N-1){
        ll li,ri;
        cin >> li;
        cin >> ri;
        G[li].push_back(ri);
        leftv.push_back(li);
        rightv.push_back(ri);
    }
    /*
    N = base10_5;
    rep(ni,N-1){
        ll li = 1;
        ll ri = ni + 2;
        G[li].push_back(ri);
        leftv.push_back(li);
        rightv.push_back(ri);
    }
    */

    for( ll nodei = 1 ; nodei <=N-1 ; nodei++ ){
        ll base_color = 1;
        rep(gi,G[nodei].size()){
            ll child_nodei = G[nodei][gi];
            if(base_color==top_color[nodei]) base_color++;

            string map_id = getMapId(nodei,child_nodei);
            color_map[map_id]=base_color;
            top_color[child_nodei] = base_color;

            base_color++;
        }
    }

    ll K = 0;
    rep(ni,N-1){
        ll li = leftv[ni];
        ll ri = rightv[ni];
        string map_id = getMapId(li,ri);
        ll color = color_map[map_id];

        if(K < color) K = color;
    }

    cout << K << endl;
    rep(ni,N-1){
        ll li = leftv[ni];
        ll ri = rightv[ni];
        string map_id = getMapId(li,ri);
        ll color = color_map[map_id];

        cout << color << endl;
    }


}