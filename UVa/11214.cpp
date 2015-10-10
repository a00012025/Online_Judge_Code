#include<stdio.h>
#include<vector>
#include<string.h>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct Cell{int x,y;};
struct P{int val,id;};
bool comp(P a,P b) {return a.val>b.val ;}

int n,m,maxd ;
bool G[10][10] ;

vector< vector<Cell> > Queen ;

bool init()
{
    scanf("%d",&n) ; if(n==0) return 0;
    scanf("%d",&m) ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        char c ;
        scanf("%c",&c) ;
        while(c!='.' && c!='X') scanf("%c",&c) ;
        G[i][j] = (c=='.' ? 0:1) ;
    }
    Queen.clear() ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
    {
        vector<Cell> now ;
        now.push_back((Cell){i,j}) ;
        for(int k=0;k<n;k++) if(k!=i) now.push_back((Cell){k,j}) ;
        for(int k=0;k<m;k++) if(k!=j) now.push_back((Cell){i,k}) ;
        int M=max(m-1,n-1) ;
        for(int k=M;k>=-M;k--)
        {
            if(k==0) continue ;
            int nx=i+k , ny=j+k ;
            if(!(nx<0 || nx>=n || ny<0 || ny>=m)) now.push_back((Cell){nx,ny}) ;
            nx=i+k ; ny=j-k ;
            if(!(nx<0 || nx>=n || ny<0 || ny>=m)) now.push_back((Cell){nx,ny}) ;
        }
        Queen.push_back(now) ;
    }
    return 1;
}

int estimate(P *d)
{
    int sum=0,ret=0,num=0 ;
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(G[i][j]) num++ ;
    while(sum<num) {sum+=d[ret].val ; ret++ ;}
    return ret ;
}

bool iddfs(int num)
{
    if(num==maxd)
    {
        for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(G[i][j]) return 0 ;
        return 1;
    }
    P d[100] ;
    for(int i=0;i<n*m;i++)
    {
        d[i].val=0 ; d[i].id=i ;
        for(int j=0;j<Queen[i].size();j++)
            if(G[Queen[i][j].x][Queen[i][j].y]) d[i].val++ ;
    }
    sort(d,d+n*m,comp) ;
    if(estimate(d)>maxd-num) return 0;

    vector<Cell> tem ;
    for(int i=0;i<n*m && d[i].val>=d[0].val-4;i++)
    {
        tem.clear() ;
        int idx=d[i].id ;
        for(int j=0;j<Queen[idx].size();j++)
            if(G[Queen[idx][j].x][Queen[idx][j].y])
        {
            G[Queen[idx][j].x][Queen[idx][j].y]=0 ;
            tem.push_back(Queen[idx][j]) ;
        }
        if(iddfs(num+1)) return 1;
        for(int j=0;j<tem.size();j++) G[tem[j].x][tem[j].y]=1 ;
    }
    return 0;
}

main()
{
    int ans[10][10]={{0,0,0,0,0,0,0,0,0,0},{0,1,1,1,1,1,1,1,1,1},
    {0,1,1,1,2,2,2,2,2,2},{0,1,1,1,2,2,2,3,3,3},{0,1,2,2,2,2,3,3,3,4},
    {0,1,2,2,2,3,3,3,4,4},{0,1,2,2,3,3,3,4,4,4},{0,1,2,3,3,3,4,4,5,5},
    {0,1,2,3,3,4,4,5,5,5},{0,1,2,3,4,4,4,5,5,5}} ;
    int tc=0,fir=1 ;
    while(init())
    {
        maxd=0 ;
        for(;maxd<ans[n][m];maxd++) if(iddfs(0)) break ;
        printf("Case %d: %d\n",++tc,maxd) ;
    }
}
