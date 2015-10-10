#include<stdio.h>
main()
{
    int n,m,c ;
    while(scanf("%d%d%d",&n,&m,&c)==3 && n+m+c)
    {
        n=n-7 ; m=m-7 ;
        if(n%2 && m%2 && c==1) printf("%d\n",(n*m+1)/2) ;
        else if(n%2 && m%2 && c==0) printf("%d\n",(n*m-1)/2) ;
        else printf("%d\n",n*m/2) ;
    }
}
