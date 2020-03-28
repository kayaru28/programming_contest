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
int seeker(vector<int> startG,int visit[]){
    vector<int> next;
    rep(start_index,startG.size()){
        int starti = startG[start_index];
        rep(next_index,G[starti].size()){
            int nexti = G[starti][next_index];
            if(visit[nexti]!=1){
                visit[nexti]=1;
                next.push_back(nexti);
            }
        }
    }
    if(next.size()>0) seeker(next,visit);
}

int main(){

    cin >> N;
    cin >> X;
    cin >> Y;
    for( int ni = 1 ; ni <N+1 ; ni++ ){
        G[ni].push_back(ni-1);
    }
    rep(ni,N-1){
        G[ni].push_back(ni+1);
    }
    X=X-1;
    Y=Y-1;
    G[X].push_back(Y);
    G[Y].push_back(X);


    rep(starti,N){
        start=starti;
        dist = 1;
        int visit[N]={0};
        vector<int> startG = {starti};
        //dcout << "++++" << starti << endl;
        seeker(startG,visit);
    }

    ans[2] = ans[2] - N;

    for( int ni = 1 ; ni <N ; ni++ ){
        cout << ans[ni]/2 << endl;
    }



    /*
    rep(ni,N){
        cout << "-----" << ni << endl;
        rep(nii,G[ni].size()){
            cout << G[ni][nii] << " " << endl;
        }
    }
    */
}