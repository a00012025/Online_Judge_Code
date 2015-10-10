#include<stdio.h>
main()
{
    int x ; double y ; scanf("%d%lf",&x,&y) ;
    if(x%5 || x+0.5>y) printf("%.2f\n",y) ;
    else printf("%.2f\n",y-x-0.5) ;
}
