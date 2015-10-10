#define NDEBUG
#ifdef NDEBUG
#define debugf(...) ((void)0)
#else
#define debugf(...) printf(__VA_ARGS__)
#endif // NDEBUG
#include<bits/stdc++.h>
using namespace std;
int n,a[100001] ;
int dp[100001],length[100001] ;
int LIS()
{
    int num=0 ;
    dp[0]=0 ; a[0]=0 ;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>dp[num])
        {
            dp[num+1]=a[i] ;
            length[i]=num+1 ;
            num++ ; continue ;
        }
        int id=lower_bound(dp,dp+num+1,a[i])-dp ;
        length[i]=id ;
        dp[id]=min(dp[id],a[i]) ;
    }
    return num ;
}

int ans[100001] , cnt[100001] ;
int head[100001] ;
main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
    int maxl=LIS() ;
    for(int i=1;i<=n;i++) ans[i]=1 ;

    memset(head,0,sizeof(head)) ;
    memset(cnt,0,sizeof(cnt)) ;
    for(int i=n;i>=1;i--) if(length[i]==maxl || head[length[i]+1]>a[i])
    {
        head[length[i]]=max(head[length[i]],a[i]) ;
        cnt[length[i]]++ ;
        ans[i]=2 ;
    }
    for(int i=1;i<=n;i++) if(ans[i]==2 && cnt[length[i]]==1)
        ans[i]=3 ;
    for(int i=1;i<=n;i++) printf("%d",ans[i]) ; printf("\n") ;
}
