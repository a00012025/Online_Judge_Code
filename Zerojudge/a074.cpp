#include<bits/stdc++.h>
using namespace std;

int n,m ;
inline int ID(int x,int y)
{
    return n*(y-1)+x-1 ;
}

struct P
{
    int x,y,z;
    bool operator < (const P &rhs) const
    {
        return x==rhs.x ? (y==rhs.y ? z<rhs.z : y<rhs.y) : x<rhs.x ;
    }
    bool operator == (const P &rhs) const
    {
        return x==rhs.x && y==rhs.y && z==rhs.z ;
    }
};

vector<int> v[20000] ;
bool G[100][100][6] ;
bool vis[20000] ;

vector<int> tmp ;
void dfs(int x)
{
    vis[x]=1 ; tmp.push_back(x) ;
    for(int i=0;i<v[x].size();i++) if(!vis[v[x][i]])
        dfs(v[x][i]) ;
}

vector<P> vec ;
bool check()
{
    vec.clear() ;
    for(int i=0;i<tmp.size();i++)
    {
        int u=tmp[i] , id=u/4 , x=(id%n)+1 , y=(id/n)+1 ;
        if(G[x][y][0] && u==4*id+3) vec.push_back((P){1,0,x-1}) ;
        if(G[x][y][1] && u==4*id) vec.push_back((P){0,1,y}) ;
        if(G[x][y][2] && u==4*id+1) vec.push_back((P){1,0,x}) ;
        if(G[x][y][3] && u==4*id+2) vec.push_back((P){0,1,y-1}) ;
        if(G[x][y][4]) vec.push_back((P){1,-1,x-y}) ;
        if(G[x][y][5]) vec.push_back((P){1,1,x+y-1}) ;
    }
    sort(vec.begin(),vec.end()) ;
    vec.resize(unique(vec.begin(),vec.end())-vec.begin()) ;
    return vec.size()==3 ;
}

main()
{
    int k ; scanf("%d%d%d",&n,&m,&k) ;
    for(int i=1;i<=m;i++) G[1][i][0]=G[n][i][2]=1 ;
    for(int i=1;i<=n;i++) G[i][1][3]=G[i][m][1]=1 ;
    while(k--)
    {
        int x1,y1,x2,y2 ; scanf("%d%d%d%d",&x1,&y1,&x2,&y2) ;
        if(x1==x2)
        {
            if(x1<n) for(int i=1;i<=m;i++) G[x1+1][i][0]=1 ;
            if(x1>0) for(int i=1;i<=m;i++) G[x1][i][2]=1 ;
        }
        else if(y1==y2)
        {
            if(y1<m) for(int i=1;i<=n;i++) G[i][y1+1][3]=1 ;
            if(y1>0) for(int i=1;i<=n;i++) G[i][y1][1]=1 ;
        }
        else if((x1-x2)*(y1-y2)>0)
        {
            if(x1>x2) swap(x1,x2) , swap(y1,y2) ;
            for(int i=1;x1+i<=n && y1+i<=m;i++) G[x1+i][y1+i][4]=1 ;
        }
        else
        {
            if(x1>x2) swap(x1,x2) , swap(y1,y2) ;
            for(int i=0;x1+i+1<=n && y1-i>=1;i++) G[x1+i+1][y1-i][5]=1 ;
        }
    }
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++)
    {
        int id=ID(i,j) ;
        if(!G[i][j][0] && i>1) v[4*id+3].push_back(4*ID(i-1,j)+1) ;
        if(!G[i][j][1] && j<m) v[4*id].push_back(4*ID(i,j+1)+2) ;
        if(!G[i][j][2] && i<n) v[4*id+1].push_back(4*ID(i+1,j)+3) ;
        if(!G[i][j][3] && j>1) v[4*id+2].push_back(4*ID(i,j-1)) ;
        if(!G[i][j][4])
            v[4*id].push_back(4*id+1) , v[4*id+1].push_back(4*id) ,
            v[4*id+2].push_back(4*id+3) , v[4*id+3].push_back(4*id+2) ;
        if(!G[i][j][5])
            v[4*id].push_back(4*id+3) , v[4*id+3].push_back(4*id) ,
            v[4*id+2].push_back(4*id+1) , v[4*id+1].push_back(4*id+2) ;
    }

    int ans=0 ;
    for(int i=0;i<4*m*n;i++) if(!vis[i])
    {
        tmp.clear() ; dfs(i) ;
        if(check()) ans++ ;
    }
    printf("%d\n",ans) ;
}
