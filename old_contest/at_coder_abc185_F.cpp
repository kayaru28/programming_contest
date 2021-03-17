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
#define vsort(v) sort(v.begin(),v.end())
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

ll N;
ll Q;
vll A;
vll T;
vll X;
vll Y;

ll ltmp;
string stmp;
double dtmp;

struct SegmentTree
{
	ll n_leaf;
	vector < ll > v, lazy, leafs;
    ll getDecidedVal(ll val1, ll val2){
        return val1 ^ val2;
    }
 	void init(vector < ll > input_leaf, ll input_size){
		n_leaf = input_size;
		leafs = input_leaf;
		input_size = 4 * n_leaf + 1;
		v.resize(input_size);
		lazy.resize(input_size); 
	}
 	void build(ll ind_left,ll ind_right,ll ind_org=1){
		if(ind_left > ind_right)	return ;
		if(ind_left == ind_right) v[ind_org] = leafs[ind_left];
		else{
			ll ind_mid = (ind_left + ind_right) / 2;
            ll ind_child_left = ind_org * 2;
            ll ind_child_right = ind_org * 2 + 1;
			build(ind_left, ind_mid,ind_child_left);
			build(ind_mid + 1, ind_right, ind_org * 2 + 1);
			v[ind_org] = getDecidedVal(v[ind_child_left]  ,  v[ind_child_right]);
		}
	}

	ll query(ll l, ll r, ll ind_left, ll ind_right, ll ind_org = 1) //<--This segtree is for sum of range
	{
		if(ind_left > ind_right) return 0;
		if(l > r) return 0;
		ll ind_mid = (ind_left + ind_right) / 2;
        ll ind_child_left = ind_org * 2;
        ll ind_child_right = ind_org * 2 + 1;
 
		if((l == ind_left) && (r == ind_right))	return v[ind_org];
		else
		 	return  getDecidedVal(query(l, min(ind_mid, r), ind_left, ind_mid, ind_child_left) , 
						query(max(ind_mid + 1, l), r, ind_mid + 1, ind_right,ind_child_right));
	} 
	void update(ll index, ll val, ll ind_left, ll ind_right, ll ind_org = 1)
	{
		if(ind_left > ind_right) return ;
		if(ind_left == ind_right){
			if(ind_left == index){
				v[ind_org] = getDecidedVal(v[ind_org], val);
			}
		}	
		else
		{
			ll ind_mid = (ind_left + ind_right) / 2;
            ll ind_child_left = ind_org * 2;
            ll ind_child_right = ind_org * 2 + 1;
			if(ind_mid >= index)
				update(index, val, ind_left, ind_mid, ind_child_left);
			else
				update(index, val, ind_mid + 1, ind_right, ind_child_right);
			v[ind_org] = getDecidedVal(v[ind_child_left] , v[ind_child_right]);
		}
 	}
};
/*
SegmentTree segtree; 
vll A;
segtree.init(A, N); 
segtree.build(0, N - 1); 
stree.update(ai,aval,0,N-1);
stree.query(li,ri,0,N-1);
*/

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> N;
    cin >> Q;

    A.resize(N);
    rep(ni,N) cin >> A[ni];

    T.resize(Q);
    X.resize(Q);
    Y.resize(Q);

    rep(qi,Q){
        cin  >> T[qi];
        cin  >> X[qi];
        cin  >> Y[qi];
    }

    SegmentTree stree; 
	stree.init(A, N); 
	stree.build(0, N - 1); 


    rep(qi,Q){
        ll ai = X[qi]-1;
        if(T[qi]==1){
            stree.update(ai,Y[qi],0,N-1);
        }else{
            ll ans = stree.query(ai,Y[qi]-1,0,N-1);
            cout << ans << endl;
        }
    }
    

}