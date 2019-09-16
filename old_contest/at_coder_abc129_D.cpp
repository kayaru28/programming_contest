#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
typedef long long ll;
//#include <stack>
//#include <queue>
#define MOD 1000000007

string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 
 

int tile[2010][2010]={};
int cnt[2010][2010][4]={};

int main(){
    int H,W;
    cin >> H >> W;
    string S;
    string tmpS;

    for( int hi = 1 ; hi <= H ; hi++ ){
        cin >> S;
        for( int wi = 1 ; wi <= W  ; wi++ ){
            tmpS = S.substr(wi-1,1);
            if(tmpS =="#") tile[hi][wi] = 0;
            else tile[hi][wi] = 1;
        }
    }
    int left = 0;
    int above = 1;
    int under = 2;
    int right = 3;
    int ih,iw,iv;
    for( int hi = 1 ; hi <= H ; hi++ ){
        for( int wi = 1 ; wi <= W  ; wi++ ){
            if(tile[hi][wi] != 0){
                ih = hi; iw = wi-1; iv = left;
                cnt[hi][wi][iv] = cnt[ih][iw][iv] * tile[ih][iw]  + 1;
                ih = hi-1; iw = wi; iv = above;
                cnt[hi][wi][iv] = cnt[ih][iw][iv] * tile[ih][iw]  + 1;
            }
        }
    }
    for( int hi = H ; hi >= 1 ; hi-- ){
        for( int wi = W ; wi >= 1  ; wi-- ){
            if(tile[hi][wi] != 0){
                ih = hi; iw = wi+1; iv = right;
                cnt[hi][wi][iv] = cnt[ih][iw][iv] * tile[ih][iw]  + 1;
                ih = hi+1; iw = wi; iv = under;
                cnt[hi][wi][iv] = cnt[ih][iw][iv] * tile[ih][iw]  + 1;
            }
        }
    }

    int ans = 0;
    int sum;
    for( int hi = H ; hi >= 1 ; hi-- ){
        for( int wi = W ; wi >= 1  ; wi-- ){
            sum = 0;
            for( int vi = 0 ; vi < 4 ; vi++ ){
                sum+= cnt[hi][wi][vi];
            }
            ans = max(sum-3,ans);
        }
    }
    cout << ans << endl;
    /*
    for( int vi = 0 ; vi < 4 ; vi++ ){
        for( int hi = 1 ; hi <= H ; hi++ ){
            for( int wi = 1 ; wi <= W  ; wi++ ){
                cout <<  cnt[hi][wi][vi];
                cout << " ";
            }
            cout << "" << endl;
        }
        cout << "" << endl;
    }
    */

}