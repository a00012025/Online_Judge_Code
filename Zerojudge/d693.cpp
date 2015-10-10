#include<stdio.h>
int gcd(int a,int b)
{
    return b==0 ? a : gcd(b,a%b) ;
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b ;
}
main()
{
    int n;
    while(scanf("%d",&n)==1 && n)
    {
        int a,ans;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a) ;
            if(i==1) ans=a ;
            else ans=lcm(ans,a) ;
        }
        printf("%d\n",ans) ;
    }
}
