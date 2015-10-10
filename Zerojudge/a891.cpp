#include<stdio.h>
int day[20]={0,31,28,31,30,31,30,31,31,30,31,30,31} ;
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int m1,d1,h1,min1,sec1 ;
        int m2,d2,h2,min2,sec2 ;
        scanf("%d-%d %d:%d:%d, %d-%d %d:%d:%d",&m1,&d1,&h1,&min1,&sec1,&m2,&d2,&h2,&min2,&sec2) ;
        int d=0 ;
        if(m1>m2)
        {
            d=-d1+1 ; d1=1 ;
            while(m1>m2)
            {
                d=d-day[m1-1] ;
                m1-- ;
            }
        }
        else if(m1<m2)
        {
            d=d2-1 ; d2=1 ;
            while(m1<m2)
            {
                d=d+day[m2-1] ;
                m2-- ;
            }
        }
        d+=d2-d1 ;
        if(h1>h2 || (h1==h2 && min1>min2) || (h1==h2 && min1==min2 && sec1>sec2))
            {d=d-1 ; h2+=24 ;}
        int x3=h2-h1,x4=min2-min1,x5=sec2-sec1,neg=0 ;
        if(x5<0) {x5+=60 ; x4-- ;}
        if(x4<0) {x4+=60 ; x3-- ;}
        if(d<0)
        {
            neg=1 ; d++ ; x3=23-x3 ; x4=59-x4 ; x5=60-x5 ;
            if(x5==60) {x5=0 ; x4++ ;}
            if(x4==60) {x4=0 ; x3++ ;}
        }
        if(neg==1 && d==0) printf("-") ;
        printf("%d %02d:%02d:%02d\n",d,x3,x4,x5) ;

    }
}
