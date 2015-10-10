#include<stdio.h>
int ans[100000] ;
main()
{
    int k;
    while(scanf("%d",&k)!=EOF)
    {
        int cnt=0 ;
        for(int i=k+1;i<=2*k;i++)
            if((k*i)%(i-k)==0) ans[cnt++]=i ;
        printf("%d\n",cnt) ;
        for(int i=0;i<cnt;i++)
            printf("1/%d = 1/%d + 1/%d\n",k,k*ans[i]/(ans[i]-k),ans[i]) ;
    }
}
