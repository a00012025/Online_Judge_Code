#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
bool vis[1000001],vis2[1000001] ;
int a[2000001],n,m ;

bool check()
{
    memset(vis2,0,sizeof(vis2)) ;
    for(int i=1;i<=n;i++)
    {
        if(vis2[a[i]]) return false ;
        vis2[a[i]]=1 ;
    }
    return true ;
}

bool comp(int x,int y)
{
    return x>y ;
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(vis,0,sizeof(vis)) ;
        scanf("%d %d",&n,&m) ;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]) ;
            vis[a[i]]=1 ;
        }
        int num=n ;
        for(int i=m;i>=1;i--)
        {
            if(vis[i]) continue ;
            num++ ; a[num]=i ;
        }
        next_permutation(a+1,a+num+1) ;
        while(!check())
        {
            memset(vis,0,sizeof(vis)) ;
            for(int i=1;i<=n;i++) vis[a[i]]=1 ;
            num=n ;
            for(int i=m;i>=1;i--)
            {
                if(vis[i]) continue ;
                num++ ; a[num]=i ;
            }
            next_permutation(a+1,a+num+1) ;
        }
        for(int i=1;i<=n;i++) printf("%d ",a[i]) ;
        printf("\n") ;
    }
}
