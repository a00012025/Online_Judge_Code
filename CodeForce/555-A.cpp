#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;
int a[maxn],b[maxn] ;
main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    int val=0 ;
    for(int z=1;z<=k;z++)
    {
        int x ; scanf("%d",&x) ;
        for(int i=1;i<=x;i++) scanf("%d",&a[i]) ;
        int i ;
        for(i=2;i<=x;i++) if(a[i]!=a[i-1]+1) break ;
        if(a[1]==1) val=i-1 ;
    }
    printf("%d\n",n-k-val+1+(n-val)) ;
}
