#include<bits/stdc++.h>
#define INF 2000000000
using namespace std;
const int maxn=100000+10 ;
struct P
{
    int x,y ;
    bool operator < (const P &rhs) const
    {
        if(x!=rhs.x) return x<rhs.x ;
        return y<rhs.y ;
    }
}a[maxn];

vector<int> dp ;
int ans[maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        a[i].x=x+y ; a[i].y=y-x ;
    }
    sort(a+1,a+n+1) ;
    int num=0 ; dp.push_back(INF) ;
    for(int i=1;i<=n;i++)
    {
        int id=lower_bound(dp.begin(),dp.end(),a[i].y,greater<int>())
                -dp.begin() ;
        ans[i]=id ;
        if(id==num+1) num++ , dp.push_back(a[i].y) ;
        else dp[id]=a[i].y ;
    }
    printf("%d\n",num) ;
    for(int i=1;i<=n;i++)
        printf("%d %d %d\n",(a[i].x-a[i].y)/2,(a[i].x+a[i].y)/2,ans[i]);
}
