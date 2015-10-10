#include<stdio.h>
main()
{
    int n,m;
    scanf("%d %d",&n,&m) ;
    printf("%d\n",(6*n-1)*m) ;
    printf("%d %d %d %d\n",m,2*m,3*m,(6*n-1)*m) ;
    for(int i=1;i<n;i++)
    {
        printf("%d %d %d %d\n",(6*i-1)*m,(6*i+1)*m,(6*i+2)*m,(6*i+3)*m) ;
    }
}
