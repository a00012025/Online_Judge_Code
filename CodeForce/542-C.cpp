#include<bits/stdc++.h>
#define LL unsigned long long
using namespace std;
const int maxn=200+10 ;

int a[maxn] ;
int vis[maxn],b[maxn],cnt ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    LL ans=1 ;
    int ma=0 ;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==i) continue ;
        memset(vis,-1,sizeof(vis)) ;
        for(int j=i,k=0;;k++,j=a[j])
        {
            vis[j]=k ;
            if(vis[a[j]]!=-1)
            {
                ma=max(ma,vis[a[j]]) ;
                LL val=k-vis[a[j]]+1 ;
                ans=(ans/__gcd(ans,val))*val ;
                break ;
            }
        }
    }
    if(ans<ma) ans=ans*((ma-1)/ans+1) ;
    printf("%I64u\n",ans) ;
}
