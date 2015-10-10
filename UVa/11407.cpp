#include<stdio.h>
int ans[10001]={0} ;
main()
{
    for(int i=0;i<=100;i++) for(int j=i;i*i+j*j<=10000;j++)
        for(int k=j;i*i+j*j+k*k<=10000;k++)
            for(int l=k;i*i+j*j+k*k+l*l<=10000;l++)
                ans[i*i+j*j+k*k+l*l] = 4 ;
    for(int i=0;i<=100;i++) for(int j=i;i*i+j*j<=10000;j++)
        for(int k=j;i*i+j*j+k*k<=10000;k++)
            ans[i*i+j*j+k*k]=3 ;
    for(int i=0;i<=100;i++) for(int j=i;i*i+j*j<=10000;j++)
        ans[i*i+j*j]=2 ;
    for(int i=0;i<=100;i++) ans[i*i]=1 ;
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int a;
        scanf("%d",&a);
        printf("%d\n",ans[a]) ;
    }
}
