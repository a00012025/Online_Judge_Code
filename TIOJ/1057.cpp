#include<bits/stdc++.h>
using namespace std;

int len,m,n ;
int a[200] ;

int solve()
{
    a[0]=0 ; a[n+1]=m ;
    for(int i=0;i<=n;i++) if(a[i+1]-a[i]>len) return -1 ;

    int num=0 , now=0 ;
    while(now<n+1)
    {
        int t=now ;
        while(now<=n+1 && a[now]-a[t]<=len) now++ ; now-- ;
        num++ ;
    }
    return num ;
}

main()
{
    scanf("%d%d%d",&len,&m,&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    int res=solve() ;
    if(res==-1) printf("IMPOSSIBLE\n") ;
    else printf("%d\n",res-1) ;
}
