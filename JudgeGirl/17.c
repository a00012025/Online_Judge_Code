#include<stdio.h>
int a[200] ;
main()
{
    int n,m,x ; scanf("%d%d",&n,&m) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) scanf("%d",&x) , a[j]+=x ;
    for(int i=0;i<m;i++) printf("%d\n",a[i]/n) ;
}
