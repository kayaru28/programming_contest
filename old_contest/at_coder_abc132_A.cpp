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

    string S;
    cin >> S;

    bool flag = false;

    int i1,i2,i3,i4;

    i1 = 0;
    i2 = 1;
    i3 = 2;
    i4 = 3;
    if(S.substr(i1,1)==S.substr(i2,1) && S.substr(i3,1)==S.substr(i4,1) && S.substr(i1,1)!=S.substr(i4,1))   flag = true;
    
    i1 = 0;
    i2 = 2;
    i3 = 1;
    i4 = 3;
    if(S.substr(i1,1)==S.substr(i2,1) && S.substr(i3,1)==S.substr(i4,1) && S.substr(i1,1)!=S.substr(i4,1))   flag = true;
    

    i1 = 0;
    i2 = 3;
    i3 = 1;
    i4 = 2;
    if(S.substr(i1,1)==S.substr(i2,1) && S.substr(i3,1)==S.substr(i4,1) && S.substr(i1,1)!=S.substr(i4,1))   flag = true;
    
    if(flag) cout << ans_Yes << endl;
    else cout << ans_No << endl;


}