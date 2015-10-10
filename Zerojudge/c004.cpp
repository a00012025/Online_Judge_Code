#include<stdio.h>
main()
{
    int a,b ;
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d %d",&a,&b) ;
        if(a<b || (a+b)%2!=0) {printf("impossible\n") ; continue ;}
        printf("%d %d\n",(a+b)/2,(a-b)/2) ;
    }
}
