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
#define base10_4 10000      //1e4
#define base10_5 100000     //1e5
#define base10_6 1000000    //1e6
#define base10_7 10000000   //1e7
#define base10_8 100000000  //1e8
#define base10_9 1000000000 //1e9
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
ll A[base10_6];
ll B[base10_6];
ll C;
ll N;
ll M;
ll K;


ll getPower(ll value,ll shisu,ll mod){
    ll ans = 1;
    ll cnt = shisu;
    while(cnt>0){
        if(cnt%2==1){
            ans += MOD;
            ans = ans * value % mod;
        }
        value += MOD;
        value = value * value % mod;
        cnt = cnt/2;
    }
    return ans;
}
long long koyaku_max(long long a,long long b){
    long long r;
    r = a % b;
    while(r!=0){
        a = b;
        b = r;
        r = a % b;
    }
    return b;
}

ll ans = 1;
#include <map>
int main(){

    
    cin >> N;
    rep(ni,N){
        cin >> A[ni];
        cin >> B[ni];
    }

    map<string,ll> count_map[2];
    map<string,string> conv;
    int m_std = 0;
    int m_rev = 1; 
    ll count_both_0=0;
    count_map[m_std]["0"]=0;
    count_map[m_rev]["0"]=0;
    conv["0"]="0";

    rep(ni,N){
        if(A[ni]==0&&B[ni]==0){
            count_both_0++;
        }else{
            if(A[ni] == 0){
                count_map[m_std]["0"]++;
            }else if(B[ni]==0){
                count_map[m_rev]["0"]++;
            }else{
                ll koyaku = koyaku_max(A[ni],B[ni]);
                A[ni] = A[ni] / koyaku;
                B[ni] = B[ni] / koyaku;
                string strA = to_string(abs(A[ni]));
                string strB = to_string(abs(B[ni]));
                string mark_std = "";
                string mark_rev = "";
                if(A[ni]*B[ni]<0){
                    mark_std = "-";
                }else{
                    mark_rev = "-";
                }

                string index1 = mark_std + strA + "/" + strB;
                string index2 = mark_rev + strB + "/" + strA;
                //cout << "-----------------" << endl;
                //cout << index1 << endl;
                //cout << index2 << endl;
                if(count_map[m_rev].count(index1)==1){
                    count_map[m_rev][index1]++;
                    //cout << "match rev" << endl;
                }else{
                    if(count_map[m_std].count(index1)==1){
                        //cout << "inc" << endl;
                        count_map[m_std][index1]++;
                    }else{
                        //cout << "create" << endl;
                        count_map[m_std][index1] = 1;
                        count_map[m_rev][index2] = 0;
                        conv[index1]=index2;
                    }
                }
            }



        }
    }

    ll ans = 1;

    for(auto x : count_map[m_std]) {
        string key = x.first;
        ll value = x.second;
        ll tmp = 1;
        tmp += getPower(2,value,MOD) - 1;

        key = conv[key];
        value = count_map[m_rev][key];
        tmp += getPower(2,value,MOD) - 1;

        ans += MOD;
        ans = ans * tmp % MOD;
        //cout << ans << endl;        
    }
    //cout << "--------" << endl;
    //cout << "answer is " << endl;
    ans = ans + count_both_0;
    ans = ans - 1 + MOD;
    ans = ans % MOD;
    cout << ans << endl;



    

}