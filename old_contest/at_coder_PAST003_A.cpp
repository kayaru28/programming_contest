#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <cctype>
#include <ctype.h>
#include <cstdlib>
#include <string>

using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define base10_4 10000      //1e4
#define base10_5 100000     //1e5
#define base10_6 1000000    //1e6
#define base10_7 10000000   //1e7
#define base10_8 100000000  //1e8
#define base10_9 1000000000 //1e9

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

ll A;
ll B;
ll C;
ll N;
ll M;
ll K;

int main(){

    
    string S;
    cin >> S;
    string T;
    cin >> T;

    string SS;
    string TT;
    
    TT = T;
    SS = S;
    transform (SS.begin (), SS.end (), SS.begin() ,::toupper);
    transform (TT.begin (), TT.end (), TT.begin (), ::toupper);

    if(S==T){
        cout << "same" << endl;
    }else if(SS==TT){
        cout << "case-insensitive" << endl;
    }else{
        cout << "different" << endl;
    }

    

}