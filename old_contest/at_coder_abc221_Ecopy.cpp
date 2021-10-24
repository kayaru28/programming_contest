#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const ll mod = 998244353;

struct binary_indexed_tree{
    int N;
    vector<ll> bit;
    binary_indexed_tree(int n):N(n){
        bit.resize(N+1,0);
    }
    ll addition(ll x, ll y){
        return (x+y)%mod;
    }
    void add(int x,ll a){
        x++;
        for(x; x<=N; x+=(x&-x)) bit[x] = addition(bit[x],a);
    }
    ll sum(int x){
        x++;
        ll ret=0;
        for(x; x>0; x-=(x&-x)) ret = addition(ret,bit[x]);
        return ret;
    }
};
ll getPower(ll value,ll shisu,ll mod=mod){
    ll ans = 1;
    ll cnt = shisu;
    while(cnt>0){
        if(cnt%2==1){
            ans = ans * value % mod;
        }
        value = value * value % mod;
        cnt = cnt/2;
    }
    return ans;
}
ll modDivision(ll warareru, ll warukazu){
    //mod is prime number
    //warukazu can not separate
    ll div = getPower(warareru,mod-2);
    return getPower(div,warukazu);
}
ll getMod(ll value){
    if(value == 0) return 0;
    if(mod==0) return -1;
    value %= mod;
    if(value<0) value += mod;
    return value;
}
int comp(vector<int> &A){
    std::map<int,int> mem;
    for(auto p: A) mem[p] = 0;
    int sz = 0;
    for(auto &p: mem) p.second = sz++;
    for(auto &p: A) p = mem[p];
    return sz;
}

int main(){
    const ll div = getPower(2,mod-2);
    int N; cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    int n = comp(A);
    binary_indexed_tree bit(n);
    ll ans = 0;
    for(int i=0; i<N; i++){
        ans += bit.sum(A[i])*getPower(2,i);
        ans %= mod;
        bit.add(A[i],modDivision(2,i+1));
    }
    cout << ans << endl;
}
