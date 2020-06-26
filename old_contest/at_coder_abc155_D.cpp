    #include<bits/stdc++.h>
    using namespace std;
    typedef long long ll;
    const int N=2e5+5;
    int n;
    ll k;
    vector<ll>v1,v2;
    bool judge(ll m)
    {
        m++;
        ll ans=0;
        ll s1=v1.size(),s2=v2.size();
        if(m==0)
        {
            for(int i=0;i<s2;i++)
                if(v2[i]==0) ans+=s1;
            ans+=(ll)s1*(s1-1)/2;
            ans+=(ll)s2*(s2-1)/2;
            ans=(ll)n*(n-1)/2-ans;
            return ans>=k;
        }
        if(m>0)
        {
            for(int i=0;i<s1-1;i++)
            {
                ll x=m/v1[i];
                if(m%v1[i]) x++;
                int k=lower_bound(v1.begin()+i+1,v1.end(),x)-v1.begin();
                ans+=s1-k;
            }
            for(int i=0;i<s2-1;i++)
            {
                if(v2[i]==0) continue;
                ll x=m/v2[i];
                if(m%v2[i]) x++;
                int k=lower_bound(v2.begin()+i+1,v2.end(),x)-v2.begin();
                ans+=s2-k;
            }
            ans=(ll)n*(n-1)/2-ans;
            return ans>=k;
        }
        if(m<0)
        {
            m*=-1;
            ans+=(ll)s1*(s1-1)/2;
            ans+=(ll)s2*(s2-1)/2;
            for(int i=0;i<s1;i++)
            {
                ll x=m/v1[i];
                int k=upper_bound(v2.begin(),v2.end(),x)-v2.begin()-1;
                ans+=k+1;
            }
            ans=(ll)n*(n-1)/2-ans;
            return ans>=k;
        }
    }
    int main()
    {
        scanf("%d%lld",&n,&k);
        for(int i=1;i<=n;i++)
        {
            int x;scanf("%d",&x);
            if(x<0) v1.push_back(-x);
            else v2.push_back(x);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        ll l=-1e18,r=1e18,ans;
        while(l<=r)
        {
            ll m=l+r>>1;
            if(judge(m)) ans=m,r=m-1;
            else l=m+1;
        }
        printf("%lld\n",ans);
    }