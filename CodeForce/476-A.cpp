#include<stdio.h>
main()
{
    int n,m ;
    scanf("%d %d",&n,&m) ;
    int x=n , y=(n-1)/2+1 ;
    int k=(y/m)*m ;
    k-=m ;
    while(k<y) k+=m ;
    if(k<=x) printf("%d\n",k);
    else printf("-1\n") ;
}
