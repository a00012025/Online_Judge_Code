#include<stdio.h>
main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int k,M=1 ;
        for(k=0;n>=M;k++,M*=2) ;
        printf("%d\n",k) ;
    }
}
