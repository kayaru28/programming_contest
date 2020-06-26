#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>

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


int n,q;
char s[500005];
int bit[26][500005];
 
int sum(int op,int pos){
    int res=0;
    while(pos>0){
        res+=bit[op][pos];
        pos-=pos&-pos;
    }
    return res;
}
 
void add(int op,int pos,int val){
    while(pos<=n){
        bit[op][pos]+=val;
        pos+=pos&-pos;
    }
}
 
int main(){
 
    int pos;
    int base;
    base = 100;
    pos = base;
    cout << pos << endl;
    cout << -pos << endl;
    pos-=pos&-pos;
    cout << pos << endl;
    pos = base;
    pos+=pos&-pos;
    cout << pos << endl;

}