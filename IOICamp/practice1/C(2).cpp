#include<bits/stdc++.h>
using namespace std;

int a[300],b[300] ;
int d[210][210][110] ;

int dp(int l,int r,int tp)
{
    if(d[l][r][tp]!=-1) return d[l][r][tp] ;
    if(l>r) return 0 ;
    int &ans=d[l][r][tp] ;
    while(l<=r && tp==0 && a[l]==b[l]) l++ ;
    while(l<=r && tp && tp==b[l]) l++ ;
    if(l>r) return ans=0 ;

    ans=1000 ;
    for(int i=l;i<=r;i++) if(b[i]==b[l]) ans=min(ans,dp(l,i,b[l])+dp(i+1,r,tp)+1) ;
    return ans ;
}

main()
{
    //freopen("input.txt","r",stdin) ;
    int T ;  scanf("%d",&T) ;
    while(T--)
    {
        int n ;  scanf("%d",&n) ;
        for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        for(int i=1;i<=n;i++) scanf("%d",&b[i]) ;
        memset(d,-1,sizeof(d)) ;
        printf("%d\n",dp(1,n,0)) ;
    }
}
