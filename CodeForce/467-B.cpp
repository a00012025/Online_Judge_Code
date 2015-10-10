#include<stdio.h>
int bit_dif(int x,int y)
{
    int a=0 ;
    for(int i=0;i<=21;i++)
        if( ((x)&(1<<i)) ^ ((y)&(1<<i))) a++ ;
    return a ;
}

main()
{
    int n,m,k ;
    int a[1010],ans=0 ;
    scanf("%d %d %d",&n,&m,&k) ;
    for(int i=1;i<=m+1;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<=m;i++) if(bit_dif(a[i],a[m+1])<=k) ans++ ;
    printf("%d\n",ans) ;
}
