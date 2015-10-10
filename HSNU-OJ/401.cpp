#include<bits/stdc++.h>
using namespace std;

int ans[105][105] ;
main()
{
    int n,k ;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        if(n%2)
        {
            if(k<0) { printf("11111\n") ; continue ; }
            int sq=sqrt(k+0.5) ;
            if(sq*sq!=k) { printf("11111\n") ; continue ; }
            printf("22222\n") ;
            for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
                printf("%d%c",i==j?sq:0,j==n?'\n':' ') ;
        }
        else
        {
            memset(ans,0,sizeof(ans)) ;
            printf("22222\n") ;
            for(int i=1;i<=n;i+=2)
                ans[i][i]=1 , ans[i][i+1]=1 ,
                ans[i+1][i]=k-1 , ans[i+1][i+1]=-1 ;
            for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
                printf("%d%c",ans[i][j],j==n?'\n':' ') ;
        }
    }
}
