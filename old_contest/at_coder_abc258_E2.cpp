


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
#define llINF numeric_limits<long long>::max();
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
ll Q;
ll T;
ll H;
ll W;
ll X;
ll Y;
ll Z;
//vll As,Bs;
ll getMod(ll value,ll mod=MOD){
    if(value == 0) return 0;
    if(mod==0) return -1;
    value %= mod;
    if(value<0) value += mod;
    return value;
}
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
vvll masu;
string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
double double_hosei = 1000000; //求められる精度分補正をかけておく

vvll tar_graphi;
bool checkGraphRoop(){
    vll visited;
    ll graphsize = tar_graphi.size();
    visited.resize(graphsize);
    for( ll nodei = 0 ; nodei <graphsize ; nodei++ ){
        if(visited[nodei]==1) continue;
        visited[nodei]=1;
        queue<P> qnode; // currentnode , parent node
        qnode.push(P(nodei,0));
        while (qnode.size()>0)
        {
            P nowv = qnode.front();
            qnode.pop();
            ll parent_nodei = nowv.second;
            ll crr_nodei = nowv.first;
            for(ll next_nodei : tar_graphi[crr_nodei]){
                if(next_nodei == parent_nodei) continue;
                if(visited[next_nodei]==1) return true;
                visited[next_nodei]=1;
                qnode.push(P(next_nodei,crr_nodei));
            }
        }
    }
    return false;
}




int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> Q >> X;

    //As.resize(N);
    ll As[N];
    rep(ni,N) cin >> As[ni];

    //Bs.resize(Q);
    //rep(qi,Q) cin >> Bs[qi];

    ll kosu[N];
    ll tar_index = 0;
    ll nextsum_index = 0;
    ll tmpsum = 0;
    ll tmpcnt = 0;
    /*
    rep(tar_index,N){
        while(tmpsum < X){
            tmpsum += As[nextsum_index];
            tmpcnt++;
            nextsum_index++;
            nextsum_index = nextsum_index % N;
            
        }
        kosu[tar_index]=tmpcnt;
        tmpcnt--;
        tmpsum-=As[tar_index];
    }
    */
    x %= all;
    for (int i = 0, j = 0, s = 0; i < N; ++i) {
        if (j < i) {
            j = i;
            s = 0;
        }
        while (s < x) {
            s += w[j];
            j += 1;
        }
        kosu[i] += j - i;
        s -= w[i];
    }   

    vector<int> order(N, -1), path;
    int loop = -1;
    for (int u = 0, k = 0;; ++k) {
        if (order[u] != -1) {    
            loop = k - order[u];
            break;
        }
        order[u] = k;
        path.push_back(u);
        u = (u + kosu[u]) % N;
    }
    const int non_loop = (int)path.size() - loop;
    rep(qi,Q) {
        ll k;
        //k = Bs[qi];
        cin >> k;
        k -= 1;
        if (k < non_loop) {
            cout << kosu[path[k]] << '\n';
        } else {
            k = (k - non_loop) % loop;
            cout << kosu[path[non_loop + k]] << '\n';
        }
    }





}