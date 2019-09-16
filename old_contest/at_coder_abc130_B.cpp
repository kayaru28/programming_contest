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
 

int main(){

    int D;
    int N;
    
    cin >> N;
    cin >> D;

    int X[N][D];

    rep(ni,N){
        rep(di,D){
            cin >> X[ni][di];
        }
    }

    int count = 0;
    double dist;
    int tmp;
    rep(n1,N-1){
        for( int n2 = n1+1 ; n2 < N ; n2++ ){
            dist = 0;
            rep(di,D){
                dist+=(X[n1][di]-X[n2][di])*(X[n1][di]-X[n2][di]);
            }
            tmp = sqrt(dist);
            if(tmp == sqrt(dist)) count++;
            
        }
    }
    cout << count << endl;
}