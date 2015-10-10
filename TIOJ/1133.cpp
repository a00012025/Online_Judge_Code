#include<bits/stdc++.h>
using namespace std;
const int maxn=300+10 ;
struct P{int x1,y1,x2,y2;};
struct Q{int x,y;};
int dp[6][maxn][maxn] ;
int mi[6][maxn][maxn] ;
int n,m,ldis[maxn],udis[maxn] ;
P tmp[maxn],r[maxn] ;
Q corn[maxn][maxn] ;

inline P inv(const P &p)
{
    return (P){n-p.x2,p.y1,n-p.x1,p.y2} ;
}

inline void srt(vector<int> &v)
{
    sort(v.begin(),v.end()) ;
    v.resize(unique(v.begin(),v.end())-v.begin()) ;
}

inline int getid(const vector<int> &v,int x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin() ;
}

int DP(int num,int X,int Y)
{
    dp[0][0][0]=0 ;
    for(int i=0;i<X;i++) for(int j=0;j<Y;j++) if(i||j)
        dp[0][i][j]= i ? dp[0][i-1][j]+udis[i] :
                            dp[0][i][j-1]+ldis[j] ;
    for(int i=1;i<=num;i++)
        for(int j=0;j<X;j++) for(int k=0;k<Y;k++)
    {
        int &ans=dp[i][j][k] ; ans=dp[i-1][j][k] ;
        if(!j && !k) ans=0 ;
        if(k) ans=min(ans,dp[i][j][k-1]+ldis[k]) ;
        if(j) ans=min(ans,dp[i][j-1][k]+udis[j]) ;
        if(corn[j][k].x!=-1)
        {
            int x0=corn[j][k].x , y0=corn[j][k].y ;
            if(j==x0 && k==y0)
                mi[i-1][j][k]=dp[i-1][j][k] ;
            else mi[i-1][j][k]= (j==x0) ?
                min(mi[i-1][j][k-1],dp[i-1][x0][k]) :
                min(mi[i-1][j-1][k],dp[i-1][j][y0]) ;
            if(j!=x0 && k!=y0) ans=min(ans,mi[i-1][j][k]) ;
            else if(j!=x0) ans=min(ans,mi[i-1][j-1][k]) ;
            else if(k!=y0) ans=min(ans,mi[i-1][j][k-1]) ;
        }
    }
    return dp[num][X-1][Y-1] ;
}

int solve(int num,int x1,int y1,int x2,int y2)
{
    vector<int> vx,vy ;
    int m2=0 ;
    for(int i=1;i<=m;i++)
    {
        if(r[i].x1>x2 || r[i].x2<x1 || r[i].y1>y2 || r[i].y2<y1)
            continue ;
        r[i].x1=max(r[i].x1,x1) ;
        r[i].y1=max(r[i].y1,y1) ;
        r[i].x2=min(r[i].x2,x2) ;
        r[i].y2=min(r[i].y2,y2) ;
        r[++m2]=r[i] ;
    }
    for(int i=1;i<=m2;i++)
        vx.push_back(r[i].x1) , vx.push_back(r[i].x2) ,
        vy.push_back(r[i].y1) , vy.push_back(r[i].y2);
    vx.push_back(x1) , vx.push_back(x2) ;
    vy.push_back(y1) , vy.push_back(y2) ;
    srt(vx) ; srt(vy) ;
    for(int i=1;i<vx.size();i++) udis[i]=vx[i]-vx[i-1] ;
    for(int i=1;i<vy.size();i++) ldis[i]=vy[i]-vy[i-1] ;
    for(int i=0;i<vx.size();i++) for(int j=0;j<vy.size();j++)
        corn[i][j]=(Q){-1,-1} ;
    for(int i=1;i<=m2;i++)
    {
        r[i].x1=getid(vx,r[i].x1) ;
        r[i].y1=getid(vy,r[i].y1) ;
        r[i].x2=getid(vx,r[i].x2) ;
        r[i].y2=getid(vy,r[i].y2) ;
        for(int j=r[i].x1;j<=r[i].x2;j++)
            for(int k=r[i].y1;k<=r[i].y2;k++)
            corn[j][k]=(Q){r[i].x1,r[i].y1} ;
    }
    return DP(num,(int)vx.size(),(int)vy.size()) ;
}

main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1;i<=m;i++)
            scanf("%d%d%d%d",&tmp[i].x1,&tmp[i].y1,&tmp[i].x2,&tmp[i].y2) ;
        int Q ; scanf("%d",&Q) ;
        while(Q--)
        {
            int num,x1,y1,x2,y2 ;
            scanf("%d%d%d%d%d",&num,&x1,&y1,&x2,&y2) ;
            if(y1>y2) swap(x1,x2) , swap(y1,y2) ;
            if(x1>x2)
            {
                for(int i=1;i<=m;i++) r[i]=inv(tmp[i]) ;
                x1=n-x1 , x2=n-x2 ;
            }
            else for(int i=1;i<=m;i++) r[i]=tmp[i] ;
            printf("%d\n",solve(num,x1,y1,x2,y2)) ;
        }
    }
}
