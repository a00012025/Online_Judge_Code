#include<stdio.h>
#define LL long long
int a[10]={1,5,10,25,50} ;
LL dp[30001]={0} ;
main()
{
    dp[0]=1LL;
    for(int i=0;i<5;i++) for(int j=1;j<=30000;j++)
        if(j>=a[i]) dp[j]+=dp[j-a[i]] ;
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(dp[n]==1) printf("There is only 1 way to produce %d cents change.\n",n);
        else printf("There are %lld ways to produce %d cents change.\n",dp[n],n);
    }
}
