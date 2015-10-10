#include<stdio.h>
main()
{
    int T,tc=0;
    scanf("%d",&T) ;
    while(T-- && ++tc)
    {
        int n;
        scanf("%d",&n) ;
        if(n==2) printf("Case #%d: 0\n",tc) ;
        else printf("Case #%d: 1\n",tc) ;
    }
}
