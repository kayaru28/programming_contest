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

ll cnt[10][100];
ll maxCnt[10][100];
ll total;
    
int main(){


    
    rep(K,100001){

        int keta;
        if(K<10){
            cout << K << endl;
        }else{
            maxCnt[0][1]=1;
            for( int ni = 0 ; ni <=9 ; ni++ ){
                cnt[ni][1]=1;
                maxCnt[ni][1]=1;
            }
            total = 9;
            
            keta = 2;
            int val;
            val = 1;
            while(1){
                cnt[0][keta]=cnt[0][keta-1]+cnt[1][keta-1];
                for( val = 1 ; val <=9 ; val++ ){
                    if(val<9){
                        cnt[val][keta]=cnt[val-1][keta-1]+cnt[val][keta-1]+cnt[val+1][keta-1];
                    }else{
                        cnt[val][keta]=cnt[val-1][keta-1]+cnt[val][keta-1];                
                    }
                    //cout << keta << " " << val << " = " << cnt[val][keta] << endl;
                    maxCnt[val][keta]=total+cnt[val][keta];
                    if(maxCnt[val][keta]>= K) break;
                    total=maxCnt[val][keta];
                    //cout << total << endl;
                }
                if(maxCnt[min(9,val)][keta] >= K) break;
                keta+=1;
            }
            //cout << cnt[val][keta] << endl;
            //cout << minCnt[val][keta] << endl;
            //cout << maxCnt[val][keta] << endl;

            int now;
            int left=0;
            left = K - total;
            cout << val;
            keta = keta -1;
            while(keta>0){
                //cout << "-----" << endl;
                //cout << left << endl;
                //cout << cnt[val-1][keta] << endl;
                //cout << cnt[val][keta] << endl;
                //cout << cnt[val+1][keta] << endl;
                
                if(left <= cnt[val-1][keta]){
                    val = val - 1;
                }else{
                    left -= cnt[val-1][keta];
                    if(left <= cnt[val][keta]){
                        val = val;
                    }else{
                        left -= cnt[val][keta];
                        val = val + 1;
                    }
                }
                cout << val;
                keta = keta -1;
            }
            cout << endl;
        }
    }
}