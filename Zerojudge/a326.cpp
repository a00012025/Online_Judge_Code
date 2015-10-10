#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;
bool organ[15][50] ;
int n,m,M ;
bool G[25][25] ;

struct P {int id,val;};
bool cmp(P x,P y)
{
    if(x.val!=y.val) return x.val>y.val ;
    else return x.id<y.id ;
}

bool vis[15] ;
bool dfs(int k)
{
    P D[50] ;
    for(int i=0;i<m+n;i++) {D[i].id=i ; D[i].val=0 ;}
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(G[i][j])
        {D[i].val++ ; D[n+j].val++ ;}
    sort(D,D+m+n,cmp) ;
    if(D[0].val==0) return 1 ;
    vector<int> tmp,attack ;
    for(int i=0;i<m+n && D[i].val>0;i++)
    {
        int id=D[i].id ;
        if(id<n)
        {
            attack.clear() ;
            for(int j=1;j<=M;j++) if(organ[j][id]==1 && !vis[j])
            {
                attack.push_back(j) ;
                vis[j]=1 ;
            }
            if(attack.size()<=k)
            {
                tmp.clear() ;
                for(int j=0;j<m;j++) if(G[id][j])
                {
                    tmp.push_back(j) ;
                    G[id][j]=0 ;
                }
                if(dfs(k-attack.size())) return 1 ;
                for(int j=0;j<tmp.size();j++)
                    G[id][tmp[j]]=1 ;
            }
            for(int j=0;j<attack.size();j++)
                vis[attack[j]]=0 ;
        }
        else
        {
            id -= n ;
            attack.clear() ;
            for(int j=1;j<=M;j++) if(organ[j][id+n] && !vis[j])
            {
                attack.push_back(j) ;
                vis[j]=1 ;
            }
            if(attack.size()<=k)
            {
                tmp.clear() ;
                for(int j=0;j<n;j++) if(G[j][id])
                {
                    tmp.push_back(j) ;
                    G[j][id]=0 ;
                }
                if(dfs(k-attack.size())) return 1 ;
                for(int j=0;j<tmp.size();j++)
                    G[tmp[j]][id]=1 ;
            }
            for(int j=0;j<attack.size();j++)
                vis[attack[j]]=0 ;
        }
    }
    return 0 ;
}

main()
{
    int T ;
    scanf("%d",&T) ;
    while(T--)
    {
        int k ;
        scanf("%d%d%d",&n,&M,&k) ;
        memset(organ,0,sizeof(organ)) ;
        for(int i=0;i<n;i++)
        {
            char tmp[50] ;
            scanf("%s",tmp) ;
            m=strlen(tmp) ;
            for(int j=0;j<m;j++) if(tmp[j]>='A' && tmp[j]<='Z')
            {
                organ[tmp[j]-'A'+1][i]=1 ;
                organ[tmp[j]-'A'+1][n+j]=1 ;
            }
            for(int j=0;j<m;j++) G[i][j]= tmp[j]=='*' ? 1 : 0 ;
        }
        memset(vis,0,sizeof(vis)) ;
        if(dfs(k)) printf("yes\n") ;
        else printf("no\n") ;
    }
}
