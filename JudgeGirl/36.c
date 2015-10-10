#include<stdio.h>
int is_leap(int x)
{
    if(x%400==0) return 1 ;
    if(x%100==0) return 0 ;
    return x%4==0 ;
}

int mon[]={0,31,28,31,30,31,30,31,31,30,31,30,31} ;
int a[10][10] ;
main()
{
    int y,m,st ; scanf("%d%d%d",&y,&m,&st) ;
    if(m<=0 || m>12 || st<0 || st>=7){printf("invalid\n") ; return 0 ;}
    int num=mon[m]+(m==2 && is_leap(y)) ;
    printf(" Su Mo Tu We Th Fr Sa\n=====================\n") ;
    int ma=0 ;
    for(int i=1,x=0,y=st;i<=num;i++)
    {
        if(x>ma) ma=x ;
        a[x][y]=i ;
        x=(y==6 ? x+1 : x) ;
        y=(y+1)%7 ;
    }
    for(int i=0;i<=ma;i++) for(int j=0;j<7;j++)
    {
        if(!a[i][j]) printf("   ") ;
        else printf("%3d",a[i][j]) ;
        if(a[i][j]==num) break ;
        if(j==6) printf("\n") ;
    }
    printf("\n=====================\n") ;
}
