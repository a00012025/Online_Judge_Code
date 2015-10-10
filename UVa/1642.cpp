#include<bits/stdc++.h>
#define LL long long
using namespace std;
struct P{int len ; LL val ;};
LL a[100001] ;

LL gcd(LL x,LL y)
{
    return y==0 ? x : gcd(y,x%y) ;
}

bool keep[500] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%lld",&a[i]) ;
        LL ans=a[1] ;
        vector<P> v ; v.push_back((P){1,a[1]}) ;
        for(int i=2;i<=n;i++)
        {
            for(int j=0;j<v.size();j++)
                v[j]=(P){v[j].len+1,gcd(v[j].val,a[i])} ;
            v.push_back((P){1,a[i]}) ;
            for(int j=0;j<v.size();j++) ans=max(ans,v[j].len*v[j].val) ;
            for(int j=0;j<v.size();j++) keep[j]=1 ;
            for(int j=0;j<v.size();j++) for(int k=0;k<v.size();k++)
                if(j!=k && v[j].val==v[k].val && v[j].len<v[k].len)
                keep[j]=0 ;
            int cnt=0 ;
            for(int j=0;j<v.size();j++) if(keep[j])
                v[cnt++]=v[j] ;
            v.resize(cnt) ;
        }
        printf("%lld\n",ans) ;
    }
}
