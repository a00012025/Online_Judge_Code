#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn=300000+10,maxk=1000000,LOG=int(log2(maxn)+1) ;

vector<int> v[maxk] ;
inline int query(int l,int r,int x)
{
    int ret=upper_bound(v[x].begin(),v[x].end(),r)-
            lower_bound(v[x].begin(),v[x].end(),l) ;
    return upper_bound(v[x].begin(),v[x].end(),r)-
            lower_bound(v[x].begin(),v[x].end(),l) ;
}

int n,a[maxn] ;
int G[LOG][maxn] ;
inline void build()
{
    for(int i=0;(1<<i)<=n;i++) for(int j=1;j+(1<<i)-1<=n;j++)
        G[i][j]=(i ?
            (a[G[i-1][j]]>a[G[i-1][j+(1<<(i-1))]] ?
            G[i-1][j] : G[i-1][j+(1<<(i-1))])
        : j) ;
}

int getpos(int l,int r)
{
    int len=floor(log2(r-l+1+0.5)) ;
    int x=G[len][l] , y=G[len][r-(1<<len)+1] ;
    return a[x]>a[y] ? x : y ;
}

int sum[maxn],k ;
LL solve(int l,int r)
{
    if(l>=r) return 0 ;
    int mid=getpos(l,r) ;
    LL ret=solve(l,mid-1)+solve(mid+1,r) ;
    if(mid<=(r+l)/2) for(int i=l-1;i<mid;i++)
    {
        int val=(sum[i]+a[mid])%k ;
        ret+=query(mid,r,val) ;
    }
    else for(int i=mid;i<=r;i++)
    {
        int val=(sum[i]-a[mid])%k ;
        if(val<0) val+=k ;
        ret+=query(l-1,mid-1,val) ;
    }
    return ret-1 ;
}

main()
{
    scanf("%d%d",&n,&k) ;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]) , sum[i]=(sum[i-1]+a[i])%k ;
    for(int i=0;i<=n;i++) v[sum[i]].push_back(i) ;
    build() ;
    printf("%lld\n",solve(1,n)) ;
}
