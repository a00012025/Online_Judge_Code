#include<stdio.h>
int x[1000],y[1000],c1,c2 ;
main()
{
    int n,m ; scanf("%d",&n) ;
    while(n--) scanf("%d",&m) , m%2?(x[c1++]=m):(y[c2++]=m) ;
    for(int i=0;i<c1;i++) printf("%d%c",x[i],i+1==c1?'\n':' ') ;
    for(int i=0;i<c2;i++) printf("%d%c",y[i],i+1==c2?'\n':' ') ;
}
