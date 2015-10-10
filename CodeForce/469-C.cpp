#include<stdio.h>
void type1()
{
    printf("1 * 2 = 2\n") ;
    printf("2 * 3 = 6\n") ;
    printf("6 * 4 = 24\n") ;
}
void type2()
{
    printf("5 - 2 = 3\n") ;
    printf("3 - 1 = 2\n") ;
    printf("2 * 3 = 6\n") ;
    printf("6 * 4 = 24\n") ;
}
main()
{
    int n;
    scanf("%d",&n) ;
    if(n<=3) printf("NO\n") ;
    else if(n%2==0)
    {
        printf("YES\n") ;
        type1() ;
        for(int i=3;i<=n/2;i++)
        {
            printf("%d - %d = 1\n",2*i,2*i-1) ;
            printf("24 * 1 = 24\n") ;
        }
    }
    else if(n%2==1)
    {
        printf("YES\n") ;
        type2() ;
        for(int i=3;2*i+1<=n;i++)
        {
            printf("%d - %d = 1\n",2*i+1,2*i) ;
            printf("24 * 1 = 24\n") ;
        }
    }
}
