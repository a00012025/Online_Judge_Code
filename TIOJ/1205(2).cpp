#include<bits/stdc++.h>
#define LL long long
#define pii pair<int,int>
#define F first
#define S second
#define mkp(x,y) make_pair(x,y)
using namespace std;
const int maxn=1500+10 ;

pii a[maxn] ;
map<pii,int> mp ;

main()
{
    int n ;
    while(scanf("%d",&n)!=EOF && n)
    {
        for(int i=1;i<=n;i++) scanf("%d%d",&a[i].F,&a[i].S) ;
        int ans=0 ;
        for(int z=1;z<=n;z++)
        {
            mp.clear() ;
            for(int j=1;j<=n;j++) if(j!=z)
            {
                int x=a[j].F-a[z].F , y=a[j].S-a[z].S ;
                int g=__gcd(x,y) ;
                if(g<0) g=-g ;
                x/=g ; y/=g ;
                mp[mkp(x,y)]++ ;
            }
            for(auto i : mp) ans+=i.S * mp[mkp(-i.F.S,i.F.F)] ;
        }
        printf("%d\n",ans) ;
    }
}
