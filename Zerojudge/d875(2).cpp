#include<stdio.h>
#define LL long long
int now,ans[1000001] ;

bool iddfs(int depth,int cnt,int n)
{
    if(n<0) return false ;
    if(n==0)
    {
        if(ans[depth]==1)
        {
            for(int i=1;i<=depth;i++) printf("%d ",ans[i]);
            printf("\n") ;
            return true ;
        }
        else return false ;
    }
    if(cnt==depth) return false ;
    LL maxsum=((LL)2*ans[cnt]+depth-cnt+1)*(depth-cnt)/2 ;
    if(maxsum<n) return false ;
    if(ans[cnt]-1>0)
    {
        ans[cnt+1]=ans[cnt]-1 ;
        if(iddfs(depth,cnt+1,n-ans[cnt+1])) return true ;
    }
    ans[cnt+1]=ans[cnt] ;
    if(iddfs(depth,cnt+1,n-ans[cnt+1])) return true ;
    ans[cnt+1]=ans[cnt]+1 ;
    if(iddfs(depth,cnt+1,n-ans[cnt+1])) return true ;
    return false ;
}

main()
{
    int n ;
    while(scanf("%d",&n)!=EOF)
    {
        int depth ;
        for(depth=1;;depth++)
        {
            ans[0]=0 ;
            if(iddfs(depth,0,n)) break ;
        }
    }
}
