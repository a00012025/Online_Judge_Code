#include<stdio.h>
main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c) ;
    if(c>=a && c<=b) printf("Take another envelope\n") ;
    else printf("Stay with this envelope\n") ;
}
