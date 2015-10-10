#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10 ;

struct P
{
    int id,val ;
    bool operator < (const P &rhs) const
    {
        return val<rhs.val ;
    }
};

int val[maxn],fa[maxn],sz[maxn] ;
vector<int> v[maxn] ;

void dfs(int x)
{
    sz[x]=1 ;
    for(int i=0;i<v[x].size();i++)
        dfs(v[x][i]) , sz[x]+=sz[v[x][i]] ;
}

P p[maxn] ;
int num[maxn] ;

main()
{
    int n,root ; scanf("%d",&n) ;
    for(int i=1;i<=n;i++) num[i]=1 ;
    bool none=0 ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d",&fa[i],&val[i]) ;
        if(val[i]) num[val[i]]=0 ;
        if(fa[i]==i && !val[i]) none=1 , root=i ;
        if(fa[i]!=i && !val[i]) v[fa[i]].push_back(i) ;
        else fa[i]=i ;
    }
    for(int i=1;i<=n;i++) num[i]+=num[i-1] ;

    if(none)
    {
        for(int i=root,j=n;;j--)
        {
            val[i]=j ;
            if(v[i].size()!=1) break ;
            i=v[i][0] ;
        }
        for(int i=1;i<=n;i++) printf("%d\n",val[i]) ;
        return 0 ;
    }

    for(int i=1;i<=n;i++) if(fa[i]==i)
        dfs(i) ;

    int cnt=0 ;
    for(int i=1;i<=n;i++) if(fa[i]==i && !v[i].empty())
        p[cnt++]=(P){i,val[i]} ;
    sort(p,p+cnt) ;

    for(int i=0,sum=0;i<cnt;i++)
    {
        sum+=sz[p[i].id]-1 ;
        int mi=-1 ;
        while(sum<num[p[i].val]) mi=p[i].val , i++ , sum+=sz[p[i].id]-1 ;
        for(int j=p[i].id,now=p[i].val;;now--)
        {
            if(v[j].size()!=1) break ;
            while(num[now]==num[now-1]) now-- ;
            j=v[j][0] ;
            if(now<mi) break ;
            else val[j]=now ;
        }
    }
    for(int i=1;i<=n;i++) printf("%d\n",val[i]) ;
}
