#include<bits/stdc++.h>
using namespace std;

bool dp[2001] ;
int num[2001] ;
int find_cons_max(int *a,int n,int res)
{
    memset(dp,0,sizeof(dp)) ; dp[0]=1 ;
    num[0]=0 ;
    for(int i=0;i<n;i++) for(int j=a[i];j<=2000;j++) if(dp[j-a[i]] && num[j-a[i]]<res)
    {
        if(dp[j]==0) num[j]=num[j-a[i]]+1 ;
        else num[j]=min(num[j],num[j-a[i]]+1) ;
        dp[j]=1 ;
    }
    int ret=0 , now=1 ;
    for(;now<=2000 && dp[now];now++) ;
    return now-1 ;
}

int ans[2000] , anslen , ansval ;

bool better(int *a,int len,int val)
{
    if(anslen==-1) return 1 ;
    if(val!=ansval) return val>ansval ;
    if(len!=anslen) return len<anslen ;
    for(int i=len-1;i>=0;i--) if(a[i]!=ans[i]) return a[i]<ans[i] ;
    return 0 ;
}

main()
{
    int res,a[2000] ;
    while(scanf("%d",&res)==1 && res)
    {
        int T ; scanf("%d",&T) ;
        anslen=-1 ; ansval=-1 ;
        while(T--)
        {
            int n ; scanf("%d",&n) ;
            for(int i=0;i<n;i++) scanf("%d",&a[i]) ;
            int val=find_cons_max(a,n,res) ;
            if(better(a,n,val))
            {
                anslen=n ;
                for(int i=0;i<n;i++) ans[i]=a[i] ;
                ansval=val ;
            }
        }
        printf("max coverage = %3d :",ansval) ;
        for(int i=0;i<anslen;i++) printf("%3d",ans[i]) ;
        printf("\n") ;
    }
}
