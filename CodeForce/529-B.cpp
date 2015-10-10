#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;
const int maxn=1000+10 ;

int w[maxn],h[maxn] ;
int tmp[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    int ma=0 ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&w[i],&h[i]) ;
        ma=max(ma,max(w[i],h[i])) ;
    }

    int ans=INF ;
    for(int i=ma;i>=1;i--)
    {
        int cnt=0,ok=1,num=n/2,sum=0 ;
        for(int j=1;j<=n;j++)
        {
            if(h[j]>i && w[j]>i) { ok=0 ; break ; }
            if(h[j]>i) num-- , sum+=h[j] ;
            else if(w[j]>i) sum+=w[j] ;
            else sum+=w[j] , tmp[cnt++]=h[j]-w[j] ;
        }
        if(!ok || num<0) break ;
        sort(tmp,tmp+cnt) ;
        for(int i=0;i<num && i<cnt && tmp[i]<0;i++)
            sum+=tmp[i] ;
        ans=min(ans,sum*i) ;
    }
    printf("%d\n",ans) ;
}
