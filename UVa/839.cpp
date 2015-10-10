#include<stdio.h>

bool solve(int &w)
{
    int w1,l1,w2,l2 ;
    scanf("%d%d%d%d",&w1,&l1,&w2,&l2) ;
    bool r1=1,r2=1 ;
    if(!w1) r1=solve(w1) ;
    if(!w2) r2=solve(w2) ;
    w=w1+w2 ;
    return (r1 && r2 && w1*l1==w2*l2) ;
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int a ;
        if(solve(a)) printf("YES\n") ;
        else printf("NO\n") ;
        if(T) printf("\n") ;
    }
}
