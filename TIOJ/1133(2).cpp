#include<bits/stdc++.h>
#define INF 100000000
using namespace std;
const int maxn=150+10 ;

int ABS(int x)
{
    return x>=0 ? x : -x ;
}

struct P
{
    int x1,y1,x2,y2 ;
    void scan()
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2) ;
    }
};

int pt_to_rec(const P &p,int x,int y)
{
    int d=0 ;
    if(x<p.x1) d+=p.x1-x ;
    if(x>p.x2) d+=x-p.x2 ;
    if(y<p.y1) d+=p.y1-y ;
    if(y>p.y2) d+=y-p.y2 ;
    return d;
}

int recdis(const P &p,const P &q)
{
    int ret=INF ;
    ret=min(ret,pt_to_rec(p,q.x1,q.y1)) ;
    ret=min(ret,pt_to_rec(p,q.x1,q.y2)) ;
    ret=min(ret,pt_to_rec(p,q.x2,q.y1)) ;
    ret=min(ret,pt_to_rec(p,q.x2,q.y2)) ;
    ret=min(ret,pt_to_rec(q,p.x1,p.y1)) ;
    ret=min(ret,pt_to_rec(q,p.x1,p.y2)) ;
    ret=min(ret,pt_to_rec(q,p.x2,p.y1)) ;
    ret=min(ret,pt_to_rec(q,p.x2,p.y2)) ;
    return ret ;
}

P r[maxn] ;
int d[10][maxn] ;
int dis[maxn][maxn],m ;
bool inq[10][maxn] ;

int SPFA(int st,int ed,int num)
{
    for(int i=0;i<=num;i++) for(int j=0;j<maxn;j++)
        d[i][j]=INF ;
    d[0][st]=0 ;
    memset(inq,0,sizeof(inq)) ;
    queue<int> q ; q.push(0) ; q.push(st) ; inq[0][st]=1 ;
    while(!q.empty())
    {
        int d0=q.front() ; q.pop() ;
        int x=q.front() ; q.pop() ;
        inq[d0][x]=0 ;
        for(int i=0;i<=m+1;i++)
        {
            int d1= i==ed ? d0 : d0+1 ;
            if(d1>num) continue ;
            if(d[d1][i] > d[d0][x]+dis[x][i])
            {
                d[d1][i]=d[d0][x]+dis[x][i] ;
                if(!inq[d1][i]) q.push(d1) , q.push(i) ;
                inq[d1][i]=1 ;
            }
        }
    }

    return d[num][ed] ;
}

main()
{
    int n ;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=m;i++) r[i].scan() ;
        for(int i=1;i<=m;i++) for(int j=i+1;j<=m;j++)
            dis[i][j]=dis[j][i]=recdis(r[i],r[j]) ;
        int Q ; scanf("%d",&Q) ;
        while(Q--)
        {
            int num,x1,y1,x2,y2 ;
            scanf("%d%d%d%d%d",&num,&x1,&y1,&x2,&y2) ;
            for(int i=1;i<=m;i++)
                dis[0][i]=dis[i][0]=pt_to_rec(r[i],x1,y1) ,
                dis[m+1][i]=dis[i][m+1]=pt_to_rec(r[i],x2,y2) ;
            dis[0][m+1]=dis[m+1][0]=ABS(x1-x2)+ABS(y1-y2) ;
            printf("%d\n",SPFA(0,m+1,num)) ;
        }
    }
}
