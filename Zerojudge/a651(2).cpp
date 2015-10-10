#include<stdio.h>
#include<string.h>
int fa[100001],fish[100001] ;
bool vis[100001] ;

int getfa(int n)
{
    if(n==0) return 0 ;
    return ( vis[n] ? n : fa[n]=getfa(fa[n]) ) ;
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,m,a,ans,ANS=0 ;
        scanf("%d %d",&n,&m) ;
        fa[0]=0 ; vis[0]=1 ;
        memset(vis,0,sizeof(vis)) ;
        for(int i=1;i<n;i++) {scanf("%d",&a) ; fa[i]=a ;}
        for(int i=1;i<=m;i++){scanf("%d",&a) ; fish[i]=a ; vis[a]=1 ;}
        for(int i=m;i>=1;i--)
        {
            ans=getfa(fa[fish[i]]) ;
            vis[fish[i]]=0 ;
            getfa(fish[i]) ;
            ANS ^= (ans+i) ;
        }
        //for(int i=1;i<=m;i++) printf("%d,",ans[i]);
        printf("%d",ANS) ;
        printf("\n") ;
    }
}
