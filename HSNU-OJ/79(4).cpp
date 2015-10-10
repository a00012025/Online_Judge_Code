#include<bits/stdc++.h>
using namespace std;
const int maxn=100000+10 ;
vector<int> v[maxn] ;
int fa[maxn] ;

struct P{int id,val;}a[maxn];
bool cmp(const P &a,const P &b)
{ return a.val==b.val ? a.id>b.id : a.val>b.val ; }

void dfs(int x,int dep)
{
    a[x]=(P){x,dep} ;

    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x])
        fa[v[x][i]]=x , dfs(v[x][i],dep+1) ;
}

bool done[maxn] ;

void dfs2(int x,int &num,int las)
{
    if(las<0 || !num) return ;
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x] /*&& !done[v[x][i]]*/)
        dfs2(v[x][i],num,las-1) ;
    if(!num || done[x])return ;
    done[x]=1 ; num-- ;
}

void place(int x,int s,int k)
{
    for(int y=x;s && k>=0;y=fa[y],k--) { dfs2(y,s,k) ; if(y==1) break ; }
}

int getnum(int x,int dep)
{
    if(dep==0) return (done[x] ? 0 : 1 ) ;
    int ret= (done[x] ? 0 : 1) ;
    for(int i=0;i<v[x].size();i++) if(v[x][i]!=fa[x] /*&& !done[v[x][i]]*/)
        ret+=getnum(v[x][i],dep-1) ;
    return ret ;
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
        int x=a[i].id , y=x ;
        if(done[x]) continue ;
        for(int z=1;z<=k;z++) y=fa[y] ;

        int num=getnum(y,k) ;
        int add= (num%s==0 ? num/s : ((num/s)+1)) ;
        ans+=add ; //printf("place %d : %d\n",y,add) ;
        place(y,add*s,k) ;
    }
/*
    int no=0 ;
    for(int i=1;i<=n;i++) if(!done[i]) no++ ;
    ans+= (no%s==0 ? no/s : (no/s)+1) ;
*/
    printf("%d\n",ans) ;
}
