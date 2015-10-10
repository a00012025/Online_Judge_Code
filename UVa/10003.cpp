#include<stdio.h>
#include<string.h>
#include<algorithm>
#define INF 1000000000
using namespace std;
int d[52][52],cut[52],n ;

int dp(int l,int r)
{
    if(d[l][r]!=-1) return d[l][r] ;
    if(r==l+1) return d[l][l+1]=0 ;
    d[l][r]=INF ;
    for(int i=l+1;i<=r-1;i++) d[l][r]=min(d[l][r],dp(l,i)+dp(i,r)+cut[r]-cut[l]);
    return d[l][r] ;
}

main()
{
    int L ;
    while(scanf("%d",&L)==1 && L)
    {
        scanf("%d",&n) ;
        cut[0]=0 ; cut[n+1]=L ;
        for(int i=1;i<=n;i++) scanf("%d",&cut[i]) ;
        memset(d,-1,sizeof(d)) ;
        printf("The minimum cutting is %d.\n",dp(0,n+1)) ;
    }
}
