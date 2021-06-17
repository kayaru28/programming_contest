

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
#define repRangeInc(i,s,n) for (ll i = (s); i <= (n) ; i++)
#define repRangeDec(i,s,n) for (ll i = (s); i >= (n) ; i--)
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




// #include <iomanip>
//  cout << fixed << setprecision(15) << y << endl;

// for(char c : S)

//min({a1, a2, ..., an})
//max({a1, a2, ..., an})
//swap(a, b)
//S.substr(si)
// sort <--> reverse
//count(v.begin(), v.end(), x) 

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
vvll flag_aice;
typedef pair<ll,ll> P;  
vector<P> field_aice[100][100];

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



using Graph = vector<vector<ll>>; //第一引数のノードは、その中のベクターにあるノードとつながりがある

ll tmpans;
void getSearchUnit(ll pn, ll pm ,ll score,vvll flag_visit){
    vvll update_flag_visit;
    update_flag_visit = flag_visit;
    score++;
    update_flag_visit[pn][pm] = 1;
    tmpans = llmax(tmpans,score);

    for(P pointnm : field_aice[pn][pm]){
        ll next_pn = pointnm.first;
        ll next_pm = pointnm.second;
        //cout << next_pn << " " << next_pm << endl;
        if(update_flag_visit[next_pn][next_pm]==0){
            getSearchUnit(next_pn,next_pm,score,update_flag_visit);
        }
    }


}
void getSearch(){
    vvll flag_visit;
    tmpans = 0;
    flag_visit.resize(N);
    rep(ni,N){
        rep(mi,M) flag_visit[ni].push_back(0);
    }

    rep(ni,N){
        rep(mi,M){
            if(flag_aice[ni][mi]==1){
                //cout << "----------------------" << endl;
                getSearchUnit(ni,mi,0,flag_visit);
                //cout << ni << " " << mi << endl;
                //cout << tmpans << endl;
            }
        }
    }




}



double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> M;
    cin >> N;
    flag_aice.resize(N);
    rep(ni,N){
        flag_aice[ni].resize(M);
        rep(mi,M){
            cin >> flag_aice[ni][mi];
        }
    }

    rep(ni,N){
        repRangeInc(mi,0,M-2){
            if(flag_aice[ni][mi+1]==1){
                field_aice[ni][mi].push_back( P(ni,mi+1) );
            }
        }
        repRangeDec(mi,M-1,1){
            if(flag_aice[ni][mi-1]==1){
                field_aice[ni][mi].push_back( P(ni,mi-1) );
            }
        }
    }
    rep(mi,M){
        repRangeInc(ni,0,N-1-1){
            if(flag_aice[ni+1][mi]==1){
                field_aice[ni][mi].push_back( P(ni+1,mi) );
            }
        }
        repRangeDec(ni,N-1,1){
            if(flag_aice[ni-1][mi]==1){
                field_aice[ni][mi].push_back( P(ni-1,mi) );
            }
        }
    }

    getSearch();
    cout << tmpans << endl;



    

}