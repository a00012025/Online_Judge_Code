#include<stdio.h>
main()
{
    int ans[10001][10]={{0}};
    for(int i=1;i<=10000;i++)
    {
        int j=i ;
        for(int r=0;r<=9;r++) ans[i][r]=ans[i-1][r] ;
        while(j!=0)
        {
            ans[i][j%10]++ ;
            j=j/10 ;
        }
    }
    int n,T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        int fir=1 ;
        for(int i=0;i<=9;i++)
        {
            if(fir==1) fir=0 ;
            else printf(" ") ;
            printf("%d",ans[n][i]) ;
        }
        printf("\n") ;
    }
}
