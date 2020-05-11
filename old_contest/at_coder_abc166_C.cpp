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

int main(){

    
    cin >> N;
    cin >> M;

    ll H[N+1]={};
    for( int hi = 1 ; hi <=N ; hi++ ){
        ll tmp;
        cin >> tmp;
        H[hi]=tmp;
    }
    int flag[N+1]={};
    int A;
    int B;
    rep(mi,M){
        cin >> A;
        cin >> B;
        if(H[A]>=H[B]) flag[B]=1;
        if(H[B]>=H[A]) flag[A]=1;
    }
    ll cnt=0;
    for( int ni = 1 ; ni <=N ; ni++ ){
        if(flag[ni]==0) cnt++;   
    }
    cout << cnt << endl;


    

}