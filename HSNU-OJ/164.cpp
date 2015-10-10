#include<bits/stdc++.h>
#define lowbit(x) ((x)&(-(x)))
using namespace std;
const int maxn=1000+10 ;

struct event
{
    int x,y,type ;
    bool operator < (const event &rhs) const
    {
        return x==rhs.x ? type<rhs.type : x<rhs.x ;
    }
};

int bit[maxn] ;
void add(int x)
{
    for(;x<maxn;x+=lowbit(x)) bit[x]++ ;
}
int query(int x)
{
    int ret=0 ;
    for(;x;x-=lowbit(x)) ret+=bit[x] ;
    return ret ;
}

char G[maxn][maxn] ;
int u[maxn][maxn],d[maxn][maxn],l[maxn][maxn],r[maxn][maxn] ;
vector<event> v[2*maxn] ;
main()
{
    int n ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) scanf("%s",G[i]+1) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        u[i][j]=(G[i][j]=='1' ? u[i-1][j]+1 : 0) ,
        l[i][j]=(G[i][j]=='1' ? l[i][j-1]+1 : 0) ;
    for(int i=n;i>=1;i--) for(int j=n;j>=1;j--)
        d[i][j]=(G[i][j]=='1' ? d[i+1][j]+1 : 0) ,
        r[i][j]=(G[i][j]=='1' ? r[i][j+1]+1 : 0) ;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++)
        v[i-j+n].push_back((event){i,i+1-min(u[i][j],l[i][j]),1}) ,
        v[i-j+n].push_back((event){i+min(r[i][j],d[i][j]),i,2}) ;
    int ans=0 ;
    for(int i=1;i<2*n;i++)
    {
        sort(v[i].begin(),v[i].end()) ;
        memset(bit,0,sizeof(bit)) ;
        for(auto j : v[i])
        {
            if(j.type==1) add(j.y) ;
            else ans+=query(j.y) ;
        }
        int sz=v[i].size()/2 ;
        ans-=sz*(sz-1)/2 ;
    }
    printf("%d\n",ans) ;
}
