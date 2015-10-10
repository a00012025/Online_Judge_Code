#include<stdio.h>
main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        int t;
        scanf("%d",&t) ;
        if(t<=4){printf("%d\n",t) ; continue ;}
        int x;
        if(t%4==0) x=(t-2)/4 ;
        else if(t%4==1) x=(t-1)/4 ;
        else if(t%4==2) x=(t-2)/4 ;
        else if(t%4==3) x=(t-3)/4 ;
        printf("%d\n",t-2*x*x+(t-2)*x) ;
    }
}
