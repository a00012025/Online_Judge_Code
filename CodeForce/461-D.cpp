#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
const int maxn=100000+10 ;
void err(){printf("0\n") ; exit(0) ;}

struct P{int to,dis;};
vector<P> v[2][maxn] ;

int fa[2][maxn],fad[2][maxn] ;
int getfa(int id,int x)
{
    if(fa[id][x]==x) return x ;
    int f=fa[id][x] , t=getfa(id,f) ;
    fad[id][x]=(fad[id][x]+fad[id][f])%2 ;
    return fa[id][x]=t ;
}

bool join(int x,int y,int id,int dis)
{
    v[id][x].push_back((P){y,dis}) ;
    v[id][y].push_back((P){x,dis}) ;
    int x2=getfa(id,x) , y2=getfa(id,y) ;
    dis=(dis+fad[id][x]+fad[id][y])%2 ;
    if(x2!=y2)
    {
        fa[id][x2]=y2 ; fad[id][x2]=dis ;
        return 1 ;
    }
    else return dis==0 ;
}

int col[2][maxn] ;
bool vis[2][maxn] ;
bool dfs(int id,int x,int c)
{
    vis[id][x]=1 ; col[id][x]=c ;
    for(auto i : v[id][x])
    {
        int c2=col[id][i.to] ;
        if(c2!=-1 && c2!=(c^i.dis)) return 0 ;
        if(!vis[id][i.to] && !dfs(id,i.to,c^i.dis))
            return 0;
    }
    return 1 ;
}

main()
{
    int n,k ; scanf("%d%d",&n,&k) ;
    memset(col,-1,sizeof(col)) ;
    for(int i=0;i<2;i++) for(int j=1;j<=n;j++)
        fa[i][j]=j ;
    for(int i=1;i<n-i;i++) join(i,n-i,0,0) ;
    for(int i=1;i<n+1-i;i++) join(i,n+1-i,1,0) ;

    while(k--)
    {
        int a,b,di ; char c[3] ;
        scanf("%d%d%s",&a,&b,c) ;
        di=(c[0]=='o' ? 1 : 0) ;
        if(a>b) swap(a,b) ;
        if((a+b)%2)
        {
            int x=(b-a-1)/2 , y=(a+b-1)/2 ;
            if(!x)
            {
                if(col[0][a]!=-1 && col[0][a]!=di) err() ;
                col[0][a]=di ; continue ;
            }
            if(!join(x,y,0,di)) err() ;
        }
        else
        {
            int x=(b-a)/2 , y=(a+b)/2 ;
            if(!x)
            {
                if(col[1][a]!=-1 && col[1][a]!=di) err() ;
                col[1][a]=di ; continue ;
            }
            if(!join(x,y,1,di)) err() ;
        }
    }

    int ans=1 ;
    for(int z=0;z<2;z++)
    {
        int n2=(z==0 ? n-1 : n) ;
        for(int i=1;i<=n2;i++)
            if(col[z][i]!=-1 && !vis[z][i]
               && !dfs(z,i,col[z][i])) err() ;
        for(int i=1;i<=n2;i++) if(!vis[z][i])
        {
            if(!dfs(z,i,0)) err() ;
            ans=ans*2%MOD ;
        }
    }
    printf("%d\n",ans) ;
}
