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
 
ll N;
ll M;
ll S;
vll candidate;
ll cost[55]={};
vll neighber[110];
vll neighber_time[110];
vll neighber_cost[110];
ll C[55];
ll D[55];
ll confirm[55]={};

class dfind {
public:
    cost[N+10]={};
    silber[N+10]={};
    void dsearch(int index){
        rep(ni,neighber[index].size()){
            int nei = neighber[index][ni];
            if(cost[index]+neighber_cost[index][ni]<cost[nei]){
                cost[nei] = cost[index]+neighber_cost[index][ni];
                dsearch(nei);
            }
        }
    }
    dfind(int index,ll base_cost,ll silver){ //最初は全てが根であるとして初期化
        rep(ni,N+10) cost[ni]=llINF
        cost[index]=0;
        dsearch(index);
        for( int ni = 1 ; ni <=N ; ni++ ){
            if(confirm[ni]!=1){
                if(cost[ni]<cost[])
            }
        }

    }
}

void doneConfirm(int index){
    confirm[index]=1;
    rep(ni,neighber[index].size()){
        int next_index = neighber[index][ni];
        if(confirm[next_index]!=1){
            candidate.push_back(neighber[index][ni]);
         }
    }
    sort(cadidate.begin(), cadidate.end());
    decltype(cadidate)::iterator result = std::unique(cadidate.begin(), cadidate.end());
    cadidate.erase(result, cadidate.end());



}

int main(){

    cin >> N >> M >> S;


    int U,V,A,B;
    rep(mi,M){
        cin >> U;
        cin >> V;
        cin >> A;
        cin >> B;
        neighber[U].push_back(V);
        neighber_cost[U].push_back(A);
        neighber_time[U].push_back(B);
        neighber[V].push_back(U);
        neighber_cost[V].push_back(A);
        neighber_time[V].push_back(B);
    }
    rep(ni,N){
        cin >> C[ni+1];
        cin >> D[ni+1];
    }
    int index = 1;

    while(candidate.size()!=0){

    }


}