#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;
vector<int> v[maxn],son[maxn][21] ;
int fa[maxn],num[maxn][21] ;
bool done[maxn] ;

struct P{int id,val;}a[maxn];
bool cmp(const P &a,const P &b) { return a.val>b.val ; }

void dfs(int x,int dep)
{
    int d=0 ; a[x]=(P){x,dep} ;
    for(int i=x;d<=20;i=fa[i])
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
        if(done[x]) continue ;
        int now=0 ;
        for(int j=0;j<son[x][k].size();j++) if(!done[son[x][k][j]])
        {
            if(!now) now+=s , ans++ ;
            now-- ; done[son[x][k][j]]=1 ;
        }

        num[x][k]=now ;
        int nowd=k ;
        for(int dep=k-1;dep>=0;dep--)
        {
            if(num[x][dep]) nowd=dep ;
            if(nowd==k && num[x][k]==0) continue ;
            for(int j=0;j<son[x][dep].size();j++) if(!done[son[x][dep][j]])
            {
                done[son[x][dep][j]]=1 ;
                if(!(--num[x][nowd]))
                    while(nowd<k && !num[x][nowd]) nowd++ ;
                if(nowd==k && num[x][k]==0) break ;
            }
        }
        for(int j=1;j<=k;j++) num[fa[x]][j-1]+=num[x][j] ;
    }

    int no=0 ;
    for(int i=1;i<=n;i++) if(!done[i]) no++ ;
    ans+= (no%s==0 ? (no/s) : (no/s+1)) ;
    printf("%d\n",ans) ;
}
