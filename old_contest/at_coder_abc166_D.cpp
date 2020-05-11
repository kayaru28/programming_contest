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
#include <math.h>

/*
int standerd = int(pow(10.0,9.0)) + 7;
*/
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

int main(){

    
    cin >> N;
    double tmp;
    rep(ai,2000){
        M = N - pow(ai,5);
        //cout << M << endl;
        A = pow(abs(M),1.0/5.0) * M/abs(M) * -1;
        tmp = pow(abs(M),1.0/5.0) * M/abs(M) * -1;
        //cout << ai << " " << tmp << " " << A << endl;
        //cout << A-tmp << endl;
        if(abs(A-tmp)<0.0000000001){
            //cout << "SS" << endl;
            cout << ai;
            cout << " ";
            cout << A << endl;
            ai=1000000;
        }
    }
    

}