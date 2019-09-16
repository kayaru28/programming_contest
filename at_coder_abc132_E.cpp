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

int visited[Nmax]={};
int ans = Nmax;
vector<int> path[Nmax][4];

void walking(int step,int current_location){
    step+=3;
    bool flag = true;
    vector<int> target;

    for(int location :path[current_location][3]){
        if(location==goal){
            flag = false;
            visited[location] = step;
        }
        else if(visited[location]==0){
            visited[location]=step;
            target.push_back(location);
        }
        else{
            if(visited[location] > step){
                target.push_back(location);
                visited[location]=step;
            }
        }
    }
    if(flag){
        target.erase(unique(target.begin(), target.end()), target.end());
        for(int location :target){
            if(visited[location]==step)  walking(step,location);
            //else //stop walking
        }

    }


}
int main(){

    cin >> N >> M;

    int source,dest;
    rep(mi,M){
        cin >> source >> dest;
        path[source][1].push_back(dest);
    }
    int leng = 2;
    rep(current_location,N){
        for(int location :path[current_location][leng-1]){
            path[current_location][leng].insert(
                path[current_location][leng].end(), 
                path[location][1].begin(), 
                path[location][1].end()
            );
        }
        sort(path[current_location][leng].begin(), path[current_location][leng].end());
        path[current_location][leng].erase(unique(path[current_location][leng].begin(), path[current_location][leng].end()), path[current_location][leng].end());
    }

    leng = 3;
    rep(current_location,N){
        for(int location :path[current_location][leng-1]){
            path[current_location][leng].insert(
                path[current_location][leng].end(), 
                path[location][1].begin(), 
                path[location][1].end()
            );
        }
        sort(path[current_location][leng].begin(), path[current_location][leng].end());
        path[current_location][leng].erase(unique(path[current_location][leng].begin(), path[current_location][leng].end()), path[current_location][leng].end());
    }


    cin >> start >> goal;

    int step = 0;
    walking(step,start);
    if(visited[goal]==0) cout << -1 << endl;
    else cout << visited[goal]/3 << endl;
}