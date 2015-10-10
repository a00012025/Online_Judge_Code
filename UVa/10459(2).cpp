#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
using namespace std;
vector<int> v[5001] ;
bool vis[5001],far[5001],far2[5001] ;
int n,lev[5001],fa[5001],maxd;

void dfs(int x,int l)
{
    vis[x]=1 ; lev[x]=l ;
    for(int i=0;i<v[x].size();i++) if(!vis[v[x][i]] || (l+1)<lev[v[x][i]])
        {fa[v[x][i]]=x ; dfs(v[x][i],l+1) ;}
}

void find_far(int st,bool *a)
{
    memset(vis,0,sizeof(vis));
    for(int i=1;i<=n;i++) a[i]=0 ;
    fa[st]=st ; dfs(st,0) ; maxd=0 ;
    for(int i=1;i<=n;i++) if(lev[i]>maxd) maxd=lev[i] ;
    for(int i=1;i<=n;i++) if(lev[i]==maxd) a[i]=1 ;
}

void find_best()
{
    printf("Best Roots  :") ;
    int now;
    for(now=1;!far2[now];now++) ;
    if(maxd%2)
    {
        int j=now ;
        while(lev[j]!=(maxd/2)+1) j=fa[j] ;
        if(j>fa[j]) printf(" %d %d\n",fa[j],j) ;
        else printf(" %d %d\n",j,fa[j]) ;
    }
    else
    {
        int j=now ;
        while(lev[j]!=maxd/2) j=fa[j] ;
        printf(" %d\n",j) ;
    }
}

void find_worst()
{
    int wor[5001],cnt=0 ;
    for(int i=1;i<=n;i++) if(far[i]) wor[cnt++]=i ;
    for(int i=1;i<=n;i++) if(far2[i]) wor[cnt++]=i ;
    sort(wor,wor+cnt) ;
    printf("Worst Roots :") ;
    for(int i=0;i<cnt;i++) if(!i || wor[i]!=wor[i-1]) printf(" %d",wor[i]) ;
    printf("\n") ;
}

main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            v[i].clear() ;
            int m,a;
            scanf("%d",&m) ;
            while(m--)
            {
                scanf("%d",&a) ;
                v[i].push_back(a) ;
            }
        }
        find_far(1,far) ;
        for(int i=1;i<=n;i++) if(far[i]) {find_far(i,far2) ; break ;}
        find_best() ;
        find_worst() ;
    }
}
