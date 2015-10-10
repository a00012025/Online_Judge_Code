#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;
int n,col[101],head[101],num0,num1 ;
bool G[101][101],vis[101],vis2[101] ;
vector<int> v[101],a,ans ;

bool dfs(int x,int c)
{
    if(c==0) num0++ ;
    else num1++ ;
    col[x]=c ; vis[x]=1 ; //printf("col[%d]=%d\n",x,c) ;
    for(int i=0;i<v[x].size();i++)
    {
        if(col[v[x][i]]==c) return 0 ;
        if(col[v[x][i]]==-1 && !dfs(v[x][i],!c)) return 0 ;
    }
    return 1 ;
}

void dfs2(int x)
{
    col[x]=!col[x] ; vis2[x]=1 ; //printf("col[%d]=%d\n",x,col[x]) ;
    for(int i=0;i<v[x].size();i++) if(!vis2[v[x][i]])
        dfs2(v[x][i]) ;
}

void reverse_col(int st)
{
    memset(vis2,0,sizeof(vis2)) ;
    dfs2(st) ;
}

bool bipartite()
{
    memset(vis,0,sizeof(vis)) ;
    memset(col,-1,sizeof(col)) ;
    a.clear() ;
    int cnt=0 ;
    for(int i=1;i<=n;i++) if(!vis[i])
    {
        num0=num1=0 ;
        if(!dfs(i,0)) return 0 ;
        //if(num1==num0) continue ;
        if(num1<num0) reverse_col(i) ;
        a.push_back(abs(num1-num0)) ; //printf("push %d\n",abs(num1-num0)) ;
        head[++cnt]=i ;
    }
    return 1 ;
}

bool d[101][101] ;
int fa[101][101] ;
void dp()
{
    for(int i=0;i<101;i++) d[0][i]=0 ;
    d[0][0]=1 ;
    if(a.empty()) return ;
    for(int i=1;i<=a.size();i++)
    {
        int x=a[i-1] ;
        for(int j=100;j>=0;j--)
        {
            if(d[i-1][j]==1) {d[i][j]=1 ; fa[i][j]=j ;}
            else if(j>=x && d[i-1][j-x]==1) {d[i][j]=1 ; fa[i][j]=j-x ;}
            else d[i][j]=0 ;
        }
    }
    int j,M=0 ;
    for(int i=0;i<a.size();i++) M+=a[i] ;
    for(j=M/2;d[a.size()][j]!=1;j--) ;
    for(int i=a.size();i>=1 && j;i--)
    {
        if(fa[i][j]!=j) ans.push_back(i) ;
        j=fa[i][j] ;
    }
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d",&n) ;
        for(int i=0;i<=n;i++) v[i].clear() ;
        memset(G,0,sizeof(G)) ;
        for(int i=1;i<=n;i++)
        {
            int t ;
            while(1)
            {
                scanf("%d",&t) ;
                if(!t) break ;
                G[i][t]=1 ;
            }
        }
        for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
            if((!G[i][j]) || (!G[j][i]))
            {v[i].push_back(j) ; v[j].push_back(i) ;}

        if(!bipartite())
            {printf("No solution\n") ; if(T) printf("\n") ; continue ;}
        ans.clear() ;
        dp() ;
        for(int i=0;i<ans.size();i++) reverse_col(head[ans[i]]) ;

        vector<int> ans0,ans1 ;
        for(int i=1;i<=n;i++)
        {
            if(col[i]==0) ans0.push_back(i) ;
            else ans1.push_back(i) ;
        }
        printf("%d",ans0.size()) ;
        for(int i=0;i<ans0.size();i++) printf(" %d",ans0[i]) ;
        printf("\n%d",ans1.size()) ;
        for(int i=0;i<ans1.size();i++) printf(" %d",ans1[i]) ;
        printf("\n") ;
        if(T) printf("\n") ;
    }
}
