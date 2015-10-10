#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10 ;

struct P
{
    int x,y ;
    bool operator < (const P &rhs) const
    {
        return x==rhs.x ? y>rhs.y : x<rhs.x ;
    }
}a[maxn],b[maxn];

vector<int> v ;
int dp[maxn] ;
int LIS()
{
    int num=0 ;
    dp[0]=0 ;
    for(auto i : v)
    {
        int id=lower_bound(dp,dp+num+1,i)-dp ;
        dp[id]=i ;
        if(id==num+1) num++ ;
    }
    return num ;
}

int solve(int num)
{
    sort(b,b+num) ;
    v.clear() ;
    for(int i=0;i<num;i++) v.push_back(b[i].y) ;
    return LIS() ;
}

main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y) ;
    int ans=0 ;
    for(int i=1;i<=n;i++)
    {
        int cnt=0 ;
        b[cnt++]=a[i] ;
        for(int j=1;j<=n;j++) if(i!=j)
        {
            if(a[i].x>=a[j].x) continue ;
            if(a[j].y<=a[i].y) continue ;
            if(a[j].x>a[i].y) continue ;
            b[cnt++]=a[j] ;
        }
        ans=max(ans,solve(cnt)) ;
    }
    printf("%d\n",ans) ;
}
