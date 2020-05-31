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
#include <queue>

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;
ll T;
ll D;

typedef pair<ll,ll> P;

/*
max 448,000,000
map<string,ll> count_map;
count_map['0']=0;
for(auto x : count_map) {
    string key = x.first;
    ll value = x.second;
}
*/

ll basecost[15];
ll minll(ll a,ll b){
    if(a<b) return a;
    else return b;
}


int main(){

    
    cin >> T;
 
    rep(ti,T){
        cin >> N;
        cin >> A;
        cin >> B;
        cin >> C;
        cin >> D;
        basecost[1]=D;
        basecost[2]=A;
        basecost[3]=B;
        basecost[5]=C;
        priority_queue<P,vector<P>, less<P> > que;
        que.push(P(N,0));
        map<ll,ll> count_map;
        count_map[N]=0;

        while(!que.empty()){
            P p = que.top();
            que.pop();
            ll number = p.first;
            ll cost = p.second;
            vll targets;
            vll costs;

            cout << "number is " << number << endl;
            cout << cost << endl;

            for( ll ni = 2 ; ni <=5 ; ni = ni * 2 -1 ){
                ll ctmp;
                ll ttmp;
                if(number%ni==0){
                    ttmp =  number /ni ;
                    targets.push_back(number/ni);
                    targets.push_back( ttmp );
                    ctmp = cost + minll(basecost[ni], (number - ttmp) * D  );
                    costs.push_back(ctmp);
                }else{
                    ll amari = number%ni;
                    ll tasu = ni-amari;
                    ll hiku = amari;
                    ttmp =  (number-hiku) /ni ;
                    targets.push_back( ttmp );
                    ctmp = cost + minll(basecost[ni] + hiku * D, (number - ttmp) * D  );
                    costs.push_back(ctmp);

                    ttmp =  (number+tasu) /ni ;
                    targets.push_back( ttmp );
                    ctmp = cost + minll(basecost[ni] + tasu * D, (number - ttmp) * D  );
                    costs.push_back(ctmp);
                }
            }
            
            rep(ti,targets.size()){
                ll target = targets[ti];
                cout << "t is " << target << endl;
                cout << costs[ti] << endl;
                
                if(count_map.count(target)==0){
                    cout << "setting" << endl;
                    count_map[target]=costs[ti];
                    if(target>1) que.push(P(target  , costs[ti]));
                }else{
                    if(count_map[target]>costs[ti]){
                        cout << "update " << endl;
                        count_map[target]=costs[ti];
                        if(target>1) que.push(P(target  , costs[ti]));
                    }
                }
                
            }
        }
        cout << count_map[1] + D << endl;
    }

    

}