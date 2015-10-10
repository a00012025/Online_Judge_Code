#include<bits/stdc++.h>
#define DB double
#define LL long long
#define F first
#define S second
using namespace std;
const int maxn=500000+10 ;

pair<int,int> p[maxn],st[maxn] ;
main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%d%d",&p[i].F,&p[i].S) ;
        sort(p+1,p+n+1) ;
        int sz=0 ;
        DB ans=0 ;
        for(int i=1,now=0;i<=n;i++)
        {
            if(!sz){st[sz++]=p[i] ; continue ;}
            while(now<sz-1 &&
                  (LL)(st[now+1].S-p[i].S)*(st[now].F-p[i].F)>=
                  (LL)(st[now+1].F-p[i].F)*(st[now].S-p[i].S) )
                now++ ;
            ans=max(ans,(st[now].S-p[i].S)*1.0/(st[now].F-p[i].F)) ;
            while(sz>=2 &&
                  (LL)(st[sz-2].S-p[i].S)*(st[sz-1].F-p[i].F)>=
                  (LL)(st[sz-2].F-p[i].F)*(st[sz-1].S-p[i].S)) sz-- ;
            st[sz++]=p[i] ;
            now=min(now,sz-1) ;
        }
        printf("%.15f\n",ans) ;
    }
}
