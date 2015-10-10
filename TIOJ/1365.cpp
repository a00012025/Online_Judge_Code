#include<bits/stdc++.h>
#define lowbit(x) (x&-x)
#define LL long long
using namespace std;
const int maxn=1000000+10 ;

struct P
{
    int x,y ;
    bool operator < (const P &rhs) const
    {
        return x==rhs.x ? y>rhs.y : x>rhs.x ;
    }
}a[maxn];

int bit[maxn] ;
void add(int x)
{
    while(x<maxn) bit[x]++ , x+=lowbit(x) ;
}

int query(int x)
{
    int ret=0 ;
    while(x) ret+=bit[x] , x-=lowbit(x) ;
    return ret ;
}

main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%d%d",&a[i].x,&a[i].y) ,
            a[i].y++ ;
        sort(a+1,a+n+1) ;
        LL ans=0LL ;
        for(int i=1;i<=n;i++)
        {
            ans+=query(a[i].y-1) ;
            add(a[i].y) ;
        }
        printf("%lld\n",ans) ;
    }
}
