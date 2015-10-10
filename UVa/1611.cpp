#include<stdio.h>
#include<stdlib.h>
int a[10001] ;
void modify(int l,int r)
{
    int len=(r-l+1)/2,tem ;
    for(int i=l;i<=r-len;i++)
    {
        tem=a[i] ;
        a[i]=a[i+len] ;
        a[i+len]=tem ;
    }
}

main()
{
    int T,ans1[20100],ans2[20100];
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        int now=1,cnt=0 ;
        while(1)
        {
            for(;now<=n && a[now]==now;now++) ;
            if(now==n+1) break ;
            int id,mid=(now+n)/2 ;
            for(id=now;id<=mid && a[id]!=now;id++) ;
            if(id==mid+1)
            {
                cnt++ ;
                ans1[cnt]=2*mid+1-n ;
                ans2[cnt]=n ;
                modify(2*mid+1-n,n) ;
                    //printf("modify %d,%d\n",2*mid+1-n,n) ;
                    //for(int i=1;i<=n;i++)printf("%d,",a[i]);
                    //system("pause") ;
                for(id=now;id<=mid && a[id]!=now;id++) ;
            }
            if(id==now) continue ;
            cnt++ ;
            ans1[cnt]=now ;
            ans2[cnt]=2*id-now-1 ;
            modify(now,2*id-now-1) ;
                //printf("modify %d,%d\n",now,2*id-now-1) ;
                //for(int i=1;i<=n;i++)printf("%d,",a[i]);
                //system("pause") ;
        }
        printf("%d\n",cnt) ;
        for(int i=1;i<=cnt;i++) printf("%d %d\n",ans1[i],ans2[i]);
    }
}
