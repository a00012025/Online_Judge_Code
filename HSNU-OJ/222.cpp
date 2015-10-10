#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int n,a[250001] ;
int dp[250001] ;
vector<int> v[250001],sum[250001] ;

int search_in_v(int id,int val) /// v : decreasing , the first < val
{
    if(v[id][0]<val) return 0 ;
    int l=0 , r=v[id].size()-1 ;
    while(r-l>1)
    {
        int mid=(r+l)/2 ;
        if(v[id][mid]<val) r=mid ;
        else l=mid ;
    }
    return r ;
}

int LIS()
{
    v[0].clear() ; sum[0].clear() ; v[0].push_back(0) ; sum[0].push_back(1) ;
    dp[0]=0 ; int num=0 ;
    for(int i=1;i<=n;i++)
    {
        int id= lower_bound(dp,dp+num+1,a[i]) - dp ;
        int id2=search_in_v(id-1,a[i]) ;
        int newsum ;
        if(id2==0) newsum=sum[id-1][sum[id-1].size()-1] ;
        else newsum=sum[id-1][sum[id-1].size()-1]-sum[id-1][id2-1] ;
        newsum%=MOD ; if(newsum<0) newsum+=MOD ;

        if(id==num+1)
        {
            v[id].clear() ; sum[id].clear() ;
            dp[id]=a[i] ;
            v[id].push_back(a[i]) ; sum[id].push_back(newsum) ;
            num++ ;
        }
        else
        {
            dp[id]=min(dp[id],a[i]) ;
            int S=sum[id][v[id].size()-1]+newsum ; S%=MOD ;
            v[id].push_back(a[i]) ; sum[id].push_back(S) ;
        }
    }
    return sum[num][v[num].size()-1] ;
}

main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ; for(int i=1;i<=n;i++) scanf("%d",&a[i]) ;
        printf("%d\n",LIS()) ;
    }
}
