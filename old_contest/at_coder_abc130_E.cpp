#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <vector>
#include <math.h>

using namespace std;
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
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
 

#define MAXN  100010
int sentakushi[MAXN] = {};
int num_friends[MAXN] = {};
int called[MAXN] = {};
vector<int> tree[MAXN];
int N;
int K;

void calc(int ni){
    int count=0;
    int ni_f;
    //cout << ni << endl;
    //cout << num_friends[ni] << endl;
    rep(fi,num_friends[ni]){
        ni_f = tree[ni][fi];
        if(called[ni_f] > 0){
            count++;
        }
    }

    rep(fi,num_friends[ni]){
        ni_f = tree[ni][fi];
        if(called[ni_f]==0){
            sentakushi[ni_f] = K - 1 - count;
            count++;
        }
    }
    
    rep(fi,num_friends[ni]){
        ni_f = tree[ni][fi];
        if(called[ni_f]==0){
            called[ni_f] = 1;
            calc(ni_f);
        }
    }

}


int main(){
    cin >> N;
    cin >> K;

    if(N==1) cout << K << endl;
    else{

        int a,b;
        for( int ni = 0 ; ni < N-1 ; ni++ ){
            cin >> a >> b;
            tree[a].push_back(b);
            tree[b].push_back(a);
            num_friends[a]++;
            num_friends[b]++;
        }

        int starti;
        rep(ni,N){
            if(num_friends[ni]==1) starti = ni;
        }

        called[starti] = 1;
        sentakushi[starti] = K;
        calc(starti);

        //cout << "sss" << endl;
        //rep(ni,N+2) cout << sentakushi[ni] << endl;
        //cout << "ss" << endl;
        ll ans=1;
        for(int ni = 1 ; ni <=N ; ni++) ans = ( ans * sentakushi[ni] ) % MOD;
        cout << ans << endl;
    }
}