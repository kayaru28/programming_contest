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
ll N;
ll P;

ll getPower(ll value,ll shisu,ll MODV){
    ll ans = 1;
    ll cnt = shisu;
    while(cnt>0){
        if(cnt%2==1){
            ans = ans * value % MODV;
        }
        value = value * value % MODV;
        cnt = cnt/2;
    }
    return ans;
}
int getIntSubstr(string s,int start_index,int length){
    return atoi(s.substr(start_index,length).c_str());
}
int main(){

    cin >> N;
    cin >> P;

    string S;
    
    cin >> S;

    int index_str;
    int index_end;
    index_str = 0;
    index_end = N-1;

    vint flag;
    int l_cnt[10010]={};
    ll shisu=0;
    ll cnt=0;
    ll value=0;
    for( int index = index_end ; index >= index_str ; index-- ){
        //cout << getIntSubstr(S,index,1)  << endl;
        value = value + getIntSubstr(S,index,1) * getPower(10,shisu,P);
        l_cnt[value % P]++;
        shisu++;
    }
    cnt = 0;
    int tmp;
    tmp = l_cnt[0];
    //cout << tmp << endl;
    cnt+=tmp*(tmp+1)/2;
    for( int ni = 1 ; ni <P+1 ; ni++ ){
        tmp = l_cnt[ni];
        //cout << tmp << endl;
        if(tmp>1) cnt+=tmp*(tmp-1)/2;
    }
    cout << cnt << endl;
    //rep(ni,flag.size()) cout << flag[ni] << endl;

    

}