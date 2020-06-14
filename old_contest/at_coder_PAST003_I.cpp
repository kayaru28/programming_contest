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

ll ROW[base10_6];
ll COL[base10_6];

int main(){

    int flag_tenl=0;

    cin >> N;
    for( int ni = 1 ; ni <=N ; ni++ ){
        ROW[ni]=ni;
        COL[ni]=ni;
    }

    cin >> C;
    
    ll flag;
    ll t1,t2;
    vll ans;
    rep(qi,C){
        cin >> flag;
        if(flag==3){
            flag_tenl = (flag_tenl+1)%2;
        }else{
            cin >> t1;
            cin >> t2;


            if(flag==1 && flag_tenl==0){
                ll tmp;
                tmp = ROW[t1];
                ROW[t1]=ROW[t2];
                ROW[t2]=tmp;
            }else if(flag==2 && flag_tenl==1){
                ll tmp;
                tmp = ROW[t1];
                ROW[t1]=ROW[t2];
                ROW[t2]=tmp;
            }else if(flag==2 && flag_tenl==0){
                ll tmp;
                tmp = COL[t1];
                COL[t1]=COL[t2];
                COL[t2]=tmp;
            }else if(flag==1 && flag_tenl==1){
                ll tmp;
                tmp = COL[t1];
                COL[t1]=COL[t2];
                COL[t2]=tmp;
            }else{
                ll t_r,t_c;
                if(flag_tenl==0){
                    t_r = ROW[t1];
                    t_c = COL[t2];
                }else{
                    t_r = ROW[t2];
                    t_c = COL[t1];
                }
                ans.push_back(N * (t_r-1) + t_c-1);

            }
        }
    }
    rep(ni,ans.size()){
        //cout << "ans is ";
        cout << ans[ni] << endl;

    }
    

}