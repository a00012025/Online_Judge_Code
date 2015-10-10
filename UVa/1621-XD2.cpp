#include<stdio.h>
int a[100000],cnt[5],n,x,y,z ;
main()
{
        freopen("2.txt","r",stdin) ;
        freopen("3.txt","w",stdout) ;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d%d%d",&x,&y,&z) ;
        for(int k=1;k<=n+1;k++) scanf("%d",&a[k]) ;
        cnt[0]=cnt[1]=cnt[2]=cnt[3]=0 ;
        for(int k=1;k<n+1;k++)
        {
            if(a[k]>a[k+1]) cnt[a[k]-a[k+1]]++ ;
            else cnt[a[k+1]-a[k]]++ ;
        }
        if(!(x==cnt[1] && y==cnt[2] && z==cnt[3])) printf("bomb\n") ;
    }
}
