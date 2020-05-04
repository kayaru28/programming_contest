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
ll Q;
ll a[100];
ll b[100];
ll c[100];
ll d[100];


ll maxV=0;

void getMax(int index,ll min,ll AA[]){
    if(index==N){
        for( int mi = min ; mi <=M ; mi++ ){
            AA[index]=mi;
            ll score = 0;
            rep(qi,Q){
                int index1=b[qi];
                int index2=a[qi];
                if(AA[index1]-AA[index2]==c[qi]) score+=d[qi];
            }
            if(score>maxV) maxV = score;
        }
    }else{
        for( int mi = min ; mi <=M ; mi++ ){
            AA[index]=mi;
            getMax(index+1,mi,AA);
        }
    }

}


int main(){

    cin >> N;
    cin >> M;
    cin >> Q;

    rep(qi,Q){
        cin >> a[qi];
        cin >> b[qi];
        cin >> c[qi];
        cin >> d[qi];
    }

    ll AA[N+1];
    getMax(1,1,AA);
    cout << maxV << endl;

}