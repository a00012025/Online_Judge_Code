#include<bits/stdc++.h>
using namespace std;
const int maxn=10000+10 ;

vector<int> v[maxn] ;

int anc[16][maxn] ;
int dep[maxn] ;

void dfs(int x,int f)
{
    anc[0][x]=f ;
    for(auto i : v[x]) if(i!=f)
    {
        dep[i]=dep[x]+1 ;
        dfs(i,x) ;
    }
}

int n ;
void build()
{
    for(int i=1;i<16;i++) for(int j=1;j<=n;j++)
        anc[i][j]=anc[i-1][anc[i-1][j]] ;
}

int query_fa(int x,int d)
{
    if(!d) return x ;
    for(int i=15;i>=0 && d;i--) if(d&(1<<i))
    {
        x=anc[i][x] ;
        d^=(1<<i) ;
    }
    return x ;
}

int LCA(int x,int y)
{
    if(dep[x]!=dep[y]) return
        dep[x]>dep[y] ? LCA(query_fa(x,dep[x]-dep[y]),y) :
                        LCA(x,query_fa(y,dep[y]-dep[x])) ;
    if(x==y) return x ;
    for(int i=15;i>=0;i--) if(anc[i][x]!=anc[i][y])
            x=anc[i][x] , y=anc[i][y] ;
    return anc[0][x] ;
}

char name[2][2000] ;
main()
{
    int T ; scanf("%d",&T) ;
    while(T--)
    {
        int Q ; scanf("%d%d",&n,&Q) ;
        for(int i=0;i<n;i++) v[i].clear() ;
        for(int i=1;i<n;i++)
        {
            int x,y ; scanf("%d%d",&x,&y) ;
            v[x].push_back(y) ;
            v[y].push_back(x) ;
        }
        dep[0]=0 ;
        dfs(0,0) ;
        build() ;
        while(Q--)
        {
            int x,y ; scanf("%s%d%s%d",name[0],&x,name[1],&y) ;
            printf("%s and %s:",name[0],name[1]) ;
            int f=LCA(x,y) , d=dep[x]+dep[y]-2*dep[f] ;
            vector<int> ans ;
            if(d%2==0)
            {
                if(dep[x]>=dep[y]) ans.push_back(query_fa(x,d/2)) ;
                else ans.push_back(query_fa(y,d/2)) ;
            }
            else
            {
                if(dep[x]>=dep[y])
                    ans.push_back(query_fa(x,d/2)) ,
                    ans.push_back(query_fa(x,d/2+1)) ;
                else
                    ans.push_back(query_fa(y,d/2)) ,
                    ans.push_back(query_fa(y,d/2+1)) ;
            }
            sort(ans.begin(),ans.end()) ;
            for(auto  i : ans) printf(" %d",i) ;
            printf("\n") ;
        }
    }
}
