


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
vll Ai,Bi,Ci;

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

vector<ll> values;
class BinarySearch
{
    private:
        // 検索対象を判定する条件を設定
        ll CODE_MARCH = 0;
        ll judge(ll target_value,ll comparison_index){
            if(target_value==values[comparison_index]) return CODE_MARCH;
            else if(target_value > values[comparison_index]) return 1;
            else return 2;
        }
    public:
        ll search(ll target){
            ll left  = 0;
            ll right = values.size();
            ll mid;

            while(left<right){
                mid = (left+right)/2;
                if(judge(target,mid)==CODE_MARCH){
                        return mid;
                // 検索結果が条件に合致しない場合の処理
                }else if(judge(target,mid)==1){
                    left = mid;
                }else{
                    right = mid;
                }
            }
        }
};
BinarySearch binary_search; // int main の中で使う

ll getIndexXXXorMore(ll target,vll xvector){
    ll left  = 0;
    ll right = xvector.size()-1;
    if(xvector[left] > target) return left;
    if(xvector[right] < target) return -1;
    if(xvector[left] == target) return left;
    if(xvector[right] == target) return right;
    while(left + 1 != right && left < right ){
        ll mid = (left+right)/2;
        if(xvector[mid]==target) return mid;
        else if(xvector[mid] < target) left  = mid;
        else if(xvector[mid] > target) right = mid;
    }
    return right;
}

ll getIndexOverXXX(ll target,vll xvector){
    return getIndexXXXorMore(target+1,xvector);
}

//探索したいkeyより大きい
//upper_bound(x_vector.begin(), x_vector.end(), key) - x_vector.begin();

//探索したいkey以上
//lower_bound(x_vector.begin(), x_vector.end(),key) - x_vector.begin();

double double_hosei = 1000000; //求められる精度分補正をかけておく
int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    Ai.resize(N);
    Bi.resize(N);
    Ci.resize(N);


    rep(ni,N) cin >> Ai[ni];
    rep(ni,N) cin >> Bi[ni];
    rep(ni,N) cin >> Ci[ni];

    sort(Ai.begin(),Ai.end());
    sort(Bi.begin(),Bi.end());
    sort(Ci.begin(),Ci.end());
    x_vector = Ai;

    ll ans = 0;
	rep(i,N) {
		ll key = Bi[i];
		// A side

		ll cnt_a = getval(key);
		// C side
		ll cnt_c = upper_bound(Ci.begin(),Ci.end(),key) - Ci.begin();
		ans += cnt_a * (N - cnt_c);		
	}
 
    /*
    for(ll vbi : Bi){
        ll indA = getIndexXXXorMore(vbi,Ai);
        ll cntA = indA;

        ll indC = getIndexOverXXX(vbi,Ci);
        ll cntC = N - indC;

        ans += ( cntA * cntC );

    }
    */
    cout << ans << endl;


}