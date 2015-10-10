#include<stdio.h>
main()
{
    int a,b,c,d ;
    while(scanf("%d%d%d%d",&a,&b,&c,&d)!=EOF)
    {
        int ans=c+d+(b/8) ;
        b=b%8 ;
        if(a<=37*c) a=0 ;
        else a-=37*c ;
        if(a!=0 || b!=0) ans+=((a+8*b-1)/64)+1 ;
        printf("%d\n",ans) ;
    }
}
