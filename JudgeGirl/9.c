#include<stdio.h>
main()
{
    int x ; scanf("%d",&x) ;
    if(x<=0) printf("-100\n") ;
    else printf("%d\n",(x%3?0:3)+(x%5?0:5)+((x>=100&&x<=200) ? 50:-50)) ;
}
