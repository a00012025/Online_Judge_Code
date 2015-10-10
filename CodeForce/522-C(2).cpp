#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;

int a[maxn],b[maxn] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int m,k ; scanf("%d%d",&m,&k) ;
        for(int i=1;i<=k;i++) scanf("%d",&a[i]) ;

        int x=-1 , y=0 ;
        while(--m)
        {
            int t,r ; scanf("%d%d",&t,&r) ;
            if(r==1 && x==-1)
            {
                x=y ;
                for(int i=1;i<=k;i++) b[i]=a[i] ;
            }
            if(t) a[t]-- ;
            else y++ ;
        }

        int mi=maxn ;
        for(int i=1;i<=k;i++)
            if(a[i]==b[i]) mi=min(mi,b[i]) ;
        for(int i=1;i<=k;i++)
        {
            if(x==-1 && y>=a[i]) printf("Y") ;
            else if(x==-1) printf("N") ;
            else if(x>=b[i] && a[i]==b[i]) printf("Y") ;
            else if(y-mi>=a[i]) printf("Y") ;
            else printf("N") ;
        }
        printf("\n") ;
    }
}

