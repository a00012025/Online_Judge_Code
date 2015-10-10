#include<bits/stdc++.h>
using namespace std;
const int maxn=50+10 ;

int l[maxn],r[maxn] ;
main()
{
    int n,x ; scanf("%d%d",&n,&x) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&l[i],&r[i]) ;
    int ans=r[n] ;
    for(int i=1;i<=n;i++) ans-=x*((l[i]-r[i-1]-1)/x) ;
    printf("%d\n",ans) ;
}
