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

vll A;
vll B;
ll C;
ll N;
ll M;
vll ans;
bool is_prime[base10_6];

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

    map<ll,ll> count_map;
    map<ll,ll> pos_map;


    cin >> N;
    rep(ni,N){
        cin >> ltmp;
        A.push_back(ltmp);
        count_map[ltmp]++;
    }

    if(N==1){
        cout << 1 << endl;        
    }else if(count_map.count(1)>0){
        if(count_map[1]==1){
            cout << 1 << endl;
        }else{
            cout << 0 << endl;
        }
    }else{
        sort(A.begin(),A.end());
        ll bef = -1;
        ll index = 0;
        rep(ai,A.size()){
            ll target = A[ai];
            if(bef!=target){
                bef = target;

                B.push_back(target);
                pos_map[target]=index;
                is_prime[index]=true;
                index++;
            }
        }
        ll cntB = index;

        for( ll number = 0 ; number < cntB ; number++ ){
            if(is_prime[number]){
                ll target = B[number];
                for( ll ni = target*2 ; ni <=B[cntB-1] ; ni+=target ){
                    if(count_map.count(ni)>0){
                        //cout << ni << endl;
                        index = pos_map[ni];
                        is_prime[index]=false;
                    }
                }
            }
        }

        ll cntans=0;
        rep(bi,cntB){
            ll target = B[bi];
            if(is_prime[bi] && count_map[target]==1){
                cntans++;
                //cout << target << endl;

            }
        }
        cout << cntans << endl;


    }



}