#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>

using namespace std;
#define rep(i,n) for (ll i = 0; i < (n) ; i++)
  
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

//#include <stack>
//#include <queue>

// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

/*
sort(ord.begin(),ord.end(),[&](int x, int y){
    return p[x]>p[y];
});
*/

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

ll ltmp;
//string stmp;
double dtmp;
ll H ,W;
vector<string> HW;
vvll visit;

#define BASE 10000
typedef pair<ll,ll> zahyou;  
ll getkey(zahyou hwi){
    return hwi.first*BASE + hwi.second;
}
zahyou getzahyou(ll key){
    zahyou ans;
    ans.first = key/BASE;
    ans.second = key % BASE;
    return ans;
}


vll warplist[30];

ll ghi,gwi;
ll shi,swi;

//https://cpprefjp.github.io/reference/queue/priority_queue/pop.html
//std::priority_queue<ll> que;
//que.push(val);
//ll getv = que.top();
//que.pop();
//typedef pair<ll,ll> P;  
//priority_queue<P,vector<P>, greater<P> > que;
//que.push(P(0,base_index));


typedef pair<ll,ll> P;  

ll solve(){

    
    queue<P> quezahyou;
    quezahyou.push(P( 0 , getkey(zahyou(shi,swi))));

    while( quezahyou.size()>0 ){
        
        P zahyouset = quezahyou.front();
        quezahyou.pop();
        ll tditance = zahyouset.first;
        ll tkey = zahyouset.second;
        ll thi = tkey / BASE;
        ll twi = tkey % BASE;
        
        char ctmp = HW[thi][twi];

        if(ctmp=='G') return tditance;
        else if(ctmp=='#') continue;
        else{
            ll dh[] = {-1,1,0,0};
            ll dw[] = {0,0,-1,1};
            
            for( ll di = 0 ; di <4 ; di++ ){
                ll nhi = thi+dh[di];
                ll nwi = twi+dw[di];
                if(nhi >= 0 && nhi<H && nwi >= 0 && nwi<W ){
                    if(visit[nhi][nwi]==0){
                        visit[nhi][nwi]=1;
                        quezahyou.push( P( tditance+1,getkey(zahyou(nhi,nwi)) )  );
                    }
                }
            }


            ll sizewarp = warplist[ctmp-'a'].size();
            for( ll warpi = 0 ; warpi <sizewarp ; warpi++ ){
                ll warpkey = warplist[ctmp-'a'][warpi];
                zahyou warppos = getzahyou(warpkey);
                ll nhi = warppos.first;
                ll nwi = warppos.second;
                if(visit[nhi][nwi]==0){
                    visit[nhi][nwi]=1;
                    quezahyou.push( P( tditance+1,getkey(zahyou(nhi,nwi)) )  );
                }
            }

        }
        //cout << quezahyou.size() << endl;
    }


    return -1;





}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> H;
    cin >> W;

    HW.resize(H);
    visit.resize(H);
    rep(hi,H){
        visit[hi].resize(W);
        cin >> HW[hi];
    }
    rep(hi,H){
        rep(wi,W){
            visit[hi][wi] = 0;

            char ctmp = HW[hi][wi];
            if(ctmp!='S' && ctmp != 'G' && ctmp != '#' && ctmp != '.'){
                ll key =  getkey(zahyou(hi,wi));
                warplist[ctmp-'a'].push_back(key);
            }else if(ctmp == 'G'){
                ghi = hi;
                gwi = wi;
            }else if(ctmp == 'S'){
                shi = hi;
                swi = wi;
            }
        }
    }

    visit[shi][swi] = 1;
    cout << solve() << endl;

    

}


