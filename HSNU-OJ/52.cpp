#include<bits/stdc++.h>
using namespace std;
int a[1000100] ;

void split(int x)
{
    a[x]-=2 ;
    if(x==1) a[x+1]++ ;
    else if(x==2) a[x-1]++ , a[x+1]++ ;
    else a[x-2]++ , a[x+1]++ ;
}

main()
{
    int n,m ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    scanf("%d",&m) ;
    for(int i=1;i<=m;i++) { int x ; scanf("%d",&x) ; a[i]+=x ; }
    n=max(m,n)+5 ;

    for(int i=1;i<=n;i++) if(a[i]&&a[i+1]&&(!a[i+2]))
            a[i]-- , a[i+1]-- , a[i+2]++ ;

    for(int i=1;i<=n;i++) if(a[i]==2)
    {
        if(i<=2 || a[i-2]==0) { split(i) ; continue ; }
        int j ;
        for(j=i-2;j>=1 && a[j]+a[j+1]==1;j--) ;
        if(j>=1 && a[j]+a[j+1]==2)
        {
            for(int k=j;k<i-1;k++) a[k]=0 ;
            a[i-1]=1 ;
            split(i) ; continue ;
        }
        if(j>=1 && a[j]+a[j+1]==0)
        {
            a[j]=1 ; j++ ;
            int ri=i+1 ; a[ri]=1 ;
            while(1)
            {
                while(a[ri]+a[ri+1]==1) ri++ ;
                if(!(a[ri]==0 && a[ri+1]==2)) break ;
                ri++ ;
                a[j]=1 ; j++ ;
                ri++ ; a[ri]=1 ;
            }
            a[j]=0 ; a[j+1]=0 ;
            for(int z=j+2;z<=ri;z++) a[z]=1-a[z-1] ;
            continue ;
        }

        a[1]=1-a[1] ; a[i+1]=1 ;
        int ri=i+1 ;
        while(1)
        {
            while(a[ri]+a[ri+1]==1) ri++ ;
            if(!(a[ri]==0 && a[ri+1]==2)) break ;
            ri++ ; a[ri+1]=1 ; ri++ ; a[1]=1-a[1] ;
        }
        for(int j=1;j<=ri;j++) a[j]=1-a[j-1] ;
    }

    for(int i=n+2;i>=1;i--) if(a[i]&&a[i+1])
    {
        for(int j=i;a[j]&&a[j+1];j+=2) a[j]-- , a[j+1]-- , a[j+2]++ ;
    }

    int M ; for(M=n+2;!a[M];M--) ;
    printf("%d",M) ;
    for(int i=1;i<=M;i++) printf(" %d",a[i]) ;
    printf("\n") ;
}
