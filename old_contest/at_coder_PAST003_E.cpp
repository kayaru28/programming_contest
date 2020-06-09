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
#define base10_3 1000      //1e4
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
ll C[base10_3];
ll N;
ll M;
ll Q;

int main(){

    vector<ll> node[base10_3];
    
    cin >> N >> M >> Q;

    rep(mi,M){
        ll m1,m2;
        cin >> m1;
        cin >> m2;
        node[m1].push_back(m2);
        node[m2].push_back(m1);
    }
    for( int ci = 1 ; ci <=N ; ci++ ){
        cin >> C[ci];
    }
    ll flag;
    ll x,y;
    rep(qi,Q){
        cin >> flag;
        cin >> x;
        
        //cout << "color is ";
        cout << C[x] << endl;
        if(flag == 1){
            rep(nni,node[x].size()){
                ll index = node[x][nni];
                C[index] = C[x];
            }
        }else{
            cin >> y;
            C[x] = y;
        }
    }
    

}