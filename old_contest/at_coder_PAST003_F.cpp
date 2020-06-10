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

map<string,ll> count_map[base10_4];

int main(){
    
    cin >> N;
    rep(ni,N){
        string S;
        cin >> S;
        rep(si,S.size()){
            string tmp;
            tmp = S.substr(si,1);
            if(count_map[ni].count(tmp)==0){
                count_map[ni][tmp]=1;
            }
        }
    }

    string ans[N];
    ll flag = 1;
    for( int ni = 0 ; ni <N/2 ; ni++ ){
        int in1 = ni;
        int in2 = (N-1)-ni;
        ll tmpf=0;
        for(auto x : count_map[in1]) {
            string key = x.first;
            ll value = x.second;
            if(count_map[in2].count(key)){
                ans[in1]=key;
                ans[in2]=key;
                tmpf = 1;
            }
        }
        if(tmpf==0){
            flag=0;
            break;
        }
    }
    if(N%2==1){

        int ind=N/2;
        for(auto x : count_map[ind]) {
            string key = x.first;
            ll value = x.second;
            ans[ind]=key;
            break;
        }

    }

    if(flag==0) cout << -1 << endl;
    else rep(ni,N) cout << ans[ni];

  
  
    

}