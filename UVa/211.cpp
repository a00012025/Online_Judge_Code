#include<stdio.h>
#include<vector>
#include<string.h>
using namespace std;
struct domino {int x1,y1,x2,y2;};
vector<domino> v[67] ;
int G[7][8],dx[]={1,0},dy[]={0,1} ;
int id[]={0,0,1,2,3,4,5,6,11,12,13,14,15,16,22,
          23,24,25,26,33,34,35,36,44,45,46,55,56,66};
int vis[7][8],cnt ;

void init()
{
    for(int i=0;i<=66;i++) v[i].clear() ;
    for(int i=0;i<7;i++) for(int j=0;j<8;j++) for(int k=0;k<2;k++)
    {
        int nx=i+dx[k] , ny=j+dy[k] ;
        if(nx>=7 || ny>=8) continue ;
        int val1=10*G[i][j]+G[nx][ny] ;
        int val2=10*G[nx][ny]+G[i][j] ;
        v[val1].push_back((domino){i,j,nx,ny}) ;
        if(val2 != val1) v[val2].push_back((domino){i,j,nx,ny}) ;
    }
}

void dfs(int num)
{
    if(num==28)
    {
        cnt++ ;
        for(int i=0;i<7;i++) for(int j=0;j<8;j++)
        {
            printf("%4d",vis[i][j]) ;
            if(j==7) printf("\n") ;
        }
        printf("\n") ;
        return ;
    }
    int idx=id[num+1] ;
    for(int i=0;i<v[idx].size();i++)
    {
        int x1=v[idx][i].x1 , y1=v[idx][i].y1 ;
        int x2=v[idx][i].x2 , y2=v[idx][i].y2 ;
        if(!vis[x1][y1] && !vis[x2][y2])
        {
            vis[x1][y1]=vis[x2][y2]=num+1 ;
            dfs(num+1) ;
            vis[x1][y1]=vis[x2][y2]=0 ;
        }
    }
}

main()
{
    int tc=0;
    while(scanf("%d",&G[0][0])!=EOF)
    {
        for(int i=0;i<7;i++) for(int j=0;j<8;j++)
        {
            if(i+j==0) continue ;
            scanf("%d",&G[i][j]) ;
        }
        init() ; cnt=0 ; memset(vis,0,sizeof(vis)) ;
        if(tc) printf("\n\n\n") ;
        printf("Layout #%d:\n\n",++tc) ;
        for(int i=0;i<7;i++) for(int j=0;j<8;j++)
        {
            printf("%4d",G[i][j]) ;
            if(j==7) printf("\n") ;
        }
        printf("\nMaps resulting from layout #%d are:\n\n",tc) ;
        dfs(0) ;
        printf("There are %d solution(s) for layout #%d.\n",cnt,tc) ;
    }
}
