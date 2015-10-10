#include<bits/stdc++.h>
#define INF 1000000000
using namespace std;
const int maxn=100000+10,maxk=16 ;

int k,n,s[maxn],sum[maxn] ;

map<int,int> d[1<<maxk] ;
vector<int> v[1<<maxk] ;
int a[maxk],tot[1<<maxk] ;
int ri[maxk][maxn] ;
int dp(int id,int S)
{
    if(id==n+1) return tot[S] ;
    auto it=d[S].find(id) ;
    if(it!=d[S].end()) return it->second ;

    int ret=-INF ;
    for(int i=0;i<v[S].size();i++)
    {
        int j=v[S][i] ;
        int id2=ri[j][id] ;
        if(id2>id) ret=max(ret,dp(id2,S^(1<<j))) ;
    }
    return d[S][id]=ret ;
}

main()
{
    freopen("nochange.in","r",stdin) ;
    freopen("nochange.out","w",stdout) ;
    scanf("%d%d",&k,&n) ;
    for(int i=0;i<k;i++) scanf("%d",&a[i]) ;
    for(int i=1;i<=n;i++) scanf("%d",&s[i]) , sum[i]=s[i]+sum[i-1] ;

    for(int i=0;i<(1<<k);i++) for(int j=0;j<k;j++)
        if(i&(1<<j)) v[i].push_back(j) ,
        tot[i]+=a[j] ;

    for(int i=0;i<k;i++) for(int j=1,j2=1,now=0;j<=n;j++)
    {
        while(j2<=n && now+s[j2]<=a[i]) now+=s[j2++] ;
        ri[i][j]=j2 ;
        now-=s[j] ;
    }

    int ans=dp(1,(1<<k)-1) ;
    printf("%d\n",ans<0 ? -1 : ans) ;
}
