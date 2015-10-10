#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
int a[1001001],n,m,k ;
int cnt[1001] ;
main()
{
    int T,tc=0;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&k) ;
        a[1]=1 ; a[2]=2 ; a[3]=3 ;
        memset(cnt,0,sizeof(cnt)) ;
        cnt[1]=cnt[2]=cnt[3]=1 ;
        for(int i=4;i<=n;i++) {a[i]=((a[i-3]+a[i-2]+a[i-1])%m)+1 ; cnt[a[i]]++ ;}
        bool no=0 ;
        for(int i=1;i<=k;i++) if(!cnt[i]) {no=1 ; break ;}
        if(no)
        {
            printf("Case %d: sequence nai\n",++tc) ;
            continue ;
        }
        memset(cnt,0,sizeof(cnt)) ;
        int num=0 , l , r=0 , ans=n ;
        for(l=1;l<=n;l++)
        {
            while(r<n && num<k)
            {
                r++ ; cnt[a[r]]++ ;
                if(cnt[a[r]]==1 && a[r]<=k) num++ ;
            }
            if(r==n && num<k) break ;
            ans=min(ans,r-l+1) ;
            cnt[a[l]]-- ; if(cnt[a[l]]==0 && a[l]<=k) num-- ;
        }
        printf("Case %d: %d\n",++tc,ans) ;
    }
}
