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
ll Q;

int main(){


    string S;
    
    cin >> S;
    cin >> Q;

    string head;
    string back;

    int flag = 1;
    int T;
    int F;
    string C;
    rep(qi,Q){
        cin >> T;
        if(T==1){
            flag = flag * -1;
        }else{
            cin >> F;
            cin >> C;
            if(F==1){
                if(flag==1){
                    head = C + head;
                }else{
                    back = back + C;
                }

            }else{
                if(flag==1){
                    back = back + C;
                }else{
                    head = C + head;
                }
            }
        }
    }
    ll index;
    if(flag==-1){
        reverse(back.begin(),back.end());
        reverse(S.begin(),S.end());
        reverse(head.begin(),head.end());
        cout << back << S << head;

    }else{
        cout << head << S << back;
    }

    

    

}