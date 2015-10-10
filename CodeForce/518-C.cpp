#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=100000+10 ;

int a[maxn],pos[maxn] ;
main()
{
    int n,m,k ; scanf("%d%d%d",&n,&m,&k) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , pos[a[i]]=i ;
    LL ans=0LL ;
    while(m--)
    {
        int x ; scanf("%d",&x) ; x=pos[x] ;
        ans+=(x-1)/k+1 ;
        if(x==1) continue ;
        swap(a[x],a[x-1]) ;
        swap(pos[a[x]],pos[a[x-1]]) ;
    }
    printf("%I64d\n",ans) ;
}
