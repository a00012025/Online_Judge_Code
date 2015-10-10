#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
const int maxn=100000 ;
int fa[maxn+10],st[maxn+10],ed[maxn+10] ;
int in[maxn+10],out[maxn+10],time ;
int q_per[maxn+10],q_pac[maxn+10] ;
bool vis[maxn+10] ;
vector<int> v[maxn+10] ;
int getfa(int a)
{
    if(fa[a]==a) return a ;
    else return fa[a]=getfa(fa[a]) ;
}

void dfs(int n)
{
    vis[n]=1 ; in[n]=++time ;
    for(int i=0;i<v[n].size();i++)
    {
        if(vis[v[n][i]]) continue ;
        dfs(v[n][i]) ;
    }
    out[n]=++time ;
}

main()
{
    memset(st,0,sizeof(st)) ;
    memset(ed,0,sizeof(ed)) ;
    memset(vis,0,sizeof(vis)) ;
    int n,m ;
    scanf("%d %d",&n,&m) ;
    for(int i=1;i<=n;i++) {fa[i]=i ; v[i].clear() ;}
    int pack=0,ques=0 ;
    for(int i=1;i<=m;i++)
    {
        int type ;
        scanf("%d",&type) ;
        if(type==1)
        {
            int x,y  ;
            scanf("%d %d",&x,&y) ;
            v[y].push_back(x) ;
            fa[getfa(x)]=getfa(y) ;
        }
        else if(type==2)
        {
            int per ;
            scanf("%d",&per) ;
            pack++ ;
            st[pack]=per ; ed[pack]=getfa(per) ;
        }
        else if(type==3)
        {
            int x,i ;
            scanf("%d %d",&x,&i) ;
            ques++ ;
            q_per[ques]=x ; q_pac[ques]=i ;
        }
    }
    time=0 ;
    for(int i=1;i<=n;i++)
    {
        if(vis[getfa(i)]) continue ;
        dfs(fa[i]) ;
    }
    for(int i=1;i<=ques;i++)
    {
        int now=q_per[i],num=q_pac[i] ; // st[num] , ed[num] , now
        if(getfa(st[num]) != getfa(now)) printf("NO\n") ;
        else if(in[st[num]]>=in[now] && out[st[num]]<=out[now]
            && in[ed[num]]<=in[now] && out[ed[num]]>=out[now]) printf("YES\n") ;
        else printf("NO\n") ;
    }
}
