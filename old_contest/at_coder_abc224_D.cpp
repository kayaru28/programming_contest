


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
vll As,Bs;

string S;
vll Ps,Us,Vs;
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
map<string,ll> valmap;
vvll graphi;
ll ans = llINF;
string getkey(vll pos){
    string tmpans = "";
    for( ll pi = 1 ; pi <=9 ; pi++ ){
        tmpans += to_string(pos[pi]);
    } 
    return tmpans;
}
ll get_quekey(vll pos){
    ll tmpans = 0;
    ll s0;
    for( ll pi = 1 ; pi <=9 ; pi++ ){
        tmpans *= 10;
        tmpans += pos[pi];
        if(pos[pi]==0) s0 = pi;
    } 
    return tmpans * 10 + s0;
}
bool judgeP(vll pos){
    return getkey(pos) == "123456780";
}
void searchAns(vll pos, ll nextpos){
    vll tmppos = pos;
    string key_from = getkey(pos);

    vll nextS;
    for(ll frompos : graphi[nextpos]){
        tmppos[nextpos] = tmppos[frompos];
        tmppos[frompos] = 0;
        string key_next = getkey(tmppos);
        cout << "bef " << key_next << " " << valmap[key_next] << endl;
        if(valmap[key_next]==0 || valmap[key_next]>valmap[key_from]+1){
            valmap[key_next]=valmap[key_from]+1;
            cout << "aft " <<key_next << " " << valmap[key_next] << endl;
            if(judgeP(tmppos)) ans = llmin(ans,valmap[key_next]);
            nextS.push_back(frompos);
        }
        tmppos[frompos] = tmppos[nextpos];
        tmppos[nextpos] = 0;
    }
    for(ll frompos : nextS){
        //cout << nextpos << " to " << frompos << endl;
        tmppos[nextpos] = tmppos[frompos];
        tmppos[frompos] = 0;
        searchAns(tmppos,frompos);
        tmppos[frompos] = tmppos[nextpos];
        tmppos[nextpos] = 0;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M;

    Us.resize(M);
    Vs.resize(M);
    rep(mi,M) cin >> Us[mi] >> Vs[mi];

    Ps.resize(9);
    vll posi;
    rep(ni,10) posi.push_back(0);
    for( ll pi = 1 ; pi <=8 ; pi++ ){
        cin >> Ps[pi];
        posi[Ps[pi]] = pi;
    }

    if(judgeP(posi)) ans = 0;
    else{
        graphi.resize(10);
        rep(mi,M){
            graphi[Us[mi]].push_back(Vs[mi]);
            graphi[Vs[mi]].push_back(Us[mi]);
        }
        //https://cpprefjp.github.io/reference/queue/priority_queue/pop.html
        //std::priority_queue<ll> que;
        //que.push(val);
        //ll getv = que.top();
        //que.pop();
        //typedef pair<ll,ll> P;  
        //priority_queue<P,vector<P>, greater<P> > que;
        //que.push(P(0,base_index));

        queue<ll> que;
        que.push(get_quekey(posi));

        while(que.size()>0){
            ll var = que.front();
            que.pop();
            ll pos0 = var % 10;
            var = var/10;
            vll tmppos;
            tmppos.resize(10);
            for( ll pi = 9 ; pi >=1 ; pi-- ){
                tmppos[pi] = var % 10;
                var = var/10;
            }
            string key_from = getkey(tmppos);
            //cout << "from " << key_from << " " << valmap[key_from]<< endl;
            //cout << pos0 << endl;
            for(ll frompos :  graphi[pos0]){
                //cout << "frompos " << frompos << endl;
                tmppos[pos0] = tmppos[frompos];
                tmppos[frompos] = 0;
                string key_next = getkey(tmppos);
                //cout << "next " << key_next << " " << valmap[key_next]<< endl;
                if(valmap[key_next]==0){
                    valmap[key_next]=valmap[key_from]+1;
                    que.push(get_quekey(tmppos));
                    if(judgeP(tmppos)){
                        ans = llmin(ans,valmap[key_next]);
                        que.empty();
                    }
                }
                tmppos[frompos] = tmppos[pos0];
                tmppos[pos0] = 0;
            }
        }
    }
    if(ans==llINF) ans = -1;
    cout << ans << endl;


}