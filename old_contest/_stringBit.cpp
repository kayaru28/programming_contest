

#include  <iostream>
#include  <stdio.h>
#include <algorithm>
#include <map>
#include <math.h>
#include <queue>
#include <vector>
#include <stack>
#include <set>
#include <bitset>

using namespace std;
#define rep(i,n) for (ll i = 0; i < (n) ; i++)
#define rep2(i,n,i2,n2) for (ll i = 0; i < (n) ; i++) for (ll i2 = 0; i2 < (n2) ; i2++)
#define incRepFT(i,s,n) for (ll i = (s); i <= (n) ; i++)
#define decRepFT(i,s,n) for (ll i = (s); i >= (n) ; i--)

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
#define ld long double
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vstr vector<string>
#define vvstr vector<vector<string>>
typedef pair<ll,ll> P;  

vll As;


// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

// for(char c : S)

//min({a1, a2, ..., an})
//max({a1, a2, ..., an})
//swap(a, b)
//S.substr(si)
// sort <--> reverse
//count(v.begin(), v.end(), x) 
// char t - 'a'
// char t - '0'

//xを2進数にした時の1の数
//__builtin_popcount(x) 
//__builtin_popcountll(x) 

ll A;
ll B;
ll C;
ll D;
ll N;
ll M;
ll K;
ll T;
ll H;
ll W;
ll X;
ll Y;
ll Z;

string S;

ll ltmp;
string stmp;
double dtmp;

ll llmin(ll a,ll b){
    if(a>=b) return b;
    return a;
}
ll llmax(ll a,ll b){
    if(a<=b) return b;
    return a;
}
P d_move[4] = {
    P(0 , 1),P(0 , -1),P(1 , 0),P(-1 , 0)//,P(1 , 1),P(1 , -1),P(-1 , 1),P(-1 , -1)
};
//for(P drc : d_move)

double double_hosei = 1000000; //求められる精度分補正をかけておく
map<ll,ll> cnt_amari;
map<ll,vstr> map_index;

ll getIndexVal(ll val){
    return pow(2,val-1);
}

#define bit_size 30 //2^30 = 10^9
/*
bitset<8> xbit(131); 　　　　// 長さ 8 の bitset を定義する。整数から初期化を行う。
bitset<8> xbit('10000011'); // 長さ 8 の bitset を定義する。2 進数から初期化を行う。
xbit = (xbita & xbitb) //XOR
xbit = (xbita | xbitb) //OR
xbit = (xbita ^ xbitb) //XOR
xbit.set(x)    //x 桁目を1に
xbit.reset(x)  //x 桁目を0に
xbit[i] //i桁目(0～)にアクセス
xbit.count() //1の数をカウント
ll bit_search_ans = 0;
void execBitAllSearch(int keta_bit){
    ll bitval = pow(2,keta_bit);
    rep(bi,bitval){
        bitset<bit_size> xbit(bi);
        ///////////////////////////////////////////////////
        //// Process Start --------------------------------


        //// Process End   --------------------------------
        ///////////////////////////////////////////////////
    }
}
*/
ll key1;
ll key2;

ll stringbit_keta = 200;
string stringbitCreate0(){
    string index;
    rep(ki,stringbit_keta) index = index + "0";
    return index;
}
ll stringbitCount(string bit1){
    ll diff=0;
    rep(ki,stringbit_keta){
        if(bit1[ki]=='1') diff++;
    }
    return diff;
}
string stringbitAND(string bit1, string bit2){
    string stringbit_ans = "";
    rep(ki,stringbit_keta){
        string stringbit_tmpans;
        if(bit1[ki]=='1' && bit2[ki] == '1') stringbit_tmpans="1";
        else stringbit_tmpans = "0";
        stringbit_ans = stringbit_ans + stringbit_tmpans;
    }
    return stringbit_ans;
}
string stringbitOR(string bit1, string bit2){
    string stringbit_ans = "";
    rep(ki,stringbit_keta){
        string stringbit_tmpans;
        if(bit1[ki]=='0' && bit2[ki] == '0') stringbit_tmpans="0";
        else stringbit_tmpans = "1";
        stringbit_ans = stringbit_ans + stringbit_tmpans;
    }
    return stringbit_ans;
}
string stringbitXOR(string bit1, string bit2){
    string stringbit_ans = "";
    rep(ki,stringbit_keta){
        string stringbit_tmpans;
        if(bit1[ki]=='1' && bit2[ki] == '1') stringbit_tmpans="0";
        else if(bit1[ki]=='0' && bit2[ki] == '0') stringbit_tmpans="0";
        else stringbit_tmpans = "1";
        stringbit_ans = stringbit_ans + stringbit_tmpans;
    }
    return stringbit_ans;
}

ll getSolve(){
    string index = stringbitCreate0();
    rep(ni,N){
        ll key = As[ni];
        cnt_amari[key]++;
        index[ni]='1';
        map_index[key].push_back( index );
        index[ni]='0';
        if(cnt_amari[key]==2) return key;
    }

    ll left = 1;
    while(left<N){
        for(auto x : cnt_amari) {
            ll xkey = x.first;
            ll xvalue = x.second;
            string xindex = map_index[xkey][0];
            for(auto y : cnt_amari) {
                ll ykey = y.first;
                ll yvalue = y.second;
                string yindex = map_index[ykey][0];
                string index_and = stringbitAND(xindex,yindex);
                //cout << xindex << " " << yindex << " " << index_and << endl;
                ll diff = stringbitCount(index_and);
                if(diff>0) continue;

                ll nkey = xkey + ykey;
                nkey = nkey % 200;
                string nindex = stringbitOR(xindex,yindex);
                if(cnt_amari[nkey]==0){
                    cnt_amari[nkey]++;
                    map_index[nkey].push_back(nindex);
                }else{
                    if(map_index[nkey][0] != nindex){
                        cnt_amari[nkey]++;
                        map_index[nkey].push_back(nindex);
                        return nkey;
                    }
                }
            }
        }
        left++;
    }

    return -1;





}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    stringbit_keta = N;
    As.resize(N);
    rep(ni,N) cin >> As[ni];
    rep(ni,N) As[ni] = As[ni] % 200;

    ll anskey = getSolve();
    if(anskey==-1) cout << "No" << endl;
    else{
        cout << "Yes" << endl;
        string xindex = map_index[anskey][0];
        string yindex = map_index[anskey][1];

        ll cnt = 0;
        rep(ni,N) if(xindex[ni]=='1')cnt++;

        cout << cnt << " ";
        rep(ni,N){
            if(xindex[ni]=='1') cout << ni + 1 << " ";
        }
        cout << endl;
        cnt = 0;
        rep(ni,N) if(yindex[ni]=='1')cnt++;
        cout << cnt << " ";
        rep(ni,N){
            if(yindex[ni]=='1') cout << ni + 1 << " ";
        }
        cout << endl;
    }


}