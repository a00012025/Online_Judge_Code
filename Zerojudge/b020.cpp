#include<stdio.h>
#include<queue>
#include<map>
#include<string.h>
using namespace std;
struct P
{
    int x,y,z;
    bool operator < (const P &rhs) const
    {
        if(x!=rhs.x) return x<rhs.x ;
        if(y!=rhs.y) return y<rhs.y ;
        return z<rhs.z ;
    }
};
bool operator == (const P &a,const P &b) {return a.x==b.x && a.y==b.y && a.z==b.z; }
int vis[3001][3001],tc=0 ;
int n,x1,y1,z1,x2,y2,z2 ;
bool solve()
{
    P goal=(P){x2,y2,z2} ;
    if(x1==x2 && y1==y2 && z1==z2) return 1 ;
    vis[x1][y1]=tc ;
    queue<P> q ; q.push((P){x1,y1,z1}) ;
    while(!q.empty())
    {
        P u=q.front() ; q.pop() ;
        P v=(P){u.y,u.x,u.z} ; if(v==goal) return 1 ;
        if(vis[v.x][v.y]!=tc) {q.push(v) ; vis[v.x][v.y]=tc ; }
        v=(P){u.x,u.z,u.y} ; if(v==goal) return 1 ;
        if(vis[v.x][v.y]!=tc) {q.push(v) ; vis[v.x][v.y]=tc ; }
        v=(P){u.z,u.y,u.x} ; if(v==goal) return 1 ;
        if(vis[v.x][v.y]!=tc) {q.push(v) ; vis[v.x][v.y]=tc ; }
        v=(P){2*u.y-u.x+1,2*u.x-u.y-1,u.z} ; if(v==goal) return 1 ;
        if(v.x<0 || v.y<0 || v.z<0 || v.x>n || v.y>n || v.z>n)
        if(vis[v.x][v.y]!=tc) {q.push(v) ; vis[v.x][v.y]=tc ; }
    }
    return 0 ;
}

main()
{
    memset(vis,0,sizeof(vis)) ;
    while(scanf("%d%d%d%d%d%d%d",&n,&x1,&y1,&z1,&x2,&y2,&z2)==7 && n)
    {
        tc++ ;
        if(x1+y1+z1!=x2+y2+z2) {printf("No\n") ; continue ; }
        if(solve()) printf("Yes\n") ;
        else printf("No\n") ;
    }
}
