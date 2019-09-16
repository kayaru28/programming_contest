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
 
ll N;
ll NN;

int main(){

    cin >> N;
    int K;
    cin >> K;

    string S;
    cin >> S;

    int Flag[N+100];
    int Fsum[N+100];
    int tmp[N+100];
    int cnt=0;
    rep(i,N){
        if(S.substr(i,1)=="L")  Flag[i+1] = -1;
        else Flag[i+1] = 1;
        cnt += Flag[i+1];
    }
    if(N==1) cout << 0 << endl;
    else if(N==2) cout << 1 << endl;
    else if(cnt==-N || cnt == N) cout << N-1 << endl;
    else{
        int ans=0;
        for( int i = 1 ; i <N ; i++ ){
            Fsum[i] = Flag[i] - Flag[i+1];
            if(Fsum[i]==0) ans++;
        }
        int l=0,r=N-1;
        int f=0;
        while(l<r){
            l++;
            if(Fsum[l]!=0){
                while(l<r && Fsum[r] !=0){
                    r--;
                }
                if(Fsum[l] == Fsum[r]) f=1;
            }
        }
        
        l=0;
        r=N-1;
        int cnt=0;
        rep(ki,K){
            while(l<r){
                l++;
                if(Fsum[l]!=0){
                    while(l<r && Fsum[l] != Fsum[r] * -1){
                        r--;
                    }
                    if(Fsum[l] == Fsum[r] * -1){
                        ans+=2;
                        cnt++;
                        break;
                    }else{
                        ans+=1;
                        cnt++;
                        break;
                    }
                }
            }
            //cout << l << " " << r << endl;
        }
        if(K>cnt) ans+=f;
        cout << ans << endl;
    }
}
