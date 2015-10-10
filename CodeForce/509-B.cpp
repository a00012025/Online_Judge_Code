#include<bits/stdc++.h>
using namespace std;
int a[200],b[200] ;
main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    int M=-1,m=101 ;
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]) , m=min(m,a[i]) , M=max(M,a[i]) ;
    if(M-m > k) { printf("NO\n") ; return 0 ; }
    printf("YES\n") ;
    int q=m/k , r=m-q*k ;
    for(int i=1;i<=k;i++) b[i]=i<=r ? q+1 : q ;
    for(int i=1;i<=n;i++)
    {
        int d=a[i]-m ;
        for(int j=1;j<=k;j++)
        {
            int tm= d>0 ? b[j]+1 : b[j] ; d-- ;
            while(tm--) printf("%d ",j) ;
        }
        printf("\n") ;
    }
}
