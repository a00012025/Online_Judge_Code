#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
struct P
{
    int a,b,c,dis ;
    bool operator < (const P &rhs) const
    {
        return dis>rhs.dis ;
    }
};
int a,b,c,dis[201],goal,INF=2100000000 ;
bool vis[201][201] ;
priority_queue<P> pq;

void pq_push(int x,int y,int z,int u)
{
    if(vis[x][y]) return ;
    vis[x][y]=1 ;
    pq.push((P){x,y,z,u}) ;
}

void bfs()
{
    for(int i=1;i<=200;i++) dis[i]=INF ;
    memset(vis,0,sizeof(vis));
    while(!pq.empty()) pq.pop() ;
    dis[c]=0 ; pq.push((P){0,0,c,0}) ;
    while(!pq.empty())
    {
        P u=pq.top() ; pq.pop() ;
        if(dis[u.a]==INF) dis[u.a]=u.dis ;
        if(dis[u.b]==INF) dis[u.b]=u.dis ;
        if(dis[u.c]==INF) dis[u.c]=u.dis ;
        if(dis[goal]!=INF)  return ;
        if(u.a!=0 && u.b!=b)
        {
            if(u.a+u.b<=b) pq_push(0,u.a+u.b,u.c,u.dis+u.a) ;
            else pq_push(u.a+u.b-b,b,u.c,u.dis+b-u.b) ;
        }
        if(u.a!=0 && u.c!=c)
        {
            if(u.a+u.c<=c) pq_push(0,u.b,u.a+u.c,u.dis+u.a) ;
            else pq_push(u.a+u.c-c,u.b,c,u.dis+c-u.c) ;
        }
        if(u.b!=0 && u.a!=a)
        {
            if(u.a+u.b<=a) pq_push(u.a+u.b,0,u.c,u.dis+u.b) ;
            else pq_push(a,u.a+u.b-a,u.c,u.dis+a-u.a) ;
        }
        if(u.b!=0 && u.c!=c)
        {
            if(u.b+u.c<=c) pq_push(u.a,0,u.b+u.c,u.dis+u.b) ;
            else pq_push(u.a,u.b+u.c-c,c,u.dis+c-u.c) ;
        }
        if(u.c!=0 && u.a!=a)
        {
            if(u.a+u.c<=a) pq_push(u.a+u.c,u.b,0,u.dis+u.c) ;
            else pq_push(a,u.b,u.a+u.c-a,u.dis+a-u.a) ;
        }
        if(u.c!=0 && u.b!=b)
        {
            if(u.b+u.c<=b) pq_push(u.a,u.b+u.c,0,u.dis+u.c) ;
            else pq_push(u.a,b,u.b+u.c-b,u.dis+b-u.b) ;
        }
    }
}

main()
{
    int T;
    scanf("%d",&T) ;
    while(T--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&goal) ;
        bfs() ;
        int ans ;
        for(ans=goal;dis[ans]==INF;ans--) ;
        printf("%d %d\n",dis[ans],ans) ;
    }
}
