#include<stdio.h>
#include<algorithm>
#include<string.h>
using namespace std;
int n,a[501],b[501],per[501];
bool vis[501] ;

int solve()
{
    memset(vis,0,sizeof(vis)) ;
    int ret=0 ;
    for(int i=1;i<=n;i++) per[a[i]]=b[i] ;
    for(int i=1;i<=n;i++) if(!vis[i])
    {
        vis[i]=1 ;
        for(int j=per[i];j!=i;j=per[j]) {ret++ ; vis[j]=1 ;}
    }
    return ret ;
}

main()
{
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        int ans=10000000 ;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) {b[j]=i+j-1 ; if(b[j]>n) b[j]-=n ;}
            ans=min(ans,solve()) ;
            for(int j=1;j<=n;j++) {b[j]=i-j+1 ; if(b[j]<1) b[j]+=n ;}
            ans=min(ans,solve()) ;
        }
        printf("%d\n",ans) ;
    }
}
