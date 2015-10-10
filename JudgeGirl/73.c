#include<stdio.h>
main()
{
    int c[3]={0},n,x ; scanf("%d",&n) ;
    while(n--) scanf("%d",&x) , c[x%3]++ ;
    printf("%d %d %d\n",c[0],c[1],c[2]) ;
}
