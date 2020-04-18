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

ll A;
ll B;
ll C;
ll N;

int main(){


    
    cin >> A;
    cin >> B;

    ll A_max;
    ll A_min;
    ll B_max;
    ll B_min;

    double tmp;
    double tmpd;
    ll tmpi;
    double tax;
    tax = 0.08;
    tmp = A;
    tmpi = (tmp+1)/tax;
    tmpd =  (tmp+1)/tax;
    if(tmpi==tmpd) A_max = tmpi -1;
    else A_max = tmpi;
    tmpi = (tmp)/tax;
    tmpd =  (tmp)/tax;
    if(tmpi==tmpd) A_min = tmpi ;
    else A_min = tmpi+1;
    
    tax = 0.1;
    tmp = B;
    tmpi = (tmp+1)/tax;
    tmpd =  (tmp+1)/tax;
    if(tmpi==tmpd) B_max = tmpi -1;
    else B_max = tmpi;
    tmpi = (tmp)/tax;
    tmpd =  (tmp)/tax;
    if(tmpi==tmpd) B_min = tmpi ;
    else B_min = tmpi+1;

    if(B_min>A_max || A_min > B_max){
        cout << -1 << endl;
    }else{
        cout << max(A_min,B_min) << endl;
    }

}