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

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

#include <queue>
//https://cpprefjp.github.io/reference/queue/priority_queue/pop.html
//std::priority_queue<ll> que;
//que.push(val);
//ll getv = que.top();
//que.pop();
typedef pair<string,ll> P;  
priority_queue<P,vector<P>, greater<P> > que;

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
map<string,ll> count_map;
/*
max 448,000,000
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

    cin >> N;
 
    string S;
    ll PP;
    for( ll ni = 1 ; ni <=N ; ni++ ){
        cin >> S;
        cin >> PP;
        PP = PP * -1;
        string key = S + to_string(PP);
        que.push(P(S,PP));
        count_map[key]=ni;

    }
    for( ll ni = 1 ; ni <=N ; ni++ ){
        auto X = que.top();
        string key = X.first + to_string(X.second);
        cout << count_map[key] << endl;
        que.pop();

    }

}