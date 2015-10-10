#include<stdio.h>
#include<string.h>
const int maxn=100000 ;
int sum[maxn] ;

void solve(int n)
{
    int l,r ;
    scanf("%d",&l) ;
    if(l!=-1) {sum[n-1]+=l ; solve(n-1) ;}
    scanf("%d",&r) ;
    if(r!=-1) {sum[n+1]+=r ; solve(n+1) ;}
}

main()
{
    int n,tc=0;
    while(scanf("%d",&n)==1 && n!=-1)
    {
        memset(sum,0,sizeof(sum)) ;
        sum[maxn/2]=n ; solve(maxn/2) ;
        printf("Case %d:\n",++tc) ;
        int i ;
        for(i=0;!sum[i];i++) ;
        for(int j=i;sum[j];j++) printf("%d%c",sum[j],sum[j+1]?' ':'\n') ;
        printf("\n") ;
    }
}
