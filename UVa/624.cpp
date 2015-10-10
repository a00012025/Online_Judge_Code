#include<stdio.h>
#include<string.h>
main()
{
    int n,m,a[30],ans[100001] ;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        memset(ans,0,sizeof(ans)) ;
        for(int i=0;i<m;i++) scanf("%d",&a[i]) ;
        for(int i=1;i<(1<<m);i++)
        {
            int sum=0 ;
            for(int j=0;j<m;j++)
            {
                if(i&(1<<j)) sum+=a[j] ;
            }
            ans[sum]=i ;
        }
        int i ;
        for(i=n;ans[i]==0;i--) ;
        for(int j=0;j<m;j++) if(ans[i]&(1<<j)) printf("%d ",a[j]) ;
        printf("sum:%d\n",i) ;
    }
}
