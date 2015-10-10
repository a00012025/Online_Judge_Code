#include<stdio.h>
main()
{
    int a,b,c ;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        double ans=a*b*1.0/(a+b)/(a+b-c-1) ;
        ans += b*(b-1)*1.0/(a+b)/(a+b-c-1) ;
        printf("%.5lf\n",ans) ;
    }
}
