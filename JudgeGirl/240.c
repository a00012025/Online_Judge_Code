#include<stdio.h>
#define SQ(x) ((x)*(x))
inline int f1(int a,int b,int c){return (a==b&&c==2*a)||(b==c&&a==2*c)||(c==a&&b==2*a) ;}
inline int f2(int a,int b,int c){return (a+b==c)||(a+c==b)||(b+c==a) ;}
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int x1,y1,x2,y2,x3,y3,x4,y4 ; scanf("%d%d%d%d%d%d%d%d",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4) ;
        int a=SQ(x1-x2)+SQ(y1-y2) , b=SQ(x2-x3)+SQ(y2-y3) , c=SQ(x1-x3)+SQ(y1-y3) ;
        int d=SQ(x4-x1)+SQ(y4-y1) , e=SQ(x4-x2)+SQ(y4-y2) , f=SQ(x4-x3)+SQ(y4-y3) ;
        if(f1(a,b,c)&&f1(a,d,e)&&f1(c,d,f)&&f1(b,e,f)) printf("square\n") ;
        else if(f2(a,b,c)&&f2(a,d,e)&&f2(c,d,f)&&f2(b,e,f)) printf("rectangle\n") ;
        else if(a==b&&b==f&&f==d) printf("diamond\n") ;
        else if(a==e&&e==f&&f==c) printf("diamond\n") ;
        else if(c==b&&b==e&&e==d) printf("diamond\n") ;
        else if(c==f&&f==e&&e==a) printf("diamond\n") ;
        else printf("other\n") ;
    }
}

