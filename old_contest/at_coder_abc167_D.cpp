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

ll A[2000000];
ll B[2000000]={};
ll C;
ll N;
ll M;
ll K;

int main(){

    cin >> N;
    cin >> K;

    rep(ni,N){
        cin >> A[ni];
        A[ni]--;

    }
    ll cnt=0;

    ll now = 0;
    ll flag = 0;
    while(cnt<K){
        ll next = A[now];
        if(flag==0){
            if(B[next]==0){
                cnt++;
                B[next]=cnt;
            }else{
                cnt++;
                ll base =cnt - B[next];
                //cout << base << endl;

                cnt = (K-B[next])/base * base;
                cnt += B[next];
                while(cnt>K) cnt-=base;
                flag=1;
            }
        }else{
            cnt++;
        }
        //cout << cnt << endl;
        now=next;
    }
    cout << now+1 << endl;

}