#include<stdio.h>
#define LL long long
LL c[51][51] ;
main()
{
    for(int i=0;i<=50;i++) {c[i][0]=1 ; c[i][i]=1 ; c[i][1]=i ;}
    for(int i=1;i<=50;i++) for(int j=1;j<=i;j++)
        c[i][j]=c[i-1][j]+c[i-1][j-1] ;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        printf("%lld\n",c[2*n][n]/(n+1)) ;
    }
}
