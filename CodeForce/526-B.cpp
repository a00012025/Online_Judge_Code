#include<bits/stdc++.h>
using namespace std;
const int maxn=12 ;

int e[1<<maxn],w[1<<maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=2;i<(1<<(n+1));i++) scanf("%d",&e[i]) ;
    int ans=0 ;
    for(int i=(1<<n)-1;i>=1;i--)
    {
        int ma=max(w[2*i]+e[2*i],w[2*i+1]+e[2*i+1]) ;
        ans+=2*ma-(w[2*i]+e[2*i])-(w[2*i+1]+e[2*i+1]) ;
        w[i]=ma ;
    }
    printf("%d\n",ans) ;
}
