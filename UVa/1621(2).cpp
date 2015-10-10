#include<stdio.h>
int a,b,c,now ;

void add(int x)
{
    int y= x<0 ? -x : x ;
    if(y==1) a-- ;
    if(y==2) b-- ;
    if(y==3) c-- ;
    now+=x ;
    printf(" %d",now) ;
}

main()
{
        freopen("jumping.in","r",stdin);
        freopen("jumping.out","w",stdout);
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d%d",&a,&b,&c) ;
        now=0 ;
        printf("0") ;

        if(c%3==0)
        {
            int t=c/3 ;
            for(int i=1;i<=t;i++) add(3) ;
            add(1) ;
            for(int i=1;i<=t;i++) add(-3) ;
            add(1) ;
            for(int i=1;i<=t;i++) add(3) ;
        }
        else if(c%3==1)
        {
            int t=(c/3)+1 ;
            for(int i=1;i<=t;i++) add(3) ;
            add(-2) ;
            for(int i=1;i<t;i++) add(-3) ;
            add(1) ;
            for(int i=1;i<t;i++) add(3) ;
            add(2) ;
        }
        else if(c%3==2)
        {
            int t=(c+1)/3 ;
            for(int i=1;i<=t;i++) add(3) ;
            add(-2) ;
            for(int i=1;i<t;i++) add(-3) ;
            add(1) ;
            for(int i=1;i<=t;i++) add(3) ;
            add(-1) ; add(2) ;
        }

        int x=b/2,type=b%2 ;
        while(a>1) add(1) ;
        while(b>x) add(2) ;
        add( type==1 ? -1 : 1 ) ;
        for(int i=1;i<=x;i++) add(-2) ;
        //printf("\n") ;
        if(T) printf("\n") ;
    }
    return 0;
}
