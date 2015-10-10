#include<stdio.h>
int mon[13]={0,31,28,31,30,31,30,31,31,30,31,30,31} ;
int isleap(int n)
{
    if(n%400==0) return 1 ;
    if(n%100==0) return 0 ;
    return n%4==0 ;
}
main()
{
    int year,x,n ; scanf("%d%d%d",&year,&x,&n) ;
    if(isleap(year)) mon[2]++ ;
    while(n--)
    {
        int m,d ; scanf("%d%d",&m,&d) ;
        if(m<1||m>12){printf("-1\n") ; continue ;}
        if(d>mon[m] || d<1){printf("-2\n") ; continue ;}
        int num=x-1+d ;
        for(int i=1;i<m;i++) num+=mon[i] ;
        printf("%d\n",num%7) ;
    }
}
