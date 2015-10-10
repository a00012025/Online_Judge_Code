#include<stdio.h>
int gcd(int x,int y)
{
    return y?gcd(y,x%y):x;
}

typedef struct frac{int x,y ;} frac ; /// x/y

frac norm(frac a)
{
    int g=gcd(a.x,a.y) ;
    a.x/=g ; a.y/=g ;
    return a ;
}

frac add(frac a,frac b)
{
    frac f ;
    f.x=a.x*b.y+a.y*b.x ; f.y=a.y*b.y ;
    return norm(f) ;
}

frac mul(frac a,int x,int y)
{
    a.x*=x ; a.y*=y ;
    return norm(a) ;
}

int n,l[20][20],r[20][20] ;
frac dp[20][20] ;
main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=i;j++)
    {
        scanf("%d%d",&l[i][j],&r[i][j]) ;
        int g=gcd(l[i][j],r[i][j]) ;
        l[i][j]/=g ; r[i][j]/=g ;
    } 
    dp[1][1].x=dp[1][1].y=1 ;
    for(int i=2;i<=n+1;i++) for(int j=1;j<=i;j++)
    {
        dp[i][j].x=0 , dp[i][j].y=1 ;
        if(j>1) dp[i][j]=add(dp[i][j],mul(dp[i-1][j-1],r[i-1][j-1],l[i-1][j-1]+r[i-1][j-1])) ;
        if(j<i) dp[i][j]=add(dp[i][j],mul(dp[i-1][j],l[i-1][j],l[i-1][j]+r[i-1][j])) ;
        if(i==n+1) printf("%d/%d\n",dp[i][j].x,dp[i][j].y) ;
    }
    if(n==0) printf("1/1\n") ;
}
