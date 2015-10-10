#include<stdio.h>
#include<algorithm>
#include<string.h>
#define LL long long
using namespace std;
LL x[600],y[600],x1[600],y1[600],x2[600],y2[600] ;
bool vis[600][600] ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int n ; scanf("%d",&n) ;
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld%lld%lld",&x1[i],&y1[i],&x2[i],&y2[i]) ;
            x[2*i]=x1[i] ; x[2*i+1]=x2[i] ;
            y[2*i]=y1[i] ; y[2*i+1]=y2[i] ;
        }
        sort(x,x+2*n) ; sort(y,y+2*n) ;
        int nx=0,ny=0 ;
        for(int i=0;i<2*n;i++)
        {
            if(i==0 || x[i]!=x[i-1]) x[nx++]=x[i] ;
            if(i==0 || y[i]!=y[i-1]) y[ny++]=y[i] ;
        }
        LL ans=0LL ;
        memset(vis,0,sizeof(vis)) ;
        for(int i=0;i<n;i++)
        {
            int stx,sty ;
            for(stx=0;x[stx]!=x1[i];stx++) ;
            for(sty=0;y[sty]!=y1[i];sty++) ;
            for(int j=stx;x[j]!=x2[i];j++) for(int k=sty;y[k]!=y2[i];k++)
            {
                if(!vis[j][k]) ans+=(x[j+1]-x[j])*(y[k+1]-y[k]) ;
                vis[j][k]=1 ;
            }
        }
        printf("%lld\n",ans) ;
    }
}
