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
#define base10_5 100010     //1e5
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
ll S;
ll T;
ll from;
ll to;

/*
max 448,000,000
map<string,ll> count_map;
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/

map<int,int> step_1;
map<int,int> step_2;
map<int,int> step_3;
ll cost3[base10_5];
vector<ll> ngraph[base10_5];

ll ltmp;
string stmp;
double dtmp;
#include <queue>
//https://cpprefjp.github.io/reference/queue/priority_queue/pop.html
//std::priority_queue<ll> que;
//que.push(val);
//
//
//que.push(P(0,base_index));

typedef pair<ll,ll> P;  


int solve(){
    rep(ni,base10_5) cost3[ni] = base10_9;
    priority_queue<P,vector<P>, greater<P> > next;
    next.push(P(0,S));
    while(next.size()>0){
        P getv = next.top();
        next.pop();
        from = getv.second;

        ll step_from = getv.first;
        ll step_to = step_from + 1;

        vll step1;
        vll step2;
        vll step3;

        rep(ti,ngraph[from].size()){
            to = ngraph[from][ti];
            if(step_1[to]==0){
                step_1[to]=1;
                step1.push_back(to);
            }
        }
        rep(si,step1.size()){
            from = step1[si];
            rep(ti,ngraph[from].size()){
                to = ngraph[from][ti];
                if(step_2[to]==0){
                    step_2[to]=1;
                    step2.push_back(to);
                }
            }
        }
        rep(si,step2.size()){
            from = step2[si];
            rep(ti,ngraph[from].size()){
                to = ngraph[from][ti];
                if(step_3[to]==0){
                    step_3[to]=1;
                    step3.push_back(to);
                }
            }
        }
        rep(si,step3.size()){
            to = step3[si];
            cost3[to]=step_to;
            next.push(P(step_to,to));
        }

        if(step_3[T]==1) return cost3[T]; 
    }

    if(cost3[T] == base10_9) return -1;
    else return cost3[T];
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    cin >> N;
    cin >> M;
    rep(mi,M){
        cin >> from;
        cin >> to;
        ngraph[from].push_back(to);
    }
    cin >> S;
    cin >> T;
    
    cout << solve() << endl;



    

}