#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+10;

struct P
{
    int l,r,w,s,val,id ;
    void scan(){scanf("%d%d%d%d%d",&l,&r,&w,&s,&val) ;}
    bool operator < (const P &rhs) const
    {
        return r==rhs.r ? l>rhs.l : r<rhs.r ;
    }
}a[maxn] ;

vector<P> v ;
vector<int> v2 ;
void get_seg()
{
    v2.clear() ;
    for(auto i : v)
        v2.push_back(i.l) , v2.push_back(i.r) ;

    sort(v2.begin(),v2.end()) ;
    v2.resize(unique(v2.begin(),v2.end())-v2.begin()) ;
    for(auto &i : v)
        i.l=lower_bound(v2.begin(),v2.end(),i.l)-v2.begin()+1 ,
        i.r=lower_bound(v2.begin(),v2.end(),i.r)-v2.begin()+1 ;
    sort(v.begin(),v.end()) ;
}

int n,dp[maxn][maxn] ;
int dp2[maxn] ;
void DP(int x)
{
    for(int i=0;i<maxn;i++)
    {
        int sz=v2.size() ;
        fill(dp2,dp2+sz+1,0) ;
        for(int j=1,k=0;j<=sz && k<v.size();k++)
        {
            for(;j<v[k].r;j++) dp2[j]=max(dp2[j],dp2[j-1]) ;
            dp2[j]=max(dp2[j],dp2[j-1]) ;
            dp2[j]=max(dp2[j],dp2[v[k].l]+dp[v[k].id][i]) ;
        }
        dp[x][i]=dp2[sz] ;
    }
    if(x==n+1) return ;
    for(int i=maxn-1;i>=a[x].w;i--)
        dp[x][i]=max(dp[x][i],
        dp[x][min(i-a[x].w,a[x].s)]+a[x].val) ;
}

main()
{
    int S ;
    scanf("%d%d",&n,&S) ;
    for(int i=1;i<=n;i++) a[i].scan() ;
    sort(a+1,a+n+1) ;
    for(int i=1;i<=n;i++) a[i].id=i ;

    a[n+1]=(P){0,2*n-1,0,S,0} ;
    for(int i=1;i<=n+1;i++)
    {
        v.clear() ;
        for(int j=1;j<i;j++) if(a[j].l>=a[i].l)
            v.push_back(a[j]) ;
        get_seg() ;
        DP(i) ;
    }

    printf("%d\n",dp[n+1][S]) ;
}
