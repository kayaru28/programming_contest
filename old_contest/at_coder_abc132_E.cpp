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

#define Nmax 100010
int N,M;
int start,goal;

int visited[Nmax][4]={};
int ans = Nmax;
vector<int> path[Nmax];

void walking(int step,vector<int> current_location){
    step++;
    bool flag = false;

    vector<int> next1;
    vector<int> next2;
    vector<int> target;
    int stage;

    stage = 1;
    for(int location :current_location){
        for(int next :path[location] ){
            if(visited[next][stage]==0){
                visited[next][stage]=1;
                next1.push_back(next);
                //cout << step << ":" <<stage << ":" << next<< endl;
            }
        }
    }
    stage = 2;
    for(int location :next1){
        for(int next :path[location] ){
            if(visited[next][stage]==0){
                visited[next][stage]=1;
                next2.push_back(next);
                //cout << step << ":" <<stage << ":" << next<< endl;
            }
        }
    }
    stage = 3;
    for(int location :next2){
        for(int next :path[location] ){
            if(next==goal){
                visited[goal][stage]=step;
            }
            else if(visited[next][stage]==0){
                flag = true;
                visited[next][stage]=1;
                target.push_back(next);
                //cout << step << ":" <<stage << ":" << next<< endl;
            }
        }
    }
    if(flag){
        if(visited[goal][3]==0){
            sort(target.begin(), target.end());
            unique(target.begin(), target.end()), target.end();
            walking(step,target);
        }
    }


}
int main(){

    cin >> N >> M;

    int source,dest;
    rep(mi,M){
        cin >> source >> dest;
        path[source].push_back(dest);
    }
    cin >> start >> goal;

    int step = 0;
    vector<int> starting;
    starting.push_back(start);
    walking(step,starting);
    if(visited[goal][3]==0) cout << -1 << endl;
    else cout << visited[goal][3] << endl;
}