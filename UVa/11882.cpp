#include<stdio.h>
#include<string.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
int n,m,G[16][16],ans_len ;
int ans[100],now[100] ;
int dx[]={1,-1,0,0} , dy[]={0,0,1,-1} , nowx,nowy ;
bool vis[16][16],vis2[16][16] ;
bool cmp(int x,int y){return x>y ;}
vector<int> v ;

bool better(int num)
{
    if(num!=ans_len) return num>ans_len ;
    for(int i=1;i<=num;i++) if(now[i]!=ans[i]) return now[i]>ans[i] ;
    return 0;
}

int dfs2(int x,int y)
{
    int ret=1 ; vis2[x][y]=1 ;
    for(int i=0;i<4;i++)
    {
        int nx=x+dx[i] , ny=y+dy[i] ;
        if(nx<0||nx>=n||ny<0||ny>=m||vis[nx][ny] || vis2[nx][ny] || !G[nx][ny])
            continue ;
        ret += dfs2(nx,ny) ; v.push_back(G[nx][ny]) ;
    }
    return ret ;
}

int estimate(int x,int y)
{
    v.clear() ;
    memset(vis2,0,sizeof(vis2)) ; vis2[x][y]=1 ;
    return dfs2(x,y) ;
}

bool may_better(int num)
{
    sort(v.begin(),v.end(),cmp) ;
    for(int i=1;i<=num;i++) if(now[i]!=ans[i]) return now[i]>ans[i] ;
    for(int i=num+1;i<=ans_len;i++) if(v[i-num-1]!=ans[i]) return v[i-num-1]>ans[i];
    return 0;
}

void dfs(int num)
{
    if(better(num))
    {
        for(int i=1;i<=num;i++) ans[i]=now[i] ;
        ans_len=num ;
    }
    int es=estimate(nowx,nowy)-1 ;
    if(num+es < ans_len) return ;
    if(num+es == ans_len && !may_better(num)) return ;

    int tem1=nowx , tem2=nowy ;
    for(int i=0;i<4;i++)
    {
        int nx=nowx+dx[i] , ny=nowy+dy[i]  ;
        if(nx<0 || nx>=n || ny<0 || ny>=m || vis[nx][ny] || !G[nx][ny])
            continue ;
        vis[nx][ny]=1 ; now[num+1]=G[nx][ny] ; nowx=nx ; nowy=ny ;
        dfs(num+1) ;
        vis[nx][ny]=0 ; nowx=tem1 ; nowy=tem2 ;
    }
}

main()
{
    while(scanf("%d%d",&n,&m)==2 && n+m)
    {
        for(int i=0;i<n;i++) for(int j=0;j<m;j++)
        {
            char c ; scanf("%c",&c) ;
            while(c!='#' && (c<'1' || c>'9')) scanf("%c",&c) ;
            G[i][j]= c=='#' ? 0 : (c-'0') ;
        }
        ans_len=0 ;
        memset(vis,0,sizeof(vis)) ;
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(G[i][j])
        {
            now[1]=G[i][j] ; vis[i][j]=1 ;
            nowx=i ; nowy=j ;
            dfs(1) ;
            vis[i][j]=0 ;
        }
        for(int i=1;i<=ans_len;i++) printf("%d",ans[i]) ;
        printf("\n") ;
    }
}
