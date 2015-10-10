#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;
vector<int> v[maxn],son[maxn][22] ;
int fa[maxn],num[maxn][22] ;
bool done[maxn] ;

struct P{int id,val;}a[maxn];
bool cmp(const P &a,const P &b)
{ return a.val==b.val ? a.id>b.id : a.val>b.val ; }

void dfs(int x,int dep)
{
    int d=0 ; a[x]=(P){x,dep} ;
    for(int i=x;d<=21;i=fa[i])
    {
        son[i][d].push_back(x) ;
        if(i==fa[i]) break ;
        d++ ;
    }

    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x])
        fa[v[x][i]]=x , dfs(v[x][i],dep+1) ;
}

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
        int now=0 ;
        for(int j=0;j<son[x][k].size();j++) if(!done[son[x][k][j]])
        {
            if(!now) now+=s , ans++ ;
            now-- ; done[son[x][k][j]]=1 ;
        }

        num[x][k]+=now ;

        for(int dep=0;dep<=k;dep++) if(num[x][dep])
        {
            for(int j=dep;j>=0 && num[x][dep];j--)
                for(int j2=0;num[x][dep] && j2<son[x][j].size();j2++)
                    if(!done[son[x][j][j2]])
                    done[son[x][j][j2]]=1 , num[x][dep]-- ;
        }

        for(int j=1;j<=k;j++) num[fa[x]][j-1]+=num[x][j] ;
    }

    int no=0 ;
    for(int i=1;i<=n;i++) if(!done[i]) no++ ;
    ans+= (((no%s)==0) ? (no/s) : ((no/s)+1)) ;

    printf("%d\n",ans) ;
}
