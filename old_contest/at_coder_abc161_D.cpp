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

ll K;
ll cnt[10][100];
ll maxCnt[10][100];
ll total;
    
int main(){

    vll count;
    int K;
    cin >> K;

    for( int ni = 1 ; ni <10 ; ni++ ){
        count.push_back(ni);
    }

    ll val;
    rep(ni,K){
        val = count[ni];
        //cout << ni+1 << " : " << val << endl;
        //count.erase(count.begin());
        int key;
        key = val%10;
        if(key>0) count.push_back(val*10+(key-1));
        count.push_back(val*10+key);
        if(key<9) count.push_back(val*10+(key+1));
    }
    cout << val << endl;


}