#include<stdio.h>
int cnt,num,n,ans[100] ;

bool ok(int len)
{
    for(int i=len-1;i>0;i=i-2)
    {
        bool same=1 ;
        for(int j=i;j<=(len+i-1)/2;j++) if(ans[j]!=ans[j+(len-i+1)/2]) same=0 ;
        if(same) return 0 ;
    }
    return 1;
}

bool dfs(int x)
{
    if(cnt==num)
    {
        for(int i=1;i<=x;i++)
        {
            if(i!=1 && i!=65 && i%4==1) printf(" ") ;
            printf("%c",'A'-1+ans[i]) ;
            if(i==64) printf("\n") ;
        }
        printf("\n%d\n",x) ;
        return 1;
    }
    for(int i=1;i<=n;i++)
    {
        ans[x+1]=i ;
        if(ok(x+1) && ++cnt && dfs(x+1)) return 1;
    }
    return 0;
}

main()
{
    while(scanf("%d%d",&num,&n)==2 && num+n)
    {
        cnt=0 ;
        dfs(0) ;
    }
}
