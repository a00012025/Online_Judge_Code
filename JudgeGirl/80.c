#include<stdio.h>
#define SQ(x) ((x)*(x))
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int x1,y1,x2,y2,x3,y3 ; scanf("%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3) ;
        int a=SQ(x1-x2)+SQ(y1-y2) ;
        int b=SQ(x2-x3)+SQ(y2-y3) ;
        int c=SQ(x1-x3)+SQ(y1-y3) ;
        if(a==b||b==c||a==c) printf("isosceles\n") ;
        else if(a==b+c||b==a+c||c==a+b) printf("right\n") ;
        else if(a>b+c||b>a+c||c>a+b) printf("obtuse\n") ;
        else printf("acute\n") ;
    }
}
