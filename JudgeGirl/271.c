#include<stdio.h>
int a[200],b[200],n,m ;
main()
{
    scanf("%d",&n) ;
    for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
    scanf("%d",&m) ;
    for(int i=0;i<m;i++) scanf("%d",&b[i]) ;
    for(int i=0;i<=m+n-2;i++)
    {
        int s=0 ;
        for(int j=(i-m+1>0?i-m+1:0);j<=i && j<n;j++)
            s+=a[j]*b[i-j] ;
        printf("%d%c",s,i==m+n-2?'\n':' ') ;
    }
}
