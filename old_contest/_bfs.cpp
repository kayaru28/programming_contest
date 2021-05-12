#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

#define base10_4 1e4 //10000
#define base10_5 1e5 //100000
#define base10_6 1e6 //1000000
#define base10_7 1e7 //10000000
#define base10_8 1e8 //100000000
#define base10_9 1e9 //1000000000



//#include <stack>
//#include <queue>

/*
#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

int N,X,Y;

#define Gsize 200000
vector<int> G[Gsize];
int visit[Gsize]={};
int layer[Gsize]={};
void seeker(vector<int> fromG){
    vector<int> next;
    rep(fi,fromG.size()){
        int from_index = fromG[fi];
        rep(ti,G[from_index].size()){
            int to_index = G[from_index][ti];
            if(visit[to_index]!=1){
                visit[to_index]=1;
                layer[to_index]=layer[from_index]+1;
                next.push_back(to_index);
            }
        }
    }
    if(next.size()>0) seeker(next);
}
/*
    G[ni].push_back(ni+1);
    vector<int> startG;
    int start = 5;
    visit[start]=1;
    startG.push_back(start);
    seeker(startG);
*/



int main(){

    cin >> N;
    for( int ni = 1 ; ni <N+1 ; ni++ ){
        G[ni].push_back(ni-1);
    }
    rep(ni,N-1){
        G[ni].push_back(ni+1);
    }

    vector<int> startG;
    int start = 5;
    visit[start]=1;
    startG.push_back(start);
    seeker(startG);

    rep(ni,N){
        cout << "-----" << ni << endl;
        rep(nii,G[ni].size()){
            cout << G[ni][nii] << " " << endl;
        }
    }

    cout << "--- layer ---" << endl;
    rep(ni,N) cout << layer[ni] << endl;

    cout <<  endl;
    cout << "add" << endl;
    cout << int(base10_5) << endl;
    cout << int(base10_6) << endl;
}