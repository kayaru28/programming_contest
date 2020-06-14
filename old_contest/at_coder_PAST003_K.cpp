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

ll topC[base10_6];
ll botC[base10_6];

ll parent[base10_6];
ll child[base10_6];

getChild(ll x){
    if(child[x]==x) return x;
    else return getChild(child[x]);
}
getParent(ll x){
    if(parent[x]==x) return x;
    else return getParent(parent[x]);
}


int main(){

    
    cin >> N;
    cin >> M;
    
    for( int ni = 1 ; ni <=N ; ni++ ){
        topC[ni]=ni;
        botC[ni]=ni;
        parent[ni]=ni;
        child[ni]=ni;
    }

    rep(qi,M){
        ll from,x,to;
        cin >> from >> to >> x;

        ll t_parent = topC[to];
        if(t_parent==0){
            parent[x]=x;
            botC[to] = x;
            topC[to] = getChild[x];
        }else{
            parent[x]=t_parent;
            topC[to] = getChild[x];
        }
        
        if(botC[from]==x){
            botC[from]=0;
            topC[from]=0;
        }else{
            topC[from] = getChild[botC[to]];
            
        }
        
         botC[from]=0;


        topC[from] = getChild[botC[from]] 
        topC[to] = getChild[x];


    }

}