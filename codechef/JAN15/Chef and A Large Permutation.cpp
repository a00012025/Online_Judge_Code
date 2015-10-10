#include<bits/stdc++.h>
#define LL long long
using namespace std;
int n,k,a[100100] ;

LL sum(int x,int y)
{
    return ((LL)x+y)*((LL)y-x+1)/2 ;
}

LL solve()
{
    LL now=0LL ;
    sort(a+1,a+k+1) ;
    for(int i=1;i<=k;i++)
    {
        now+=sum(a[i-1]+1,a[i]-1) ;
        if(now<a[i]) return now+1 ;
    }
    now+=sum(a[k]+1,n) ;
    return now+1 ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d",&n,&k) ;
        a[0]=0 ;
        for(int i=1;i<=k;i++) scanf("%d",&a[i]) ;
        if(solve()%2) printf("Chef\n") ;
        else printf("Mom\n") ;
    }
}
