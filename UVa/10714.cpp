#include<stdio.h>
main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,len ;
        scanf("%d%d",&len,&n) ;
        int ans1=0,ans2=0 ;
        for(int i=1;i<=n;i++)
        {
            int a;
            scanf("%d",&a) ;
            int x= (a<=(len-a) ? a : (len-a)) ;
            int y= len-x ;
            if(ans1 < x) ans1=x ;
            if(ans2 < y) ans2=y ;
        }
        printf("%d %d\n",ans1,ans2);
    }

}
