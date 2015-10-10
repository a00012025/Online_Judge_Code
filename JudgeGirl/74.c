#include<stdio.h>
#define maxn 1000010
int a[maxn],c[maxn] ;
main()
{
    int n,m ; scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
    scanf("%d",&m) ;
    for(int i=0;i<n;i++) c[a[i]%m]++ ;
    for(int i=0;i<m;i++) printf("%d\n",c[i]) ;
}
