#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;
vector<int> v[maxn] ;
int fa[maxn] ;

struct P{int id,val;}a[maxn];
bool cmp(const P &a,const P &b)
{ return a.val==b.val ? a.id>b.id : a.val>b.val ; }

int d[maxn] ;
void dfs(int x,int dep)
{
    d[x]=dep ; a[x]=(P){x,dep} ;

    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x])
        fa[v[x][i]]=x , dfs(v[x][i],dep+1) ;
}

int cnt[maxn] ;
set<int> have[maxn][21] ;
main()
{
    int n,s,k ; scanf("%d%d%d",&n,&s,&k) ;
    for(int i=1;i<n;i++)
    {
        int x,y ; scanf("%d%d",&x,&y) ;
        v[x].push_back(y) ;
        v[y].push_back(x) ;
    }

    fa[1]=1 ;
    dfs(1,0) ;

    sort(a+1,a+n+1,cmp) ;
    int ans=0 ;
    for(int i=1;i<=n;i++)
    {
        int x=a[i].id ;

        int found=-1,dep=-1 ;
        for(int j=0;j<=k;j++) if(have[x][j].size())
            { found=(*have[x][j].begin()) ; dep=d[found] ; break ; }

        int y=x ;
        for(int z=1;z<=k;z++)
        {
            y=fa[y] ;
            for(int j=z;j<=k;j++) if(have[y][j].size())
            {
                if(found==-1 || d[*have[y][j].begin()]>dep)
                    found=(*have[y][j].begin()) ,
                    dep = d[*have[y][j].begin()];
            }
        }

        if(found!=-1)
        {
            if(!(--cnt[found]))
                for(int z=0,j=found;z<=k;z++,j=fa[j])
                    have[j][k-z].erase(found) ;
            continue ;
        }

        cnt[y]=s-1 ; ans++ ;
        if(s==1) continue ;

        for(int z=0,j=y;z<=k;z++,j=fa[j])
            {have[j][k-z].insert(y) ; if(j==1) break ;}
    }
    printf("%d\n",ans) ;
}
