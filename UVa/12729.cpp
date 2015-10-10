#include<stdio.h>
main()
{
    int T,tc=0;
    scanf("%d",&T);
    while(T--)
    {
        int n,m ;
        scanf("%d%d",&n,&m) ;
        int k=(n/2)*(m/2) ;
        int anna=((k+1)/2)*4 ;
        if(2*anna==n*m) printf("Case #%d: Draw\n",++tc) ;
        else if(2*anna>n*m) printf("Case #%d: Ana\n",++tc) ;
        else printf("Case #%d: Bob\n",++tc) ;
    }
}
