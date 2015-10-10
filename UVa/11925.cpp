#include<stdio.h>
main()
{
    int n,a[400],b[400],ans[300000];
    while(scanf("%d",&n)==1 && n)
    {
        for(int i=1;i<=n;i++) {scanf("%d",&a[i]) ; b[a[i]]=i ;}
        for(int i=1;i<=n;i++) a[i]=b[i] ;
        int now=1,cnt=0 ;
        while(now!=n+1)
        {
            for(;now<=n && a[now]==now;now++) ;
            if(now==n+1) break ;
            int id ;
            for(id=now;a[id]!=now;id++) ;
            for(int i=1;i<id;i++) ans[++cnt]=2 ;
            for(int i=1;i<n-id+now;i++) {ans[++cnt]=1 ; ans[++cnt]=2 ;}
            if(now!=1)
                for(int i=1;i<=n-now+1;i++) ans[++cnt]=2 ;
            for(int i=id;i>=now+1;i--) a[i]=a[i-1] ;
            a[now]=now ;
        }
        int num=0 ;
        for(int i=1;i<=cnt;i++)
        {
            if(ans[i]==1)
            {
                for(int j=1;j<=num;j++) printf("2") ;
                printf("1") ;
                num=0 ;
            }
            else
            {
                num++ ;
                if(num==n) num=0 ;
            }
        }
        for(int i=1;i<=num;i++) printf("2") ;
        printf("\n") ;
    }
}
