#include<stdio.h>
#include<string.h>

int a[1000201],next[1000201],prev[1000201],rep[1000201] ;
bool vis[1000201] ;

void printans(int m)
{
    for(int i=1;i<=m;i++) printf("%d ",a[i]) ;
    printf("\n") ;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int m,n ;
        scanf("%d %d",&m,&n) ;
        for(int i=1;i<=m;i++) scanf("%d",&a[i]) ;
        for(int i=0;i<=n;i++) vis[i]=0 ;

        a[m]++ ; int m2=m ;
        while(a[m2]>n) {a[m2]=1 ; a[m2-1]++ ; m2-- ;}

        next[0]=1 ; prev[n+1]=n ;
        for(int i=1;i<=n;i++) {next[i]=i+1 ; prev[i]=i-1 ;}

        int fir ;
        for(fir=1;fir<=m;fir++)
        {
            if(vis[a[fir]]) break ;
            vis[a[fir]]=1 ;
            rep[fir]=next[a[fir]] ;
            next[prev[a[fir]]]=next[a[fir]] ;
            prev[next[a[fir]]]=prev[a[fir]] ;
        }
        if(fir==m+1) {printans(m) ; continue ;}
            //for(int i=1;i<=m;i++) printf("%d,",rep[i]) ;
            //printf("\n") ;
        int fir2 ;
        for(fir2=a[fir];fir2<=n && vis[fir2]==1;fir2++) ;
        if(fir2<=n)
        {
            a[fir]=fir2 ; vis[fir2]=1 ;
            int cnt=1 ;
            for(int i=fir+1;i<=m;i++)
            {
                for(;vis[cnt]==1;cnt++) ;
                a[i]=cnt ;
                vis[cnt]=1 ;
            }
            printans(m) ; continue ;
        }
        int sear=fir-1 ;
        for(;((sear>=1) && (rep[sear]==n+1));sear--) vis[a[sear]]=0 ;
        vis[a[sear]]=0 ; a[sear]=rep[sear] ; vis[a[sear]]=1 ;
        int cnt=1 ;
        for(int i=sear+1;i<=m;i++)
        {
            for(;vis[cnt]==1;cnt++) ;
            a[i]=cnt ;
            vis[cnt]=1 ;
        }
        printans(m) ;
    }
}
