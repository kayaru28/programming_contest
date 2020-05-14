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

ll A[100][100];
ll B[100];
ll C[100];
ll N;
ll M;
ll X;
ll total[100]={};
ll cnt=0;

ll getAns(int index,ll learn[],ll ans){
    if(index<N){
        ll tmp1,tmp2;
        ll tmpl[M];
        rep(mi,M) tmpl[mi]=learn[mi];
        tmp1 = getAns(index+1,tmpl,ans);
        rep(mi,M) tmpl[mi]+=A[index][mi];
        ans += C[index];
        tmp2 = getAns(index+1,tmpl,ans);
        if(tmp1==-1){
            //cout << "m1" << endl;
            return tmp2;
        }else if(tmp2==-1){
            //cout << "m2" << endl;
            return tmp1;
        }else{
            return min(tmp1,tmp2);
        }

    }else{
        ll mintotal=X;
        rep(mi,M){
            mintotal = min(mintotal,learn[mi]);
            //cout << learn[mi] << " ";
        }
        //cout << endl;
        //cout << ans << endl;
        if(mintotal>=X){
            //cout << "bust" << endl;
            return ans;
        }else{
            return -1;
        }
    }


}

int main(){

    

    cin >> N;
    cin >> M;
    cin >> X;

    rep(ni,N){
        cin >> C[ni];
        rep(mi,M){
            cin >> A[ni][mi];
            total[mi]+=A[ni][mi];
        }
    }
    ll mintotal=X;
    rep(mi,M){
        if(total[mi]<mintotal) mintotal=total[mi];
    }
    if(mintotal>=X){
        //cout << "marl" << endl;
        ll ans = 0;
        ll learn[M]={};
        ans = getAns(0,learn,ans);
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }

}