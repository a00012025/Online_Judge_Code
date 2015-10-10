#include<stdio.h>
#include<string.h>
#include<set>
using namespace std;
set<int> hos1[101] , hos2[101] ;
int G[101][101] , c1[10001] , c2[10001] , m,n,cnt ;
bool boom1[101] , boom2[101] ;
bool d1[101],d2[101] ;
void init()
{
    memset(boom1,0,sizeof(boom1)) ;
    memset(boom2,0,sizeof(boom2)) ;
    for(int i=0;i<=100;i++) {hos1[i].clear() ; hos2[i].clear() ;}
    memset(d1,0,sizeof(d1)) ;
    memset(d2,0,sizeof(d2)) ;
    for(int i=0;i<=100;i++) for(int j=0;j<=100;j++) G[i][j]=1000 ;
}

void boom(int r,int type)
{
    if(type==1) for(int i=0;i<m;i++)
    {
        G[r][i]-=100 ;
        if(G[r][i]==50) {hos1[r].insert(i) ; hos2[i].insert(r) ;}
    }
    else for(int i=0;i<n;i++)
    {
        G[i][r]-=100 ;
        if(G[i][r]==50) {hos1[i].insert(r) ; hos2[r].insert(i) ;}
    }
    if(type==1) boom1[r]=1 ;
    else boom2[r]=1 ;
}

void redo(int r,int type)
{
    if(type==1) for(int i=0;i<m;i++)
    {
        G[r][i]+=100 ;
        if(G[r][i]==150) {hos1[r].erase(i) ; hos2[i].erase(r) ;}
    }
    else for(int i=0;i<n;i++)
    {
        G[i][r]+=100 ;
        if(G[i][r]==150) {hos1[i].erase(r) ; hos2[r].erase(i) ;}
    }
    if(type==1) boom1[r]=0 ;
    else boom2[r]=0 ;
}

bool dfs(int num)
{
    if(!num) return 1 ;
    int x=c1[num] , y=c2[num] ;
    if(boom1[x] || boom2[y]) return dfs(num-1) ;
    if(hos1[x].empty())
    {
        boom(x,1) ;
        if(dfs(num-1)) return 1 ;
        redo(x,1) ;
    }
    if(hos2[y].empty())
    {
        boom(y,2) ;
        if(dfs(num-1)) return 1;
        redo(y,2) ;
    }
    return 0;
}

bool process()
{
    for(int i=0;i<n;i++)
    {
        if(d1[i] && hos1[i].size()) return 0 ;
        boom(i,1) ;
    }
    for(int i=0;i<m;i++)
    {
        if(d2[i] && hos2[i].size()) return 0 ;
        boom(i,2) ;
    }
    if(dfs(cnt)) return 1 ;
    else return 0 ;
}

main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int k ; cnt=0 ;
        scanf("%d %d %d",&n,&m,&k) ;
        init() ;
        while(k--)
        {
            int x,y,type ;
            scanf("%d %d %d",&x,&y,&type) ;
            if(type==0)
                {hos1[x].insert(y) ; hos2[y].insert(x) ; G[x][y]=50 ;}
            if(type==1) {d1[x]=1 ; d2[y]=1 ;}
            if(type==2) G[x][y]=150 ;
            if(type==3) {cnt++ ; c1[cnt]=x ; c2[cnt]=y ;}
        }
        if(process()) printf("YES\n");
        else printf("NO\n") ;
    }
}
