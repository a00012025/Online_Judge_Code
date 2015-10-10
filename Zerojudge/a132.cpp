#include<stdio.h>

int bitc(int n)
{
    if(n==1) return 1 ;
    if(n==0) return 0 ;
    if(n%2==1) return bitc(n/2)+1 ;
    if(n%2==0) return bitc(n/2) ;
}

main()
{
    int a;
    while(scanf("%d",&a)==1)
    {
        if(!a) break ;
        int lev=0,b=a ;
        for(;b>0;b=b/2) lev++ ;
        printf("The parity of ") ;
        for(int j=lev-1;j>=0;j--)
        {
            if((a & (1<<j))!=0) printf("1") ;
            else printf("0") ;
        }
        printf(" is %d (mod 2).\n",bitc(a)) ;
    }
}
