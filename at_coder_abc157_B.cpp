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
 

int main(){

    int A[9];
    rep(ni,9){
        cin >> A[ni];
    }
    int B[9]={};

    int N;
    cin >> N;
    int b;
    rep(ni,N){
        cin >> b;
        rep(mi,9){
            if(A[mi]==b) B[mi]=1;
        }
    }
    if(B[0]==1){
        if(B[1]==1 && B[2]==1){
            cout << "Yes" << endl;
        }else if(B[4]==1 && B[8]==1){
            cout << "Yes" << endl;
        }else if(B[3]==1 && B[6]==1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else if(B[6]==1){
        if(B[7]==1 && B[8]==1){
            cout << "Yes" << endl;
        }else if(B[4]==1 && B[2]==1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else if(B[2]==1){
        if(B[5]==1 && B[8]==1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else if(B[3]==1){
        if(B[4]==1 && B[5]==1){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        cout << "No" << endl;
    }







    

}