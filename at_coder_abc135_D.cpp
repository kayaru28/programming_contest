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
 
ll A[10000000];
ll B[10000000];
ll cnt[10000]={};
ll mod_cnt[10][15]={};
ll max[10000]={};
ll val[10000]={};

int main(){

    val[0] = 1;
    val[1] = 10;
    val[2] = 9;
    val[3] = 12;
    val[4] = 3;
    val[5] = 4;


    string S;
    cin >> S;
    string Sn;
    int keta;
    int index;
    for( int si = 0 ; si < S.length() ;si++ ){
        si = (S.length() - 1) - si;
        Sn = S.substr(si,1);

        keta = si + 1;
        index = (keta-1) % 6 
        cnt[index]++;
    }

    int x13;
    int mod13;
    for( int ii = 0 ; ii <6 ; ii++ ){
        max[ii] = cnt[ii]*9;
        x13   = max[ii] / 13;
        mod13 = max[ii] % 13;
        rep(ii,13) mod_cnt[ii] = x13
        rep(ii,mod13+1) mod_cnt[mod(val[ii]*ii,13)]++;
    }

    

}