#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <string>
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
    int N;
    
    cin >> N;
    cin >> S;

    char target;

    int tar;
    for( int si = 0 ; si <S.length() ; si++ ){
        tar = (int)S[si];
        tar = ( (tar+N-65) % 26 );
        printf("%c",'A'+tar);

    }
    


}