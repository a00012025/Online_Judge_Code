#include<stdio.h>
#include<algorithm>
using namespace std;
int vis[10000]={0},N=2100000000 ;
int a[10000],b[10000];
main()
{
    int n=1 ;
    while(scanf("%d %d",&a[n],&b[n])!=EOF) {if(a[n]<=b[n]) n++ ;}
    n-- ;
    int len=0,id,remain=N ;
    for(len=1;len<=n;len++)
    {
        int newr=-N ;
        for(int i=1;i<=n;i++)
        {
            if(remain<a[i]) vis[i]=1 ;
            if(vis[i]) continue ;
            if(min(remain-a[i],b[i]-a[i])>newr)
                {id=i ; newr=min(remain-a[i],b[i]-a[i]);}
                    if(len==3)
                        printf("%d , %d , %d\n",i,remain-a[i],b[i]-a[i]) ;
        }
        if(newr<0) break ;
        remain=newr ;
        vis[id]=1 ;
            printf("use %d , remain %d\n",id,remain) ;
    }
    printf("%d\n",len-1) ;
}
