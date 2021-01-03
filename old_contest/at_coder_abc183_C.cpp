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

ll timer[10][10];

ll cnt = 0;

/*
max 448,000,000
map<string,ll> count_map;
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/

void solver(map<ll,ll> visited,ll count, ll cost, ll from){

    if(count == N){

        if(from == 0){
            if(cost == K) cnt++;
        }
    }else{
        count++;
        rep(to,N){
            //cout << count << " : " << from << " -> " << to << " = " << visited[to] << endl;
            if(visited[to]==0){
                map<ll,ll> visited2;
                visited2 = visited;
                visited2[to]++;
                ll tmpcost = cost + timer[from][to];
                solver(visited2,count,tmpcost, to);
            }
        }

    }

}


int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> K;

    rep(ni,N){
        rep(nii,N){
            cin >> timer[ni][nii];
        }
    }


    map<ll,ll> visited;
    solver(visited,0,0,0);
    cout << cnt << endl;
    

}