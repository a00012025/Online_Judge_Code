#include<stdio.h>
main()
{
    int x ; scanf("%d",&x) ;
    printf("%d\n",(x%3)||(x%5)||(!(x%7))) ;
}
