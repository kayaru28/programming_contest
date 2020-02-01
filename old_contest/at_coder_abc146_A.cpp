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

    if(S=="SUN") cout << 7 << endl;
    else if(S=="MON") cout << 6 << endl;
    else if(S=="TUE") cout << 5 << endl;
    else if(S=="WED") cout << 4 << endl;
    else if(S=="THU") cout << 3 << endl;
    else if(S=="FRI") cout << 2 << endl;
    else if(S=="SAT") cout << 1 << endl;
    

}