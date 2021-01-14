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
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
    
/*
multiset<int> ms;
ms.insert(7);
ms.insert(5);
ms.insert(2);
ms.insert(7);
ms.count(5);
if (ms.find(5) == ms.end()){}else{}
ms.erase(5);
*/


int main(){
    int n;
    cin>>n;
    int p[n];
    rep(i,n)cin>>p[i];
    vector<int> ord(n);
    rep(i,n)ord[i]=i;
    sort(ord.begin(),ord.end(),[&](int x, int y){
        return p[x]>p[y];
    });
    multiset<int> st;
    ll ans = 0;
    st.insert(n);
    st.insert(n);
    st.insert(-1);
    st.insert(-1);

    
    for(auto i : ord){
        auto itr = st.lower_bound(i);
        cout << *itr << endl;
        ll idx1 = *itr;
        ++itr;

        ll idx2 = *itr;
        --itr;
        --itr;
        ll idx3 = *itr;
        --itr;
        ll idx4 = *itr;
        ans += p[i]*(idx2-idx1)*(i-idx3);
        ans += p[i]*(idx3-idx4)*(idx1-i);
        st.insert(i);
    }
    cout<< "ans is " << ans<<endl;
    return 0;
}