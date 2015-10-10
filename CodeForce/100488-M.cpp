#include<stdio.h>
main()
{
    int a,b ;
    scanf("%d %d",&a,&b) ;
    printf("%d\n",a*b) ;
    for(int i=1;i<=b;i++) for(int j=1;j<=a;j++)
    {
        printf("%d ",a*b-i*a+j) ;
    }
    printf("\n") ;
}
