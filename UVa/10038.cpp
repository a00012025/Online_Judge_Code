#include<stdio.h>
int a[3001],n ;

bool solve()
{
    bool vis[3001]={0} ;
    for(int i=1;i<n;i++)
        if(a[i]>a[i+1]) vis[a[i]-a[i+1]]=1 ;
        else vis[a[i+1]-a[i]]=1 ;
    for(int i=1;i<n;i++) if(!vis[i]) return 0;
    return 1;
}

main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        if(solve())printf("Jolly\n");
        else printf("Not jolly\n");
    }
}
