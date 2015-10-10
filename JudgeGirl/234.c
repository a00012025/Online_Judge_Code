#include<stdio.h>
int a,b,c ;
int isroot(int x)
{
    if(!x) return !c ;
    if(c%x) return 0 ;
    int now=-c/x-b ;
    if(now%x) return 0 ;
    return now/x==(x+a) ;
}

main()
{
    scanf("%d%d%d",&a,&b,&c) ;
    int cnt=0,r[3] ;
    for(int i=-100000;i<=100000;i++) if(isroot(i))
        r[cnt++]=i ;
    if(cnt==1) printf("%d %d %d\n",-r[0],-r[0],-r[0]) ;
    else if(cnt==2) printf("%d %d %d\n",-r[1],a+r[0]+r[1],-r[0]) ;
    else printf("%d %d %d\n",-r[2],-r[1],-r[0]) ;
}
