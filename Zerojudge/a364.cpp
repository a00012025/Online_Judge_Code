#include<stdio.h>
#include<string.h>
int a,ans[4] ;
int c[100][4]={0},N,yes ;

void dfs(int n,int sum)
{
    if(yes) return ;
    if(n==3)
    {
        for(int i=1;i<=3;i++)printf("%d",ans[i]) ;
        printf("\n") ;
        yes=1 ;
    }
    for(int i=ans[n]-1 ; i>=0 ; i--) if(c[i][3-n]+sum<=a)
    {
        ans[n+1]=i ;
        dfs(n+1,sum+c[i][3-n]) ;
        if(yes) return ;
    }
}
main()
{
    for(int i=0;i<100;i++)
    {
        if(i>=1) c[i][1]=i ;
        if(i>=2) c[i][2]=(i*(i-1))/2 ;
        if(i>=3) c[i][3]=(i*(i-1)*(i-2))/6 ;
    }
    scanf("%d",&N) ;
    while(N--)
    {
        scanf("%d",&a) ;
        yes=0 ;
        ans[0]=100 ;
        dfs(0,0) ;
    }
}
