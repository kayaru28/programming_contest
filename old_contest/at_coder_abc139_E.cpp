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

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

vll match[base10_4];
ll B;
ll C;
ll N;
ll M;
ll K;

ll ltmp;
string stmp;
double dtmp;

ll cnt_match = 0;
ll all_match;
ll cnt_date=0;

#include <queue>
//https://cpprefjp.github.io/reference/queue/priority_queue/pop.html
//std::priority_queue<ll> que;
//que.push(val);
//ll getv = que.top();
//que.pop();
//priority_queue<P,vector<P>, greater<P> > que;
//que.push(P(0,base_index));

/*
max 448,000,000
map<string,ll> count_map;
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/

typedef pair<ll,ll> P;  
priority_queue<P,vector<P>, less<P> > que;

map<ll,ll> count_map;

ll index_p[1010] = {};

ll getKey(ll p1, ll p2){
    ltmp = p1 * 10000 + p2;
    if(p1<p2) ltmp = p2 * 10000 + p1;
    return ltmp;
    
}
ll getp1(ll key){
    return key / 10000;
}
ll getp2(ll key){
    return key % 10000;
}


ll solve(){
    for( ll ni = 1 ; ni <=N ; ni++ ){
        ll p1 = ni;
        ll p2 = match[ni][0];
        ll key = getKey(p1,p2);
        count_map[key]++;
        que.push(P( count_map[key] , key ));
    }

    P next_match;
    next_match = que.top();
    while(next_match.first == 2){
        vll matched_p;
        while(next_match.first == 2){
            que.pop();
            cnt_match++;
            ll key = next_match.second;
            //cout << key << endl;
            ll p1  = getp1(key);
            ll p2  = getp2(key);
            index_p[p1]++;
            index_p[p2]++;
            matched_p.push_back(p1);
            matched_p.push_back(p2);

            next_match = que.top();
        }
        rep(mi,matched_p.size()){
            ll p1 = matched_p[mi];
            ll ind = index_p[p1];
            if(ind<N-1){
                ll p2 = match[p1][ind];
                ll key = getKey(p1,p2);
                //cout << "add " << key << endl;
                count_map[key]++;
                que.push(P( count_map[key] , key ));

            }
        }
        next_match = que.top();
        cnt_date++;
    }
    if(cnt_match==all_match) return cnt_date;
    else return -1;
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    all_match = N * (N-1) /2;
    rep(ni,N){
        rep(ni2,N-1){
            cin >> ltmp;
            match[ni+1].push_back(ltmp);
        }
    }


    cout << solve() << endl;

}