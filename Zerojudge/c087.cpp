#include<stdio.h>
#include<math.h>
int gcd(int x,int y)
{
    while(x!=0 && y!=0)
    {
        if(x>y) x=x%y ;
        else y=y%x ;
    }
    if(!x) return y ;
    else return x ;
}
main()
{
    int n,a[100];
    while(scanf("%d",&n)!=EOF && n)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        int cnt=0 ;
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
            if(gcd(a[i],a[j])==1) cnt++ ;
        if(!cnt) printf("No estimate for this data set.\n");
        else printf("%.6lf\n",sqrt((double)3*n*(n-1)/cnt)) ;
    }
}
