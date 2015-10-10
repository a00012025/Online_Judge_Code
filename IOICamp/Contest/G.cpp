#include<bits/stdc++.h>
using namespace std;

int p[1000],n ;
int now[10001],num ;

void push(int x)
{
    for(int i=x;i<=n;i+=x)
    {
        now[i]^=1 ;
        if(!now[i]) num-- ;
        else num++ ;
    }
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int k ; scanf("%d%d",&n,&k) ;
        for(int i=0;i<k;i++) scanf("%d",&p[i]) ;
        sort(p,p+k) ;
        int cnt=0 ;
        for(;cnt<k && p[cnt]<=37;cnt++) ;

        int ans=0 ;
        for(int i=0;i<(1<<cnt);i++)
        {
            memset(now,0,sizeof(now)) ;
            num=0 ;
            for(int j=0;j<cnt;j++) if(i&(1<<j)) push(p[j]) ;
            for(int j=cnt;j<k;j++)
            {
                int tmp=num ;
                push(p[j]) ;
                if(num<tmp) push(p[j]) ;
            }
            ans=max(ans,num) ;
        }
        if(!cnt)
        {
            memset(now,0,sizeof(now)) ;
            num=0 ;
            for(int j=0;j<k;j++)
            {
                int tmp=num ;
                push(p[j]) ;
                if(num<tmp) push(p[j]) ;
            }
            ans=max(ans,num) ;
        }
        printf("%d\n",ans) ;
    }
}
